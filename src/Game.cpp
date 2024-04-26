#include <Game.hpp>
namespace msp {

	Game::Game(int width_window, int height_window, int dalfa, float dv, std::string capture) {
		this->width_window = width_window; this->height_window = height_window; this->capture = capture;
		this->dalfa = dalfa; this->dv = dv;
	}
	int Game::Texture_setup() {

		if (!texture_background.loadFromFile("assets//background.jpg") || ship.Ship_setup(width_window / 2, height_window / 2) == -1
			|| !font.loadFromFile("assets//AGENCYR.TTF")) {
			std::cerr << "Failed to load texture" << std::endl;
			return -1;
		}
		sprite_background.setTexture(texture_background);
		text.setFont(font);
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::Blue);
		text.setStyle(sf::Text::Italic);
		text.setOutlineColor(sf::Color::White);
		text.setOutlineThickness(2);
		text.setPosition(0, 0);
		return 0;
	}

	void Game::Life_cycle() {
		sf::Clock clock; sf::Clock clock_fps;
		sf::RenderWindow window(sf::VideoMode(width_window, height_window), capture);
		window.setVerticalSyncEnabled(true);
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}
			dt = clock.restart().asSeconds();
			//std::cout << 1 / dt<< " " << dt << std::endl;
			if (clock_fps.getElapsedTime().asSeconds() > 1) {
				text.setString(std::to_string(1 / dt));
				clock_fps.restart();
			}
			//std::cout << dt << "  "<<time_cycle<<std::endl;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				ship.Ship_rotate(dalfa, dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				ship.Ship_rotate(-dalfa, dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				ship.Update_ship_position(dv, dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				ship.Update_ship_position(-dv, dt);
			}
			window.clear();
			window.draw(sprite_background);
			window.draw(ship.Get_sprite_ship());
			window.draw(text);
			window.display();
		}
	}
}
