#pragma once
#include "stdafx.h"
#include "Consts.h"

class Player
{
	sf::Sprite playerSprite;
	sf::Texture textureSheet;
	float speedX = 0;
	float speedY = 0;
	float ballRadius = 39;
	bool onGround = false;

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
	void initBall(b2World &World);


public:
	Player(b2World &world);
	virtual ~Player();

	//Functions
	
	void update(float time, std::string *map, b2World &World);
	void render(sf::RenderTarget& target, b2World& World);
};

