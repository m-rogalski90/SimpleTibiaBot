#pragma once

#include <QtWidgets\qapplication.h>
#include "player.h"

class Application : public QApplication
{
public:
	Application(int, char*[]);
	~Application();

	Player* GetPlayer();

private:
	Player*	m_Player;
};