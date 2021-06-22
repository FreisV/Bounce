#include "Game.h"
#include "stdafx.h"

using namespace sf;


int main()
{
	srand(static_cast<unsigned>(time(0)));

	Game game;

	sf::Clock clock;
	
	while (game.getWindow().isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds() / 4000;
		clock.restart();

		game.update(time);
		game.render();
	}
}

