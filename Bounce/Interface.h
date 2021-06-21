#pragma once
#include "stdafx.h"
class Interface
{

	sf::Font font;

	bool isClickActive = true;

	bool isLastDead = false;
	bool isLastRing = false;
	bool isRestartPressed = false;
	bool isMenuPressed = false;

	//lives
	sf::Sprite livesSprite;
	sf::Texture livesTextureSheet;
	sf::Text livesCounterText;
	std::ostringstream livesCounter;

	//rings
	sf::Sprite ringSprite;
	sf::Texture ringTextureSheet;
	int ringsCounter;

	//score
	sf::Text scoreText;
	std::ostringstream score;

	//Windows 
	sf::RectangleShape whiteBackgroundShape;
	sf::RectangleShape levelEndedWindowShape;
	
	sf::Sprite menuButtonSprite;
	sf::Texture menuButtonTextureSheet;
		
		//LevelFailed
	sf::Sprite levelFailedSprite;
	sf::Texture levelFailedTextureSheet;


		//Restart
	sf::Sprite restartButtonSprite;
	sf::Texture restartButtonTextureSheet;

	void initTextures();
	void initSprites();
	void initShapes();
	void initFont();
	void initScoreText();
	void initLivesCounterText();

	void setScore(int scoreInt);
	void setLives(int livesCounterInt);
public:
	Interface();

	void update(sf::Vector2f viewPosition, int scoreInt, int livesCounter);
	void render(sf::RenderTarget& target,sf::Vector2f viewPosition, int ringsCounter);

	bool getIsLastRing();

	bool getIsRestartPressed();
	bool getIsMenuPressed();

};

