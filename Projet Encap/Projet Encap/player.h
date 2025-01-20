#pragma once

#include "entity.h"

class Player : public Entity {
public:

	Player(float posX, float posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void handleInput(float deltaTime, sf::RenderWindow& window);
};
