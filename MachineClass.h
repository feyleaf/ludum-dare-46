#pragma once
#include "Header.h"
class MachineClass
{
public:
	//machine initialization
	bool placed;
	int machineType;
	void initialize(int _machineType);
	void setPlacement(bool place, sf::Vector2f pos);
	sf::Vector2f position;
	sf::Sprite drw;
	sf::Texture TEX;
	float oxygenIncreasePerSecond;
	float waterIncreasePerSecond;
	float radiationIncreasePerSecond;
	float energyIncreasePerSecond;
};

