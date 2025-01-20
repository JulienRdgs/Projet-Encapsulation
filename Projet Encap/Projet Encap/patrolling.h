#pragma once

#include "enemy.h"

class PatrollingEnemy : public Enemy {
public:
	PatrollingEnemy(float xPos, float yPos);

	void patroll(float& deltaTime, sf::RenderWindow& window);
};