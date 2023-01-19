#include "../pch.h"
#include "../include/Menu.hpp"
#include "../Offsets.h"
#include <TlHelp32.h>
#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> 
namespace DX11_Base {


    HANDLE handle = offsets::GetHandle();


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
        
        if (g_Menu->dbg_RAINBOW_THEME) {
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
            ImGui::PopStyleColor();
        }


        float ImGuiWidth = 400.f;
        float ImGuiHight = 400.f;

        if (ImGui::Begin("THCOTW INTERNAL CHEAT", &g_GameVariables->m_ShowMenu, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
        {
            Styles::InitStyle();

            ImGui::PushStyleColor(ImGuiCol_Border, ImColor(0, 0, 0, 255).Value);

            ImGui::SetWindowSize(ImVec2((float)ImGuiWidth, (float)ImGuiHight));

            //Misc
            int readValuegRuntime;
            int gRuntime = ReadProcessMemory(handle, (LPVOID)offsets::gRuntime, &readValuegRuntime, sizeof(readValuegRuntime), 0);

            //Runtime Header
            ImGui::Text("Runtime: ");
            ImGui::SameLine();
            ImGui::Text(std::to_string(readValuegRuntime / 60).c_str());
            ImGui::SameLine();
            ImGui::Text("min ");

            //Player Public Var
            

            if (ImGui::CollapsingHeader(("Player")))
            {
                //FOV
                {
                    ImGui::Text("FOV:");
                    ImGui::SameLine();
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);

                    static int currentFov = 60;

                    ImGui::SliderInt("FOV", &currentFov, 1, 200);

                    WriteProcessMemory(handle, (LPVOID)offsets::gFov, &currentFov, sizeof(currentFov), 0);
                }
                
                

            };

            if (ImGui::CollapsingHeader("Online")) {

                //Online
                int readValuegIsmultiplayer;
                int readValuegPlayersinsession;
                int readValuegItemindexwielding;
                int readValuegIswieldingitem;
                int readValuegIshost;
                int readValuegTimeinsession;

                int gTimeinsession = ReadProcessMemory(handle, (LPVOID)offsets::gTimeinsession, &readValuegTimeinsession, sizeof(readValuegTimeinsession), 0);
                int gIsmultiplayer = ReadProcessMemory(handle, (LPVOID)offsets::gIsmultiplayer, &readValuegIsmultiplayer, sizeof(readValuegIsmultiplayer), 0);
                int gPlayersinsession = ReadProcessMemory(handle, (LPVOID)offsets::gPlayersinsession, &readValuegPlayersinsession, sizeof(readValuegPlayersinsession), 0);
                int gItemindexwielding = ReadProcessMemory(handle, (LPVOID)offsets::gItemindexwielding, &readValuegItemindexwielding, sizeof(readValuegItemindexwielding), 0);
                int gIswieldingitem = ReadProcessMemory(handle, (LPVOID)offsets::gIswieldingitem, &readValuegIswieldingitem, sizeof(readValuegIswieldingitem), 0);
                int gIshost = ReadProcessMemory(handle, (LPVOID)offsets::gIshost, &readValuegIshost, sizeof(readValuegIshost), 0);
                


                ImGui::Text("Is Multiplayer: ");
                ImGui::SameLine();
                if (readValuegIsmultiplayer == 1)
                {
                    ImGui::Text("Yes");
                }
                else 
                {
                    ImGui::Text("No");
                }

                ImGui::Text("Players in session: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuegPlayersinsession).c_str());

                ImGui::Text("Time in MTPLY session: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuegTimeinsession).c_str());

                ImGui::Text("Item in hand: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuegItemindexwielding).c_str());

                ImGui::Text("Is Session Host: ");
                ImGui::SameLine();
                if (readValuegIshost == 1)
                {
                    ImGui::Text("Yes");
                }
                else
                {
                    ImGui::Text("No");
                }


               
            }
            if (ImGui::CollapsingHeader("World")) {
                
                //TIME
                {
                    ImGui::SameLine();
                    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);

                    static float currentTime = 9;
                    static float currentTimemulti = 1.0f;
                    static float set_multi_back = 1.0f;
                    int value;
                    bool is_timemulti_active = false;
                    bool is_time_active = false;


                    value, is_time_active = ImGui::SliderFloat("Time", &currentTime, 0.0f, 23.99f);
                    value, is_timemulti_active = ImGui::SliderFloat("Time Multiplier", &currentTimemulti, 0.0f, 10000.0f);
                    if (ImGui::IsItemHovered)
                    {
                        ImGui::Text("- Time is server sided if host ");
                    }
                    if (ImGui::Button("Set to 1", ImVec2(80, 20)))
                    {
                        WriteProcessMemory(handle, (LPVOID)offsets::wTimeMulti, &set_multi_back, sizeof(set_multi_back), 0);
                    }

                    if (is_time_active)
                    {
                        WriteProcessMemory(handle, (LPVOID)offsets::wTime, &currentTime, sizeof(currentTime), 0);
                    }
                    else if ((is_timemulti_active))
                    {
                        WriteProcessMemory(handle, (LPVOID)offsets::wTimeMulti, &currentTimemulti, sizeof(currentTimemulti), 0);
                    }



                }

            }
            if (ImGui::CollapsingHeader("ESP")) {
                //ImGui::Checkbox("Stone Ore", &features::Visuals_Ores::StoneOre);
                //ImGui::Spacing();
                //ImGui::Checkbox("Metal Ore", &features::Visuals_Ores::MetalOre);
                //ImGui::Spacing();
                //ImGui::Checkbox("Sulfur Ore", &features::Visuals_Ores::SulfurOre);
                //ImGui::Spacing();
            }
            if (ImGui::CollapsingHeader("Stat Editor")) {
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
            }

            if (ImGui::CollapsingHeader("Misc")) {
                //Coords
                float readValuebufferpxcoord;
                float readValuebufferpycoord;
                float readValuebufferpzcoord;

                int pxcoord = ReadProcessMemory(handle, (LPVOID)offsets::pxcoord, &readValuebufferpxcoord, sizeof(readValuebufferpxcoord), 0);
                int pycoord = ReadProcessMemory(handle, (LPVOID)offsets::pycoord, &readValuebufferpycoord, sizeof(readValuebufferpycoord), 0);
                int pzcoord = ReadProcessMemory(handle, (LPVOID)offsets::pzcoord, &readValuebufferpzcoord, sizeof(readValuebufferpzcoord), 0);

                //Coords
                ImGui::Text("Coords");
                ImGui::Text("X: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuebufferpxcoord).c_str());

                ImGui::Text("Y: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuebufferpycoord).c_str());

                ImGui::Text("Z: ");
                ImGui::SameLine();
                ImGui::Text(std::to_string(readValuebufferpzcoord).c_str());

            }
            
            if (ImGui::Button("UNHOOK", ImVec2(ImGui::GetWindowContentRegionWidth() - 3, 20)))
            {
                g_Console->printdbg("\n\n[+] UNHOOK INITIALIZED [+]\n\n", g_Console->color.red);

                g_KillSwitch = TRUE;
            }
            ImGui::PopStyleColor();
            if (ImGui::Button("Exit Game", ImVec2(ImGui::GetWindowContentRegionWidth() - 3, 20)))
            {
                g_Console->printdbg("\n\n[+]Game Exiting...\n\n", g_Console->color.red);
                Sleep(300);
                system("taskkill /F /T /IM theHunterCotW_F.exe");
               
            }
           




            
        }
        ImGui::End();
    };
       
        

	void Menu::HUD(bool* p_open)
	{

	}

	void Menu::Loops()
	{

	}
}