#pragma once
#include "stdafx.h"
#include "Consts.h"

class LevelsMenu
{
	sf::Font font;
	sf::Text levelNumberText;
	std::ostringstream levelNumber;

	//level Blocks 
	sf::Sprite levelBlockSprite;
	sf::Texture levelBlockTextureSheet;
	
	std::vector<sf::FloatRect> levelsPositions;

	//Stars
	sf::Sprite starSprite;
	sf::Texture starTextureSheet;

	sf::Sprite activeStarSprite;
	sf::Texture activeStarTextureSheet;

	//Blocks
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	//Back button 
	sf::Sprite backButtonSprite;
	sf::Texture backButtonTextureSheet;

	//Reset progress button
	sf::Sprite resetButtonSprite;
	sf::Texture resetButtonTextureSheet;


	int earnedStarsInLevels[20];

	bool isClickActive = false;

	bool isLevelSelected = false;
	int selectedLevel = 0;
	bool isBackPressed = false;
	bool isResetPressed = false;

	void initTextures();
	void initSprites();
	void initFont();
	void initText();
	void createLevelsBlock();

public:
	LevelsMenu();

	void update();
	void render(sf::RenderTarget& target);

	void setEarnedStarsInLevels(int* earnedStarsInLevels);

	bool getIsLevelSelected();
	int getSelectedLevel();
	bool getIsBackPressed();
	bool getIsResetPressed();

};

