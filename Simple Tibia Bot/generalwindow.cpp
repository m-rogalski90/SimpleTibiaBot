#include "generalwindow.h"

#include <QtCore\qdebug.h>

HealingRule::HealingRule(QString name, __int32 index, QWidget* parent) : QWidget(parent)
{
	m_Name = name;
	m_Index = index;
	CreateLayout();
}

HealingRule::~HealingRule()
{

}

BOOL HealingRule::IsMarkedForDeletion()
{
	return this->m_DeleteCheck->isChecked();
}

void HealingRule::CreateLayout()
{
	QHBoxLayout* layout = new QHBoxLayout;

	layout->addWidget((m_LblName = new QLineEdit(m_Name)));

	layout->addWidget((m_MinSpin = new QSpinBox));
	m_MinSpin->setMinimum(0);
	m_MinSpin->setMaximum(2147483647);
	m_MinSpin->setValue(m_Min);

	layout->addWidget((m_MaxSpin = new QSpinBox));
	m_MaxSpin->setMinimum(0);
	m_MaxSpin->setMaximum(2147483647);
	m_MaxSpin->setValue(m_Max);

	layout->addWidget((m_EditSpell = new QLineEdit(m_Spell)));

	layout->addWidget((m_BtnSave = new QPushButton("save")));
	connect(m_BtnSave, SIGNAL(clicked()),
		this, SLOT(onSave()));

	layout->addWidget((m_DeleteCheck = new QCheckBox("delete")));

	setLayout(layout);
}

void HealingRule::SetIndex(__int32 idx)
{
	this->m_Index = idx;
}

QString HealingRule::GetName()
{
	return this->m_Name;
}

void HealingRule::onSave()
{
	this->m_LblName->setText((this->m_Name = this->m_LblName->text()));
	this->m_MinSpin->setValue((this->m_Min = this->m_MinSpin->value()));
	this->m_MaxSpin->setValue((this->m_Max = this->m_MaxSpin->value()));
	this->m_EditSpell->setText((this->m_Spell = this->m_EditSpell->text()));
}

// ----------------------------------------------------------------------------------------------------------------------------------------------

HealerTab::HealerTab(MemoryManager* m, QWidget* parent) : QWidget(parent)
{
	m_HealingRules.clear();
	CreateLayout();
}

HealerTab::~HealerTab()
{

}

void HealerTab::CreateLayout()
{
	m_Layout = new QVBoxLayout(this);

	m_DelButton = new QPushButton;
	m_DelButton->setText("Delete selected");
	connect(m_DelButton, SIGNAL(clicked()),
		this, SLOT(onDelete()));

	m_AddButton = new QPushButton;
	m_AddButton->setText("Add new rule");
	connect(m_AddButton, SIGNAL(clicked()), this, SLOT(onRequestNewRule()));
	m_Layout->addWidget(m_AddButton);

	setLayout(m_Layout);
}

void HealerTab::UpdateLayout()
{
	ClearLayout();
	for (int i = 0; i < m_HealingRules.count(); ++i)
	{
		HealingRule* hr = m_HealingRules[i];
		connect(hr, SIGNAL(deleteMe(__int32)),
			this, SLOT(onDelete(__int32)));
		m_Layout->addWidget(hr);

	}
	m_Layout->addWidget(m_DelButton);
	m_Layout->addWidget(m_AddButton);
}

void HealerTab::ClearLayout()
{
	for (int i = 0; i < m_Layout->children().count(); ++i)
	{
		auto item = m_Layout->itemAt(i);
		m_Layout->removeItem(item);
	}
}

#define hrLimit 15

void HealerTab::onRequestNewRule()
{
	if (m_HealingRules.count() < hrLimit)
	{
		__int32 idx = m_HealingRules.count();
		m_HealingRules.append(new HealingRule("noname", idx));
		UpdateLayout();
	}
}

void HealerTab::onDelete()
{
	for (int i = 0; i < m_HealingRules.count();)
	{
		if (m_HealingRules.at(i)->IsMarkedForDeletion())
		{
			HealingRule* hr = m_HealingRules.at(i);
			m_HealingRules.removeAt(i);
			m_Layout->removeWidget(hr);

			delete hr;
		}
		else
			++i;
	}

	for (int i = 0; i < m_HealingRules.count(); ++i)
	{
		m_HealingRules.at(i)->SetIndex(i);
	}

	UpdateLayout();
}

// ----------------------------------------------------------------------------------------------------------------------------------------------

PlayerTab::PlayerTab(MemoryManager* m, QWidget* parent) 
	: QWidget(parent)
{
	m_Player = new Player(m);
	CreateLayout();
}

PlayerTab::~PlayerTab(){}

void PlayerTab::CreateLayout()
{
	QVBoxLayout* layout = new QVBoxLayout(this);

	QHBoxLayout* healthLayout = new QHBoxLayout;
	healthLayout->addWidget(new QLabel("Health:"));
	healthLayout->addWidget((m_PlayerHealth = new QLabel(QString::number(m_Player->GetHealth()))));
	layout->addLayout(healthLayout);

	QHBoxLayout* maxHealthLayout = new QHBoxLayout;
	maxHealthLayout->addWidget(new QLabel("Max health:"));
	maxHealthLayout->addWidget((m_PlayerMaxHealth = new QLabel(QString::number(m_Player->GetHealthMax()))));
	layout->addLayout(maxHealthLayout);


	QHBoxLayout* manaLayout = new QHBoxLayout;
	manaLayout->addWidget(new QLabel("Mana:"));
	manaLayout->addWidget((m_PlayerMana = new QLabel(QString::number(m_Player->GetHealthMax()))));
	layout->addLayout(manaLayout);

	QHBoxLayout* maxManaLayout = new QHBoxLayout;
	maxManaLayout->addWidget(new QLabel("Max mana:"));
	maxManaLayout->addWidget((m_PlayerMaxMana = new QLabel(QString::number(m_Player->GetHealthMax()))));
	layout->addLayout(maxManaLayout);

	setLayout(layout);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------

GeneralWindow::GeneralWindow(DWORD pid, QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle("General bot window");
	m_Client = new GameClient(pid); 
	m_MemoryManager = new MemoryManager(m_Client);
	CreateLayout();
}

GeneralWindow::~GeneralWindow()
{
	{ // memory manager memory cleanup;
		delete m_MemoryManager;
		m_MemoryManager = 0;
	}
	{ // client memory cleanup;
		delete m_Client;
		m_Client = 0;
	}
}

void GeneralWindow::CreateLayout()
{
	QHBoxLayout* layout = new QHBoxLayout(this);
	QTabWidget* tabs = new QTabWidget;
	tabs->addTab(new PlayerTab(m_MemoryManager, tabs), "Player");
	tabs->addTab(new HealerTab(m_MemoryManager, tabs), "Healer");
	layout->addWidget(tabs);

	setLayout(layout);
}