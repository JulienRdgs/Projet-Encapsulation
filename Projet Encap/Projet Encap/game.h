#pragma once

#include "includes.h"
#include "player.h"


class Game {
public:
	sf::RenderWindow window;
	Player player;
	sf::Clock Clock;
	float deltaTime = 0;

	Game();

	void gameLoop();
	void pollEvent();
	void drawAll();
	void run();
};
