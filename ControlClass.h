#pragma once
#include "Header.h"

class RobotClass;
class ControlClass
{
public:
	sf::Event theEvent;
	sf::Keyboard keys;
	sf::Clock keyClock;
	float keyTime;
	bool looseArms;
//	int cursor = 0;

	void initialize();
	bool handleQuit(sf::RenderWindow& win);
	bool keyAvailable(sf::Keyboard::Key thisKey) { return (keys.isKeyPressed(thisKey) && keyClock.getElapsedTime().asSeconds() > keyTime); }
	void safeKey() { keyClock.restart(); }
	int handleKeys(int state, RobotClass& robo);
};

