#include "pch.h"
#include <TlHelp32.h>
#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> 
#include "include/helper.h"
#include "include/Console.hpp"
#include "include/Game.hpp"
#include "include/D3D11Window.hpp"
#include "include/Hooking.hpp"
#include "mem.h"
namespace offsets
{
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"theHunterCotW_F.exe");

	HANDLE GetHandle()
	{
		//HANDLE handleresult = nullptr;
		DWORD procID;
		HWND hwnd = FindWindowA(NULL, "theHunter: Call Of The Wild");
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handleresult = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		return handleresult;
		
	}

	//Misc
	extern uintptr_t gRuntime = (mem::FindDMAAddy(moduleBase + 0x20DD788, {}));


	//Coords
	extern uintptr_t pxcoord = (mem::FindDMAAddy(moduleBase + 0x20DD7B8, {}));
	extern uintptr_t pycoord = (mem::FindDMAAddy(moduleBase + 0x20DD7B4, {}));
	extern uintptr_t pzcoord = (mem::FindDMAAddy(moduleBase + 0x20DD7B0, {}));

	//Player Stats
	extern uintptr_t pName = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x7E0, 0x1D8, 0x70, 0xC20 }));
	extern uintptr_t pMoney = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x10, 0x38, 0x20, 0xF8 }));
	extern uintptr_t pSkillPoint = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x10, 0x38, 0x20, 0x6C }));
	extern uintptr_t pXPPoint = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x10, 0x38, 0x20, 0x68 }));
	extern uintptr_t pPerkPoint = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x10, 0x38, 0x20, 0x70 }));
	extern uintptr_t pLevel = (mem::FindDMAAddy(moduleBase + 0x022535C0, { 0x10, 0x38, 0x34 }));

	//Online Info
	extern uintptr_t gIsmultiplayer = (mem::FindDMAAddy(moduleBase + 0x20DD858, {}));
	extern uintptr_t gTimeinsession = (mem::FindDMAAddy(moduleBase + 0x20DD8A8, {}));
	extern uintptr_t gPlayersinsession = (mem::FindDMAAddy(moduleBase + 0x20DD8D0, {}));
	extern uintptr_t gItemindexwielding = (mem::FindDMAAddy(moduleBase + 0x20DD948, {}));
	extern uintptr_t gIswieldingitem = (mem::FindDMAAddy(moduleBase + 0x20DD920, {}));
	extern uintptr_t gIshost = (mem::FindDMAAddy(moduleBase + 0x20DD880, {}));
	extern uintptr_t gFov = mem::FindDMAAddy(moduleBase + 0x02254B38, {0x18, 0xDC8, 0xE4 });

	//World
	extern uintptr_t wTime = (mem::FindDMAAddy(moduleBase + 0x02226050, { 0xE8 }));
	extern uintptr_t wTimeMulti = (mem::FindDMAAddy(moduleBase + 0x02226050, { 0xF0 }));

};