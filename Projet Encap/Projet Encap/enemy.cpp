#include "enemy.h"
#include "chaser.h"
#include "patrolling.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::update(float deltaTime) {
    posX = sprite.getPosition().x;
    posY = sprite.getPosition().y;
}
void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Enemy::createEnemy(std::string type,float xPos, float yPos) {
    if (type == "chaser") {
        std::unique_ptr<Enemy> enemy = std::make_unique<ChaserEnemy>(100, 100);
        //enemies.push_back(enemy);
    }
    if (type == "patrolling") {
        std::unique_ptr<Enemy> enemy = std::make_unique<PatrollingEnemy>(500, 500);
        //enemies.push_back(enemy);
    }
}

void Enemy::destroyEnemy(std::unique_ptr<Enemy>& enemy) {
    auto it = std::find(enemies.begin(), enemies.end(), enemy);
    if (it != enemies.end()) {
        //delete* it; ne fonctionne pas car unique_ptr ig
        enemies.erase(it);
    }
}