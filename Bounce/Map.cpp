#include "Map.h"

void Map::initTextures()
{
	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))  
		std::cout << "ERROR::PLYER::Could not load the Block sheet!" << std::endl;

	if (!this->rightAscentTextureSheet.loadFromFile("Assets/ui_nw_ground_block@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the Block sheet!" << std::endl;

	if (!this->leftAscentTextureSheet.loadFromFile("Assets/ui_ne_ground_block@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the Block sheet!" << std::endl;

}

void Map::initSprites()
{
	blockSprite.setTexture(this->blockTextureSheet);
	blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
	rightAscentSprite.setTexture(this->rightAscentTextureSheet);
	leftAscentSprite.setTexture(this->leftAscentTextureSheet);



}

void Map::createBlock(b2World &World, int x, int y)
{
	b2PolygonShape block;
	block.SetAsBox(c::GRID_SIZE / 2 / c::SCALE, c::GRID_SIZE / 2 / c::SCALE);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, y / c::SCALE);

	b2FixtureDef fdef;
	fdef.friction = 100;
	fdef.shape = &block;

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&fdef); 
}

void Map::createRightAscent(b2World& World, int x, int y)
{
	x = x - c::GRID_SIZE / 2;
	y = y + c::GRID_SIZE / 2;
	b2PolygonShape rightAscent;

	b2Vec2 vertices[3];
	vertices[0].Set(0, 0);
	vertices[1].Set(80/c::SCALE, 0);
	vertices[2].Set(80 / c::SCALE, -80 / c::SCALE);
	
	rightAscent.Set(vertices, 3);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, y / c::SCALE);

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&rightAscent,1);

}

void Map::createLeftAscent(b2World& World, int x, int y)
{
	x = x - c::GRID_SIZE / 2;
	y = y + c::GRID_SIZE / 2;
	b2PolygonShape rightAscent;

	b2Vec2 vertices[3];
	vertices[0].Set(0, 0);
	vertices[1].Set(0, -80 / c::SCALE);
	vertices[2].Set(80 / c::SCALE,0);

	rightAscent.Set(vertices, 3);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, y / c::SCALE);

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&rightAscent, 1);
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
				createBlock(World, x, y);
			}
			if (map[i][j] == 'R')
			{
				createRightAscent(World, x, y);
			}
			if (map[i][j] == 'L')
			{
				createLeftAscent(World, x, y);
			}
			if (map[i][j] == ' ')
				continue;
		}
}

void Map::render(sf::RenderTarget& target)
{
	initTextures();
	initSprites();

	for(int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == 'B')
			{
				blockSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(blockSprite);
			}
			if (map[i][j] == 'R')
			{
				rightAscentSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(rightAscentSprite);
			}
			if (map[i][j] == 'L')
			{
				leftAscentSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(leftAscentSprite);
			}
			if (map[i][j] == ' ')
				continue;

		}
}


//Need finish this function, change return type and deside how ball will be spawn after dead
b2Vec2 Map::getSpawnPosition()
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
			if (map[i][j] == 'P')
				return b2Vec2(j * 80, i * 80);
}

sf::FloatRect Map::getBlockBounds()
{
	return sf::FloatRect() ;
}

std::string *Map::setMap()
{
	return this->map;
}


