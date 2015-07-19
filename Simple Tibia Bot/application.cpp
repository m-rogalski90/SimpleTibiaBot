#include "pch.h"
#include "application.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv), m_Player(0)
{
	m_Player = new Player;
}

Application::~Application()
{
	delete m_Player;
}

Player* Application::GetPlayer()
{
	return m_Player;
}