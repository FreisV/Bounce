#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bounce", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initPlayer()
{
	this->player = new Player(World, map->getSpawnPosition());
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
	this->view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
}

Game::Game()
{
	this->initWindow();
	this->initMap();
	this->initPlayer();
	this->initView();

}

Game::~Game()
{
	delete this->player;
}

void Game::updatePlayer(float time, std::string *map)
{
	this->player->update(time, map, World);
}

void Game::updateView(float time)
{
	sf::Vector2f playerPosition = player->getPosition();
	sf::Vector2f viewPosition = view.getCenter();
	sf::Vector2f nextPosition = sf::Vector2f(viewPosition.x + (playerPosition.x - viewPosition.x) * 0.1, viewPosition.y + (playerPosition.y - viewPosition.y) * 0.1);
	view.setCenter(nextPosition);
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
	this->updateView(time);
}

void Game::renderView()
{
	this->window.setView(view);
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
	this->renderView();

	this->window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}
