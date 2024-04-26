#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Ship.hpp>
#include <iostream>
int main()
{
    msp::Game game(1000,500,40,40,"sfml_textures");
    if (game.Texture_setup() == -1) {
        return -1;
    }
    srand(time(nullptr));
    game.Life_cycle();
}
