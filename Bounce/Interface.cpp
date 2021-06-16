#include "Interface.h"

void Interface::initTextures()
{
	if (!this->ringTextureSheet.loadFromFile("Assets/ring_small@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the ring sheet!" << std::endl;
}

void Interface::initSprites()
{
	this->ringSprite.setTexture(ringTextureSheet);
	//this->ringSprite.setScale(1.0 / 40 * 30, 1.0 / 120 * 80);

}

Interface::Interface()
{
	this->initTextures();
	this->initSprites();
}


void Interface::update()
{
}

void Interface::render(sf::RenderTarget& target, sf::Vector2f viewPosition, int ringsCounter)
{
	ringSprite.setPosition(viewPosition.x - 960, viewPosition.y - 500);
	for (int i = 0; i < ringsCounter; i++)
	{
		ringSprite.move(50, 0);
		target.draw(ringSprite);
	}
}

