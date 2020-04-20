#pragma once
#include "Header.h"
class MachineClass;
class SceneClass;

class MachineList
{
public:
	sf::Clock environmentClock;

	sf::Texture machSolarPanelTEX;
	sf::Texture machTrashCompactorTEX;
	sf::Texture machToxicWasteTEX;
	sf::Texture machOxygenatorTEX;
	sf::Texture machPlanterTEX;
	sf::Texture machVaporizerTEX;
	sf::Sprite machSolarPanel;
	sf::Sprite machTrashCompactor;
	sf::Sprite machToxicWaste;
	sf::Sprite machOxygenator;
	sf::Sprite machPlanter;
	sf::Sprite machVaporizer;

	sf::Sprite machRadioTower;
	sf::Texture machRadioTowerTEX;


	std::vector<MachineClass> machines;
	void initialize();
	void add(MachineClass& mach);
	float effectOxygen();
	float effectWater();
	float effectRadiation();
	float effectEnergy();
	bool communicate();
	void drawAll(sf::RenderWindow& app, SceneClass& scene);
};

