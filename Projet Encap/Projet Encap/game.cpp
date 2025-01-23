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
                    if (retryText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                        reset();
                        gameOver = false;
                        playing = true;
                    }
                }
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            if (gameOver) {
                if (retryText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    retryText.setFillColor(sf::Color::Yellow); //ne fonctionne pas
                }
            }
        }
    }
}

void Game::updateAll() {
    if (playing) {
        //std::cout << player.speedX << " - " << player.speedY << "               " << player.potionTimer << std::endl;
        player.update(deltaTime);
        player.handleInput(deltaTime, window, wallSprite);
        player.potionTimer += deltaTime;
        player.potionUpdate(deltaTime);

        //COLLISIONS
        if (!enemies.empty()) {
            for (auto& enemy : enemies) {
                enemy->update(deltaTime);
                enemy->behavior(deltaTime, wallSprite, player);
                if (player.sprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {
                    /*playing = false;
                    gameOver = true;*/
                }
            }
        }
        if (!objects.empty()) {
            for (auto& obj : objects) {
                if (player.sprite.getGlobalBounds().intersects(obj->sprite.getGlobalBounds())) {
                    obj->interact(player);
                }
            }
        }
        for (int i = 0; i < objects.size(); i++) {
            if (objects[i]->state == false) {
                objects.erase(objects.begin() + i);
            }
        }
    }
}

void Game::drawAll() {
    window.clear();
    if (playing) {
        player.sprite.setTexture(playerTexture);
        keyIcone.setTexture(keyTexture);
        if (player.key) window.draw(keyIcone);
        player.draw(window);
        if (!enemies.empty()) {
            for (auto& enemy : enemies) {
                if (enemy->type == "chaser") enemy->sprite.setTexture(chaserTexture);
                else if (enemy->type == "patrolling") enemy->sprite.setTexture(patrollingTexture);
                enemy->draw(window);
            }
        }
        if (!objects.empty()) {
            for (auto& obj : objects) {
                if (obj->type == "potion") obj->sprite.setTexture(potionTexture);
                else if (obj->type == "key") obj->sprite.setTexture(keyTexture);
                window.draw(obj->sprite);
            }
        }
        /*if (!theMap.walls.empty()) {
            for (auto& wallz : theMap.walls) {
                for (auto& wall : wallz) {
                    wallSprite.setScale(wall->getScale());
                    wallSprite.setPosition(wall->getPosition());
                    window.draw(wallSprite);
                }
            }
        }*/
        wallSprite.setPosition(650, 650);
        wallSprite.setScale(0.1f, 0.1f);
        window.draw(wallSprite);
        if (!theMap.paves.empty()) {
            for (auto& pave : theMap.paves) {
                paveSprite.setScale(pave->getScale());
                paveSprite.setPosition(pave->getPosition());
                window.draw(paveSprite);
            }
        }
    }
    if (gameOver) {
        window.draw(gameOverText);
        window.draw(retryText);
    }
    window.display();
}

void Game::loadTextures() {
    theMap.loadMap();
    playerTexture.loadFromFile("assets/player.png");
    chaserTexture.loadFromFile("assets/chaser.png");
    patrollingTexture.loadFromFile("assets/patrolling.png");
    potionTexture.loadFromFile("assets/potion.png");
    keyTexture.loadFromFile("assets/key.png");
    wallTexture.loadFromFile("assets/wall.png");
    paveTexture.loadFromFile("assets/pave.png");

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

    keyIcone.setTexture(keyTexture);
    keyIcone.setScale(0.075, 0.075);
    keyIcone.setPosition(0, 0);
    wallSprite.setTexture(wallTexture);
    paveSprite.setTexture(paveTexture);
    for (auto& wallz : theMap.walls) {
        for (auto& wall : wallz) {
            wall->setTexture(wallTexture);
            wall->setScale(0.1f, 0.1f);
        }
    }
    for (auto& pave : theMap.paves) {
        pave->setTexture(paveTexture);
        pave->setScale(0.1f, 0.1f);
    }
}

void Game::setupSpawns() {
    //std::unique_ptr<Enemy> chaser = std::make_unique<ChaserEnemy>(100, 100);
    //enemies.push_back(chaser);
    enemies.emplace_back(std::make_unique<ChaserEnemy>(100, 100));
    //std::unique_ptr<PatrollingEnemy> patrolling = std::make_unique<PatrollingEnemy>(700, 700);
    //patrollings.push_back(patrolling);
    enemies.emplace_back(std::make_unique<PatrollingEnemy>(500, 500));

    objects.emplace_back(std::make_unique<Potion>());
    objects.emplace_back(std::make_unique<Key>());
    for (auto& obj : objects) {
        obj->sprite.setPosition(rand() % window.getSize().x * 0.95, rand() % window.getSize().y * 0.95);
    }
}

void Game::reset() {
    enemies.clear();
    objects.clear();
    player.sprite.setPosition(600, 400);
    player.potion = false;
    player.key = false;
    setupSpawns();
}

void Game::run() {
    loadTextures();
    setupSpawns();
    gameLoop();
}