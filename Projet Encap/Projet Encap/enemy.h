#pragma once

#include "entity.h"

class Enemy : public Entity {
public:
	sf::RectangleShape rect;
	float speed = 400;

	Enemy(float x, float y, float posX, float posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};