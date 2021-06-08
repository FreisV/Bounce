#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(1440, 960), "Bounce", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initPlayer()
{
	this->player = new Player(World);
}

void Game::initMap()
{
	this->map = new Map();
	this->map->createBlocks(World);
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initMap();

}

Game::~Game()
{
	delete this->player;
}

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World);
}

void Game::update(float time)
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if(this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
	}

	World.Step(1 / 60.f, 8, 3);
	this->updatePlayer(time, map->setMap());
}

void Game::renderPlayer()
{
	this->player->render(this->window, World);
}

void Game::renderMap()
{
	this->map->render(this->window);
}

void Game::render()
{
	this->window.clear(sf::Color(125, 184, 209, 0));

	//Render game
	this->renderPlayer();
	this->renderMap();

	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
