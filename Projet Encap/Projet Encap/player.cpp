#include "player.h"

Player::Player(float x, float y, float posX, float posY) {
    rect.setSize({ x,y });
    rect.setPosition({ posX,posY });
    rect.setFillColor(sf::Color::Red);
}
void Player::update(float deltaTime) {
		std::cout << "update" << std::endl;
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(rect);
}
void Player::handleInput(float deltaTime, sf::RenderWindow& window) {
    //MOUVEMENTS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect.move(0, speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rect.move(0, -speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.move(-speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.move(speed * deltaTime, 0);
    }
    //LIMITES
    if (rect.getPosition().y + rect.getSize().y > window.getSize().y) {
        rect.setPosition(rect.getPosition().x, window.getSize().y - rect.getSize().y);
    }
    if (rect.getPosition().y < 0) {
        rect.setPosition(rect.getPosition().x, 0);
    }
    if (rect.getPosition().x < 0) {
        rect.setPosition(0, rect.getPosition().y);
    }
    if (rect.getPosition().x + rect.getSize().x > window.getSize().x) {
        rect.setPosition(window.getSize().x - rect.getSize().x, rect.getPosition().y);
    }

}