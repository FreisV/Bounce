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

void Game::initInterface()
{
	this->gameInterface = new Interface();
}

void Game::initMenu()
{
	this->menu = new Menu;
}

void Game::initLevelsMenu()
{
	this->levelsMenu = new LevelsMenu;
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

}

Game::~Game()
{
	delete this->player;
}

void Game::updateMenu()
{
	this->menu->update();
}

void Game::updateLevelsMenu()
{
	this->levelsMenu->update();
}

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World, this->map->getInWather(), this->map->getSpawnPosition(), this->gameInterface->getIsLastRing());
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

void Game::moveInLevelsMenu()
{
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
	if (menu->checkPlayPressed() && isMenu)
	{
		isMenu = false;
		isLevelsMenu = true;

	}
	if (levelsMenu->getIsLevelSelected() && this->isLevelsMenu)
	{
		isLevelsMenu = false;
		selectedLevel = levelsMenu->getSelectedLevel();
		isGame = true;

		this->map->setMap(selectedLevel);
		this->map->createBlocks(World);
		this->player->setItemsPositions(map->getSpawnPosition(), World, map->getThornsPositions(), map->getBonusLivesPositions());
	}
	if (levelsMenu->getIsBackPressed() && this->isLevelsMenu)
	{
		isMenu = true;
		isLevelsMenu = false;
	}
	if (this->gameInterface->getIsRestartPressed() && this->isGame)
	{
		reloadLevel();
	}
	if (this->gameInterface->getIsMenuPressed() && this->isGame)
	{
		moveInLevelsMenu();
	}
	if (this->gameInterface->getIsNextPressed() && this->isGame)
	{
		selectedLevel++;

		if (selectedLevel > 20)
		{
			selectedLevel = 20;
			moveInLevelsMenu();
		}
		else
		{
			reloadLevel();
		}
	}

}

void Game::update(float time)
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
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
