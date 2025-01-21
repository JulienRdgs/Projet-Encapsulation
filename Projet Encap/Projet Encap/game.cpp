#include "game.h"

Game::Game() : window(sf::VideoMode(1200, 800), "Escape the Dungeon"), player(600, 400) {
}

void Game::gameLoop() {
    while (window.isOpen()) {
        deltaTime = Clock.restart().asSeconds();
        updateAll();
        pollEvent();
        drawAll();
    }
}

void Game::pollEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                if (gameOver) window.close();
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (gameOver) {
                    if (retryText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        reset();
                        gameOver = false;
                        playing = true;
                    }
                }
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            if (gameOver) {
                if (retryText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    retryText.setFillColor(sf::Color::Yellow); //ne fonctionne pas
                }
            }
        }
    }
}

void Game::updateAll() {
    if (playing) {
        player.update(deltaTime);
        player.handleInput(deltaTime, window);

        if (!enemies.empty()) {
            for (auto& enemy : enemies) {
                enemy->update(deltaTime);
                enemy->behavior(deltaTime, window, player);
                if (player.sprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {
                    playing = false;
                    gameOver = true;
                }
            }
        }
    }
}

void Game::drawAll() {
    if (playing) {
        player.sprite.setTexture(playerTexture);
        if (!enemies.empty()) {
            for (auto& enemy : enemies) {
                if (enemy->type == "chaser") enemy->sprite.setTexture(chaserTexture);
                else if (enemy->type == "patrolling") enemy->sprite.setTexture(patrollingTexture);
            }
        }

        window.clear();
        player.draw(window);
        if (!enemies.empty()) {
            for (auto& enemy : enemies) {
                enemy->draw(window);
            }
        }
    }
    if (gameOver) {
        window.clear();
        window.draw(gameOverText);
        window.draw(retryText);
    }
    window.display();
}

void Game::loadTextures() {
    playerTexture.loadFromFile("assets/player.png");
    chaserTexture.loadFromFile("assets/chaser.png");
    patrollingTexture.loadFromFile("assets/patrolling.png");
    baseFont.loadFromFile("assets/Arial.ttf");

    gameOverText.setFont(baseFont);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(100);
    gameOverText.setPosition((window.getSize().x - gameOverText.getGlobalBounds().width) / 2,
        (window.getSize().y - gameOverText.getCharacterSize()) / 3);
    gameOverText.setFillColor(sf::Color::Red);

    retryText.setFont(baseFont);
    retryText.setString("RETRY ?");
    retryText.setCharacterSize(50);
    retryText.setPosition((window.getSize().x - retryText.getGlobalBounds().width) / 2,
        gameOverText.getPosition().y + gameOverText.getCharacterSize() + window.getSize().y * 0.1);
    retryText.setFillColor(sf::Color::White);

}

void Game::setupSpawns() {
    //std::unique_ptr<Enemy> chaser = std::make_unique<ChaserEnemy>(100, 100);
    //enemies.push_back(chaser);
    enemies.emplace_back(std::make_unique<ChaserEnemy>(100, 100));
    //std::unique_ptr<PatrollingEnemy> patrolling = std::make_unique<PatrollingEnemy>(700, 700);
    //patrollings.push_back(patrolling);
    enemies.emplace_back(std::make_unique<PatrollingEnemy>(700, 700));
}

void Game::reset() {
    enemies.clear();
    player.sprite.setPosition(600, 400);
    setupSpawns();
}

void Game::run() {
    loadTextures();
    setupSpawns();
    gameLoop();
}