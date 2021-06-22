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
	
	if (!this->winRestartButtonTextureSheet.loadFromFile("Assets/game_dialog_complete_button_retry@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the win restart button sheet!" << std::endl;

	if (!this->menuButtonTextureSheet.loadFromFile("Assets/game_dialog_failed_button_menu@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the menu button sheet!" << std::endl;

	if (!this->nextButtonTextureSheet.loadFromFile("Assets/game_dialog_complete_button_next@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the next level button sheet!" << std::endl;

	if (!this->starTextureSheet.loadFromFile("Assets/game_dialog_complete_star_gray@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the star sheet!" << std::endl;

	if (!this->activeStarTextureSheet.loadFromFile("Assets/game_dialog_complete_star_yellow@2x.png"))
		std::cout << "ERROR::INTERFACE::Could not load the active star sheet!" << std::endl;


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
	
	this->winRestartButtonSprite.setTexture(winRestartButtonTextureSheet);
	this->winRestartButtonSprite.setOrigin(50, 50);

	this->menuButtonSprite.setTexture(menuButtonTextureSheet);
	this->menuButtonSprite.setOrigin(50, 50);
	
	this->nextButtonSprite.setTexture(nextButtonTextureSheet);
	this->nextButtonSprite.setOrigin(143, 50);
	
	this->starSprite.setTexture(starTextureSheet);
	this->starSprite.setOrigin(32, 32);
	this->starSprite.setScale(1.5, 1.5);

	this->activeStarSprite.setTexture(activeStarTextureSheet);
	this->activeStarSprite.setOrigin(32, 32);
	this->activeStarSprite.setScale(1.5, 1.5);
}

void Interface::initShapes()
{
	this->levelEndedWindowShape.setFillColor(sf::Color::White);
	this->levelEndedWindowShape.setOutlineColor(sf::Color::Black);
	this->levelEndedWindowShape.setOutlineThickness(10);
	this->levelEndedWindowShape.setSize(sf::Vector2f(1200, 900));
	this->levelEndedWindowShape.setOrigin(sf::Vector2f(600, 450));

	this->whiteBackgroundShape.setFillColor(sf::Color(255,255,255,120));
	this->whiteBackgroundShape.setSize(sf::Vector2f(1920, 1080));
	this->whiteBackgroundShape.setOrigin(sf::Vector2f(960, 540));
}

void Interface::initFont()
{
	if (!this->font.loadFromFile("Assets/Fonts/Pixels.otf"))
		std::cout << "ERROR:: Could not load the Pixels.otf font" << std::endl;

	if (!this->finalScoreFont.loadFromFile("Assets/Fonts/TwCen.otf"))
		std::cout << "ERROR:: Could not load the TwCen.otf font" << std::endl;
}

void Interface::initScoreText()
{
	this->scoreText.setString("");
	this->scoreText.setCharacterSize(120);
	this->scoreText.setFont(font);
	this->scoreText.setFillColor(sf::Color::White);

	this->finalScoreText.setString("");
	this->finalScoreText.setCharacterSize(190);
	this->finalScoreText.setFont(finalScoreFont);
	this->finalScoreText.setFillColor(sf::Color::Red);
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
	this->scoreString.str("");
	this->scoreString << std::setw(6) << std::setfill('0') << playerScore;
}

void Interface::setLives(int livesCounterInt)
{
	this->livesCounterString.str("");
	this->livesCounterString << "X" << livesCounterInt;
}

void Interface::update(sf::Vector2f viewPosition, int playerScore, int livesCounter, int maxScore, int maxLives)
{
	if (livesCounter == 0)
		isLastDead = true;
	if (ringsCounter == 0)
		isLastRing = true;

	this->score = playerScore;
	this->livesCounter = livesCounter;
	this->maxScore = maxScore;
	this->maxLives = maxLives;

	setLives(livesCounter);
	livesSprite.setPosition(viewPosition.x - 940, viewPosition.y - 520);
	livesCounterText.setPosition(viewPosition.x - 845, viewPosition.y - 570);
	livesCounterText.setString(this->livesCounterString.str());

	setScore(playerScore);
	scoreText.setPosition(viewPosition.x + 500, viewPosition.y - 570);
	scoreText.setString(scoreString.str());
	finalScoreText.setPosition(viewPosition.x - 250, viewPosition.y - 300);
	finalScoreText.setString(scoreString.str());

	this->whiteBackgroundShape.setPosition(viewPosition.x, viewPosition.y);
	this->levelEndedWindowShape.setPosition(viewPosition.x, viewPosition.y - 20);
	this->levelFailedSprite.setPosition(viewPosition.x , viewPosition.y - 180);
	this->restartButtonSprite.setPosition(viewPosition.x + 100, viewPosition.y + 250);
	this->winRestartButtonSprite.setPosition(viewPosition.x - 95, viewPosition.y + 250);
	this->nextButtonSprite.setPosition(viewPosition.x + 105, viewPosition.y + 250);
	this->starSprite.setPosition(viewPosition.x - 150, viewPosition.y + 50);
	this->activeStarSprite.setPosition(viewPosition.x - 150, viewPosition.y + 50);
	if (isLastDead)
		this->menuButtonSprite.setPosition(viewPosition.x - 150, viewPosition.y + 250);
	else if (isLastRing)
		this->menuButtonSprite.setPosition(viewPosition.x - 200, viewPosition.y + 250);



	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		isClickActive = true;
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

		std::cout << mousePos.x << "\t" << mousePos.y << std::endl;

		if(isLastDead && (mousePos.x >= 920 && mousePos.x <= 1215) &&(mousePos.y >= 770 && mousePos.y <= 870))
			isRestartPressed = true;
		if (isLastRing && (mousePos.x >= 823 && mousePos.x <= 923) && (mousePos.y >= 770 && mousePos.y <= 870))
			isRestartPressed = true;

		if (isLastRing && (mousePos.x >= 930 && mousePos.x <= 1215) && (mousePos.y >= 770 && mousePos.y <= 870))
			isNextPresssed = true;

		if (isLastDead && (mousePos.x >= 768 && mousePos.x <= 868) && (mousePos.y >= 770 && mousePos.y <= 870))
			isMenuPressed = true;
		if (isLastRing && (mousePos.x >= 718 && mousePos.x <= 818) && (mousePos.y >= 770 && mousePos.y <= 870))
			isMenuPressed = true;
	}
	else
	{
		if (isClickActive)
			isClickActive = false;
	}

}

void Interface::render(sf::RenderTarget& target, sf::Vector2f viewPosition, int ringsCounter)
{
	ringSprite.setPosition(viewPosition.x - 750, viewPosition.y - 515);

	this->ringsCounter = ringsCounter;

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
		target.draw(levelEndedWindowShape);
		
		target.draw(levelFailedSprite);
		target.draw(restartButtonSprite);
		target.draw(menuButtonSprite);
	}
	if (isLastRing == true)
	{

		target.draw(whiteBackgroundShape);
		target.draw(levelEndedWindowShape);
		
		target.draw(finalScoreText);
		for (int i = -1; i < 2; i++)
		{
			starSprite.setPosition(viewPosition.x + 150 * i , viewPosition.y + 50);
			activeStarSprite.setPosition(viewPosition.x + 150 * i , viewPosition.y + 50);

			if (i == -1)
				target.draw(activeStarSprite);

			if (i == 0 && maxScore == score)
				target.draw(activeStarSprite);
			else if (i == 0 && maxScore != score)
				target.draw(starSprite);

			if (i == 1 && maxLives == livesCounter)
				target.draw(activeStarSprite);
			else if (i == 1 && maxLives != livesCounter)
				target.draw(starSprite);
		}
		target.draw(menuButtonSprite);
		target.draw(winRestartButtonSprite);
		target.draw(nextButtonSprite);
	}
}


bool Interface::getIsLastRing()
{		return false;

	return this->isLastRing;
}

bool Interface::getIsMenuPressed()
{
	if (this->isClickActive)
		return false;

	bool buffer = isMenuPressed;
	isMenuPressed = false;
	if (buffer)
	{
		isLastDead = false;
		isLastRing = false;
	}
	return buffer;
}

bool Interface::getIsRestartPressed()
{
	if (this->isClickActive)
		return false;

	bool buffer = isRestartPressed;
	isRestartPressed = false;
	if (buffer)
	{
		isLastDead = false;
		isLastRing = false;
	}
	return buffer;
}

bool Interface::getIsNextPressed()
{
	if (this->isClickActive)
		return false;

	bool buffer = isNextPresssed;
	isNextPresssed = false;
	if (buffer)
	{
		isLastDead = false;
		isLastRing = false;
	}
	return buffer;
}

