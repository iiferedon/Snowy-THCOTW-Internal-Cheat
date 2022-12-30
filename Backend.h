#pragma once
#include <windows.h>
#include <tchar.h>
#include <vector>

namespace Backend
{
    extern DWORD WINAPI BackendThread();
    extern float readValuebufferX;
    extern float readValuebufferY;
    extern float readValuebufferZ;
}