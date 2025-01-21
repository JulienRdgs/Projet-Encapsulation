#pragma once

#include "entity.h"

class Player : public Entity {
public:
	bool potion = false;
	float potionTimer;
	float baseSpeed = 500;
	bool key = false;

	Player(float posX, float posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void handleInput(float deltaTime, sf::RenderWindow& window);
	void potionUpdate(float deltaTime);
};
