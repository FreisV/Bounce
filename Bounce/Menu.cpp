#include "Menu.h"

void Menu::initTextures()
{
	if (!this->playButtonTextureSheet.loadFromFile("Assets/menu_button_play@2x.png"))
		std::cout << "ERROR::MENU::Could not load the play button sheet!" << std::endl;

	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))
		std::cout << "ERROR::MENU::Could not load the Block sheet!" << std::endl;
}

void Menu::initSprites()
{
	this->playButtonSprite.setTexture(playButtonTextureSheet);
	this->playButtonSprite.setPosition(c::WINDOW_WIDTH / 2 - c::GRID_SIZE/2 - 127, c::WINDOW_HEIGHT / 2 - 50);

	this->blockSprite.setTexture(blockTextureSheet);
	this->blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
}

void Menu::initFont()
{
	if (!this->font.loadFromFile("Assets/Fonts/Pixels.otf"))
		std::cout << "ERROR::MENU::Could not load the Pixels.otf font" << std::endl;
}

void Menu::initText()
{
	this->text.setString("");
	this->text.setCharacterSize(240);
	this->text.setFont(font);
	this->text.setOutlineColor(sf::Color::White);
	this->text.setFillColor(sf::Color::Red);
	this->text.setOutlineThickness(12);
	

	text.setPosition(c::WINDOW_WIDTH / 2 - 340 , c::WINDOW_HEIGHT / 12);
	text.setString("Bounce");
}


Menu::Menu()
{
	this->initTextures();
	this->initSprites();
	this->initFont();
	this->initText();

	sf::Vector2f playerButtonPosition = sf::Vector2f(this->playButtonSprite.getPosition().x + 10, this->playButtonSprite.getPosition().y + 30);
	this->playBottonRect = sf::FloatRect(playerButtonPosition, sf::Vector2f(356, 100));
}

void Menu::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{	
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if (playBottonRect.contains(mousePos))
			isClickActive = true;
		else
			isClickActive = false;
	}
	else
	{
		if (isClickActive)
		{
			isPlayPressed = true;
			isClickActive = false;
		}
	}
}

void Menu::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 24; i++)
	{
		blockSprite.setPosition(c::GRID_SIZE * i, c::WINDOW_HEIGHT - 110);
		target.draw(blockSprite);
	}
	
	target.draw(text);
	target.draw(playButtonSprite);
}

bool Menu::checkPlayPressed()
{
	bool buffer = this->isPlayPressed;
	this->isPlayPressed = false;
	return buffer;
}

