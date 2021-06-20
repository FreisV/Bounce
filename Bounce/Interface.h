#pragma once
#include "stdafx.h"
class Interface
{

	sf::Font font;
	sf::RectangleShape whiteBackgroundShape;

	//lives
	sf::Sprite livesSprite;
	sf::Texture livesTextureSheet;
	sf::Text livesCounterText;
	std::ostringstream livesCounter;
	bool isLastDead = false;
	bool isRestartPressed = false;

	//rings
	sf::Sprite ringSprite;
	sf::Texture ringTextureSheet;
	int ringsCounter;

	//score
	sf::Text scoreText;
	std::ostringstream score;

	//LevelFailed
	sf::Sprite levelFailedSprite;
	sf::Texture levelFailedTextureSheet;

	sf::RectangleShape levelFailedWindowShape;

	//Restart
	sf::Sprite restartButtonSprite;
	sf::Texture restartButtonTextureShape;




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

	bool getIsRestartPressed();
};

