#pragma once

#include <Windows.h>
#include <TlHelp32.h>

#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qcombobox.h>
#include <QtWidgets\qmainwindow.h>
#include <QtWidgets\qpushbutton.h>


#include <QtCore\qmap.h>
#include <QtCore\qdebug.h>
#include <QtCore\qtimer.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QString, QWidget* = 0);
	~MainWindow();

private:
	QComboBox*		m_AvailableClients;
	QPushButton*	m_BtnFindClient;
	QPushButton*	m_BtnChooseClient;
	QTimer*			m_Timer;

	QList<DWORD> m_ClientsList; // dont have time to iterate thrugh processes...

	void ScanForClients();

private slots:
	void onFindClientClicked();
	void onClientChoosen();
	void onTimerTick();

signals:
	void ClientChoosen(DWORD);
};