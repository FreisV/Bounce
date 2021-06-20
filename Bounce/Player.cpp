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
	int speedX = 0;
	int speedY = 0;
	float speedAnimation = 0;

	if (isLight)
	{
		speedX = 5.f * time;
		speedY = 9.f * time;
		speedAnimation = 2.25 * time;

	}
	else if (isHeavy)
	{
		speedX = 3.f * time;
		speedY = 5.f * time;
		speedAnimation = 1.5 * time;
	}
	else
	{
		speedX = 4.f * time;
		speedY = 7.f * time;
		speedAnimation = 2 * time;
	}
	playerBody->SetLinearVelocity(b2Vec2(0.f,vel.y));
	playerBody->ApplyTorque(0, false);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right
	{
		if (vel.x < 25) {
			animation(speedAnimation);
			playerBody->SetLinearVelocity(b2Vec2(speedX, vel.y));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
	{
		if (vel.x > -25) {
			animation(-speedAnimation);
			playerBody->SetLinearVelocity(b2Vec2(-speedX, vel.y));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Up
	{
		if (onGround) {
			playerBody->SetLinearVelocity(b2Vec2(vel.x, -speedY));//-9*time
		}
	}
}

void Player::initTexture()
{
	if (!this->ballTextureSheet.loadFromFile("Assets/ball_small@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the ball sheet!" << std::endl;
	
	if (!this->lightBallTextureSheet.loadFromFile("Assets/ball_small_light@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the light ball sheet!" << std::endl;
	
	if (!this->heavyBallTextureSheet.loadFromFile("Assets/ball_small_heavy@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the heavy ball sheet!" << std::endl;

	if (!this->deadBallTextureSheet.loadFromFile("Assets/ball_pop@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the dead ball sheet!" << std::endl;
}

void Player::initSprite()
{
	this->playerSprite.setTexture(this->ballTextureSheet);
	this->playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
}

void Player::initPlayer(b2World &World, b2Vec2 spawnPosition)
{
	bdef.type = b2_dynamicBody;
	bdef.position.Set(spawnPosition.x / c::SCALE, spawnPosition.y / c::SCALE);
	this->spawnPosition = spawnPosition;
	circle.m_radius = ballRadius/c::SCALE;
	fdef.density = 1; //Задаём плотность 
	fdef.restitution = 0.3; //Задаём упругость
	fdef.friction = 100;
	fdef.shape = &circle; 
	playerBody = World.CreateBody(&bdef);
	playerBody->CreateFixture(&fdef);
	
}

void Player::checkThorns()
{
	sf::Vector2f ballPos = playerSprite.getPosition();
	for (auto thorn : this->thornsPositions) 
		if ((ballPos.x - 40 <= thorn.x + 42 && ballPos.x + 40 >= thorn.x) && (ballPos.y - 41 <= thorn.y + c::GRID_SIZE && ballPos.y + 42 >= thorn.y))
		{
			isDead = true;
			livesCounter--;
			timeAfterDead = 50;
			playerSprite.setTexture(deadBallTextureSheet);
			break;
		}
}

void Player::takeBonusLives()
{
	sf::Vector2f ballPos = playerSprite.getPosition();
	for (size_t i = 0; i < size(bonusLivesPositions); i++)
		if ((ballPos.x - ballRadius <= bonusLivesPositions[i].x + c::GRID_SIZE && ballPos.x + ballRadius >= bonusLivesPositions[i].x) && (ballPos.y - ballRadius <= bonusLivesPositions[i].y + c::GRID_SIZE && ballPos.y + ballRadius >= bonusLivesPositions[i].y))
		{
			livesCounter++;
			bonusLivesPositions.erase(bonusLivesPositions.begin() + i);
			break;
		}
}

void Player::initThornsPositions(std::vector<sf::Vector2f> thornsPositions)
{
	this->thornsPositions.clear();
	for (size_t i = 0; i < size(thornsPositions); i++)
		this->thornsPositions.push_back(thornsPositions[i]);
}

void Player::initBonusLivesPositions(std::vector<sf::Vector2f> bonusLivesPositions)
{
	this->bonusLivesPositions.clear();
	for (size_t i = 0; i < size(bonusLivesPositions); i++)
		this->bonusLivesPositions.push_back(bonusLivesPositions[i]);
}

Player::Player(b2World &World, b2Vec2 spawnPosition, std::vector<sf::Vector2f> thornsPositions, std::vector<sf::Vector2f> bonusLifesPositions)
{
	this->initTexture();
	this->initSprite();
	this->initPlayer(World, spawnPosition);
	this->initThornsPositions(thornsPositions);
	this->initBonusLivesPositions(bonusLifesPositions);
}

Player::~Player()
{

}


void Player::updateIfLife(float time, std::string* map, b2World& World, bool inWather)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		setBall(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		setBall(2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		setBall(3);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		godmodeOn = godmodeOn ? false : true;

	movement(time, World);
	takeBonusLives();

	b2Vec2 pos = playerBody->GetPosition();
	float angle = playerBody->GetAngle();

	playerSprite.setPosition(pos.x * c::SCALE, pos.y * c::SCALE);

	if (inWather && !isHeavy)
	{
		b2Vec2 vel = playerBody->GetLinearVelocity();
		playerBody->SetLinearVelocity(b2Vec2(vel.x, vel.y / 100 * 60 - 1 * time));
	}
}

void Player::updateIfDead(float time, std::string* map, b2World& World, bool inWather)
{
	if (timeAfterDead > 0)
	{
		//playerSprite.setPosition(pos.x * c::SCALE, pos.y * c::SCALE);
		timeAfterDead--;
	}
	else
	{

		spawnBall(World);

		if (isLight)
			setBall(2);
		else if (isHeavy)
			setBall(3);
		else
			setBall(1);
	}
}

void Player::update(float time, std::string *map, b2World &World, bool inWather, b2Vec2 spawnPosition)
{
	if (!isDead)
	{
		updateIfLife(time, map, World, inWather);
		if (!godmodeOn)
			checkThorns();
	}
	else if (isDead)
		updateIfDead(time, map, World, inWather);

	this->spawnPosition = spawnPosition;
}	

void Player::render(sf::RenderTarget& target, b2World& World)
{
	target.draw(this->playerSprite); // было до цикла
}

void Player::setItemsPositions(b2Vec2 spawnPosition, b2World& World, std::vector<sf::Vector2f> thornsPositions, std::vector<sf::Vector2f> bonusLifesPositions)
{
	this->spawnPosition = spawnPosition;
	spawnBall(World);
	this->initThornsPositions(thornsPositions);
	this->initBonusLivesPositions(bonusLifesPositions);
}

void Player::setBall(int colorNumber)
{
	isLight = false;
	isHeavy = false;
	switch (colorNumber)
	{
	case 1:
	{
		playerSprite.setTexture(ballTextureSheet);
		break;
	}
	case 2:
	{
		playerSprite.setTexture(lightBallTextureSheet);
		isLight = true;
		break;
	}
	case 3:
	{
		playerSprite.setTexture(heavyBallTextureSheet);
		isHeavy = true;
		break;
	}
	default:
		break;
	}
}

void Player::spawnBall(b2World& World)
{
	bdef.position.Set((spawnPosition.x + c::GRID_SIZE / 2) / c::SCALE, (spawnPosition.y + c::GRID_SIZE / 2) / c::SCALE);
	World.DestroyBody(playerBody);
	playerBody = World.CreateBody(&bdef);
	playerBody->CreateFixture(&fdef);
	isDead = false;
}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

int Player::getLivesCounter()
{
	return this->livesCounter;
}
