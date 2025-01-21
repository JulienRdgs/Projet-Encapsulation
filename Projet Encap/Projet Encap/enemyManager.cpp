#include "enemyManager.h"

//USELESS
void EnemyManager::createEnemy(std::string type, float xPos, float yPos) {
    if (type == "chaser") {
        std::unique_ptr<Enemy> enemy = std::make_unique<ChaserEnemy>(100, 100);
        //enemies.push_back(enemy);
    }
    if (type == "patrolling") {
        std::unique_ptr<Enemy> enemy = std::make_unique<PatrollingEnemy>(500, 500);
        //enemies.push_back(enemy);
    }
}

void EnemyManager::destroyEnemy(std::unique_ptr<Enemy>& enemy) {
    auto it = std::find(enemies.begin(), enemies.end(), enemy);
    if (it != enemies.end()) {
        //delete* it; ne fonctionne pas car unique_ptr ig
        enemies.erase(it);
    }
}