#include "Game.h"
#include "Consts.h"

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
	this->map->createBlocks(World);
}

void Game::initView()
{
	b2Vec2 pos = map->getSpawnPosition();
	this->view.setCenter(pos.x, pos.y);
	this->view.setSize(sf::Vector2f(c::WINDOW_WIDTH, c::WINDOW_HEIGHT));
}

void Game::initInterface()
{
	this->interface = new Interface();
}

void Game::initMenu()
{
	this->menu = new Menu;
}

Game::Game()
{
	this->initWindow();
	this->initMenu();
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

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World, this->map->getInWather(), this->map->getSpawnPosition());
}

void Game::updateView()
{
	sf::Vector2f playerPosition = player->getPosition();
	sf::Vector2f viewPosition = view.getCenter();
	sf::Vector2f nextPosition = sf::Vector2f(viewPosition.x + (playerPosition.x - viewPosition.x) * 0.1, viewPosition.y + (playerPosition.y - viewPosition.y) * 0.1);
	view.setCenter(nextPosition);
}

void Game::updateMap()
{
	map->update(player->getPosition());
}

void Game::updateInterface()
{
	interface->update(view.getCenter(), map->getScore(), player->getLivesCounter());
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

	changeDisplay();

	if (isMenu)
	{
		this->updateMenu();
	}
	else if (isGame) {
		World.Step(1 / 60.f, 8, 3);

		this->updatePlayer(time, map->getMap());
		this->updateView();
		this->updateMap();
		this->updateInterface();
	}
	
}

void Game::renderMenu()
{
	this->menu->render(window);
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
	this->window.setView(view);
}

void Game::renderInterface()
{
	int ringsCounter = map->getRingsCounter();
	this->interface->render(window, view.getCenter(), ringsCounter);
}

void Game::changeDisplay()
{
	if (menu->isPlayButtonPressed())
	{
		isMenu = false;
		isGame = true;
	}
}

void Game::render()
{
	this->window.clear(sf::Color(86, 219, 254, 0));

	//Render game
	if (isMenu)
	{
		this->renderMenu();
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
