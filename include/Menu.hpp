#pragma once
#include "helper.h"
#include "Game.hpp"
#include "D3D11Window.hpp"
namespace DX11_Base {
	class Menu
	{
	public:
		ImColor dbg_RAINBOW{};				
		bool dbg_RAINBOW_THEME = FALSE;		
		float sOpacity = 0.80;				
		bool dbg_ALERTS = TRUE;

		//	INITIALIZE CLASS
		Menu()  noexcept = default;
		~Menu() noexcept = default;
		Menu(Menu const&) = delete;
		Menu(Menu&&) = delete;
		Menu& operator=(Menu const&) = delete;
		Menu& operator=(Menu&&) = delete;

		//	FORWARD DECLARE FUNCTIONS
		void Draw();
		void MainMenu();
		void HUD(bool* p_open);
		void Loops();

	private:
		bool m_StyleInit{};
	};
	inline std::unique_ptr<Menu> g_Menu;
}
