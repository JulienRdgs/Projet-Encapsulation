#include "game.h"

Game::Game() : window(sf::VideoMode(1200, 800), "Escape the Dungeon"), player(sf::Vector2f(50,50)) {
    player.setPosition((window.getSize().x - player.getSize().x) / 2, (window.getSize().y - player.getSize().y) / 2);
    player.setFillColor(sf::Color::Red);
}

void Game::gameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0, 2.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0, -2.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-2.f, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(2.f, 0);
        }

        window.clear();
        window.draw(player);
        window.display();
    }
}