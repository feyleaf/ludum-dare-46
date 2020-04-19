#pragma once
#include "Header.h"
class ControlClass
{
public:
	sf::Event theEvent;
	sf::Keyboard keys;
	sf::Clock keyClock;
	float keyTime;

	void initialize();
	bool handleQuit(sf::RenderWindow& win);
	bool keyAvailable(sf::Keyboard::Key thisKey) { return (keys.isKeyPressed(thisKey) && keyClock.getElapsedTime().asSeconds() > keyTime); }
	void safeKey() { keyClock.restart(); }
	gameState handleKeys(gameState state);
};

