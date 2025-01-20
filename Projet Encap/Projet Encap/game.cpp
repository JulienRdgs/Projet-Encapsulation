#include "game.h"

Game::Game() : window(sf::VideoMode(1200, 800), "Escape the Dungeon"), player(600, 400), 
chaser(100, 100), patrolling(700, 700) {
}

void Game::gameLoop() {
    while (window.isOpen()) {
        while (playing) {
            deltaTime = Clock.restart().asSeconds();
            updateEntities();
            pollEvent();
            drawAll();
        }
        window.clear(sf::Color::Red);
        window.display();

    }
}

void Game::pollEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::updateEntities() {
    player.update(deltaTime);
    chaser.update(deltaTime);
    patrolling.update(deltaTime);

    player.handleInput(deltaTime, window);
    chaser.chase(deltaTime, player);
    patrolling.patroll(deltaTime, window);

    //collisions temporaires
    if (player.sprite.getGlobalBounds().intersects(chaser.sprite.getGlobalBounds()) 
        || player.sprite.getGlobalBounds().intersects(patrolling.sprite.getGlobalBounds())) {
        playing = false;
    }
}

void Game::drawAll() {
    player.sprite.setTexture(playerTexture);
    chaser.sprite.setTexture(chaserTexture);
    patrolling.sprite.setTexture(patrollingTexture);

    window.clear();
    player.draw(window);
    chaser.draw(window);
    patrolling.draw(window);
    window.display();
}

void Game::loadTextures() {
    playerTexture.loadFromFile("assets/burger.png");
    chaserTexture.loadFromFile("assets/pepper.png");
    patrollingTexture.loadFromFile("assets/salad.png");
}

void Game::run() {
    loadTextures();
    gameLoop();
}