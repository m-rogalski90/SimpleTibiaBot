#include "addresses.h"

DWORD __GetBaseAddress(DWORD, TCHAR*);
DWORD __GetGameProcessId(TCHAR*);

int main(int argc, char* argv[])
{
	DWORD gProcessId = __GetGameProcessId("Tibia");
	if (!gProcessId)
		return 1;

	HANDLE gHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, gProcessId);
	if (!gHandle)
		return 2;

	DWORD gBase = __GetBaseAddress(gProcessId, "Tibia.exe");
	if (!gBase)
	{
		CloseHandle(gHandle);
		return 3;
	}

	while (1)
	{
		DWORD address = A_LEVEL + gBase;
		unsigned __int32 level = 0;
		unsigned __int32 experience = 0;
		SIZE_T size = sizeof(__int32);
		SIZE_T readed = 0;
		int ok = 0;
		
		ok = ReadProcessMemory(gHandle, (LPCVOID)address, &level, size, &readed);
		if (!ok || size != readed)
			std::cout << "nope" << std::endl;

		readed = 0;
		address = A_EXPERIENCE + gBase;
		ok = ReadProcessMemory(gHandle, (LPCVOID)address, &experience, size, &readed);
		if (!ok || size != readed)
			std::cout << "nope" << std::endl;

		std::cout << "LEVEL :: " << level << std::endl;
		std::cout << "EXPERIENCE :: " << experience << std::endl;

		Sleep(1000);
	}

	CloseHandle(gHandle);
	std::cin.get();

	return 0;
}

DWORD __GetGameProcessId(TCHAR* name)
{
	HWND hWnd = 0;
	DWORD pid = 0;
	if ((hWnd = FindWindow(0, name)))
	{
		GetWindowThreadProcessId(hWnd, &pid);
		if (pid)
			return pid;
	}
	return 0;
}

DWORD __GetBaseAddress(DWORD pid, TCHAR* name)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	if (snapshot)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(MODULEENTRY32);

		if (Module32First(snapshot, &modEntry))
		{
			do
			{
				if (!strcmp(modEntry.szModule, name))
				{
					CloseHandle(snapshot);
					return (DWORD)modEntry.modBaseAddr;
				}
			} while (Module32Next(snapshot, &modEntry));
		}
		CloseHandle(snapshot);
	}
	return 0;
}