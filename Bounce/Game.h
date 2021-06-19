#pragma once

#include "stdafx.h"
#include "Player.h"
#include "Map.h"
#include "Consts.h"
#include "Interface.h"
#include "Menu.h"

class Game
{
	sf::RenderWindow window;
	sf::Event ev;
	sf::View view;

	b2Vec2 Gravity{ 0.f, 37.6f};//37,6
	b2World World{Gravity};

	Player *player;
	Map *map;
	Interface *interface;
	Menu* menu;

	bool isMenu = true;
	bool isGame = false;

	void initWindow();
	void initPlayer();
	void initMap();
	void initView();
	void initInterface();
	void initMenu();

	void updateMenu();
	void updatePlayer(float time, std::string *map);
	void updateView();
	void updateMap();
	void updateInterface();
	
	void renderMenu();
	void renderPlayer();
	void renderMap();
	void renderView();
	void renderInterface();

	void changeDisplay();

public:
	//Functions
	Game();
	virtual  ~Game();

	//Functions
	void update(float time);
	void render();
	const sf::RenderWindow& getWindow() const;
};

