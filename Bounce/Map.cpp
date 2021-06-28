 #include "Map.h"

void Map::initTextures()
{
	if (!this->blockTextureSheet.loadFromFile("Assets/ui_ground_block@2x.png"))  
		std::cout << "ERROR::MAP::Could not load the Block sheet!" << std::endl;

	if (!this->rightAscentTextureSheet.loadFromFile("Assets/ui_nw_ground_block@2x.png"))
		std::cout << "ERROR::MAP::Could not load the right ascent sheet!" << std::endl;

	if (!this->leftAscentTextureSheet.loadFromFile("Assets/ui_ne_ground_block@2x.png"))
		std::cout << "ERROR::MAP::Could not load the left ascent sheet!" << std::endl;

	if (!this->bottomRingTextureSheet.loadFromFile("Assets/ring_small_bottom@2x.png"))
		std::cout << "ERROR::MAP::Could not load the small bottom ring sheet!" << std::endl;

	if (!this->topRingTextureSheet.loadFromFile("Assets/ring_small_top@2x.png"))
		std::cout << "ERROR::MAP::Could not load the small top ring sheet!" << std::endl;

	if (!this->catchedBottomRingTextureSheet.loadFromFile("Assets/ring_small_catched_bottom@2x.png"))
		std::cout << "ERROR::MAP::Could not load the small catched bottom ring sheet!" << std::endl;

	if (!this->catchedTopRingTextureSheet.loadFromFile("Assets/ring_small_catched_top@2x.png"))
		std::cout << "ERROR::MAP::Could not load the small catched top ring sheet!" << std::endl;

	if (!this->thornTextureSheet.loadFromFile("Assets/thorn@2x.png"))
		std::cout << "ERROR::MAP::Could not load the thorn sheet!" << std::endl;

	if (!this->checkpointTextureSheet.loadFromFile("Assets/checkpoint@2x.png"))
		std::cout << "ERROR::MAP::Could not load the checkpoint sheet!" << std::endl;

	if (!this->catchedCheckpointTextureSheet.loadFromFile("Assets/checkpoint_catched@2x.png"))
		std::cout << "ERROR::MAP::Could not load the catched checkpoint sheet!" << std::endl;

	if (!this->bonusLifeTextureSheet.loadFromFile("Assets/life@2x.png"))
		std::cout << "ERROR::MAP::Could not load the life sheet!" << std::endl;
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

	watherSprite.setFillColor(sf::Color::Blue);
	watherSprite.setSize(sf::Vector2f(c::GRID_SIZE, c::GRID_SIZE));

	thornSprite.setTexture(thornTextureSheet);
	invertedThornSprite.setTexture(thornTextureSheet);
	invertedThornSprite.rotate(180);

	checkpointSprite.setTexture(checkpointTextureSheet);
	catchedCheckpointSprite.setTexture(catchedCheckpointTextureSheet);

	bonusLifeSprite.setTexture(bonusLifeTextureSheet);
}

void Map::initSoundBuffer()
{
	if (!this->takeRingBuffer.loadFromFile("Assets/Sound/PickupRing.wav"))
		std::cout << "ERROR::MAP::Could not load the take ringsound !" << std::endl;

	if (!this->takeItemBuffer.loadFromFile("Assets/Sound/PickupItem.wav"))
		std::cout << "ERROR::MAP::Could not load the take item sound !" << std::endl;
}

void Map::initSound()
{
	takeRingSound.setBuffer(takeRingBuffer);
	takeItemSound.setBuffer(takeItemBuffer);
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

	bodyList.push_back(b_ground);
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

	bodyList.push_back(b_ground);
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

	bodyList.push_back(b_ground);
}

void Map::createRing(b2World& World, int x, int y)
{
	b2PolygonShape block;
	block.SetAsBox(10 / c::SCALE, 9 / c::SCALE);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, (y + 6) / c::SCALE); //bdef.position.Set(x / c::SCALE, (y + 7) / c::SCALE);

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&block, 1);

	bodyList.push_back(b_ground);
	
	bdef.position.Set(x / c::SCALE, (y + 111) / c::SCALE); //bdef.position.Set(x / c::SCALE, (y + 107) / c::SCALE);

	b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&block, 1);

	bodyList.push_back(b_ground);
}

void Map::createThorn(b2World& World, int x, int y)
{
	b2PolygonShape thorn;
	thorn.SetAsBox(c::GRID_SIZE / 4 / c::SCALE, c::GRID_SIZE / 2 / c::SCALE);

	b2BodyDef bdef;
	bdef.position.Set(x / c::SCALE, y / c::SCALE);

	b2Body* b_ground = World.CreateBody(&bdef);
	b_ground->CreateFixture(&thorn, 1);

	bodyList.push_back(b_ground);
}


void Map::takeRings(sf::Vector2f playerPosition)
{
	for (size_t i = 0; i < size(this->ringsPositions); i++)
		if ((playerPosition.x <= ringsPositions[i].x && playerPosition.x + 45 >= ringsPositions[i].x) && (playerPosition.y - 30 <= ringsPositions[i].y && playerPosition.y + 30 >= ringsPositions[i].y))
		{
			takeRingSound.play();
			int row = (static_cast<int>(ringsPositions[i].y) + 20) / c::GRID_SIZE;
			int col = (static_cast<int>(ringsPositions[i].x) + c::GRID_SIZE / 4 - c::GRID_SIZE / 2) / c::GRID_SIZE;
			map[row][col] = 'o';
			ringsCounter--;
			score += 500;
			ringsPositions.erase(ringsPositions.begin() + i);
		}
}

void Map::checkInWather(sf::Vector2f playerPosition)
{
	inWather = false;
	for (auto pos : watherPositions)
		if ((playerPosition.x >= pos.x && playerPosition.x <= pos.x + c::GRID_SIZE) && (playerPosition.y >= pos.y && playerPosition.y<= pos.y + c::GRID_SIZE))
			inWather = true;
}

void Map::takeCheckpoints(sf::Vector2f playerPosition)
{
	
	for (size_t i = 0; i < size(this->checkpointsPositions); i++)
		if ((playerPosition.x - 39 <= checkpointsPositions[i].x + c::GRID_SIZE && playerPosition.x + 39 >= checkpointsPositions[i].x) && (playerPosition.y - 39 <= checkpointsPositions[i].y + c::GRID_SIZE && playerPosition.y + 39 >= checkpointsPositions[i].y))
		{
			takeItemSound.play();
			b2Vec2 spawnPosition = getSpawnPosition();
			int removeSpawnY = static_cast<int>(spawnPosition.y) / c::GRID_SIZE;
			int removeSpawnX = static_cast<int>(spawnPosition.x) / c::GRID_SIZE;
			map[removeSpawnY][removeSpawnX] = ' ';
			int row = (static_cast<int>(checkpointsPositions[i].y)) / c::GRID_SIZE;
			int col = (static_cast<int>(checkpointsPositions[i].x)) / c::GRID_SIZE;
			map[row][col] = 'P';
			score += 500;
			checkpointsPositions.erase(checkpointsPositions.begin() + i);
		}
}

void Map::takeBonusLives(sf::Vector2f playerPosition)
{
	sf::Vector2f ballPos = playerPosition;
	for (size_t i = 0; i < size(bonusLivesPositions); i++)
		if ((playerPosition.x - 39 <= bonusLivesPositions[i].x + c::GRID_SIZE && playerPosition.x + 39>= bonusLivesPositions[i].x) && (playerPosition.y - 39 <= bonusLivesPositions[i].y + c::GRID_SIZE && playerPosition.y + 39 >= bonusLivesPositions[i].y))
		{
			takeItemSound.play();
			int bonusLifeX = static_cast<int>(bonusLivesPositions[i].x) / c::GRID_SIZE;
			int bonusLifeY = static_cast<int>(bonusLivesPositions[i].y) / c::GRID_SIZE;
			map[bonusLifeY][bonusLifeX] = ' ';
			score += 1000;
			bonusLivesPositions.erase(bonusLivesPositions.begin() + i);
			break;
		}
}


Map::Map()
{
	this->initTextures();
	this->initSprites();
	this->initSoundBuffer();
	this->initSound();
}

void Map::update(sf::Vector2f playerPosition)
{
	this->checkInWather(playerPosition);
	this->takeRings(playerPosition);
	this->takeCheckpoints(playerPosition);
	this->takeBonusLives(playerPosition);
}

void Map::render(sf::RenderTarget& target)
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == 'B')
			{
				blockSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(blockSprite);
			}
			if (map[i][j] == 'R')
			{
				if (i != 1 && map[i][j-1] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				rightAscentSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(rightAscentSprite);
			}
			if (map[i][j] == 'L')
			{
				if (i != 1 && map[i][j + 1] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				leftAscentSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(leftAscentSprite);
			}
			if (map[i][j] == 'O')
			{
				if (i != 1 && map[i - 1][j] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				bottomRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(bottomRingSprite);
			}
			if (map[i][j] == 'o')
			{
				if (map[i - 1][j] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				catchedBottomRingSprite.setPosition(j * c::GRID_SIZE + c::GRID_SIZE / 4, i * c::GRID_SIZE - c::GRID_SIZE / 2 - 20);
				target.draw(catchedBottomRingSprite);
			}
			if (map[i][j] == 'W')
			{
				watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(watherSprite);
			}
			if (map[i][j] == 'T')
			{
				if (i != 0 && map[i - 1][j] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				thornSprite.setPosition(j * c::GRID_SIZE + 19, i * c::GRID_SIZE);
				target.draw(thornSprite);
			}
			if (map[i][j] == 't')
			{
				if (map[i + 1][j] == 'W')
				{
					watherSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
					target.draw(watherSprite);
				}
				invertedThornSprite.setPosition(j * c::GRID_SIZE + 59, i * c::GRID_SIZE + 80);
				target.draw(invertedThornSprite);
			}
			if (map[i][j] == 'C')
			{
				checkpointSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(checkpointSprite);
			}
			if (map[i][j] == 'P')
			{
				catchedCheckpointSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(catchedCheckpointSprite);
			}
			if (map[i][j] == 'l')
			{
				bonusLifeSprite.setPosition(j * c::GRID_SIZE, i * c::GRID_SIZE);
				target.draw(bonusLifeSprite);
			}
			if (map[i][j] == ' ')
				continue;

		}
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


void Map::createBlocks(b2World &World)
{
	ringsPositions.clear();
	watherPositions.clear();
	thornsPositions.clear();
	checkpointsPositions.clear();
	bonusLivesPositions.clear();

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
				maxScore += 500;
				ringsCounter++;
				ringsPositions.push_back(sf::Vector2f(x + c::GRID_SIZE / 4, y - c::GRID_SIZE / 2 - 20));
				createRing(World, x, y - c::GRID_SIZE - 20);
			}
			if (map[i][j] == 'W')
			{
				watherPositions.push_back(sf::Vector2f(x - c::GRID_SIZE / 2, y - c::GRID_SIZE / 2));
			}
			if (map[i][j] == 'T' || map[i][j] == 't')
			{
				createThorn(World, x, y);
				thornsPositions.push_back(sf::Vector2f(x - c::GRID_SIZE / 2 + 19, y - c::GRID_SIZE / 2));
			}
			if (map[i][j] == 'C')
			{
				maxScore += 500;
				checkpointsPositions.push_back(sf::Vector2f(x - c::GRID_SIZE / 2, y - c::GRID_SIZE / 2));
			}
			if (map[i][j] == 'l')
			{
				maxScore += 1000;
				maxLives++;
				bonusLivesPositions.push_back(sf::Vector2f(x - c::GRID_SIZE / 2, y - c::GRID_SIZE / 2));
			}
			if (map[i][j] == ' ')
				continue;
		}
}

void Map::setMap(int levelNumber)
{
	switch (levelNumber)
	{
	case 1: 
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelOne[i];
		break;
	}
	case 2:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelTwo[i];
		break;
	}
	case 3:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelThree[i];
		break;
	}
	case 4:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelFour[i];
		break;
	}
	case 5:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelFive[i];
		break;
	}
	case 6:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelSix[i];
		break;
	}
	case 7:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelSeven[i];
		break;
	}
	case 8:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelEight[i];
		break;
	}
	case 9:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelNine[i];
		break;
	}
	case 10:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelTen[i];
		break;
	}
	case 11:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelEleven[i];
		break;
	}
	case 12:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelTwelve[i];
		break;
	}
	case 13:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelThirteen[i];
		break;
	}
	case 14:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelFourteen[i];
		break;
	}
	case 15:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelFifeteen[i];
		break;
	}
	case 16:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelSixteen[i];
		break;
	}
	case 17:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelSeventeen[i];
		break;
	}
	case 18:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelEighteen[i];
		break;
	}
	case 19:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelNineteen[i];
		break;
	}
	case 20:
	{
		for (size_t i = 0; i < mapHeight; i++)
			this->map[i] = this->levelTwenty[i];
		break;
	}
	default:
		break;
	}
}

void Map::clearWorld(b2World& World)
{
	for (size_t i = 0; i < size(bodyList); i++)
	{
		World.DestroyBody(bodyList[i]);
	}
}


b2Vec2 Map::getSpawnPosition()
{
	for (int i = 0; i < mapHeight; i++)
		for (int j = 0; j < map[i].length(); j++)
			if (map[i][j] == 'P')
				return b2Vec2(j * 80 , i * 80);
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

bool Map::getInWather()
{
	return this->inWather;
}

std::vector<sf::Vector2f> Map::getThornsPositions()
{
	return thornsPositions;
}

std::vector<sf::Vector2f> Map::getBonusLivesPositions()
{
	return bonusLivesPositions;
}

int Map::getMaxScore()
{
	return this->maxScore;
}

int Map::getMaxLives()
{
	return this->maxLives;
}

