#include "player.h"

Player::Player(int x, int y, int posX, int posY) {
    rect.setPosition({ posX,posY });
    rect.setSize({ x,y });
}
void Player::update(float deltaTime) {
		std::cout << "update" << std::endl;
}
void Player::draw(sf::RenderWindow& window) {
		std::cout << "draw" << std::endl;
}
void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect.move(0, 2.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rect.move(0, -2.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.move(-2.f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.move(2.f, 0);
    }
}