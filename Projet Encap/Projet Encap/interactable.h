#pragma once

#include "player.h"

class Interactable {
public:
	bool state = true;
	std::string type;
	sf::Sprite sprite;

	Interactable();

	virtual void interact(Player& player) = 0;
	//void destroy(std::vector<Interactable>& objects);
};