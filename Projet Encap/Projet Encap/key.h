#pragma once

#include "interactable.h"

class Key : public Interactable {
public:
	Key();

	void interact(Player& player) override;
};