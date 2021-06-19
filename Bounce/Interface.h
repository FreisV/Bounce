#pragma once
#include "stdafx.h"
class Interface
{

	sf::Font font;

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


	void initTextures();
	void initSprites();
	void initFont();
	void initScoreText();
	void initLivesCounterText();

	void setScore(int scoreInt);
	void setLives(int livesCounterInt);
public:
	Interface();

	void update(sf::Vector2f viewPosition, int scoreInt, int livesCounter);
	void render(sf::RenderTarget& target,sf::Vector2f viewPosition, int ringsCounter);
};

