#pragma once

#include "entity.h"

class Player : public Entity {
public:
	sf::RectangleShape rect;
	float speed = 500;


	Player(float x, float y, float posX, float posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void handleInput(float deltaTime, sf::RenderWindow& window);
};
