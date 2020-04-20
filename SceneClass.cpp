#include "Header.h"


void SceneClass::initialize()
{
	skyTEX.loadFromFile("assets/images/sky-prelim.png");
	parallaxTEX.loadFromFile("assets/images/parallax-prelim.png");
	landscapeTEX.loadFromFile("assets/images/landscape-prelim.png");
	robotTEX.loadFromFile("assets/images/robot-prelim.png");
	outerArmTEX.loadFromFile("assets/images/robot-arm-outer.png");
	outerArmExtendedTEX.loadFromFile("assets/images/robot-arm-outer-ext.png");
	innerArmTEX.loadFromFile("assets/images/robot-arm-inner.png");
	innerArmExtendedTEX.loadFromFile("assets/images/robot-arm-inner-ext.png");
	cabinTEX.loadFromFile("assets/images/robot-cabin.png");
	bodyTEX.loadFromFile("assets/images/robot-body.png");
	treadTEX.loadFromFile("assets/images/robot-tread.png");
	robotTEX.loadFromFile("assets/images/robot-prelim.png");
	robotALT.loadFromFile("assets/images/robot-prelim2.png");
	//towerTEX.loadFromFile("tower-5g.png");
	boxTEX.loadFromFile("assets/images/airdrop.png");

	treadTEX1.loadFromFile("assets/images/robot-tread1.png");
	treadTEX2.loadFromFile("assets/images/robot-tread2.png");
	treadTEX3.loadFromFile("assets/images/robot-tread3.png");

	solarPanelTEX.loadFromFile("assets/images/solar-panel-icon.png");
	trashCompactorTEX.loadFromFile("assets/images/trashincinerator-icon.png");
	toxicWasteTEX.loadFromFile("assets/images/toxic-waste-icon.png");
	oxygenatorTEX.loadFromFile("assets/images/oxygenizer-icon.png");
	planterTEX.loadFromFile("assets/images/planter-icon.png");
	vaporizerTEX.loadFromFile("assets/images/vaporizer-icon.png");

	spaceShipTEX.loadFromFile("assets/images/mothership.png");
	spaceShip.setTexture(spaceShipTEX);

	//scene sprites initialization
	sky.setTexture(skyTEX);
	sky.setPosition(0.0f, 0.0f);
	parallax.setTexture(parallaxTEX);
	parallax.setPosition(-2550.0f, 0.0f);
	landscape.setTexture(landscapeTEX);
	landscape.setPosition(-2550.0f, 0.0f);

	//frame time
	frameTime = 1.24f;


	//scene color initializaion
	theColor = sf::Color(255, 255, 255, 255);
	skyColor = sf::Color(255, 255, 255, 255);

	//scene sprites initializaion
	robotArmOuter.setTexture(outerArmTEX);
	//robotArmOuterExtended.setTexture(outerArmExtendedTEX);
	//robotArmOuter.setOrigin(sf::Vector2f(30.0f, 64.0f));
	//robotArmOuter.setScale(sf::Vector2f(0.75f, 0.75f));
	robotArmInner.setTexture(innerArmTEX);
	//robotArmInner.setOrigin(sf::Vector2f(107.0f, 59.0f));
	//robotArmInner.setScale(sf::Vector2f(0.75f, 0.75f));
	robotCabin.setTexture(cabinTEX);
	//robotCabin.setOrigin(sf::Vector2f(108.0f, 96.0f));
	//robotCabin.setScale(sf::Vector2f(0.75f, 0.75f));
	robotBody.setTexture(bodyTEX);
	//robotBody.setOrigin(sf::Vector2f(93.0f, 109.0f));
	//robotBody.setScale(sf::Vector2f(0.75f, 0.75f));
	robotTread.setTexture(treadTEX1);
	//robotTread.setOrigin(sf::Vector2f(87.0f, 164.0f));
	//robotTread.setScale(sf::Vector2f(0.75f, 0.75f));
	box.setTexture(boxTEX);
	airDropSprite.setTexture(boxTEX);
	//box.setOrigin(sf::Vector2f(-60.0f, -40.0f));

	//machine sprites initialization
	//tower.setTexture(towerTEX);
	//tower.setPosition(0.0f, 0.0f);

	robotPos = sf::Vector2f(200.0f, 60.0f);

	//GUI Sprites
	solarPanel.setTexture(solarPanelTEX);
	trashCompactor.setTexture(trashCompactorTEX);
	toxicWaste.setTexture(toxicWasteTEX);
	oxygenator.setTexture(oxygenatorTEX);
	planter.setTexture(planterTEX);
	vaporizer.setTexture(vaporizerTEX);
	
	breathingTime.restart();
	sf::Vector2f myScale = sf::Vector2f(0.75f, 0.75f);

	robotArmInner.setScale(myScale);
	robotArmOuter.setScale(myScale);
	robotBody.setScale(myScale);
	robotCabin.setScale(myScale);
	robotTread.setScale(myScale);



}


//scene world cleanup display
void SceneClass::cleanupLikeMarioSunshine()
{
	if (skyColor.r > 2)
	{
		theColor.r = theColor.r - 2;
		theColor.b = theColor.b - 1;
		landscape.setColor(theColor);
		parallax.setColor(theColor);
		skyColor.r = skyColor.r - 2;
		skyColor.g = skyColor.g - 1;
		sky.setColor(skyColor);
	}
}

void SceneClass::cleanupLikeScorpion()
{
	if (theColor.r > 1)
	{
		theColor.r = theColor.r - 1;
		theColor.b = theColor.b - 1;
		landscape.setColor(theColor);
		parallax.setColor(theColor);
	}
}

void SceneClass::cleanupLikeSubZero()
{
	if (skyColor.r > 1)
	{
		skyColor.r = skyColor.r - 1;
		skyColor.g = skyColor.g - 1;
		sky.setColor(skyColor);
	}
}

//scene machine bridge
//TODO: edit the boolean inputs passed as arguments by passing a reference to a machine and(?) a robot
void SceneClass::sceneMachineBridge(MachineClass& mach)
{
	if (!mach.placed)
	{
		//initialize placement of tower machine
		sf::Vector2f place;
		mach.placed = true;
		mach.setPlacement(true, robotPos);
		mach.position.x = 200.0f - landscape.getPosition().x;
		mach.position.y = 00.0f;
//		tower.setPosition(mach.position);
	}
}

//SceneClass::movementRobot(0.75f, )
