#pragma once
#include "stdafx.h"
class Interface
{

	sf::Font font;
	sf::Font finalScoreFont;

	bool isClickActive = true;

	bool isLastDead = false;
	bool isLastRing = false;
	bool isMenuPressed = false;
	bool isRestartPressed = false;
	bool isNextPresssed = false; 

	int maxScore = 0;
	int maxLives = 0;

	//lives
	sf::Sprite livesSprite;
	sf::Texture livesTextureSheet;
	sf::Text livesCounterText;
	std::ostringstream livesCounterString;
	int livesCounter = 0;

	//rings
	sf::Sprite ringSprite;
	sf::Texture ringTextureSheet;
	int ringsCounter = 0;

	//score
	sf::Text scoreText;
	std::ostringstream scoreString;
	int score = 0;

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

		//Next Level 
	sf::Sprite nextButtonSprite;
	sf::Texture nextButtonTextureSheet;
	
		//Final Score
	sf::Text finalScoreText;
	 
		//Stars 
	sf::Sprite starSprite;
	sf::Texture starTextureSheet;

	sf::Sprite activeStarSprite;
	sf::Texture activeStarTextureSheet;

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

	void update(sf::Vector2f viewPosition, int scoreInt, int livesCounter, int maxScore, int maxLives);
	void render(sf::RenderTarget& target,sf::Vector2f viewPosition, int ringsCounter);

	bool getIsLastRing();

	bool getIsMenuPressed();
	bool getIsRestartPressed();
	bool getIsNextPressed();
};

