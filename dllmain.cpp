#pragma once
#include "pch.h"
#include "initialize.hpp"
#include "Backend.h"
extern DWORD WINAPI MainThread_Initialize();
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwCallReason, LPVOID lpReserved)
{
    using namespace DX11_Base;
    g_hModule = hModule;

    switch (dwCallReason) {
        case (DLL_PROCESS_ATTACH): {
            DisableThreadLibraryCalls(hModule);
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread_Initialize, g_hModule, NULL, NULL);
            //CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Backend::BackendThread, g_hModule, NULL, NULL);
            break;
        }
        case (DLL_PROCESS_DETACH): {
            g_KillSwitch = TRUE;
            break;
        }
    }
    return TRUE;
}