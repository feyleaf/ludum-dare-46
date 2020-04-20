#include "Header.h"

void ControlClass::initialize()
{
	keyTime = 0.19f;
	keyClock.restart();
	looseArms = false;

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
	return true;
}

int ControlClass::handleKeys(int state, RobotClass& robo)
{
	if (state == finished)
	{
		if (keyAvailable(sf::Keyboard::Space))
		{
			safeKey();
			return freePlay;
		}
	}

	if(state==armDown || state==freePlay || state==holdingBox)
	{
		if (state == freePlay)
		{
			if (keyAvailable(sf::Keyboard::Space))
			{
				robo.isArmDrop = true;
				safeKey();
				return armDown;
			}
		}
		if (state == holdingBox)
		{
			if (keyAvailable(sf::Keyboard::Space))
			{
				robo.isCarrying = false;
				//robo.boxInHands = -1;
				safeKey();
				return placingBox;
			}
		}
		if (state == armDown)
		{
			if (keyAvailable(sf::Keyboard::Space))
			{
				robo.isArmDrop = false;
				safeKey();
				return armUpInit;
			}
		}
		if(state==freePlay)
		{
			if (keyAvailable(sf::Keyboard::X))
			{
				safeKey();
				return airDropOpenMenu; //cursor=0

			}
		}
//		if (keyAvailable(sf::Keyboard::C))
//		{
//			safeKey();
//			return mothership; //cursor=0
//		}


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
	if (state == airDropSeek)
	{
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
	if (state == moveLeft)
	{
		if (!keys.isKeyPressed(sf::Keyboard::Left))
		{
			if (robo.seekingBox > -1) return airDropSeek;
			if (robo.isCarrying && robo.boxInHands>-1) return holdingBox;
			if (!robo.isCarrying && robo.isArmDrop) return armDown;
			if(!robo.isCarrying && !robo.isArmDrop) return freePlay;
		}
	}
	if (state == moveRight)
	{
		if (!keys.isKeyPressed(sf::Keyboard::Right))
		{
			if (robo.seekingBox > -1) return airDropSeek;
			if (robo.isCarrying && robo.boxInHands > -1) return holdingBox;
			if (!robo.isCarrying && robo.isArmDrop) return armDown;
			if (!robo.isCarrying && !robo.isArmDrop) return freePlay;
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
		return airDropMenu;
	}
	if (state == title)
	{
		if (keyAvailable(sf::Keyboard::Space))
		{
			safeKey();
			return intro;
		}
	}
	if (state == intro)
	{
		if (keyAvailable(sf::Keyboard::Space))
		{
			safeKey();
			return holdingBox;
		}
	}
	return state;
}

//TODO: after church set this stuff up in main