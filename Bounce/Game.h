#pragma once

#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Consts.h"
#include "Interface.h"

class Game
{
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1080;

	sf::RenderWindow window;
	sf::Event ev;
	sf::View view;

	b2Vec2 Gravity{ 0.f, 37.6f};//37,6

	b2World World{Gravity};

	Player *player;
	Map *map;
	Interface *interface;

	void initWindow();
	void initPlayer();
	void initMap();
	void initView();
	void initInterface();

public:
	//Functions
	Game();
	virtual  ~Game();

	//Functions
	void updatePlayer(float time, std::string *map);
	void updateView();
	void updateMap();
	void updateInterface();
	void update(float time);
	void renderPlayer();
	void renderMap();
	void renderView();
	void renderInterface();
	void render();
	const sf::RenderWindow& getWindow() const;
};

