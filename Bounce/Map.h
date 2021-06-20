#pragma once
#include "stdafx.h"
#include "Consts.h"

const int mapHeight = 30;

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

	//Thorns
	sf::Sprite thornSprite;
	sf::Texture thornTextureSheet;
	std::vector<sf::Vector2f> thornsPositions;

	//Checkpoints
	sf::Sprite checkpointSprite;
	sf::Texture checkpointTextureSheet;

	sf::Sprite catchedCheckpointSprite;
	sf::Texture catchedCheckpointTextureSheet;

	std::vector<sf::Vector2f> checkpointsPositions;

	//Bonus life
	sf::Sprite bonusLifeSprite;
	sf::Texture bonusLifeTextureSheet;

	std::vector<sf::Vector2f> bonusLivesPositions;

	//Interface
	int ringsCounter = 0;
	int score = 0;

	std::string map[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P BB                                                 B",
		"B     BB     OC                                          B",
		"B     BBWWWWWBB    l                                     B",
		"B BBB BBWWWWWBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B                                                        B",
		"B                                                        B",
		"B                                                        B",
		"B                                                        B",
		"BTTTTTBB                                                 B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelOne[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O        O       O   B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwo[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                       O       B",
		"B               WWBBBBBBBBBBBBBBB",
		"B               WWBBBBBBBBBBBBBBB",
		"B               WWBBBBBBBBBBBBBBB",
		"B  P            WWBBBBBBBBBBBBBBB",
		"B               WWBBBBBBBBBBBBBBB",
		"B               WWBBBBBBBBBBBBBBB",
		"B               WWBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelThree[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B       T   T   T   T   T    O  B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFour[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B   P                    BBBBBBBBBBBBBBBBBBBBBB",
		"B                               BBBBBBBBBBBBBBB",
		"B                          l  O BBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B                        BBBBBBBBBBBBBBBBBBBBBB",
		"B                                             B",
		"B                   C                         B",
		"B                     T    T   T   O      O   B",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B           O    WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B         T   T  WBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFive[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSix[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSeven[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEight[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelNine[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEleven[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwelve[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelThirteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFourteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelFifeteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSixteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelSeventeen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelEighteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelNineteen[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B                               B",
		"B  P                            B",
		"B                               B",
		"B                               B",
		"B          O                    B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	std::string levelTwenty[mapHeight] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B   P BB                                                 B",
		"B     BB     OC                                          B",
		"B     BBWWWWWBB    l                                     B",
		"B BBB BBWWWWWBB                                          B",
		"B     BBBBBBBBB                                          B",
		"B                  RL                                    B",
		"B                 RBBL                                   B",
		"B                RBBBBL                                  B",
		"B               RBBBBBBL                                 B",
		"BTTTTTBB       RBBBBBBBBL                                B",
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
	void takeCheckpoints(sf::Vector2f playerPosition);
	void takeBonusLives(sf::Vector2f playerPosition);


public:
	Map();
	void createBlocks(b2World& World);
	void setMap(int levelNumber);

	void update(sf::Vector2f playerPosition);
	void render(sf::RenderTarget& target);
	void renderTopRings(sf::RenderTarget& target);
	
	b2Vec2 getSpawnPosition();
	std::string *getMap();

	int getRingsCounter();
	int getScore();
	bool getInWather();
	std::vector<sf::Vector2f> getThornsPositions();
	std::vector<sf::Vector2f> getBonusLivesPositions();
};

