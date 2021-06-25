#pragma once
#include "stdafx.h"
#include "Consts.h"

class LevelsMenu
{
	sf::Font font;
	sf::Text levelNumberText;
	std::ostringstream levelNumber;

	sf::Text enterNameTitleText;
	sf::Text enterNameText;

	sf::SoundBuffer buttonBuffer;
	sf::Sound buttonSound;

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

	//Reset
	sf::RectangleShape whiteBackgroundShape;
	sf::RectangleShape enterNameWindowShape;

		//Reset progress button
	sf::Sprite resetButtonSprite;
	sf::Texture resetButtonTextureSheet;
		
		//Enter name button
	sf::Sprite enterNameButtonSprite;
	sf::Texture enterNameButtonTextureSheet;
		
		//cancel reset
	sf::Sprite cancelResetButtonSprite;
	sf::Texture cancelResetButtonTextureSheet;

	int earnedStarsInLevels[20];

	bool isClickActive = false;

	bool isLevelSelected = false;
	int selectedLevel = 0;
	bool isBackPressed = false;
	bool isEnterNamePressed = false;
	bool bufferForIsEnterNamePressed = false;
	bool isResetPressed = false;

	void initTextures();
	void initSprites();
	void initShapes();
	void initFont();
	void initText();
	void initSoundBuffer();
	void initSound();
	void createLevelsBlock();

public:
	LevelsMenu();

	void update(std::string playerName);
	void render(sf::RenderTarget& target);

	void setEarnedStarsInLevels(int* earnedStarsInLevels);

	bool getIsLevelSelected();
	int getSelectedLevel();
	bool getIsBackPressed();
	bool getIsResetPressed();
	bool getIsEnterNamePressed();

};

