#pragma once
#include "stdafx.h"
#include "Consts.h"

class Player
{
	sf::Sprite playerSprite;
	sf::Texture ballTextureSheet;
	sf::Texture lightBallTextureSheet;
	sf::Texture heavyBallTextureSheet;
	sf::Texture deadBallTextureSheet;

	sf::SoundBuffer jumpBuffer;
	sf::Sound jumpSound;

	sf::SoundBuffer deadBuffer;
	sf::Sound deadSound;

	float ballRadius = 39;

	bool onGround = false;
	bool isLight = false;
	bool isHeavy = false;
	bool isDead = false;

	bool godmodeOn = false;
	bool isGPressed = false;

	bool flyOn = false;
	bool isFPressed = false;

	bool isLastDead = false;

	int timeAfterDead = 0;
	int livesCounter = 3;

	b2BodyDef bdef;
	b2CircleShape circle;
	b2Body* playerBody;
	b2FixtureDef fdef;
	b2Vec2 spawnPosition;

	bool isFirstPause = true;
	b2Vec2 velocityBeforePause;

	std::vector<sf::Vector2f> thornsPositions;
	std::vector<sf::Vector2f> bonusLivesPositions;


	//Core
	void initTexture();
	void initSprite();
	void initSoundBuffer();
	void initSound();
	void initPlayer(b2World &World, b2Vec2 startPosition);
	void initThornsPositions(std::vector<sf::Vector2f> thornsPositions);
	void initBonusLivesPositions(std::vector<sf::Vector2f> bonusLivesPositions);


	void updateIfLife(float time, std::string* map, b2World& World, bool inWather, bool windowHasFocus);
	void updateIfDead(float time, std::string* map, b2World& World, bool inWather);
	

	void setBall(int colorNumber);
	void spawnBall(b2World& World);


	//Interaction with the map
	void checkThorns();
	void takeBonusLives();

	//Animation
	void animation(float speed);
	
	//Movement
	void checkOnGround(b2World& World);
	void movement(float time, b2World& World, bool windowHasFocus);
	void flyMovement(float time, b2World& World, bool windowHasFocus);

public:
	Player(b2World &world, b2Vec2 spawnPosition, std::vector<sf::Vector2f>  thornsPositions, std::vector<sf::Vector2f> bonusLifesPositions);
	virtual ~Player();

	//Functions
 	void update(float time, std::string* map, b2World& World, bool inWather, b2Vec2 spawnPosition, bool isLastRing, bool isPause, bool windowHasFocus);
	void render(sf::RenderTarget& target, b2World& World);

	void setItemsPositions(b2Vec2 spawnPosition, b2World& World, std::vector<sf::Vector2f>  thornsPositions, std::vector<sf::Vector2f> bonusLifesPositions);
	
	sf::Vector2f getPosition();
	int getLivesCounter();
	
	b2Body*& getPlayerBody();
};

