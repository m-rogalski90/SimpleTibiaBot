#pragma once

#include <QtCore\qobject.h>

class Player : public QObject
{
public:
	Player(QObject* = 0);
	~Player();

	QString GetPlayerName();
	void SetPlayerName(QString);

	unsigned __int32 GetPlayerLevel();
	void SetPlayerLevel(unsigned __int32);

	unsigned __int32 GetPlayerExperience();
	void SetPlayerExperience(unsigned __int32);

	unsigned __int32 GetPlayerHealth();
	void SetPlayerHealth(unsigned __int32);

	unsigned __int32 GetPlayerMaxHealth();
	void SetPlayerMaxHealth(unsigned __int32);

private:
	QString m_PlayerName;
	unsigned __int32 m_PlayerLevel;
	unsigned __int32 m_PlayerExperience;
	unsigned __int32 m_PlayerHealth;
	unsigned __int32 m_PlayerMaxHealth;
};