#pragma once

#include "enemy.h"

class PatrollingEnemy : public Enemy {
public:
	PatrollingEnemy(float xPos, float yPos);

	void behavior(float& deltaTime, sf::RenderWindow& window, Player& player) override;
};