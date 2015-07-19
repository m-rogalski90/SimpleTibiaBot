#include "player.h"

Player::Player(QObject* parent) : QObject(parent)
{

}

Player::~Player()
{

}

// ------------------------------------------------------------------------------------

QString Player::GetPlayerName()
{
	return m_PlayerName;
}

void Player::SetPlayerName(QString name)
{
	m_PlayerName = name;
}

// ------------------------------------------------------------------------------------

unsigned __int32 Player::GetPlayerLevel()
{
	return m_PlayerLevel;
}

void Player::SetPlayerLevel(unsigned __int32 level)
{
	m_PlayerLevel = level;
}

// ------------------------------------------------------------------------------------

unsigned __int32 Player::GetPlayerExperience()
{
	return m_PlayerExperience;
}

void Player::SetPlayerExperience(unsigned __int32 experience)
{
	m_PlayerExperience = experience;
}

// ------------------------------------------------------------------------------------

unsigned __int32 Player::GetPlayerHealth()
{
	return m_PlayerHealth;
}

void Player::SetPlayerHealth(unsigned __int32 health)
{
	m_PlayerHealth = health;
}

// ------------------------------------------------------------------------------------

unsigned __int32 Player::GetPlayerMaxHealth()
{
	return m_PlayerMaxHealth;
}

void Player::SetPlayerMaxHealth(unsigned __int32 maxhealth)
{
	m_PlayerMaxHealth = maxhealth;
}