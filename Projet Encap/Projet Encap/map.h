#pragma once

#include "includes.h"

class Map {
public:
	std::ifstream mapFile;
	std::vector<std::vector<std::unique_ptr<sf::Sprite>>> walls;
	std::vector<std::unique_ptr<sf::Sprite>> paves;
	std::string line;

	Map();

	void loadMap();
	//void drawWall(sf::RenderWindow& window);
};