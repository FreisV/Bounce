#pragma once

#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Consts.h"

class Game
{
	sf::RenderWindow window;
	sf::Event ev;

	b2Vec2 Gravity{ 0.f, 37.6f};//60

	b2World World{Gravity};

	Player *player;
	Map* map;

	void initWindow();
	void initPlayer();
	void initMap();

public:
	//Functions
	Game();
	virtual  ~Game();

	//Functions
	void updatePlayer(float time, std::string *map);
	void update(float time);
	void renderPlayer();
	void renderMap();
	void render();
	const sf::RenderWindow& getWindow() const;
};

