#include "Player.h"

void Player::animation(float speed)
{
	this->playerSprite.rotate(speed);
}

void Player::checkOnGround(b2World &World)
{
	onGround = false;
	b2Vec2 pos = playerBody->GetPosition();
	pos.y += (ballRadius + 3) / c::SCALE;
	for (int i = -10; i < 11; i++)
	{
		pos.x = playerBody->GetPosition().x;
		pos.x += 20 * i  / 10 / c::SCALE;
		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext())
			for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
				if (f->TestPoint(pos))  onGround = true;
	}
}

void Player::movement(float time, b2World &World)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float  angVel = playerBody->GetAngularVelocity();
	checkOnGround(World);

	playerBody->SetLinearVelocity(b2Vec2(0.f,vel.y));
	playerBody->ApplyTorque(0, false);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right
	{
		if (vel.x < 20) {
			animation(2 * time);
			playerBody->SetLinearVelocity(b2Vec2(4.f * time, vel.y));
			if (angVel < 15)
				playerBody->ApplyTorque(10, false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
	{
		if (vel.x > -20) {
			animation(-2 * time);
			playerBody->SetLinearVelocity(b2Vec2(-4.f * time, vel.y));
			if (angVel > -15)
				playerBody->ApplyTorque(-10, false);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Up
	{
		if (onGround) {
			playerBody->SetLinearVelocity(b2Vec2(vel.x, -7 * time));//-9*time
		}
	}
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Assets/ball_small@2x.png"))
	{
		std::cout << "ERROR::PLYER::Could not load the player sheet!" << std::endl;
	}
}

void Player::initSprite()
{
	this->playerSprite.setTexture(this->textureSheet);
	this->playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
}

Player::Player(b2World &World, b2Vec2 spawnPosition)
{
	this->initTexture();
	this->initSprite();
	this->initBall(World, spawnPosition);
}

Player::~Player()
{

}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

void Player::update(float time, std::string *map, b2World &World, bool inWather)
{
	movement(time, World);
	b2Vec2 pos = playerBody->GetPosition();
	float angle = playerBody->GetAngle();
	playerSprite.setPosition(pos.x * c::SCALE, pos.y * c::SCALE);
	if (inWather)
	{
		//Исправить скорость выталкивания
		b2Vec2 vel = playerBody->GetLinearVelocity();
		playerBody->SetLinearVelocity(b2Vec2(vel.x, vel.y /100 * 60 - 1 * time));
	}
}

void Player::render(sf::RenderTarget& target, b2World& World)
{
	target.draw(this->playerSprite); // было до цикла
}

void Player::initBall(b2World &World, b2Vec2 spawnPosition)
{
	bdef.type = b2_dynamicBody;
	bdef.position.Set(spawnPosition.x / c::SCALE, spawnPosition.y / c::SCALE);
	circle.m_radius = ballRadius/c::SCALE;
	fdef.density = 1; //Задаём плотность 
	fdef.restitution = 0.3; //Задаём упругость
	fdef.friction = 100;
	fdef.shape = &circle; 
	playerBody = World.CreateBody(&bdef);
	playerBody->CreateFixture(&fdef);
	
}
