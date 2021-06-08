#include "Map.h"

void Map::initTexture()
{
	if (!this->textureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))  
		std::cout << "ERROR::PLYER::Could not load the Block sheet!" << std::endl;
}

void Map::createBlock(b2World &World, int x, int y, int w, int h)
{
	b2PolygonShape block;
	block.SetAsBox(w/c::SCALE, h/c::SCALE);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, y / c::SCALE);

	b2FixtureDef fdef;
	fdef.friction = 100;
	fdef.shape = &block;

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&fdef); 
}

void Map::createBlocks(b2World &World)
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			int x = j * 80 + c::GRID_SIZE / 2;
			int y = i * 80 + c::GRID_SIZE / 2;
			if (map[i][j] == 'B')
			{
				createBlock(World, x, y, c::GRID_SIZE / 2, c::GRID_SIZE / 2);
			}
			if (map[i][j] == ' ')
				continue;
		}
}

void Map::render(sf::RenderTarget& target)
{
	initTexture();

	for(int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == 'B')
			{
				blockSprite.setTexture(this->textureSheet);
				blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
			}
			if (map[i][j] == ' ')
				continue;

			blockSprite.setPosition(j * 80, i * 80);
			target.draw(blockSprite);
		}
}

sf::FloatRect Map::getBlockBounds()
{
	return sf::FloatRect() ;
}

std::string *Map::setMap()
{
	return this->map;
}


