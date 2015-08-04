#ifndef GAME_CLIENT
#define GAME_CLIENT

#include <Windows.h>
#include <TlHelp32.h>
#include <QtCore\qobject.h>

// forward declarations
class MemoryManager;
class GameClient;
// ----------------------------------------------------------

class MemoryManager
{
public:
	MemoryManager(GameClient*);
	~MemoryManager();

	char ReadByte(DWORD);
	void* ReadBytes(DWORD, SIZE_T);

	template <typename T>
	inline T ReadMemoryValue(DWORD address)
	{
		DWORD completeAddress = m_Client->GetBaseAddress() + address;
		SIZE_T readed = 0;
		SIZE_T size = sizeof(T);

		char* buffer = new char[size];

		int ok = ReadProcessMemory(m_Client->GetHandle(), (LPVOID)completeAddress, &buffer, size, &readed);
		if (!ok)
			throw QString("Couldn't read value from specified memory address.");
		
		T* value = reinterpret_cast<T*>(buffer); //the fuck is this
		
		return *value;
	}

private:
	GameClient* m_Client;
};

// ----------------------------------------------------------

class GameClient : public QObject
{
public:
	GameClient(DWORD, QObject* = 0);
	~GameClient();

	DWORD GetBaseAddress();
	HANDLE GetHandle();

private:
	DWORD m_ProcessId;
	DWORD m_BaseAddress;
	HANDLE m_ClientHandle;
};

#endif
