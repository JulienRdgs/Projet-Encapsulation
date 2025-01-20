#pragma once

#include "enemy.h"
#include "chaser.h"
#include "patrolling.h"

class EnemyManager {
public:
	std::vector<std::unique_ptr<Enemy>> enemies;

	void createEnemy(std::string type, float xPos, float yPos);
	void destroyEnemy(std::unique_ptr<Enemy>& enemy);
};