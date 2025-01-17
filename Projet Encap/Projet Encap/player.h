#pragma once

#include "entity.h"

class Player : public Entity {
public:
	sf::RectangleShape rect;
	sf::Vector2f position;
	float speed;

	Player(int x, int y, int posX, int posY);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	void handleInput();
};
