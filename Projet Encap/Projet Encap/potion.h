#pragma once

#include "interactable.h"

class Potion : public Interactable {
public:
	Potion();

	void interact(Player& player) override;
};