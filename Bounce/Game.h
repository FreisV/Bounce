#pragma once

#include "stdafx.h"
#include "Consts.h"
#include "Menu.h"
#include "Map.h"
#include "Player.h"
#include "Interface.h"
#include "LevelsMenu.h"

class Game
{
	sf::RenderWindow window;
	sf::Event ev;
	sf::View viewInGame;
	sf::View viewInMenu;

	b2Vec2 Gravity{ 0.f, 37.6f};//37,6
	b2World World{Gravity};

	Menu *menu;
	LevelsMenu *levelsMenu;
	Player *player;
	Map *map;
	Interface *gameInterface;

	bool isMenu = true;
	bool isLevelsMenu = false;
	bool isGame = false;

	int selectedLevel = 0;

	int earnedStarsInLevels[20];

	//Test
	int counter = 0;

	void initWindow();
	void initMenu();
	void initLevelsMenu();
	void initPlayer();
	void initMap();
	void initView();
	void initInterface();

	void updateMenu();
	void updateLevelsMenu();
	void updatePlayer(float time, std::string *map);
	void updateView();
	void updateMap();
	void updateInterface();
	void updateEarnedStarsInLevels(int quantityStars);
	
	void renderMenu();
	void renderLevelsMenu();
	void renderPlayer();
	void renderMap();
	void renderView();
	void renderInterface();

	void moveInLevelsMenu();
	void reloadLevel();
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

