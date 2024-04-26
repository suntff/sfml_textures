#pragma once
#include <string>
#include <cmath>
#include <vector> 
#include <iostream>
#include <Ship.hpp>
namespace msp{
	class Game {
		sf::Texture texture_background;  float a; std::string capture; sf::Sprite sprite_background; sf::Text text; int width_window; 
		int height_window; Ship ship; long double dt;  int dalfa; float dv; sf::Font font; long double time_cycle;
	public:
		Game(int width_window, int height_window, int dalfa, float dv, std::string capture);
		int Texture_setup();
		void Life_cycle();	
	};
}
