#pragma once

#include "entity.h"

class Enemy : public Entity {
public:

	Enemy();
	~Enemy();
	
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};