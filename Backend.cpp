#include "pch.h"
#include "mem.h"
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
#include "Backend.h"


//TODO
/*
DWORD __stdcall Backend::BackendThread()
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << " Main Thread Initialized\n";


    HWND hwnd = FindWindowA(NULL, "theHunter: Call of the Wild.exe");

    DWORD procID;
    //char gameName[] = "theHunter: Call of the Wild.exe";
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"theHunter: Call of the Wild.exe");
    uintptr_t checkplayer = mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x74 });
    bool bFlyHack = false;

    //Get XYZ Coords

    while ((hwnd != NULL))
    {
        if ((checkplayer != NULL))
        {
            if (GetAsyncKeyState(VK_LCONTROL) & 1)
            {
                bFlyHack = !bFlyHack;
                std::cout << "FLy Enabled?\n" << bFlyHack << std::endl;

            };


            while (mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x74 }) == NULL)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 31);
                std::cout << "[*] Coords Unavailable..\n" << std::endl;
            }

            while (mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x74 }) != NULL)
            {
                GetWindowThreadProcessId(hwnd, &procID);
                HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); 

                float readValuebufferX;
                float readValuebufferY;
                float readValuebufferZ;

                uintptr_t Xread = mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x74 });
                uintptr_t Yread = mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x78 });
                uintptr_t Zread = mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x70 });

                float Xaxis = ReadProcessMemory(handle, (LPVOID)Xread, &readValuebufferX, sizeof(readValuebufferX), 0);

                float Yaxis = ReadProcessMemory(handle, (LPVOID)Yread, &readValuebufferY, sizeof(readValuebufferY), 0);

                float Zaxis = ReadProcessMemory(handle, (LPVOID)Zread, &readValuebufferZ, sizeof(readValuebufferZ), 0);

                std::cout << "[*]" << " X: " << readValuebufferX << " Y: " << readValuebufferY << " Z: " << readValuebufferZ << " [*]" << std::endl;
                Sleep(1000);
            }




            while (bFlyHack && GetAsyncKeyState(VK_SPACE) & 1)
            {
                GetWindowThreadProcessId(hwnd, &procID);
                HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
                float readValue;
                uintptr_t Yread = mem::FindDMAAddy(moduleBase + 0x059D6F68, { 0xF0, 0x3E0, 0x470, 0x78 });
                ReadProcessMemory(handle, (LPVOID)Yread, &readValue, sizeof(readValue), 0);
                float current = readValue + 1.0f;
                WriteProcessMemory(handle, (LPVOID)Yread, &current, sizeof(current), 0);
                std::cout << readValue << std::endl;
                Sleep(1);
            };
        }
        else
        {
            DX11_Base::g_Console->printdbg("Coords Unavailable\n", DX11_Base::g_Console->color.red);
        };
        Sleep(1);
    };
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(DX11_Base::g_hModule, 0);
}
*/