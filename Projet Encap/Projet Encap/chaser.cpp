#include "chaser.h"

ChaserEnemy::ChaserEnemy(float xPos, float yPos) {
	sprite.setScale(0.05, 0.05);
	sprite.setPosition({ xPos, yPos });
	posX = xPos;
	posY = yPos;
}

void ChaserEnemy::chase(float& deltaTime, Player& player) {
	playerPosX = player.sprite.getPosition().x + (player.sprite.getLocalBounds().width * player.sprite.getScale().x 
		+ player.sprite.getLocalBounds().height * player.sprite.getScale().y 
		- sprite.getLocalBounds().width * sprite.getScale().x 
		- sprite.getLocalBounds().height * sprite.getScale().y) / 4;
	playerPosY = player.sprite.getPosition().y + (player.sprite.getLocalBounds().width * player.sprite.getScale().x
		+ player.sprite.getLocalBounds().height * player.sprite.getScale().y
		- sprite.getLocalBounds().width * sprite.getScale().x
		- sprite.getLocalBounds().height * sprite.getScale().y) / 4;

	if (posX > playerPosX) {
		sprite.move(-speedX * deltaTime, 0);
	}
	if (posX < playerPosX) {
		sprite.move(speedX * deltaTime, 0);
	}
	if (posY > playerPosY) {
		sprite.move(0, -speedY * deltaTime);
	}
	if (posY < playerPosY) {
		sprite.move(0, speedY * deltaTime);
	}

	//compliqué
	/*if (speedX > 0 && speedY > 0) {
		if (abs(posX - playerPosX) > abs(posY - playerPosY)) {
			if (speedX <= maxSpeed) speedX++;
			if (speedY > 0) speedY--;
		}
		else if (abs(posX - playerPosX) < abs(posY - playerPosY)) {
			if (speedX > 0) speedX--;
			if (speedY <= maxSpeed) speedY++;
		}
	}*/
}