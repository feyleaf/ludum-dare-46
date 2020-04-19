#pragma once
#include "Header.h"
class MachineClass
{
public:
	//machine initialization
	bool placedTower;
	void initialize();
	void setPlacement(bool place, sf::Vector2f pos);
	sf::Vector2f position;
};

