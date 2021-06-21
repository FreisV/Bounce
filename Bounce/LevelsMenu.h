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
	
	//Blocks
	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	//Back button 
	sf::Sprite backButtonSprite;
	sf::Texture backButtonTextureSheet;

	bool isLevelSelected = false;
	int selectedLevel = 0;
	bool isBackPressed = false;

	void initTextures();
	void initSprites();
	void initFont();
	void initText();
	void createLevelsBlock();
public:
	LevelsMenu();

	void update();
	void render(sf::RenderTarget& target);

	bool getIsLevelSelected();
	int getSelectedLevel();
	bool getIsBackPressed();
};

