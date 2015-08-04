#include "gameclient.h"

MemoryManager::MemoryManager(GameClient* client) 
	: m_Client(client)
{ 
	
}

MemoryManager::~MemoryManager()
{

}

// this could be done with template... i think
char MemoryManager::ReadByte(DWORD address)
{
	return '\0';
}

void* MemoryManager::ReadBytes(DWORD address, SIZE_T length)
{
	DWORD completeAddress = m_Client->GetBaseAddress() + address;
	SIZE_T readed = 0;
	SIZE_T size = length; // sizeof(char) == 1; as it's one byte only
	void* buffer = new char[length]; // malloc would generate memory leak and this... ? i dont quite know... 

	int ok = ReadProcessMemory(m_Client->GetHandle(), (LPVOID)completeAddress, &buffer, size, &readed);
	if (!ok)
		throw QString("Couldn't read value from specified memory address.");

	return buffer;
}

// -------------------------------------------------------------------------------------------------------------------------------------

GameClient::GameClient(DWORD pid, QObject* parent) : QObject(parent), m_ProcessId(pid), m_ClientHandle(0)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_ProcessId);
	MODULEENTRY32 modEntry;
	modEntry.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(snapshot, &modEntry))
	{
		do{

			if (!_stricmp((char*)modEntry.szModule, "Tibia.exe"))
			{
				m_BaseAddress = (DWORD)modEntry.modBaseAddr;
				break;
			}

		} while (Module32Next(snapshot, &modEntry));
	}
	CloseHandle(snapshot);

	m_ClientHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, m_ProcessId);
}

GameClient::~GameClient()
{
	if (m_ClientHandle)
		CloseHandle(m_ClientHandle);
}

DWORD GameClient::GetBaseAddress()
{
	return m_BaseAddress;
}

HANDLE GameClient::GetHandle()
{
	return m_ClientHandle;
}

