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

	//
};