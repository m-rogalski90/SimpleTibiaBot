#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <Windows.h>
#include <QtCore\qstring.h>

// forward declarations
class MemoryManager;
// ---------------------------------------------------

class GameObject
{
public:
	GameObject(MemoryManager*);
	virtual ~GameObject();

protected:
	MemoryManager* m_MemoryManager;
	unsigned __int32 m_InstanceId;
};

// ---------------------------------------------------

class Player : public GameObject
{
public:
	Player(MemoryManager*);
	~Player();

	unsigned __int32 GetHealth();
	unsigned __int32 GetHealthMax();

	unsigned __int32 GetMana();
	unsigned __int32 GetManaMax();

private:
	unsigned __int32 m_Health;
	unsigned __int32 m_HealthMax;

	unsigned __int32 m_Mana;
	unsigned __int32 m_ManaMax;

	unsigned __int32 m_Xor;
};

#endif
