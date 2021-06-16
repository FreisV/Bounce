#pragma once
#include "stdafx.h"
class Interface
{

	int ringsCounter;
	int ballLives;
	std::ostringstream score;

	sf::Sprite ringSprite;
	sf::Texture ringTextureSheet;

	sf::Font font;
	sf::Text scoreText;


	void initTextures();
	void initSprites();
	void initFont();
	void initScoreText();

	void setScore(int scoreInt);
public:
	Interface();

	void update(sf::Vector2f viewPosition, int scoreInt);
	void render(sf::RenderTarget& target,sf::Vector2f viewPosition, int ringsCounter);
};

