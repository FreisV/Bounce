#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(c::WINDOW_WIDTH, c::WINDOW_HEIGHT), "Bounce", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
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
		std::cout << "ERROR::PLAYER::Could not load the button sound !" << std::endl;
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
	while (std::getline(F, str)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
		std::cout << str << std::endl; // выводим на экран
		gamers[counter++] = str;
	}
	F.close();
}

void Game::addGamer()
{

	std::string newGamer = "";

	newGamer += playerName;
	playerName = "";

	std::cout << newGamer << std::endl;

	for (int i = 0; i < 5; i++)
		if (gamers[i] == "" || i == 4)
		{
			std::cout << "i: " << i << std::endl;
 			for (int j = i; j >= 0; j--)
			{
				if (j == 0)
					gamers[j] = newGamer;
				else
				{
					
					gamers[j] = gamers[j - 1];
					std::cout << "j: " << gamers[j] << std::endl;
				}
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
		}
		F << "\n";
	}
	F.close();

	readGamers();
}


void Game::updateMenu()
{
	this->menu->update();
}

void Game::updateLevelsMenu()
{
	this->levelsMenu->update(this->playerName);
}

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World, this->map->getInWather(), this->map->getSpawnPosition(), this->gameInterface->getIsLastRing(), this->gameInterface->getIsPause());
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
	this->gameInterface->update(viewInGame.getCenter(), map->getScore(), player->getLivesCounter(), map->getMaxScore(), map->getMaxLives());
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
	if (this->menu->checkExitPressed() && this->isMenu)
	{
		buttonSound.play();

		window.close();
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
		buttonSound.play();

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
	this->initMenu();
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
		//else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
		//	this->window.close();
	}


	if (isMenu)
	{
		this->updateMenu();
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
