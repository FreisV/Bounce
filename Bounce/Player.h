#pragma once
#include "stdafx.h"
#include "Consts.h"

class Player
{
	sf::Sprite playerSprite;
	sf::Texture ballTextureSheet;
	sf::Texture lightBallTextureSheet;
	sf::Texture heavyBallTextureSheet;

	float ballRadius = 39;
	bool onGround = false;
	bool isLight = false;
	bool isHeavy = false;

	b2BodyDef bdef;
	b2CircleShape circle;
	b2Body* playerBody;
	b2FixtureDef fdef;

	//Animation
	void animation(float speed);
	
	//Movement
	void checkOnGround(b2World& World);
	void movement(float time, b2World& World);

	//Core
	void initTexture();
	void initSprite();
	void initPlayer(b2World &World, b2Vec2 startPosition);
	void setBall(int colorNumber);

public:
	Player(b2World &world, b2Vec2 spawnPosition);
	virtual ~Player();

	//Functions
	sf::Vector2f getPosition();
 	void update(float time, std::string* map, b2World& World, bool inWather);
	void render(sf::RenderTarget& target, b2World& World);
};

