#include "mainwindow.h"
#include "application.h"

MainWindow::MainWindow(QString title, QWidget* parent) : QMainWindow(parent)
{
	this->setWindowTitle(title);

	QWidget* central = new QWidget(this);
	QVBoxLayout* splitter = new QVBoxLayout(central);
	QHBoxLayout* layout = new QHBoxLayout;
	splitter->addLayout(layout);
	central->setLayout(splitter);

	m_AvailableClients = new QComboBox;
	layout->addWidget(m_AvailableClients);

	m_BtnFindClient = new QPushButton;
	m_BtnFindClient->setText("Find client");
	connect(m_BtnFindClient, SIGNAL(clicked()), this, SLOT(onFindClientClicked()));
	layout->addWidget(m_BtnFindClient);

	m_BtnChooseClient = new QPushButton;
	m_BtnChooseClient->setText("Choose client");
	connect(m_BtnChooseClient, SIGNAL(clicked()),
		this, SLOT(onClientChoosen()));
	splitter->addWidget(m_BtnChooseClient);

	setCentralWidget(central);

	m_Timer = new QTimer;
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(onTimerTick()));
	m_Timer->start(1000);

	m_ClientsList.clear();
}

MainWindow::~MainWindow()
{

}

void MainWindow::ScanForClients()
{
	m_ClientsList.clear();
	m_AvailableClients->clear();

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap)
	{
		PROCESSENTRY32 pEntry;
		pEntry.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(hProcessSnap, &pEntry))
		{
			do{
				if (!strcmp(pEntry.szExeFile, "Tibia.exe"))
				{
					m_ClientsList.append(pEntry.th32ProcessID);
				}
			} while (Process32Next(hProcessSnap, &pEntry));
		}
		CloseHandle(hProcessSnap);
	}
}

void MainWindow::onFindClientClicked()
{
	ScanForClients();
	for (int i = 0; i < m_ClientsList.length(); ++i)
		m_AvailableClients->addItem(QString::number(m_ClientsList.at(i)));
}

void MainWindow::onClientChoosen()
{
	// create a new window here... with bot specifics...
	emit ClientChoosen(m_ClientsList.at(m_AvailableClients->currentIndex()));
}

void MainWindow::onTimerTick()
{
}