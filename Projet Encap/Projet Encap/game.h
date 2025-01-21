#pragma once

#include "includes.h"
#include "player.h"
#include "chaser.h"
#include "patrolling.h"
#include "enemyManager.h"


class Game {
public:
	sf::RenderWindow window;
	Player player;
	//EnemyManager enemyManager; //USELESS
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<ChaserEnemy>> chasers;
	std::vector<std::unique_ptr<PatrollingEnemy>> patrollings;
	sf::Clock Clock;
	float deltaTime = 0;
	bool playing = true;
	bool gameOver = false;

	sf::Texture playerTexture;
	sf::Texture chaserTexture;
	sf::Texture patrollingTexture;

	sf::Font baseFont;
	sf::Text gameOverText;
	sf::Text retryText;

	Game();

	void loadTextures();
	void setupSpawns();
	void gameLoop();
	void pollEvent();
	void updateAll();
	void drawAll();
	void reset();
	void run();
};
