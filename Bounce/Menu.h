#pragma once
#include "stdafx.h"
#include "Consts.h"

class Menu
{
	sf::Font font;
	sf::Text text;
	
	//Play
	sf::Sprite playButtonSprite;
	sf::Texture playButtonTextureSheet;
	sf::FloatRect playButtonRect;

	//Leaderboard
	sf::Sprite leaderboardButtonSprite;
	sf::Texture leaderboardButtonTextureSheet;
	sf::FloatRect leaderboardBottonRect;

	//Exit
	sf::Sprite exitButtonSprite;
	sf::Texture exitButtonTextureSheet;
	sf::FloatRect exitBottonRect;

	//Blocks
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	bool isClickActive = false;
	bool isPlayPressed = false;
	bool isLeaderboardPressed = false;
	bool isExitPressed = false;

	void initTextures();
	void initSprites();
	void initFont();
	void initText();

public:
	Menu();

	void update();
	void render(sf::RenderTarget& target);

	bool checkPlayPressed();
	bool checkExitPressed();
	bool checkIsLeaderboardPressed();

};

