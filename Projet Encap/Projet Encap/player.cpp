#include "player.h"
#include "game.h"
#include "map.h"

Player::Player(float xPos, float yPos) {
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition({ xPos, yPos });
    posX = xPos;
    posY = yPos;
    speedX = baseSpeed;
    speedY = baseSpeed;
}
void Player::update(float deltaTime) {
    posX = sprite.getPosition().x;
    posY = sprite.getPosition().y;
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void Player::handleInput(float deltaTime, sf::RenderWindow& window, sf::Sprite wall) {
    //MOUVEMENTS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, speedY * deltaTime);
        if (sprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 1);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        sprite.move(0, -speedY * deltaTime);
        if (sprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 50 + 1);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        sprite.move(-speedX * deltaTime, 0);
        if (sprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            sprite.setPosition(sprite.getPosition().y + 50 + 1, sprite.getPosition().y);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(speedX * deltaTime, 0);
        if (sprite.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            sprite.setPosition(sprite.getPosition().y - sprite.getGlobalBounds().width * sprite.getScale().x - 1, sprite.getPosition().y);
        }
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
    ///////////////////////////
    /*if (sprite.getPosition().y + sprite.getLocalBounds().height * sprite.getScale().y > window.getSize().y) {
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
    }*/
}

void Player::potionUpdate(float deltaTime) {
    if (potion) {
        sprite.setColor(sf::Color(24, 202, 237));
        speedX = baseSpeed * 1.5f;
        speedY = baseSpeed * 1.5f;
        if (potionTimer >= 5) potion = false;
    }
    else {
        sprite.setColor(sf::Color::White);
        potionTimer = 0;
        speedX = baseSpeed;
        speedY = baseSpeed;
    }
}