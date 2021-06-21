#pragma once
#include "stdafx.h"
#include "Consts.h"

class Menu
{
	sf::Font font;
	sf::Text text;

	sf::Sprite playButtonSprite;
	sf::Texture playButtonTextureSheet;
	sf::FloatRect playBottonRect;

	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	bool isClickActive = false;
	bool isPlayPressed = false;

	void initTextures();
	void initSprites();
	void initFont();
	void initText();

public:
	Menu();

	void update();
	void render(sf::RenderTarget& target);

	bool checkPlayPressed();
};

