#include "Interface.h"
#include "Consts.h"

void Interface::initTextures()
{
	if (!this->ringTextureSheet.loadFromFile("Assets/ring_small@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the ring sheet!" << std::endl;

	if (!this->ringTextureSheet.loadFromFile("Assets/ring_small@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the ring sheet!" << std::endl;

	if (!this->livesTextureSheet.loadFromFile("Assets/gbar_life@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the life sheet!" << std::endl;

	if (!this->levelFailedTextureSheet.loadFromFile("Assets/game_dialog_failed_title@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the level failed sheet!" << std::endl;

	if (!this->restartButtonTextureSheet.loadFromFile("Assets/game_dialog_failed_button_retry@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the restart button sheet!" << std::endl;

	if (!this->menuButtonTextureSheet.loadFromFile("Assets/game_dialog_failed_button_menu@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the menu button sheet!" << std::endl;
}

void Interface::initSprites()
{
	this->ringSprite.setTexture(ringTextureSheet);
	this->ringSprite.setScale(1.0 / 4 * 3, 1.0 / 12 * 8);
	this->livesSprite.setTexture(livesTextureSheet);
	this->livesSprite.setScale(1.0 / 44 * 80, 1.0 / 44 * 80);
	this->levelFailedSprite.setTexture(levelFailedTextureSheet);
	this->levelFailedSprite.setOrigin(128, 164);
	this->restartButtonSprite.setTexture(restartButtonTextureSheet);
	this->restartButtonSprite.setOrigin(148, 50);
	this->menuButtonSprite.setTexture(menuButtonTextureSheet);
	this->menuButtonSprite.setOrigin(50, 50);

}

void Interface::initShapes()
{
	this->levelFailedWindowShape.setFillColor(sf::Color::White);
	this->levelFailedWindowShape.setOutlineColor(sf::Color::Black);
	this->levelFailedWindowShape.setOutlineThickness(10);
	this->levelFailedWindowShape.setSize(sf::Vector2f(1200, 900));
	this->levelFailedWindowShape.setOrigin(sf::Vector2f(600, 450));

	this->whiteBackgroundShape.setFillColor(sf::Color(255,255,255,120));
	this->whiteBackgroundShape.setSize(sf::Vector2f(1920, 1080));
	this->whiteBackgroundShape.setOrigin(sf::Vector2f(960, 540));
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
	this->initShapes();
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
	if (livesCounter == 0)
		isLastDead = true;

	setLives(livesCounter);
	livesSprite.setPosition(viewPosition.x - 940, viewPosition.y - 520);
	livesCounterText.setPosition(viewPosition.x - 845, viewPosition.y - 570);
	livesCounterText.setString(this->livesCounter.str());

	setScore(playerScore);
	scoreText.setPosition(viewPosition.x + 500, viewPosition.y - 570);
	scoreText.setString(score.str());

	this->whiteBackgroundShape.setPosition(viewPosition.x, viewPosition.y);
	this->levelFailedWindowShape.setPosition(viewPosition.x, viewPosition.y - 20);
	this->levelFailedSprite.setPosition(viewPosition.x , viewPosition.y - 180);
	this->menuButtonSprite.setPosition(viewPosition.x - 150, viewPosition.y + 250);
	this->restartButtonSprite.setPosition(viewPosition.x + 100, viewPosition.y + 250);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isLastDead)
	{
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if((mousePos.x >= 920 && mousePos.x <= 1215) &&(mousePos.y >= 770 && mousePos.y <= 870))
			isRestartPressed = true;

		if ((mousePos.x >= 768 && mousePos.x <= 868) && (mousePos.y >= 770 && mousePos.y <= 870))
			isMenuPressed = true;
	}

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

	if (isLastDead == true)
	{
		target.draw(whiteBackgroundShape);
		target.draw(levelFailedWindowShape);
		target.draw(levelFailedSprite);
		target.draw(restartButtonSprite);
		target.draw(menuButtonSprite);
	}
}

bool Interface::getIsRestartPressed()
{
	bool buffer = isRestartPressed;
	isRestartPressed = false;
	if (buffer)
		isLastDead = false;
	return buffer;
}

bool Interface::getIsMenuPressed()
{
	bool buffer = isMenuPressed;
	isMenuPressed = false;
	if (buffer)
		isLastDead = false;
	return buffer;
}

