#pragma once
#include "stdafx.h"
#include "Consts.h"

class LevelsMenu
{
	sf::Font font;
	sf::Text levelNumberText;
	std::ostringstream levelNumber;

	sf::Sprite levelBlockSprite;
	sf::Texture levelBlockTextureSheet;

	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	std::vector<sf::FloatRect> levelsPositions;

	bool isLevelSelected = false;
	int selectedLevel = 0;

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

};

