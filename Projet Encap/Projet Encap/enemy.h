#pragma once

#include "entity.h"

class Enemy : public Entity {
public:
	std::vector<std::unique_ptr<Enemy>> enemies;

	Enemy();
	~Enemy();
	
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void createEnemy(std::string type,float xPos, float yPos);
	void destroyEnemy(std::unique_ptr<Enemy>& enemy);
};