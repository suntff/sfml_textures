#pragma once
#include <string>
#include <cmath>
#include <vector> 
#include <Ship.hpp>
#include <iostream>
namespace msp
{
	class Game
	{
		const float pi = acos(-1);
		int width;
		int height;
		std::string capture;
		int n;
		sf::RenderWindow window;
		sf::Texture textureBackground;
		sf::Sprite spriteBackground;
		sf::Font font;
		sf::Text fpsText;
		Ship ship;

	public:
		Game(int width, int height, const std::string& capture)
		{
			this->width = width;
			this->height = height;
			this->capture = capture;
		}

		bool Setup(int n)
		{
			this->n = n;
			window.create(sf::VideoMode(width, height), capture);
			if (!textureBackground.loadFromFile("assets\\background.jpg"))
			{
				std::cout << "Error while loading background.jpg" << std::endl;
				return false;
			}

			spriteBackground.setTexture(textureBackground);
			fpsText.setFont(font);
			if (!ship.Setup(100, 100))
				return false;

		}


		void LifeCycle()
		{
			sf::Clock clock;

			float fps = 60;
			int fpsTextViewCnt = 0;

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					ship.setVelocity(0.005);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					ship.setVelocity(-0.005);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					ship.Rotate(-1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					ship.Rotate(1);
				}
				float dt = clock.getElapsedTime().asSeconds();
				if (1 / fps > dt)
				{
					sf::Time t = sf::seconds(1 / fps - dt);
					sf::sleep(t);
				}
				dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				fpsTextViewCnt++;
				if (fpsTextViewCnt > fps)
				{
					fpsTextViewCnt = 0;
					fpsText.setString(std::to_string(1 / dt));
				}
				ship.Move();
				window.clear();
				window.draw(spriteBackground);
				window.draw(ship.Get());
				window.draw(fpsText);

				window.display();
			}
		}
	};
}
