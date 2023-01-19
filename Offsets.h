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
	extern uintptr_t gIsmultiplayer;
	extern uintptr_t gTimeinsession;
	extern uintptr_t gPlayersinsession;
	extern uintptr_t gItemindexwielding;
	extern uintptr_t gIswieldingitem;
	extern uintptr_t gIshost;
	extern uintptr_t gFov;
	extern uintptr_t wTime;
	extern uintptr_t wTimeMulti;
	extern HANDLE GetHandle();
}