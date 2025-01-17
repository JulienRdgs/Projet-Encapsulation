#pragma once

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class Game {
public:
	sf::RenderWindow window;
	sf::RectangleShape player;

	Game();

	void gameLoop();
};
