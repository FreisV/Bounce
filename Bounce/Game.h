#pragma once

#include "stdafx.h"
#include "Consts.h"
#include "Menu.h"
#include "Leaderboard.h"
#include "Map.h"
#include "Player.h"
#include "Interface.h"
#include "LevelsMenu.h"
#include <ctime>
#include <chrono>

class Game
{
	sf::RenderWindow window;
	sf::Event ev;
	sf::View viewInGame;
	sf::View viewInMenu;

	b2Vec2 Gravity{ 0.f, 37.6f};//37,6
	b2World World{Gravity};

	Menu *menu;
	Leaderboard* leaderboard;
	LevelsMenu *levelsMenu;
	Player *player;
	Map *map;
	Interface *gameInterface;

	sf::SoundBuffer buttonBuffer;
	sf::Sound buttonSound;

	std::string playerName;

	bool isMenu = true;
	bool isLevelsMenu = false;
	bool isGame = false;
	bool isLeaderboard = false;

	int selectedLevel = 0;

	int earnedStarsInLevels[20];
	std::string gamers[5];

	void initWindow();
	void initMenu();
	void initLeaderboard();
	void initLevelsMenu();
	void initPlayer();
	void initMap();
	void initView();
	void initInterface();
	void initSoundBuffer();
	void initSound();

	void readProgressFile();
	void changeProgressFile();
	void resetProgress();
	void readGamers();
	void addGamer();

	void updateMenu();
	void updateLeaderboard();
	void updateLevelsMenu();
	void updatePlayer(float time, std::string *map);
	void updateView();
	void updateMap();
	void updateInterface();
	void updateEarnedStarsInLevels(int quantityStars);
	
	void renderMenu();
	void renderLeaderboard();
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

