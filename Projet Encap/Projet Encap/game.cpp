#include "game.h"

Game::Game() : window(sf::VideoMode(1200, 800), "Escape the Dungeon"), player(50,50,600,400) {
}

void Game::gameLoop() {
    while (window.isOpen()) {

        deltaTime = Clock.restart().asSeconds();
        pollEvent();
        player.handleInput(deltaTime, window);
        drawAll();
    }
}

void Game::pollEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::drawAll() {
    window.clear();
    player.draw(window);
    window.display();
}

void Game::run() {
    gameLoop();
}