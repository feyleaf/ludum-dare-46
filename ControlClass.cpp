#include "Header.h"

void ControlClass::initialize()
{
	keyTime = 0.19f;
	keyClock.restart();

}

bool ControlClass::handleQuit(sf::RenderWindow& win)
{
	while (win.pollEvent(theEvent))
	{
		if (theEvent.type == sf::Event::Closed)
		{
			win.close();
			return false;
		}
	}
}

gameState ControlClass::handleKeys(gameState state)
{

	if (state == freePlay)
	{

		if (keyAvailable(sf::Keyboard::Space))
		{
			safeKey();
			return armDown;
		}
		if (keyAvailable(sf::Keyboard::X))
		{
			safeKey();
			return airDropOpenMenu; //cursor=0
		}

		if (keys.isKeyPressed(sf::Keyboard::Right))
		{
			return moveRight;
		}

		//controls update robot and scene
		if (keys.isKeyPressed(sf::Keyboard::Left))
		{
			return moveLeft;
		}

	}

	if(state==airDropMenu)
	{
		if (keyAvailable(sf::Keyboard::Right))
		{
			safeKey();
			return menuCursorInc;
		}
		if (keyAvailable(sf::Keyboard::Left))
		{
			safeKey();
			return menuCursorDec;
		}
		if (keyAvailable(sf::Keyboard::Return))
		{
			safeKey();
			return airDropCall;
		}
	}

	if (state == title)
	{
		if (keyAvailable(sf::Keyboard::Space))
		{
			return intro;
		}
	}
	if (state == intro)
	{
		if (keyAvailable(sf::Keyboard::Space))
		{
			return freePlay;
		}
	}
}

//TODO: after church set this stuff up in main