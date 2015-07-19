#include "mainwindow.h"

unsigned __int32 ReadInt32(HANDLE handle, DWORD addr);

MainWindow::MainWindow(QString title, QWidget* parent) : QMainWindow(parent)
{
	this->setWindowTitle(title);

	m_GameHandle = 0;
	m_BaseAddress = 0;

	m_BtnFindClient = new QPushButton;
	m_BtnFindClient->setText("Find client");
	connect(m_BtnFindClient, SIGNAL(clicked()), this, SLOT(onFindClientClicked()));

	setCentralWidget(m_BtnFindClient);

	m_Timer = new QTimer;
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(onTimerTick()));
	m_Timer->start(1000);
}

MainWindow::~MainWindow()
{
	if (m_GameHandle)
		CloseHandle(m_GameHandle);
}

void MainWindow::onFindClientClicked()
{
	HWND hWnd = 0;
	DWORD pid = 0;
	if ((hWnd = FindWindow(0, "Tibia")))
	{
		GetWindowThreadProcessId(hWnd, &pid);
		if (pid)
		{
			if (m_GameHandle)
			{
				CloseHandle(m_GameHandle);
				m_GameHandle = 0;
			}
			m_GameHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, pid);
			if (m_GameHandle)
			{
				HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
				if (snapshot)
				{
					MODULEENTRY32 modEntry;
					modEntry.dwSize = sizeof(MODULEENTRY32);

					if (Module32First(snapshot, &modEntry))
					{
						do
						{
							if (!strcmp(modEntry.szModule, "Tibia.exe"))
							{
								m_BaseAddress = (DWORD)modEntry.modBaseAddr;
								break;
							}
						} while (Module32Next(snapshot, &modEntry));
					}
					CloseHandle(snapshot);
				}
			}
		}
	}
}

void MainWindow::onTimerTick()
{
	try
	{
		((Application*)qApp)->GetPlayer()->SetPlayerExperience(::ReadInt32(m_GameHandle, m_BaseAddress + A_EXPERIENCE));
		((Application*)qApp)->GetPlayer()->SetPlayerLevel(::ReadInt32(m_GameHandle, m_BaseAddress + A_LEVEL));
		((Application*)qApp)->GetPlayer()->SetPlayerHealth((::ReadInt32(m_GameHandle, m_BaseAddress + A_HEALTH) ^ ::ReadInt32(m_GameHandle, m_BaseAddress + A_XOR)));
		((Application*)qApp)->GetPlayer()->SetPlayerMaxHealth((::ReadInt32(m_GameHandle, m_BaseAddress + A_HEALTH_MAX) ^ ::ReadInt32(m_GameHandle, m_BaseAddress + A_XOR)));
	}
	catch (QString ex)
	{
		qDebug() << ex;
	}

	qDebug() << "LEVEL :: " << ((Application*)qApp)->GetPlayer()->GetPlayerLevel();
	qDebug() << "EXPERIENCE :: " << ((Application*)qApp)->GetPlayer()->GetPlayerExperience();
	qDebug() << "HEALTH :: " << ((Application*)qApp)->GetPlayer()->GetPlayerHealth();
	qDebug() << "MAX HEALTH :: " << ((Application*)qApp)->GetPlayer()->GetPlayerMaxHealth();
}
//... 
unsigned __int32 ReadInt32(HANDLE handle, DWORD addr)
{
	unsigned __int32 value = 0;
	SIZE_T size = sizeof(__int32);
	SIZE_T readed = 0;

	int ok = ReadProcessMemory(handle, (LPVOID)addr, &value, size, &readed);
	if (!ok || size != readed)
		throw QString("couldn't read from the specified memory location...");

	return value;
}