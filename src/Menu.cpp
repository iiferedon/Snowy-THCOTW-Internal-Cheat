#include "../pch.h"
#include "../include/Menu.hpp"
#include "../Offsets.h"
#include <TlHelp32.h>
#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> 
namespace DX11_Base {

    namespace Styles {

        void InitStyle()
        {
            ImGuiStyle& style = ImGui::GetStyle();
            ImVec4* colors = ImGui::GetStyle().Colors;

            //	STYLE PROPERTIES
            style.ScrollbarRounding = 0;
            style.WindowMinSize = ImVec2(480, 330);


            style.Colors[ImGuiCol_WindowBg] = ImColor(16, 16, 16);
            style.Colors[ImGuiCol_ChildBg] = ImColor(24, 24, 24);
            style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
            style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255);

            style.Colors[ImGuiCol_Header] = ImColor(30, 30, 30);
            style.Colors[ImGuiCol_HeaderActive] = ImColor(28, 28, 28);
            style.Colors[ImGuiCol_HeaderHovered] = ImColor(28, 28, 28);

            style.Colors[ImGuiCol_Button] = ImColor(31, 31, 31);
            style.Colors[ImGuiCol_ButtonActive] = ImColor(34, 34, 34);
            style.Colors[ImGuiCol_ButtonHovered] = ImColor(34, 34, 34);

            style.Colors[ImGuiCol_Border] = ImColor(0, 0, 0, 255);

           
            ImGui::StyleColorsClassic();

           
            if (g_Menu->dbg_RAINBOW_THEME) {
                
                colors[ImGuiCol_Separator] = ImVec4(g_Menu->dbg_RAINBOW);
                colors[ImGuiCol_TitleBg] = ImVec4(0, 0, 0, 1.0f);
                colors[ImGuiCol_TitleBgActive] = ImVec4(0, 0, 0, 1.0f);
                colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0, 0, 0, 1.0f);
            }
            else {
               
            }
        }
    }

	

	void Menu::Draw()
	{
		if (g_GameVariables->m_ShowMenu)
			MainMenu();

		if (g_GameVariables->m_ShowHud)
			HUD(&g_GameVariables->m_ShowHud);

		if (g_GameVariables->m_ShowDemo)
			ImGui::ShowDemoWindow();
	}

	void Menu::MainMenu()
	{
        if (!g_GameVariables->m_ShowDemo)
            Styles::InitStyle();

        if (g_Menu->dbg_RAINBOW_THEME) {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(g_Menu->dbg_RAINBOW));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(g_Menu->dbg_RAINBOW));
            ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(g_Menu->dbg_RAINBOW));
        }
        //if (!ImGui::Begin("FALLOUT4 INTERNAL CHEAT", &g_GameVariables->m_ShowMenu, 96))
        //{
            //ImGui::End();
            //return;
        //}
        if (g_Menu->dbg_RAINBOW_THEME) {
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
        }
        
        //  Display Menu Content
        if (ImGui::Begin("THCOTW INTERNAL CHEAT", &g_GameVariables->m_ShowMenu, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
        {
            Styles::InitStyle();

            ImGui::PushStyleColor(ImGuiCol_Border, ImColor(0, 0, 0, 255).Value);

            ImGui::BeginChild("##LeftSide", ImVec2(120, ImGui::GetContentRegionAvail().y), true);
            {
                
                //ImGui::Text(std::to_string(Backend::readValuebufferX).c_str());
                //ImGui::Text(std::to_string(Backend::readValuebufferY).c_str());
                //ImGui::Text(std::to_string(Backend::readValuebufferZ).c_str());

                
            }
            ImGui::EndChild();

            {
                ImGui::SameLine(0);
                ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
                ImGui::SameLine();
            }

            ImGui::BeginChild("##RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true);
            {
                
                //ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);
                //ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 37.5);
                

                    HANDLE handle = offsets::GetHandle();

                    //Misc
                    int readValuegRuntime;

                    int gRuntime = ReadProcessMemory(handle, (LPVOID)offsets::gRuntime, &readValuegRuntime, sizeof(readValuegRuntime), 0);


                    //Stats
                    int readValuebufferpMoney;
                    int readValuebufferpSkillPoint;
                    int readValuebufferpXPPoint;
                    int readValuebufferpPerkPoint;
                    int readValuebufferpLevel;

                    int pMoneyValue = ReadProcessMemory(handle, (LPVOID)offsets::pMoney, &readValuebufferpMoney, sizeof(readValuebufferpMoney), 0);
                    int pSkillPointValue = ReadProcessMemory(handle, (LPVOID)offsets::pSkillPoint, &readValuebufferpSkillPoint, sizeof(readValuebufferpSkillPoint), 0);
                    int pXPPointValue = ReadProcessMemory(handle, (LPVOID)offsets::pXPPoint, &readValuebufferpXPPoint, sizeof(readValuebufferpXPPoint), 0);
                    int pPerkPoint = ReadProcessMemory(handle, (LPVOID)offsets::pPerkPoint, &readValuebufferpPerkPoint, sizeof(readValuebufferpPerkPoint), 0);
                    int pLevelValue = ReadProcessMemory(handle, (LPVOID)offsets::pLevel, &readValuebufferpLevel, sizeof(readValuebufferpLevel), 0);


                    //Coords
                    float readValuebufferpxcoord;
                    float readValuebufferpycoord;
                    float readValuebufferpzcoord;
                    
                    int pxcoord = ReadProcessMemory(handle, (LPVOID)offsets::pxcoord, &readValuebufferpxcoord, sizeof(readValuebufferpxcoord), 0);
                    int pycoord = ReadProcessMemory(handle, (LPVOID)offsets::pycoord, &readValuebufferpycoord, sizeof(readValuebufferpycoord), 0);
                    int pzcoord = ReadProcessMemory(handle, (LPVOID)offsets::pzcoord, &readValuebufferpzcoord, sizeof(readValuebufferpzcoord), 0);

                    //Player Stats Menu
                    ImGui::Text("Runtime: ");
                    ImGui::SameLine();
                    ImGui::Text(std::to_string(readValuegRuntime / 60).c_str());
                    ImGui::SameLine();
                    ImGui::Text("min ");

                    ImGui::Text("Player Stats"); 
                    ImGui::Text("X: ");
                    ImGui::SameLine(); 
                    ImGui::Text(std::to_string(readValuebufferpxcoord).c_str());
                    
                    ImGui::Text("Y: ");
                    ImGui::SameLine(); 
                    ImGui::Text(std::to_string(readValuebufferpycoord).c_str());
                    
                    ImGui::Text("Z: ");
                    ImGui::SameLine();
                    ImGui::Text(std::to_string(readValuebufferpzcoord).c_str());

                   // ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);

                    //Money
                    ImGui::Text("Money:"); 
                    ImGui::SameLine(); 
                    if (ImGui::Button(" + 3000", ImVec2(70, 20))) { int currentMoney = readValuebufferpMoney + 3000; WriteProcessMemory(handle, (LPVOID)offsets::pMoney, &currentMoney, sizeof(currentMoney), 0); };
                    ImGui::SameLine(); 
                    ImGui::Text(std::to_string(readValuebufferpMoney).c_str());
                    ImGui::SameLine(); 
                    if (ImGui::Button(" - 3000", ImVec2(70, 20))) { int currentMoney = readValuebufferpMoney - 3000; WriteProcessMemory(handle, (LPVOID)offsets::pMoney, &currentMoney, sizeof(currentMoney), 0); };
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //Skill Points
                    ImGui::Text("SkillPoint:"); 
                    ImGui::SameLine(); 
                    if (ImGui::Button(" + 10", ImVec2(70, 20))) { int currentSkillPoint = readValuebufferpSkillPoint + 10; WriteProcessMemory(handle, (LPVOID)offsets::pSkillPoint, &currentSkillPoint, sizeof(currentSkillPoint), 0); };
                    ImGui::SameLine();
                    ImGui::Text(std::to_string(readValuebufferpSkillPoint).c_str());
                    ImGui::SameLine(); 
                    if (ImGui::Button(" - 10", ImVec2(70, 20))) { int currentSkillPoint = readValuebufferpSkillPoint - 10; WriteProcessMemory(handle, (LPVOID)offsets::pSkillPoint, &currentSkillPoint, sizeof(currentSkillPoint), 0); };
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //XP Points
                    ImGui::Text("XPPoint:"); 
                    ImGui::SameLine(); 
                    if (ImGui::Button(" + 1500 ", ImVec2(70, 20))) { int currentXPPoint = readValuebufferpXPPoint + 1500; WriteProcessMemory(handle, (LPVOID)offsets::pXPPoint, &currentXPPoint, sizeof(currentXPPoint), 0); };
                    ImGui::SameLine();
                    ImGui::Text(std::to_string(readValuebufferpXPPoint).c_str());
                    ImGui::SameLine(); 
                    if (ImGui::Button(" - 1500 ", ImVec2(70, 20))) { int currentXPPoint = readValuebufferpXPPoint - 1500; WriteProcessMemory(handle, (LPVOID)offsets::pXPPoint, &currentXPPoint, sizeof(currentXPPoint), 0); };
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //Perk Points
                    ImGui::Text("PerkPoint:"); 
                    ImGui::SameLine(); 
                    if (ImGui::Button(" + 5", ImVec2(70, 20))) { int currentPerkPoint = readValuebufferpPerkPoint + 5; WriteProcessMemory(handle, (LPVOID)offsets::pPerkPoint, &currentPerkPoint, sizeof(currentPerkPoint), 0); };
                    ImGui::SameLine(); 
                    ImGui::Text(std::to_string(readValuebufferpPerkPoint).c_str());
                    ImGui::SameLine(); 
                    if (ImGui::Button(" - 5", ImVec2(70, 20))) { int currentPerkPoint = readValuebufferpPerkPoint - 5; WriteProcessMemory(handle, (LPVOID)offsets::pPerkPoint, &currentPerkPoint, sizeof(currentPerkPoint), 0); };
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //Level
                    ImGui::Text("Level:"); 
                    ImGui::SameLine(); 
                    if (ImGui::Button(" + 1", ImVec2(70, 20))) { int currentLevel = readValuebufferpLevel + 1; WriteProcessMemory(handle, (LPVOID)offsets::pLevel, &currentLevel, sizeof(currentLevel), 0); };
                    ImGui::SameLine(); 
                    ImGui::Text(std::to_string(readValuebufferpLevel).c_str());
                    ImGui::SameLine(); 
                    if (ImGui::Button(" - 1", ImVec2(70, 20))) { int currentLevel = readValuebufferpLevel - 1; WriteProcessMemory(handle, (LPVOID)offsets::pLevel, &currentLevel, sizeof(currentLevel), 0); };




                ImGui::EndChild();
                if (ImGui::Button("UNHOOK", ImVec2(ImGui::GetWindowContentRegionWidth() - 3, 20)))
                {
                    g_Console->printdbg("\n\n[+] UNHOOK INITIALIZED [+]\n\n", g_Console->color.red);

                    g_KillSwitch = TRUE;
                }
                ImGui::PopStyleColor();


                ImGui::End();
            }
        }
        ImGui::End();
	}

	void Menu::HUD(bool* p_open)
	{

	}

	void Menu::Loops()
	{

	}
}