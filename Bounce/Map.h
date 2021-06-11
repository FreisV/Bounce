#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 12;

class Map
{
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	sf::Sprite rightAscentSprite;
	sf::Texture rightAscentTextureSheet;

	sf::Sprite leftAscentSprite;
	sf::Texture leftAscentTextureSheet;

	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B     BBB                                                B",
		"B     BB  BBBBB                                          B",
		"B     BBB    BB                                          B",
		"B     BBBBBBBBB                                          B",
		"B                                                        B",
		"B                 RL                                     B",
		"B                RBBL                                    B",
		"B               RBBBBL                                   B",
		"B              RBBBBBBL                                  B",
		"B             RBBBBBBBBL                                 B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	sf::Sprite mapBlocks[mapHeight] = {};
	void initTextures();
	void initSprites();
	void createBlock(b2World& World, int x, int y);
	void createRightAscent(b2World& World, int x, int y);
	void createLeftAscent(b2World& World, int x, int y);


public:
	void createBlocks(b2World& World);
	void render(sf::RenderTarget& target);
	sf::FloatRect getBlockBounds();
	std::string *setMap();
};

