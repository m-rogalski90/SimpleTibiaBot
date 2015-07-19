#pragma once
#include "pch.h"
#include <QtWidgets\qmainwindow.h>
#include <QtWidgets\qpushbutton.h>

#include <QtCore\qdebug.h>
#include <QtCore\qtimer.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QString, QWidget* = 0);
	~MainWindow();

private:
	QPushButton*	m_BtnFindClient;
	QTimer*			m_Timer;
	HANDLE			m_GameHandle;
	DWORD			m_BaseAddress;

private slots:
	void onFindClientClicked();
	void onTimerTick();
};