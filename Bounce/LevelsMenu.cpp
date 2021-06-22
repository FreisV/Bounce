#include "LevelsMenu.h"

void LevelsMenu::initTextures()
{
	if (!this->levelBlockTextureSheet.loadFromFile("Assets/lselect_level@2x.png"))
		std::cout << "ERROR::MENU::Could not load the level block sheet!" << std::endl;

	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))
		std::cout << "ERROR::MENU::Could not load the Block sheet!" << std::endl;

	if (!this->backButtonTextureSheet.loadFromFile("Assets/menu_button_back@2x.png"))
		std::cout << "ERROR::MENU::Could not load the back button sheet!" << std::endl;

	if (!this->starTextureSheet.loadFromFile("Assets/lselect_star_grey@2x.png"))
		std::cout << "ERROR::MENU::Could not load the star sheet!" << std::endl;

	if (!this->activeStarTextureSheet.loadFromFile("Assets/lselect_star@2x.png"))
		std::cout << "ERROR::MENU::Could not load the active star sheet!" << std::endl;
}

void LevelsMenu::initSprites()
{
	this->levelBlockSprite.setTexture(levelBlockTextureSheet);
	
	this->blockSprite.setTexture(blockTextureSheet);
	this->blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
	
	this->backButtonSprite.setTexture(backButtonTextureSheet);
	this->backButtonSprite.setOrigin(178, 50);

	this->starSprite.setTexture(starTextureSheet);
	this->starSprite.setOrigin(12, 12);

	this->activeStarSprite.setTexture(activeStarTextureSheet);
	this->activeStarSprite.setOrigin(12, 12);
}

void LevelsMenu::initFont()
{
	if (!this->font.loadFromFile("Assets/Fonts/TwCen.otf"))
		std::cout << "ERROR::MENU::Could not load the Pixels.otf font" << std::endl;
}

void LevelsMenu::initText()
{
	this->levelNumberText.setString("");
	this->levelNumberText.setCharacterSize(100);
	this->levelNumberText.setFont(font);
	this->levelNumberText.setFillColor(sf::Color::White);
}

void LevelsMenu::createLevelsBlock()
{
	for (size_t i = 0; i < 4; i++)
	{
		int y = 240 + 128 * i;
		for (size_t j = 0; j < 5; j++)
		{
			levelBlockSprite.setPosition(640 + 128 * j, y); 
			sf::Vector2f blockSpritePosition(levelBlockSprite.getPosition().x, levelBlockSprite.getPosition().y + 30);
			levelsPositions.push_back(sf::FloatRect(blockSpritePosition,sf::Vector2f(128,128)));
		}
	}
}

LevelsMenu::LevelsMenu()
{
	this->initTextures();
	this->initSprites();
	this->initFont();
	this->initText();
	this->createLevelsBlock();
}

void LevelsMenu::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if ((mousePos.x >= 790 && mousePos.x <= 1146) && (mousePos.y >= 846 && mousePos.y <= 946))
			isBackPressed = true;

		for (size_t i = 0; i < size(levelsPositions); i++)
		{
			if (levelsPositions[i].contains(mousePos))
			{
				this->selectedLevel = i + 1;
				this->isLevelSelected = true;
				break;
			}
		}
	}

	this->backButtonSprite.setPosition(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2 + 325);
}

void LevelsMenu::render(sf::RenderTarget& target)
{
	int levelsCounter = 1;
	for (size_t i = 0; i < 4; i++)
	{
		int y = 240 + 128 * i;
		for (size_t j = 0; j < 5; j++)
		{
			levelBlockSprite.setPosition(640 + 128 * j, y);
			target.draw(levelBlockSprite);
			
			levelNumber.str("");
			levelNumber << levelsCounter;
			if (levelsCounter < 10)
				levelNumberText.setPosition(640 + 128 * j + 45, y - 20);
			else
				levelNumberText.setPosition(640 + 128 * j + 20, y - 20);
			levelNumberText.setString(levelNumber.str());
			target.draw(levelNumberText);

			for (size_t n = 1; n < 4; n++)
			{
				starSprite.setPosition(648 + 128 * j + 30 * n, y + 100);
				activeStarSprite.setPosition(648 + 128 * j + 30 * n, y + 100);

				if (earnedStarsInLevels[levelsCounter - 1] > 0 && earnedStarsInLevels[levelsCounter - 1] >= n)
					target.draw(activeStarSprite);
				else 
					target.draw(starSprite);
			}

			levelsCounter++;
		}
	}

	for (size_t i = 0; i < 24; i++)
	{
		blockSprite.setPosition(c::GRID_SIZE * i, c::WINDOW_HEIGHT - 110);
		target.draw(blockSprite);
	}

	target.draw(backButtonSprite);
}

void LevelsMenu::setEarnedStarsInLevels(int *earnedStarsInLevels)
{
	for (int i = 0; i < 20; i++)
	{
		this->earnedStarsInLevels[i] = earnedStarsInLevels[i];
	}
	std::cout << std::endl;

}

bool LevelsMenu::getIsLevelSelected()
{
	bool buffer = this->isLevelSelected;
	this->isLevelSelected = false;
	return buffer;
}

int LevelsMenu::getSelectedLevel()
{
	return selectedLevel;
}

bool LevelsMenu::getIsBackPressed()
{
	bool buffer = this->isBackPressed;
	this->isBackPressed = false;
	return buffer;
}
