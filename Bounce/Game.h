#pragma once

#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Consts.h"

class Game
{
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1080;

	sf::RenderWindow window;
	sf::Event ev;
	sf::View view;

	b2Vec2 Gravity{ 0.f, 37.6f};//60

	b2World World{Gravity};

	Player *player;
	Map* map;

	void initWindow();
	void initPlayer();
	void initMap();
	void initView();

public:
	//Functions
	Game();
	virtual  ~Game();

	//Functions
	void updatePlayer(float time, std::string *map);
	void updateView(float time);
	void update(float time);
	void renderPlayer();
	void renderMap();
	void renderView();
	void render();
	const sf::RenderWindow& getWindow() const;
};

