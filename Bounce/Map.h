#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 12;

class Map
{
	sf::Sprite blockSprite;
	sf::Texture textureSheet;
	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B     BBBBBBBBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B                 B                                      B",
		"B                BBB                                     B",
		"B               BBBBB                                    B",
		"B              BBBBBBB                                   B",
		"B             BBBBBBBBB                                  B",
		"B            BBBBBBBBBBB                                 B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
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

