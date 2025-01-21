#include "potion.h"

Potion::Potion() {
	type = "potion";
}

void Potion::interact(Player& player) {
	if (player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		player.potion = true;
		state = false;
	}
}