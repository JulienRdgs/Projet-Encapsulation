#include "patrolling.h"

PatrollingEnemy::PatrollingEnemy(float xPos, float yPos) {
    type = "patrolling";
    sprite.setScale(0.1, 0.1);
    sprite.setPosition({ xPos, yPos });
    posX = xPos;
    posY = yPos;
}

void PatrollingEnemy::behavior(float& deltaTime, sf::RenderWindow& window, Player& player) {
    sprite.move(speedX * deltaTime, speedY * deltaTime);

    if (sprite.getPosition().y + sprite.getLocalBounds().height * sprite.getScale().y > window.getSize().y || sprite.getPosition().y < 0) {
        speedY = -speedY;
    }
    if (sprite.getPosition().x + sprite.getLocalBounds().width * sprite.getScale().x > window.getSize().x || sprite.getPosition().x < 0) {
        speedX = -speedX;
    }
}