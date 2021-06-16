#include "Map.h"

void Map::initTextures()
{
	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))  
		std::cout << "ERROR::PLYER::Could not load the Block sheet!" << std::endl;

	if (!this->rightAscentTextureSheet.loadFromFile("Assets/ui_nw_ground_block@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the right ascent sheet!" << std::endl;

	if (!this->leftAscentTextureSheet.loadFromFile("Assets/ui_ne_ground_block@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the left ascent sheet!" << std::endl;

	if (!this->bottomRingTextureSheet.loadFromFile("Assets/ring_small_bottom@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the small bottom ring sheet!" << std::endl;

	if (!this->topRingTextureSheet.loadFromFile("Assets/ring_small_top@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the small top ring sheet!" << std::endl;

	if (!this->catchedBottomRingTextureSheet.loadFromFile("Assets/ring_small_catched_bottom@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the small catched bottom ring sheet!" << std::endl;

	if (!this->catchedTopRingTextureSheet.loadFromFile("Assets/ring_small_catched_top@2x.png"))
		std::cout << "ERROR::PLYER::Could not load the small catched top ring sheet!" << std::endl;
}

void Map::initSprites()
{
	blockSprite.setTexture(blockTextureSheet);
	blockSprite.setScale(1.0 / 125 * 80, 1.0 / 125 * 80);
	rightAscentSprite.setTexture(rightAscentTextureSheet);
	leftAscentSprite.setTexture(leftAscentTextureSheet);
	topRingSprite.setTexture(topRingTextureSheet);
	catchedTopRingSprite.setTexture(catchedTopRingTextureSheet);
	bottomRingSprite.setTexture(bottomRingTextureSheet);
	catchedBottomRingSprite.setTexture(catchedBottomRingTextureSheet);

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

void Map::createRing(b2World& World, int x, int y)
{
	b2PolygonShape block;
	block.SetAsBox(10 / c::SCALE, 9 / c::SCALE);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, (y + 6) / c::SCALE); //bdef.position.Set(x / c::SCALE, (y + 7) / c::SCALE);

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&block, 1);

	bdef.position.Set(x / c::SCALE, (y + 111) / c::SCALE); //bdef.position.Set(x / c::SCALE, (y + 107) / c::SCALE);

	b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&block, 1);
}

void Map::takeRings(sf::Vector2f ballPosition)
{
	for (size_t i = 0; i < size(this->ringsPositions); i++)
	{
		if ((ballPosition.x <= ringsPositions[i].x && ballPosition.x + 45 >= ringsPositions[i].x) && (ballPosition.y - 30 <= ringsPositions[i].y && ballPosition.y + 30 >= ringsPositions[i].y))
		{
			std::cout << "True"  << "\n" << std::endl;
			int row = (static_cast<int>(ringsPositions[i].y) + 20) / c::GRID_SIZE;
			int col = (static_cast<int>(ringsPositions[i].x) + c::GRID_SIZE / 4 - c::GRID_SIZE / 2) / c::GRID_SIZE;
			map[row][col] = 'o';
			ringsCounter--;
			score += 500;
			ringsPositions.erase(ringsPositions.begin() + i );
		}
	}
}

void Map::createBlocks(b2World &World)
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			int x = j * c::GRID_SIZE + c::GRID_SIZE / 2;
			int y = i * c::GRID_SIZE + c::GRID_SIZE / 2;
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
			if (map[i][j] == 'O')
			{
				ringsCounter++;
				ringsPositions.push_back(sf::Vector2f(x + c::GRID_SIZE / 4, y - c::GRID_SIZE / 2 - 20));
				createRing(World, x, y - c::GRID_SIZE - 20);
			}

			if (map[i][j] == ' ')
				continue;
		}
}

Map::Map()
{
	this->initTextures();
	this->initSprites();
}

void Map::render(sf::RenderTarget& target)
{
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
			if (map[i][j] == 'O')
			{
				bottomRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(bottomRingSprite);
			}
			if (map[i][j] == 'o')
			{
				catchedBottomRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(catchedBottomRingSprite);
				
			}
			if (map[i][j] == ' ')
				continue;

		}
}

void Map::update(sf::Vector2f ballPosition)
{
	this->takeRings(ballPosition);
}

void Map::renderTopRings(sf::RenderTarget& target)
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == 'O')
			{
				topRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(topRingSprite);
			}
			if (map[i][j] == 'o')
			{
				catchedTopRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(catchedTopRingSprite);

			}
		}
}

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

std::string *Map::getMap()
{
	return this->map;
}

int Map::getRingsCounter()
{
	return this->ringsCounter;
}

int Map::getScore()
{
	return this->score;
}


