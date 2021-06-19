#include "Interface.h"

void Interface::initTextures()
{
	if (!this->ringTextureSheet.loadFromFile("Assets/ring_small@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the ring sheet!" << std::endl;

	if (!this->ringTextureSheet.loadFromFile("Assets/ring_small@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the ring sheet!" << std::endl;

	if (!this->livesTextureSheet.loadFromFile("Assets/gbar_life@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the life sheet!" << std::endl;
}

void Interface::initSprites()
{
	this->ringSprite.setTexture(ringTextureSheet);
	this->ringSprite.setScale(1.0 / 4 * 3, 1.0 / 12 * 8);
	this->livesSprite.setTexture(livesTextureSheet);
	this->livesSprite.setScale(1.0 / 44 * 80, 1.0 / 44 * 80);
}

void Interface::initFont()
{
	if (!this->font.loadFromFile("Assets/Fonts/Pixels.otf"))
		std::cout << "ERROR:: Could not load the Pixels.otf font" << std::endl;
}

void Interface::initScoreText()
{
	this->scoreText.setString("");
	this->scoreText.setCharacterSize(120);
	this->scoreText.setFont(font);
	this->scoreText.setFillColor(sf::Color::White);
}

void Interface::initLivesCounterText()
{
	this->livesCounterText.setString("");
	this->livesCounterText.setCharacterSize(120);
	this->livesCounterText.setFont(font);
	this->livesCounterText.setFillColor(sf::Color::White);
}

Interface::Interface()
{
	this->initTextures();
	this->initSprites();
	this->initFont();
	this->initScoreText();
	this->initLivesCounterText();
}


void Interface::setScore(int playerScore)
{
	this->score.str("");
	this->score << std::setw(6) << std::setfill('0') << playerScore;
}

void Interface::setLives(int livesCounterInt)
{
	this->livesCounter.str("");
	this->livesCounter << "X" << livesCounterInt;
}



void Interface::update(sf::Vector2f viewPosition, int playerScore, int livesCounter)
{
	setLives(livesCounter);
	livesSprite.setPosition(viewPosition.x - 940, viewPosition.y - 520);
	livesCounterText.setPosition(viewPosition.x - 845, viewPosition.y - 570);
	livesCounterText.setString(this->livesCounter.str());

	setScore(playerScore);
	scoreText.setPosition(viewPosition.x + 500, viewPosition.y - 570);
	scoreText.setString(score.str());
}

void Interface::render(sf::RenderTarget& target, sf::Vector2f viewPosition, int ringsCounter)
{
	ringSprite.setPosition(viewPosition.x - 750, viewPosition.y - 515);

	for (int i = 0; i < ringsCounter; i++)
	{
		ringSprite.move(40, 0);
		target.draw(ringSprite);
	}

	target.draw(scoreText);
	target.draw(livesCounterText);
	target.draw(livesSprite);
}

