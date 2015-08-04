#include "application.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv)
{
	m_MainWindow = new MainWindow("Simple tibia bot");
	connect(m_MainWindow, SIGNAL(ClientChoosen(DWORD)),
		this, SLOT(onClientChoosen(DWORD)));
	m_MainWindow->show();
}

Application::~Application()
{
}

void Application::onClientChoosen(DWORD pid)
{ 

	//some kind of window.show();
	if (m_Window)
	{
		m_Window->close();
		delete m_Window;
	}
	m_MainWindow->hide();

	m_Window = new GeneralWindow(pid);
	connect(m_Window, SIGNAL(finished(int)),
		this, SLOT(WindowClosing(int)));
	m_Window->show();
}

void Application::WindowClosing(int)
{
	//qt built in management...
	m_MainWindow->show();
}