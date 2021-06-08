#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 12;

class Map
{
	sf::Sprite blockSprite;
	sf::Texture textureSheet;
	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                              B",
		"B                              B",
		"B            B                 B",
		"B          B                   B",
		"B               B              B",
		"B        BB                    B",
		"B        BB      B             B",
		"B        BB                    B",
		"B        BB       B            B",
		"B       BBBB                   B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	sf::Sprite mapBlocks[mapHeight] = {};
	void initTexture();
	void createBlock(b2World& World, int x, int y, int w, int h);

public:
	void createBlocks(b2World& World);
	void render(sf::RenderTarget& target);
	sf::FloatRect getBlockBounds();
	std::string *setMap();
};

