#pragma once

#include <QtCore\qlist.h>
#include <QtWidgets\qcheckbox.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qboxlayout.h>
#include <QtWidgets\qtabwidget.h>
#include <QtWidgets\qtabwidget.h>
#include <QtWidgets\qdialog.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qspinbox.h>
#include <QtWidgets\qcombobox.h>

#include <gameobject.h>
#include <gameclient.h>


class HealingRule : public QWidget
{
	Q_OBJECT

public:
	HealingRule(QString, __int32, QWidget* = NULL);
	~HealingRule();

	QString GetName();
	void SetIndex(__int32);

	BOOL IsMarkedForDeletion();

private:
	QLineEdit* m_LblName;
	QSpinBox* m_MinSpin;
	QSpinBox* m_MaxSpin;
	QLineEdit* m_EditSpell;
	QCheckBox* m_DeleteCheck;

	QPushButton* m_BtnSave;

	QString m_Name;
	__int32 m_Min;
	__int32 m_Max;
	QString m_Spell;

	__int32 m_Index;

	void CreateLayout();

public slots:
	void onSave();

};

class HealerTab : public QWidget
{
	Q_OBJECT

public:
	HealerTab(MemoryManager*, QWidget* = 0);
	~HealerTab();

private:
	QVBoxLayout* m_Layout;
	QList<HealingRule*> m_HealingRules;
	QPushButton* m_AddButton;
	QPushButton* m_DelButton;
	void CreateLayout();
	void UpdateLayout();
	void ClearLayout();

public slots:
	void onDelete();
	void onRequestNewRule();
};

class PlayerTab : public QWidget
{
public:
	PlayerTab(MemoryManager*, QWidget* = 0);
	~PlayerTab();

private:
	Player* m_Player;

	QLabel* m_PlayerHealth;
	QLabel*	m_PlayerMaxHealth;

	QLabel* m_PlayerMaxMana;
	QLabel* m_PlayerMana;

	void CreateLayout();

};

// make it modular... 
class GeneralWindow : public QDialog
{
	Q_OBJECT

public:
	GeneralWindow(DWORD pid, QWidget* = 0);
	~GeneralWindow();

private:
	GameClient*		m_Client;
	MemoryManager*	m_MemoryManager;
	//more dialogs... [ configurator, healer, walker and whatever the fuck "doer" ]

	//layouts

	//widgets

	//methods
	void CreateLayout();

};