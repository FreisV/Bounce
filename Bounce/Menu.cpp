#include "Menu.h"

void Menu::initTextures()
{
	if (!this->playButtonTextureSheet.loadFromFile("Assets/menu_button_play@2x.png"))
		std::cout << "ERROR::MENU::Could not load the play button sheet!" << std::endl;

	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))
		std::cout << "ERROR::MENU::Could not load the Block sheet!" << std::endl;

	if (!this->exitButtonTextureSheet.loadFromFile("Assets/menu_button_exit@2x.png"))
		std::cout << "ERROR::MENU::Could not load the exit sheet!" << std::endl;

	if (!this->leaderboardButtonTextureSheet.loadFromFile("Assets/menu_button_leaderboard@2x.png"))
		std::cout << "ERROR::MENU::Could not load the leaderbord sheet!" << std::endl;
}

void Menu::initSprites()
{
	this->playButtonSprite.setTexture(playButtonTextureSheet);
	this->playButtonSprite.setOrigin(178,50);
	this->playButtonSprite.setPosition(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2 - 100);

	this->blockSprite.setTexture(blockTextureSheet);
	this->blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);

	this->leaderboardButtonSprite.setTexture(leaderboardButtonTextureSheet);
	this->leaderboardButtonSprite.setOrigin(178, 50);
	this->leaderboardButtonSprite.setPosition(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2 + 50);
	
	this->exitButtonSprite.setTexture(exitButtonTextureSheet);
	this->exitButtonSprite.setOrigin(178, 50);
	this->exitButtonSprite.setPosition(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2 + 200);


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
	

	text.setPosition(c::WINDOW_WIDTH / 2 - 360 , c::WINDOW_HEIGHT / 2 - 500);
	text.setString("Bounce");
}


Menu::Menu()
{
	this->initTextures();
	this->initSprites();
	this->initFont();
	this->initText();

	sf::Vector2f playerButtonPosition = sf::Vector2f(this->playButtonSprite.getPosition().x -168, this->playButtonSprite.getPosition().y - 20);
	this->playButtonRect = sf::FloatRect(playerButtonPosition, sf::Vector2f(356, 100));

	sf::Vector2f leaderboardButtonPosition = sf::Vector2f(this->leaderboardButtonSprite.getPosition().x -168, this->leaderboardButtonSprite.getPosition().y - 20);
	this->leaderboardBottonRect = sf::FloatRect(leaderboardButtonPosition, sf::Vector2f(356, 100));

	sf::Vector2f exitButtonPosition = sf::Vector2f(this->exitButtonSprite.getPosition().x -168, this->exitButtonSprite.getPosition().y - 20);
	this->exitBottonRect = sf::FloatRect(exitButtonPosition, sf::Vector2f(356, 100));
}

void Menu::update(bool windowHasFocus)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && windowHasFocus)
	{	
		isClickActive = true;
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if (playButtonRect.contains(mousePos))
			isPlayPressed = true;

		if (leaderboardBottonRect.contains(mousePos))
			isLeaderboardPressed = true;

		if (exitBottonRect.contains(mousePos))
			isExitPressed = true;

	}
	else
	{
		isClickActive = false;
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
	target.draw(leaderboardButtonSprite);
	target.draw(exitButtonSprite);
}

bool Menu::checkPlayPressed()
{
	if (isClickActive)
		return false;

	bool buffer = this->isPlayPressed;
	this->isPlayPressed = false;
	return buffer;
}

bool Menu::checkExitPressed()
{
	if (isClickActive)
		return false;

	bool buffer = this->isExitPressed;
	this->isExitPressed = false;
	return buffer;
}

bool Menu::checkIsLeaderboardPressed()
{
	if (isClickActive)
		return false;

	bool buffer = this->isLeaderboardPressed;
	this->isLeaderboardPressed = false;
	return buffer;
}



