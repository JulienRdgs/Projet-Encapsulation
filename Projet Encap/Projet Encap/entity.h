#pragma once

#include "game.h"

class Entity {
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

