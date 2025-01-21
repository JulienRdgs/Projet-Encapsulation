#include "player.h"
#include "game.h"

Player::Player(float xPos, float yPos) {
    sprite.setScale(0.1, 0.1);
    sprite.setPosition({ xPos, yPos });
    posX = xPos;
    posY = yPos;
    speedX = 500;
    speedY = 500;
}
void Player::update(float deltaTime) {
    posX = sprite.getPosition().x;
    posY = sprite.getPosition().y;
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void Player::handleInput(float deltaTime, sf::RenderWindow& window) {
    //MOUVEMENTS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, speedY * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        sprite.move(0, -speedY * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        sprite.move(-speedX * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(speedX * deltaTime, 0);
    }
    //LIMITES
    if (sprite.getPosition().y + sprite.getLocalBounds().height * sprite.getScale().y  > window.getSize().y) {
        sprite.setPosition(sprite.getPosition().x, window.getSize().y - sprite.getLocalBounds().height * sprite.getScale().y);
    }
    if (sprite.getPosition().y < 0) {
        sprite.setPosition(sprite.getPosition().x, 0);
    }
    if (sprite.getPosition().x < 0) {
        sprite.setPosition(0, sprite.getPosition().y);
    }
    if (sprite.getPosition().x + sprite.getLocalBounds().width * sprite.getScale().x > window.getSize().x) {
        sprite.setPosition(window.getSize().x - sprite.getLocalBounds().height * sprite.getScale().y, sprite.getPosition().y);
    }

}