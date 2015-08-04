#ifndef APPLICATION
#define APPLICATION

#include <Windows.h>
#include <QtWidgets\qapplication.h>
#include <QtCore\qtimer.h>
#include <QtCore\qdebug.h>
#include "generalwindow.h"
#include "mainwindow.h"

class Application : public QApplication
{
	Q_OBJECT

public:
	Application(int, char*[]);
	~Application();

private:
	MainWindow* m_MainWindow;
	GeneralWindow* m_Window;

private slots:
	void onClientChoosen(DWORD);
	void WindowClosing(int);
};

#endif
