#include "map.h"

Map::Map() {}

void Map::loadMap() {
	//mapFile.open("assets/mapFile.txt");
	//int y = 0;
	//while (getline(mapFile, line)) {
	//	for (int i = 0; i < 24; i++) {
	//		if (line[i] == '#') {
	//			walls[y].emplace_back(std::make_unique<sf::Sprite>());
	//			walls[y][i]->setPosition((float)i * 50.f, (float)y * 50.f); /////////////////////////// 50->wallTexture.getScale().x * 10 ?
	//			walls[y][i]->setScale(0.1f, 0.1f);
	//			//std::cout << y << std::endl;
	//		}
	//		else if (line[i] == ' ') {
	//			walls[y].emplace_back(std::make_unique<sf::Sprite>());
	//			walls[y][i]->setPosition((float)i * 50.f, (float)y * 50.f); /////////////////////////// 50->wallTexture.getScale().x * 10 ?
	//			walls[y][i]->setScale(0.1f, 0.1f);
	//		}
	//		//std::cout << y << std::endl;
	//		//std::cout << line[i];
	//	}
	//	y++;
	//	//std::cout << std::endl;
	//}
	////for (int j = 0; j < walls.size(); j++) {
	////	std::cout << walls[j]->getPosition().x << " - " << walls[j]->getPosition().y << std::endl;
	////}
	std::cout << walls.size();
}