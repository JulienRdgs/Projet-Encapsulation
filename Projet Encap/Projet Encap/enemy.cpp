#include "enemy.h"

Enemy::Enemy(float x, float y, float posX, float posY) {
    rect.setSize({ x,y });
    rect.setPosition({ posX,posY });
    rect.setFillColor(sf::Color::Red);
}
void Enemy::update(float deltaTime) {
    std::cout << "update" << std::endl;
}
void Enemy::draw(sf::RenderWindow& window) {
    window.draw(rect);
}