#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace msp {
	class Ship {
		sf::Texture texture_ship; sf::Sprite sprite_ship; float x; float y; float alfa; const long double pi = acos(-1);
	public:
		int Ship_setup(float x, float y);
		void Ship_rotate(float dalfa, float dt);
		void Update_ship_position(float dv, float dt);
		
		sf::Sprite Get_sprite_ship();
		long double Degrees_to_rad(int alfa);
	};
}