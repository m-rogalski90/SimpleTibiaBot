#include "gameobject.h"
#include "gameclient.h"
#include <QtCore\qdebug.h>

GameObject::GameObject(MemoryManager* mem)
	: m_MemoryManager(mem)
{

}

GameObject::~GameObject(){}

// ------------------------------------------------------------------------------------------------------

Player::Player(MemoryManager* mem) : GameObject(mem)
{

}

Player::~Player()
{
}

unsigned __int32 Player::GetHealth()
{
	try
	{
		m_Xor = m_MemoryManager->ReadMemoryValue<__int32>(0x5D5000);
		m_Health = m_MemoryManager->ReadMemoryValue<__int32>(0x4380F8);
	}
	catch (QString ex)
	{
		qDebug() << ex;
	}

	m_Health ^= m_Xor;
	return m_Health;
}

unsigned __int32 Player::GetHealthMax()
{
	try
	{
		m_Xor = m_MemoryManager->ReadMemoryValue<__int32>(0x5D5000);
		m_HealthMax = m_MemoryManager->ReadMemoryValue<__int32>(0x4380F8);
	}
	catch (QString ex)
	{
		qDebug() << ex;
	}

	m_HealthMax ^= m_Xor;
	return m_HealthMax;
}

unsigned __int32 Player::GetMana()
{
	try
	{
		m_Xor = m_MemoryManager->ReadMemoryValue<__int32>(0x5D5000);
		m_Mana = m_MemoryManager->ReadMemoryValue<__int32>(0x4380F8);
	}
	catch (QString ex)
	{
		qDebug() << ex;
	}

	m_Mana ^= m_Xor;
	return m_Mana;
}

unsigned __int32 Player::GetManaMax()
{
	try
	{
		m_Xor = m_MemoryManager->ReadMemoryValue<__int32>(0x5D5000);
		m_ManaMax = m_MemoryManager->ReadMemoryValue<__int32>(0x4380F8);
	}
	catch (QString ex)
	{
		qDebug() << ex;
	}

	m_ManaMax ^= m_Xor;
	return m_ManaMax;
}