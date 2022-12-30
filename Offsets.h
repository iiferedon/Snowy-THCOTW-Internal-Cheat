#pragma once
#include <windows.h>
#include <tchar.h>
#include <vector>

namespace offsets
{
	extern uintptr_t pMoney;
	extern uintptr_t pSkillPoint;
	extern uintptr_t pXPPoint;
	extern uintptr_t pPerkPoint;
	extern uintptr_t pLevel;
	extern uintptr_t pxcoord;
	extern uintptr_t pycoord;
	extern uintptr_t pzcoord;
	extern uintptr_t gRuntime;
	extern HANDLE GetHandle();
}