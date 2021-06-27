#pragma once
#include "stdafx.h"
#include "Consts.h"

class Leaderboard
{
	sf::Font font;
	sf::Text titleText;

	sf::Text gamerOneNameText;
	sf::Text gamerOneProgressText;
	sf::Text gamerOneTimeText;

	sf::Text gamerTwoNameText;
	sf::Text gamerTwoProgressText;
	sf::Text gamerTwoTimeText;

	sf::Text gamerThreeNameText;
	sf::Text gamerThreeProgressText;
	sf::Text gamerThreeTimeText;

	sf::Text gamerFourNameText;
	sf::Text gamerFourProgressText;
	sf::Text gamerFourTimeText;

	sf::Text gamerFiveNameText;
	sf::Text gamerFiveProgressText;
	sf::Text gamerFiveTimeText;

	sf::Sprite backButtonSprite;
	sf::Texture backButtonTextureSheet;

	sf::Sprite blockSprite;
	sf::Texture blockTextureSheet;

	std::string gamersCopy[5];

	bool isClickActive = false;
	bool isBackPressed = false;

	void initFont();
	void initText();
	void initTextures();
	void initSprites();
public:
	Leaderboard();

	void update(std::string gamers[5]);
	void render(sf::RenderTarget& target);

	bool checkIsBackPressed();
};

