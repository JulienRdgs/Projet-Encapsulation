#include "key.h"

Key::Key() {
	type = "key";
}

void Key::interact(Player& player) {
	if (player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		player.key = true;
		state = false;
	}
}