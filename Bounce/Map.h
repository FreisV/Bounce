#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 12;

class Map
{
	//blocks
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	//ascents
	sf::Sprite rightAscentSprite;
	sf::Texture rightAscentTextureSheet;

	sf::Sprite leftAscentSprite;
	sf::Texture leftAscentTextureSheet;
	
	//rings
	sf::Sprite topRingSprite;
	sf::Sprite catchedTopRingSprite;
	sf::Texture topRingTextureSheet;
	sf::Texture catchedTopRingTextureSheet;

	sf::Sprite bottomRingSprite;
	sf::Sprite catchedBottomRingSprite;
	sf::Texture bottomRingTextureSheet;
	sf::Texture catchedBottomRingTextureSheet;

	std::vector<sf::Vector2f> ringsPositions;

	//Wather
	sf::RectangleShape watherSprite;
	std::vector<sf::Vector2f> watherPositions;
	bool inWather = false;

	//Thorn
	sf::Sprite thornSprite;
	sf::Texture thornTextureSheet;
	std::vector<sf::Vector2f> thornsPositions;

	//Interface
	int ringsCounter = 0;
	int score = 0;

	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P BB                                                 B",
		"B     BB     O                                           B",
		"B     BBWWWWWBB                                          B",
		"B BBB BBWWWWWBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B                  RL                                    B",
		"B                 RBBL                                   B",
		"B                RBBBBL                                  B",
		"B               RBBBBBBL                                 B",
		"B  TTBBT       RBBBBBBBBL                   T            B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	void initTextures();
	void initSprites();
	
	void createBlock(b2World& World, int x, int y);
	void createRightAscent(b2World& World, int x, int y);
	void createLeftAscent(b2World& World, int x, int y);
	void createRing(b2World& World, int x, int y);
	void createThorn(b2World& World, int x, int y);

	void takeRings(sf::Vector2f playerPosition);
	void checkInWather(sf::Vector2f playerPosition);
public:
	Map();
	void createBlocks(b2World& World);

	void update(sf::Vector2f playerPosition);
	void render(sf::RenderTarget& target);
	void renderTopRings(sf::RenderTarget& target);
	
	b2Vec2 getSpawnPosition();
	sf::FloatRect getBlockBounds();
	std::string *getMap();

	int getRingsCounter();
	int getScore();
	bool getInWather();
	std::vector<sf::Vector2f> getThornsPositions();
};

