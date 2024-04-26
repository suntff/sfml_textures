#include <Ship.hpp>
namespace msp {
	int Ship::Ship_setup(float x, float y) {

		if (!texture_ship.loadFromFile("assets//ship.png")) {
			return -1;
		}
		alfa = 0;
		this->x = x; this->y = y;
		sprite_ship.setTexture(texture_ship);
		sprite_ship.setPosition(x, y);
		sprite_ship.setOrigin(sprite_ship.getLocalBounds().width / 2, sprite_ship.getLocalBounds().height / 2);
		sprite_ship.setRotation(90);
		sprite_ship.scale(0.3, 0.3);
		return 0;
	}
	void Ship::Ship_rotate(float dalfa, float dt) {
		alfa += dalfa * dt;
		sprite_ship.rotate(dalfa * dt);

	}
	void Ship::Update_ship_position(float dv, float dt) {
		x += dv * cos(Degrees_to_rad(alfa)) * dt;
		y += dv * sin(Degrees_to_rad(alfa)) * dt;
		sprite_ship.setPosition(x, y);
	}

	sf::Sprite Ship::Get_sprite_ship() {
		return sprite_ship;
	}
	long double Ship::Degrees_to_rad(int alfa) {
		return pi * alfa / 180;
	}
}