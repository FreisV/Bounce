#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(c::WINDOW_WIDTH, c::WINDOW_HEIGHT), "Bounce", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
	this->window.setPosition(sf::Vector2i(-10, 0));
}

void Game::initIcon()
{
	if (!icon.loadFromFile("Assets/gbar_life@2x.png"))
		std::cout << "ERROR::Game::Could not load the icon image!" << std::endl;
	window.setIcon(44, 44, icon.getPixelsPtr());
}

void Game::initPlayer()
{
	this->player = new Player(World, map->getSpawnPosition(), map->getThornsPositions(), map->getBonusLivesPositions());
}

void Game::initMap()
{
	this->map = new Map();
}

void Game::initView()
{
	b2Vec2 pos = map->getSpawnPosition();
	this->viewInGame.setCenter(pos.x, pos.y);
	this->viewInGame.setSize(sf::Vector2f(c::WINDOW_WIDTH, c::WINDOW_HEIGHT));

	this->viewInMenu.setCenter(sf::Vector2f(c::WINDOW_WIDTH / 2, c::WINDOW_HEIGHT / 2));
	this->viewInMenu.setSize(sf::Vector2f(c::WINDOW_WIDTH, c::WINDOW_HEIGHT));

}

void Game::initMenu()
{
	this->menu = new Menu;
}

void Game::initLeaderboard()
{
	this->leaderboard = new Leaderboard();
}

void Game::initLevelsMenu()
{
	this->levelsMenu = new LevelsMenu;
}

void Game::initInterface()
{
	this->gameInterface = new Interface();
}

void Game::initSoundBuffer()
{
	if (!this->buttonBuffer.loadFromFile("Assets/Sound/ButtonEffect.wav"))
		std::cout << "ERROR::GAME::Could not load the button sound !" << std::endl;
}

void Game::initSound()
{
	buttonSound.setBuffer(buttonBuffer);
}


void Game::changeProgressFile()
{
	std::ofstream F("Save/progress.txt", std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < 20; i++)
		F << earnedStarsInLevels[i] << " ";
	F.close();
}

void Game::readProgressFile()
{
	std::ifstream F("Save/progress.txt");
	if (F.is_open())
	{
		int counter = 0;
		while (true)
		{
			int x;
			F >> x;
			if (F.eof())
				break;
			earnedStarsInLevels[counter++] = x;
		}
	}
	else
	{
		std::cout << "Unable to open file";
	}
	F.close();
}

void Game::resetProgress()
{
	addGamer();

	std::ofstream F("Save/progress.txt", std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < 20; i++)
	{
		F << 0 << " ";
		earnedStarsInLevels[i] = 0;
	}
	F.close();
}


void Game::readGamers()
{
	std::string str;
	std::ifstream F("Save/gamers.txt");

	int counter = 0;
	while (std::getline(F, str))
	{ 
		gamers[counter++] = str;
	}
	F.close();
}

void Game::addGamer()
{
	std::string newGamer = "";
	time_t now = time(0);
	tm* ltm = localtime(&now);

	newGamer += playerName;
	playerName = "";

	for (int i = 0; i < 5; i++)
		if (gamers[i] == "" || i == 4)
		{
			std::cout << "i: " << i << std::endl;
 			for (int j = i; j >= 0; j--)
			{
				if (j == 0)
					gamers[j] = newGamer;
				else
					gamers[j] = gamers[j - 1];
			}
			break;
		}
	
	std::ofstream F("Save/gamers.txt", std::ofstream::out);

	for (int i = 0; i < 5 ; i++)
	{

		if (gamers[i] == "")
			break;
		F << gamers[i] << " ";

		if (i == 0)
		{
			for (int j = 0; j < 20; j++)
			{
				F << earnedStarsInLevels[j] << " ";
				earnedStarsInLevels[j] = 0;
			}
			F << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1920 + ltm->tm_year << " " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << " ";
		}

		F << "\n";
	}
	F.close();

	readGamers();
}


void Game::updateMenu()
{
	this->menu->update(this->windowHasFocus);
}

void Game::updateLeaderboard()
{
	this->leaderboard->update(this->gamers, this->windowHasFocus);
}

void Game::updateLevelsMenu()
{
	this->levelsMenu->update(this->playerName, this->windowHasFocus);
}

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World, this->map->getInWather(), this->map->getSpawnPosition(), this->gameInterface->getIsLastRing(), this->gameInterface->getIsPause(), this->windowHasFocus);
}

void Game::updateView()
{
	sf::Vector2f playerPosition = player->getPosition();
	sf::Vector2f viewPosition = viewInGame.getCenter();
	sf::Vector2f nextPosition = sf::Vector2f(viewPosition.x + (playerPosition.x - viewPosition.x) * 0.1, viewPosition.y + (playerPosition.y - viewPosition.y) * 0.1);
	viewInGame.setCenter(nextPosition);
}

void Game::updateMap()
{
	map->update(player->getPosition());
}

void Game::updateInterface()
{
	this->gameInterface->update(viewInGame.getCenter(), map->getScore(), player->getLivesCounter(), map->getMaxScore(), map->getMaxLives(), this->windowHasFocus);
}

void Game::updateEarnedStarsInLevels(int quantityStars)
{
	if (earnedStarsInLevels[selectedLevel - 1] < quantityStars)
		earnedStarsInLevels[selectedLevel - 1] = quantityStars;
	changeProgressFile();
}


void Game::renderMenu()
{
	this->menu->render(window);
}

void Game::renderLeaderboard()
{
	this->leaderboard->render(window);
}

void Game::renderLevelsMenu()
{
	this->levelsMenu->render(window);
}

void Game::renderPlayer()
{
	this->player->render(this->window, World);
}

void Game::renderMap()
{
	this->map->render(this->window);
}

void Game::renderView()
{
	this->window.setView(viewInGame);
}

void Game::renderInterface()
{
	int ringsCounter = map->getRingsCounter();
	this->gameInterface->render(window, viewInGame.getCenter(), ringsCounter);
}


void Game::moveInLevelsMenu()
{
	World.SetGravity(Gravity);
	World.DestroyBody(player->getPlayerBody());
	delete player;
	this->map->clearWorld(World);
	delete map;
	initMap();
	initPlayer();
	window.setView(viewInMenu);
	isGame = false;
	isLevelsMenu = true;
}

void Game::reloadLevel()
{
	World.SetGravity(Gravity);
	World.DestroyBody(player->getPlayerBody());
	delete player;
	this->map->clearWorld(World);
	delete map;
	initMap();
	this->map->setMap(selectedLevel);
	this->map->createBlocks(World);
	initPlayer();
}

void Game::changeDisplay()
{
	if (this->menu->checkPlayPressed() && this->isMenu)
	{
		buttonSound.play();
		updateEarnedStarsInLevels(this->gameInterface->getEarnedStars());
		this->levelsMenu->setEarnedStarsInLevels(earnedStarsInLevels);
		
		isMenu = false;
		isLevelsMenu = true;
	}
	if (this->menu->checkIsLeaderboardPressed() && this->isMenu)
	{
		buttonSound.play();
		isMenu = false;
		isLeaderboard = true;
	}
	if (this->menu->checkExitPressed() && this->isMenu)
	{
		buttonSound.play();

		window.close();
	}
	if (this->leaderboard->checkIsBackPressed() && this->isLeaderboard)
	{
		buttonSound.play();

		isMenu = true;
		isLeaderboard = false;
	}
	if (this->levelsMenu->getIsLevelSelected() && this->isLevelsMenu)
	{
		buttonSound.play();

		isLevelsMenu = false;
		selectedLevel = levelsMenu->getSelectedLevel();
		isGame = true;

		this->map->setMap(selectedLevel);
		this->map->createBlocks(World);
		this->player->setItemsPositions(map->getSpawnPosition(), World, map->getThornsPositions(), map->getBonusLivesPositions());
	}
	if (this->levelsMenu->getIsBackPressed() && this->isLevelsMenu)
	{
		buttonSound.play();

		isMenu = true;
		isLevelsMenu = false;
	}
	if (this->levelsMenu->getIsResetPressed() && this->isLevelsMenu)
	{
		this->resetProgress();
		this->levelsMenu->setEarnedStarsInLevels(earnedStarsInLevels);
	}
	if (this->gameInterface->getIsRestartPressed() && this->isGame)
	{
		buttonSound.play();

		updateEarnedStarsInLevels(this->gameInterface->getEarnedStars());
		this->levelsMenu->setEarnedStarsInLevels(earnedStarsInLevels);

		reloadLevel();
	}
	if (this->gameInterface->getIsMenuPressed() && this->isGame)
	{
		buttonSound.play();

		updateEarnedStarsInLevels(this->gameInterface->getEarnedStars());
		this->levelsMenu->setEarnedStarsInLevels(earnedStarsInLevels);

		moveInLevelsMenu();
	}
	if (this->gameInterface->getIsNextPressed() && this->isGame)
	{
		buttonSound.play();

		updateEarnedStarsInLevels(this->gameInterface->getEarnedStars());
		this->levelsMenu->setEarnedStarsInLevels(earnedStarsInLevels);

		selectedLevel++;

		if (selectedLevel > 20)
		{
			selectedLevel = 20;
			moveInLevelsMenu();
		}
		else
			reloadLevel();
	}
}


Game::Game()
{
	this->initWindow();
	this->initIcon();
	this->initMenu();
	this->initLeaderboard();
	this->initLevelsMenu();
	this->initMap();
	this->initPlayer();
	this->initView();
	this->initInterface();
	this->initSoundBuffer();
	this->initSound();

	this->readProgressFile();
	this->readGamers();
}

Game::~Game()
{
	delete this->player;
}

void Game::update(float time)
{
	while (this->window.pollEvent(this->ev))
	{
		if (ev.type == sf::Event::LostFocus)
		{
			this->windowHasFocus = false;
		}
		else if (ev.type == sf::Event::GainedFocus)
		{
			this->windowHasFocus = true;
		}
		if (levelsMenu->getIsEnterNamePressed()  && this->ev.type == sf::Event::TextEntered)
		{
			switch (this->ev.text.unicode)
			{
			case 0xD: //Return
				break;
			case 0x8://Backspace
				if (playerName.length() != 0)
					playerName.erase(playerName.length() - 1);
				break;
			default:
			{
				if (playerName.length() < 9 && this->ev.text.unicode < 128)
					playerName += static_cast<char>(static_cast<wchar_t>(this->ev.text.unicode));
			}
			}
		}

		if (this->ev.type == sf::Event::Closed)
			this->window.close();
	}


	if (isMenu)
	{
		this->updateMenu();
	}
	else if (isLeaderboard)
	{
		this->updateLeaderboard();
	}
	else if (isLevelsMenu)
	{
		this->updateLevelsMenu();
	}
	else if (isGame) {
		World.Step(1 / 60.f, 8, 3);

		this->updatePlayer(time, map->getMap());
		this->updateView();
		this->updateMap();
		this->updateInterface();
	}

	changeDisplay();
}

void Game::render()
{
	this->window.clear(sf::Color(86, 219, 254, 0));

	//Render game
	if (isMenu)
	{
		this->renderMenu();
	}
	else if (isLevelsMenu)
	{
		this->renderLevelsMenu();
	}
	else if (isLeaderboard)
	{
		this->renderLeaderboard();
	}
	else if (isGame) 
	{
		this->renderMap();
		this->renderPlayer();
		this->map->renderTopRings(window);
		this->renderView();
		this->renderInterface();
	}

	this->window.display();
}


const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
