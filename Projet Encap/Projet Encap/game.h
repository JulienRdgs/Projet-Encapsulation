#pragma once

#include "includes.h"
#include "player.h"
#include "chaser.h"
#include "patrolling.h"


class Game {
public:
	sf::RenderWindow window;
	Player player;
	Enemy enemyManager;
	ChaserEnemy chaser;
	PatrollingEnemy patrolling;
	sf::Clock Clock;
	float deltaTime = 0;
	bool playing = true;

	sf::Texture playerTexture;
	sf::Texture chaserTexture;
	sf::Texture patrollingTexture;

	Game();

	void loadTextures();
	void gameLoop();
	void pollEvent();
	void updateEntities();
	void drawAll();
	void run();
};
