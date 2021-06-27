#include "Leaderboard.h"

void Leaderboard::initTextures()
{
	if (!this->backButtonTextureSheet.loadFromFile("Assets/menu_button_back@2x.png"))
		std::cout << "ERROR::LEADERBOARD::Could not load the back button sheet!" << std::endl;

	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))
		std::cout << "ERROR::LEADERBOARD::Could not load the Block sheet!" << std::endl;
}

void Leaderboard::initSprites()
{
	this->backButtonSprite.setTexture(backButtonTextureSheet);
	this->backButtonSprite.setOrigin(178, 50);
	this->backButtonSprite.setPosition(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2 + 325);

	this->blockSprite.setTexture(blockTextureSheet);
	this->blockSprite.setScale(1.0 / 125 * c::GRID_SIZE, 1.0 / 125 * c::GRID_SIZE);
}

void Leaderboard::initFont()
{
	if (!this->font.loadFromFile("Assets/Fonts/TwCen.otf"))
		std::cout << "ERROR::MENU::Could not load the TwCen.otf font" << std::endl;
}

void Leaderboard::initText()
{
	this->titleText.setString("");
	this->titleText.setCharacterSize(40);
	this->titleText.setFont(font);
	this->titleText.setOutlineColor(sf::Color::Black);
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setOutlineThickness(2);
	this->titleText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 - 500);
	this->titleText.setString("gamer:\t\t\t\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16\t17\t18\t19\t20");

	this->gamerOneNameText.setString("");
	this->gamerOneNameText.setCharacterSize(40);
	this->gamerOneNameText.setFont(font);
	this->gamerOneNameText.setOutlineColor(sf::Color::White);
	this->gamerOneNameText.setFillColor(sf::Color::Black);
	this->gamerOneNameText.setOutlineThickness(2);
	this->gamerOneNameText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 - 370);

	this->gamerOneProgressText.setString("");
	this->gamerOneProgressText.setCharacterSize(40);
	this->gamerOneProgressText.setFont(font);
	this->gamerOneProgressText.setOutlineColor(sf::Color::White);
	this->gamerOneProgressText.setFillColor(sf::Color::Black);
	this->gamerOneProgressText.setOutlineThickness(2);
	this->gamerOneProgressText.setPosition(c::WINDOW_WIDTH / 2 - 410, c::WINDOW_HEIGHT / 2 - 370);

	this->gamerOneTimeText.setString("");
	this->gamerOneTimeText.setCharacterSize(40);
	this->gamerOneTimeText.setFont(font);
	this->gamerOneTimeText.setOutlineColor(sf::Color::White);
	this->gamerOneTimeText.setFillColor(sf::Color::Black);
	this->gamerOneTimeText.setOutlineThickness(2);
	this->gamerOneTimeText.setPosition(c::WINDOW_WIDTH / 2 - 920, c::WINDOW_HEIGHT / 2 - 370);


	this->gamerTwoNameText.setString("");
	this->gamerTwoNameText.setCharacterSize(40);
	this->gamerTwoNameText.setFont(font);
	this->gamerTwoNameText.setOutlineColor(sf::Color::White);
	this->gamerTwoNameText.setFillColor(sf::Color::Black);
	this->gamerTwoNameText.setOutlineThickness(2);
	this->gamerTwoNameText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 - 240);

	this->gamerTwoProgressText.setString("");
	this->gamerTwoProgressText.setCharacterSize(40);
	this->gamerTwoProgressText.setFont(font);
	this->gamerTwoProgressText.setOutlineColor(sf::Color::White);
	this->gamerTwoProgressText.setFillColor(sf::Color::Black);
	this->gamerTwoProgressText.setOutlineThickness(2);
	this->gamerTwoProgressText.setPosition(c::WINDOW_WIDTH / 2 - 410, c::WINDOW_HEIGHT / 2 - 240);

	this->gamerTwoTimeText.setString("");
	this->gamerTwoTimeText.setCharacterSize(40);
	this->gamerTwoTimeText.setFont(font);
	this->gamerTwoTimeText.setOutlineColor(sf::Color::White);
	this->gamerTwoTimeText.setFillColor(sf::Color::Black);
	this->gamerTwoTimeText.setOutlineThickness(2);
	this->gamerTwoTimeText.setPosition(c::WINDOW_WIDTH / 2 - 920, c::WINDOW_HEIGHT / 2 - 240);


	this->gamerThreeNameText.setString("");
	this->gamerThreeNameText.setCharacterSize(40);
	this->gamerThreeNameText.setFont(font);
	this->gamerThreeNameText.setOutlineColor(sf::Color::White);
	this->gamerThreeNameText.setFillColor(sf::Color::Black);
	this->gamerThreeNameText.setOutlineThickness(2);
	this->gamerThreeNameText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 - 110);

	this->gamerThreeProgressText.setString("");
	this->gamerThreeProgressText.setCharacterSize(40);
	this->gamerThreeProgressText.setFont(font);
	this->gamerThreeProgressText.setOutlineColor(sf::Color::White);
	this->gamerThreeProgressText.setFillColor(sf::Color::Black);
	this->gamerThreeProgressText.setOutlineThickness(2);
	this->gamerThreeProgressText.setPosition(c::WINDOW_WIDTH / 2 - 410, c::WINDOW_HEIGHT / 2 - 110);

	this->gamerThreeTimeText.setString("");
	this->gamerThreeTimeText.setCharacterSize(40);
	this->gamerThreeTimeText.setFont(font);
	this->gamerThreeTimeText.setOutlineColor(sf::Color::White);
	this->gamerThreeTimeText.setFillColor(sf::Color::Black);
	this->gamerThreeTimeText.setOutlineThickness(2);
	this->gamerThreeTimeText.setPosition(c::WINDOW_WIDTH / 2 - 920, c::WINDOW_HEIGHT / 2 - 110);


	this->gamerFourNameText.setString("");
	this->gamerFourNameText.setCharacterSize(40);
	this->gamerFourNameText.setFont(font);
	this->gamerFourNameText.setOutlineColor(sf::Color::White);
	this->gamerFourNameText.setFillColor(sf::Color::Black);
	this->gamerFourNameText.setOutlineThickness(2);
	this->gamerFourNameText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 + 20);

	this->gamerFourProgressText.setString("");
	this->gamerFourProgressText.setCharacterSize(40);
	this->gamerFourProgressText.setFont(font);
	this->gamerFourProgressText.setOutlineColor(sf::Color::White);
	this->gamerFourProgressText.setFillColor(sf::Color::Black);
	this->gamerFourProgressText.setOutlineThickness(2);
	this->gamerFourProgressText.setPosition(c::WINDOW_WIDTH / 2 - 410, c::WINDOW_HEIGHT / 2 + 20);

	this->gamerFourTimeText.setString("");
	this->gamerFourTimeText.setCharacterSize(40);
	this->gamerFourTimeText.setFont(font);
	this->gamerFourTimeText.setOutlineColor(sf::Color::White);
	this->gamerFourTimeText.setFillColor(sf::Color::Black);
	this->gamerFourTimeText.setOutlineThickness(2);
	this->gamerFourTimeText.setPosition(c::WINDOW_WIDTH / 2 - 920, c::WINDOW_HEIGHT / 2 + 20);


	this->gamerFiveNameText.setString("");
	this->gamerFiveNameText.setCharacterSize(40);
	this->gamerFiveNameText.setFont(font);
	this->gamerFiveNameText.setOutlineColor(sf::Color::White);
	this->gamerFiveNameText.setFillColor(sf::Color::Black);
	this->gamerFiveNameText.setOutlineThickness(2);
	this->gamerFiveNameText.setPosition(c::WINDOW_WIDTH / 2 - 650, c::WINDOW_HEIGHT / 2 + 150);

	this->gamerFiveProgressText.setString("");
	this->gamerFiveProgressText.setCharacterSize(40);
	this->gamerFiveProgressText.setFont(font);
	this->gamerFiveProgressText.setOutlineColor(sf::Color::White);
	this->gamerFiveProgressText.setFillColor(sf::Color::Black);
	this->gamerFiveProgressText.setOutlineThickness(2);
	this->gamerFiveProgressText.setPosition(c::WINDOW_WIDTH / 2 - 410, c::WINDOW_HEIGHT / 2 + 150);

	this->gamerFiveTimeText.setString("");
	this->gamerFiveTimeText.setCharacterSize(40);
	this->gamerFiveTimeText.setFont(font);
	this->gamerFiveTimeText.setOutlineColor(sf::Color::White);
	this->gamerFiveTimeText.setFillColor(sf::Color::Black);
	this->gamerFiveTimeText.setOutlineThickness(2);
	this->gamerFiveTimeText.setPosition(c::WINDOW_WIDTH / 2 - 930, c::WINDOW_HEIGHT / 2 + 150);

}


Leaderboard::Leaderboard()
{
	this->initFont();
	this->initText();
	this->initTextures();
	this->initSprites();
}

void Leaderboard::update(std::string gamers[5], bool windowHasFocus)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && windowHasFocus)
	{
		isClickActive = true;
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if ((mousePos.x >= 790 && mousePos.x <= 1146) && (mousePos.y >= 846 && mousePos.y <= 946))
			isBackPressed = true;

	}
	else
		isClickActive = false;

	for (size_t i = 0; i < 5; i++)
	{
		std::string name = "";
		std::string progress = "";
		std::string time = "";
		int charAfterNickname = 0;

		bool isSpaceAfterName = true;
		for (int j = 0; j < gamers[i].length(); j++)
		{
			if (gamers[i][j] == ' ' && isSpaceAfterName)
			{
				isSpaceAfterName = false;
				charAfterNickname = j;
			}

			if (isSpaceAfterName)
				name.push_back(gamers[i][j]);
			else if (j < charAfterNickname + 40)
			{
				if (gamers[i][j] == ' ' && (j - charAfterNickname < 20))
					progress.push_back('\t');
				else if (gamers[i][j] == ' ')
				{
					progress.push_back(' ');
					progress.push_back(' ');
					progress.push_back('\t');
				}
				else
					progress.push_back(gamers[i][j]);
			}
			else
					time.push_back(gamers[i][j]);
		}

		switch (i)
		{
		case 0:
		{
			gamerOneNameText.setString(name);
			gamerOneProgressText.setString(progress);
			gamerOneTimeText.setString(time);

			break;
		}
		case 1:
		{
			gamerTwoNameText.setString(name);
			gamerTwoProgressText.setString(progress);
			gamerTwoTimeText.setString(time);
			break;
		}
		case 2:
		{
			gamerThreeNameText.setString(name);
			gamerThreeProgressText.setString(progress);
			gamerThreeTimeText.setString(time);
			break;
		}
		case 3:
		{
			gamerFourNameText.setString(name);
			gamerFourProgressText.setString(progress);
			gamerFourTimeText.setString(time);
			break;
		}
		case 4:
		{
			gamerFiveNameText.setString(name);
			gamerFiveProgressText.setString(progress);
			gamerFiveTimeText.setString(time);
			break;
		}
		default:
			break;
		}
	}
}

void Leaderboard::render(sf::RenderTarget& target)
{
	target.draw(this->titleText);

	target.draw(this->gamerOneNameText);
	target.draw(this->gamerOneProgressText);
	target.draw(this->gamerOneTimeText);

	target.draw(this->gamerTwoNameText);
	target.draw(this->gamerTwoProgressText);
	target.draw(this->gamerTwoTimeText);

	target.draw(this->gamerThreeNameText);
	target.draw(this->gamerThreeProgressText);
	target.draw(this->gamerThreeTimeText);

	target.draw(this->gamerFourNameText);
	target.draw(this->gamerFourProgressText);
	target.draw(this->gamerFourTimeText);

	target.draw(this->gamerFiveNameText);
	target.draw(this->gamerFiveProgressText);
	target.draw(this->gamerFiveTimeText);

	target.draw(backButtonSprite);

	for (size_t i = 0; i < 24; i++)
	{
		blockSprite.setPosition(c::GRID_SIZE * i, c::WINDOW_HEIGHT - 110);
		target.draw(blockSprite);
	}
}

bool Leaderboard::checkIsBackPressed()
{
	if (isClickActive)
		return false;

	bool buffer = this->isBackPressed;
	this->isBackPressed = false;
	return buffer;
}