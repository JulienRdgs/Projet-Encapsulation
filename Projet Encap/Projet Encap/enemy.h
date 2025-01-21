#pragma once

#include "player.h"

class Enemy : public Entity {
public:
	std::string type;

	Enemy();
	~Enemy();
	
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	virtual void behavior(float& deltaTime, sf::RenderWindow& window, Player& player);
};