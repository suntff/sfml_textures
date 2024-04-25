#pragma once
#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <iostream>
namespace msp {
	class Ship
	{
		const float pi = acos(-1);
		float x, y;
		float alpha;
		float v;
		sf::Texture textureShip;
		sf::Sprite spriteShip;

	public:
		
		bool Setup(float x, float y)
		{
			this->x = x;
			this->y = y;
			alpha = 0;
			v = 0;
			if (!textureShip.loadFromFile("assets\\ship.png"))
			{
				std::cout << "Error while loading ship.png" << std::endl;
				return false;
			}
			spriteShip.setTexture(textureShip);
			spriteShip.setScale(0.3f, 0.3f);	
			spriteShip.setOrigin(textureShip.getSize().x / 2, textureShip.getSize().y / 2);
			spriteShip.setPosition(x, y);
			spriteShip.setRotation(90);
			spriteShip.rotate(alpha);
			
		}

		void setVelocity(float dv)
		{
			v += dv;
		}

		void Move()
		{
			float alphaRad = acos(-1) * alpha / 180;
			x += v * cos(alphaRad);
			y += v * sin(alphaRad);
			spriteShip.setPosition(x, y);
		}

		void Rotate(float dalpha)
		{
			alpha += dalpha;
			spriteShip.setRotation(alpha);
		}

		sf::Sprite Get()
		{
			return spriteShip;
		}
	};
}