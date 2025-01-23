#pragma once

#include "entity.h"

class Player : public Entity {
public:
	bool potion = false;
	float potionTimer = 0;
	float baseSpeed = 500;
	bool key = false;
	sf::Vector2f playerPos;

	Player(float posX, float posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void handleInput(float deltaTime, sf::RenderWindow& window, sf::Sprite wall);
	void potionUpdate(float deltaTime);
};
