#pragma once

#include "enemy.h"
#include "player.h"

class ChaserEnemy : public Enemy {
public:

	float maxSpeed = 100;
	float playerPosX = 0;
	float playerPosY = 0;

	ChaserEnemy(float xPos, float yPos);

	void behavior(float& deltaTime, sf::RenderWindow& window, Player& player) override;
};
