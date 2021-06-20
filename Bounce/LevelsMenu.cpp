#include "LevelsMenu.h"

void LevelsMenu::initTextures()
{
	if (!this->levelBlockTextureSheet.loadFromFile("Assets/lselect_level@2x.png"))
		std::cout << "ERROR::MENU::Could not load the level block sheet!" << std::endl;

	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))
		std::cout << "ERROR::MENU::Could not load the Block sheet!" << std::endl;
}

void LevelsMenu::initSprites()
{
	this->levelBlockSprite.setTexture(levelBlockTextureSheet);
	this->blockSprite.setTexture(blockTextureSheet);
	this->blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
	
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
			levelsPositions.push_back(levelBlockSprite.getGlobalBounds());
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
			levelsCounter++;
		}
	}

	for (size_t i = 0; i < 24; i++)
	{
		blockSprite.setPosition(c::GRID_SIZE * i, c::WINDOW_HEIGHT - 110);
		target.draw(blockSprite);
	}
}

bool LevelsMenu::checkLevelSelected()
{
	return isLevelSelected;
}

int LevelsMenu::getSelectedLevel()
{
	return selectedLevel;
}
