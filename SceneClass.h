#pragma once
#include "Header.h"

class MachineClass;
class RobotClass;

class SceneClass
{
public:
	//scene textures
	sf::Texture skyTEX;
	sf::Texture parallaxTEX;
	sf::Texture landscapeTEX;
	sf::Texture outerArmTEX;
	sf::Texture outerArmExtendedTEX;
	sf::Texture innerArmTEX;
	sf::Texture innerArmExtendedTEX;
	sf::Texture cabinTEX;
	sf::Texture treadTEX;
	sf::Texture bodyTEX;
	sf::Texture robotTEX;
	sf::Texture robotALT;

	sf::Texture boxTEX;

	sf::Texture treadTEX1;
	sf::Texture treadTEX2;
	sf::Texture treadTEX3;
	//GUI Textures
	sf::Texture solarPanelTEX;
	sf::Texture trashCompactorTEX;
	sf::Texture toxicWasteTEX;
	sf::Texture oxygenatorTEX;
	sf::Texture planterTEX;
	sf::Texture vaporizerTEX;

	sf::Texture spaceShipTEX;
	sf::Sprite spaceShip;

	//scene sprites
	sf::Sprite sky;
	sf::Sprite parallax;
	sf::Sprite landscape;

	//robot sprites
	sf::Sprite robot;
	sf::Sprite robotArmOuter;
	sf::Sprite robotArmOuterExtended;
	sf::Sprite robotArmInner;
	sf::Sprite robotCabin;
	sf::Sprite robotTread;
	sf::Sprite robotBody;

	//machine sprites
	sf::Sprite box;
	sf::Sprite airDropSprite;

	//GUI Sprites
	sf::Sprite solarPanel;
	sf::Sprite trashCompactor;
	sf::Sprite toxicWaste;
	sf::Sprite oxygenator;
	sf::Sprite planter;
	sf::Sprite vaporizer;


	//scene timers
	sf::Clock bigTime;
	sf::Clock breathingTime;
	float frameTime;

	//scene color initializaion
	sf::Color theColor;
	sf::Color skyColor;

	sf::Vector2f robotPos;

	void initialize();
	void cleanupLikeMarioSunshine();
	void cleanupLikeScorpion();
	void cleanupLikeSubZero();
	void sceneMachineBridge(MachineClass& mach);



};

