#pragma once

#include "enemy.h"
#include "map.h"

class PatrollingEnemy : public Enemy {
public:
	PatrollingEnemy(float xPos, float yPos);

	void behavior(float& deltaTime, sf::Sprite wall, Player& player) override;
};