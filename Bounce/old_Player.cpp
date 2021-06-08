#include "stdafx.h"
#include "Player.h"

void Player::animation(float speed)
{
	this->sprite.rotate(speed);
}

void Player::gravity(float time, std::string* map)
{
	float positionX = sprite.getPosition().x + ballSize; //float positionX = this->sprite.getPosition().x; 
	float positionY = sprite.getPosition().y + ballSize; //float positionY = this->sprite.getPosition().y;
	const float acceleration = 0.04;
	float ground = 850;

	positionX += speedX * time;

	/*if (checkCollisionX(map))
	{
		std::cout << "_______________________" << std::endl;
		positionX = collisionX(map) + ballSize;
	}
	else if (checkCollision(map, positionX + 0.0001f, positionY - 0.0001f))
	{
		std::cout << ")))))))))))))))))))))))" << std::endl;
		positionX -= speedX * time;
	}*/

	if (!onGround)
		speedY = speedY + acceleration * time;

	positionY += speedY * time;

	onGround = false;

	//positionY = checkCollisionY(map) ? collisionY(map) + ballSize : positionY;

	/*if (checkCollisionY(map))
		positionY = collisionY(map) + ballSize;
	else if (checkCollisionY(map, positionX + 0.0001f, positionY + 0.0001f))
		positionY -= speedX * time;*/


	if (positionY > ground)
	{
		switch (rebounceCounter) //
		{
		case 3:
		{
			positionY = ground;
			speedY = -2.0f;
			onGround = true;
			break;
		}
		case 2:
		{
			positionY = ground;
			speedY = -1.5f;
			onGround = true;
			break;
		}
		case 1:
		{
			positionY = ground;
			speedY = -0.5f;
			onGround = true;
			break;
		}
		default:
			positionY = ground;
			speedY = 0;
			onGround = true;
			break;
		}
		rebounceCounter--;
	}

	sprite.setPosition(positionX - ballSize, positionY - ballSize);
	speedX = 0;

}

void Player::movement(float time)
{
	float speed = 2.0f * time;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Up
	{
		if (onGround)
		{
			this->speedY = -6.0f;
			rebounceCounter = 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
	{
		animation(-speed);
		this->speedX = -2.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right
	{
		animation(speed);
		this->speedX = +2.0f;
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
	this->sprite.setTexture(this->textureSheet);
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	this->sprite.setPosition(160, 160);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::update(float time, std::string* map)
{
	movement(time);
	gravity(time, map);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}












//
//bool Player::checkCollision(std::string* map, float positionX, float positionY)
//{
//	float centerX = positionX == 0 ? sprite.getPosition().x : positionX - ballSize;
//	float centerY = positionY == 0 ? sprite.getPosition().y : positionY - ballSize;
//
//	for (int i = (centerY - ballSize) / 80; i < (centerY + ballSize -1) / 80; i++)
//		for (int j = (centerX - ballSize) / 80; j < (centerX + ballSize) / 80; j++)
//			if (map[i][j] == 'B')
//			{
//				return true;
//			}
//
//	return false;
//}
//
//bool Player::checkCollisionX(std::string* map, float positionX, float positionY)
//{
//	float centerX = positionX == 0 ? sprite.getPosition().x : positionX - ballSize;
//	float centerY = positionY == 0 ? sprite.getPosition().y : positionY - ballSize + 1;
//
//	int i = (centerY) / 80;
//		for (int j = (centerX - ballSize) / 80; j < (centerX + ballSize) / 80; j++)
//			if (map[i][j] == 'B')
//			{
//				return true;
//			}
//
//	return false;
//}
//
//bool Player::checkCollisionY(std::string* map, float positionX, float positionY)
//{
//	float centerX = positionX == 0 ? sprite.getPosition().x : positionX - ballSize;
//	float centerY = positionY == 0 ? sprite.getPosition().y : positionY - ballSize;
//
//	for (float i = (centerY - ballSize)+0.01; i < (centerY + ballSize); i+=0.1)
//	{
//		float baleX1 =sqrt(pow(ballSize, 2) - pow(i - centerY, 2)) + centerX;
//		float baleX2 = -sqrt(pow(ballSize, 2) - pow(i - centerY, 2)) + centerX;
//		if (map[(int)(i/80)][(int)(baleX1/80)] == 'B'||map[(int)(i / 80)][(int)(baleX2 / 80)] == 'B')
//		{
//			return true;
//		}
//	}
//
//	/*int j = (centerX) / 80;
//	for (int i = (centerY - ballSize) / 80; i < (centerY + ballSize) / 80; i++)
//		if (map[i][j] == 'B')
//			return true;*/
//
//	return false;
//}
//
//
//float Player::collisionX(std::string *map)
//{
//	float centerX = sprite.getPosition().x;
//	float centerY = sprite.getPosition().y;
//
//	for (int i = (centerY - ballSize)/80; i < (centerY + ballSize)/80 ; i++)
//		for (int j = (centerX - ballSize)/80; j < (centerX + ballSize)/80; j++)
//		{
//			if (map[i][j] == 'B')
//			{
//				if (speedX < 0)
//					return j * 80 + 80 + ballSize;
//				if (speedX > 0)
//					return j * 80 - ballSize;
//			}
//		}
//}
//
//float Player::collisionY(std::string *map)
//{
//	float centerX = sprite.getPosition().x;
//	float centerY = sprite.getPosition().y;
//
//	for (int i = (centerY - ballSize) / 80; i < (centerY + ballSize) / 80; i++)
//		for (int j = (centerX - ballSize) / 80; j < (centerX + ballSize) / 80; j++)
//		{
//			if (map[i][j] == 'B')
//			{
//				if (speedY < 0)
//				{
//					std::cout << "UP:   " << i * 80 + 80 + ballSize << std::endl;
//					return i * 80 + 80 + ballSize;
//				}
//				if (speedY > 0)
//				{
//					std::cout << "DOWN:   " << i * 80 + 80 + ballSize << std::endl;
//					bounces();
//					return i * 80 - ballSize;
//				}
//			}
//		}
//}
//
//void Player::bounces()
//{
//	switch (rebounceCounter) 
//	{
//	case 3:
//	{
//		speedY = -1.0f;
//		onGround = true;
//	}
//	case 2:
//	{
//		speedY = -0.5f;
//		onGround = true;
//	}
//	case 1:
//	{
//		speedY = -0.1f;
//		onGround = true;
//	}
//	default:
//		speedY = 0;
//		onGround = true;
//	}
//	rebounceCounter--;
//}
//