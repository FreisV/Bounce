#pragma once
#include "stdafx.h"
class Interface
{

	int ringsCounter;
	int ballLives;

	sf::Sprite ringSprite;
	sf::Texture ringTextureSheet;

	void initTextures();
	void initSprites();
public:
	Interface();

	void update();
	void render(sf::RenderTarget& target,sf::Vector2f viewPosition, int ringsCounter);
};

