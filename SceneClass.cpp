#include "Header.h"


void SceneClass::initialize()
{
	skyTEX.loadFromFile("sky-prelim.png");
	parallaxTEX.loadFromFile("parallax-prelim.png");
	landscapeTEX.loadFromFile("landscape-prelim.png");
	robotTEX.loadFromFile("robot-prelim.png");
	outerArmTEX.loadFromFile("robot-arm-outer.png");
	outerArmExtendedTEX.loadFromFile("robot-arm-outer-ext.png");
	innerArmTEX.loadFromFile("robot-arm-inner.png");
	innerArmExtendedTEX.loadFromFile("robot-arm-inner-ext.png");
	cabinTEX.loadFromFile("robot-cabin.png");
	bodyTEX.loadFromFile("robot-body.png");
	treadTEX.loadFromFile("robot-tread.png");
	robotTEX.loadFromFile("robot-prelim.png");
	robotALT.loadFromFile("robot-prelim2.png");
	towerTEX.loadFromFile("tower-5g.png");
	boxTEX.loadFromFile("box.png");

	treadTEX1.loadFromFile("robot-tread1.png");
	treadTEX2.loadFromFile("robot-tread2.png");
	treadTEX3.loadFromFile("robot-tread3.png");

	solarPanelTEX.loadFromFile("solar-panel-icon.png");
	trashCompactorTEX.loadFromFile("trashincinerator-icon.png");
	toxicWasteTEX.loadFromFile("toxic-waste-icon.png");
	oxygenatorTEX.loadFromFile("oxygenizer-icon.png");
	planterTEX.loadFromFile("planter-icon.png");
	vaporizerTEX.loadFromFile("vaporizer-icon.png");

	//scene sprites initialization
	sky.setTexture(skyTEX);
	sky.setPosition(0.0f, 0.0f);
	parallax.setTexture(parallaxTEX);
	parallax.setPosition(0.0f, 0.0f);
	landscape.setTexture(landscapeTEX);
	landscape.setPosition(0.0f, 0.0f);

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
	//box.setOrigin(sf::Vector2f(-60.0f, -40.0f));

	//machine sprites initialization
	tower.setTexture(towerTEX);
	tower.setPosition(0.0f, 0.0f);

	robotPos = sf::Vector2f(200.0f, 60.0f);

	//GUI Sprites
	solarPanel.setTexture(solarPanelTEX);
	trashCompactor.setTexture(trashCompactorTEX);
	toxicWaste.setTexture(toxicWasteTEX);
	oxygenator.setTexture(oxygenatorTEX);
	planter.setTexture(planterTEX);
	vaporizer.setTexture(vaporizerTEX);
	



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

//scene machine bridge
//TODO: edit the boolean inputs passed as arguments by passing a reference to a machine and(?) a robot
void SceneClass::sceneMachineBridge(MachineClass& mach)
{
	if (!mach.placedTower)
	{
		//initialize placement of tower machine
		sf::Vector2f place;
		mach.placedTower = true;
		mach.setPlacement(true, robotPos);
		mach.position.x = 200.0f - landscape.getPosition().x;
		mach.position.y = 00.0f;
		tower.setPosition(mach.position);
	}
}

//SceneClass::movementRobot(0.75f, )
void SceneClass::movementRobot(float sizeScale, RobotClass& robo) {
	//robot update
	float neg1 = -1;
	float local = 0;
	//local = -1950.0f
	if (sizeScale > 0){
		neg1 = -1;
		local = 0;
	}
	else {
		neg1 = 1;
	}
	float BreathTime = breathingTime.getElapsedTime().asSeconds() * 10;
	robotArmOuter.setScale(sizeScale, abs(sizeScale));
	robotArmInner.setScale(sizeScale, abs(sizeScale));
	robotBody.setScale(sizeScale, abs(sizeScale));
	robotCabin.setScale(sizeScale, abs(sizeScale));
	robotTread.setScale(sizeScale, abs(sizeScale));

	if (!robo.isArmDrop)
	{
		robotArmOuter.setRotation(2.5f*sinf(BreathTime));
		robotArmInner.setRotation(cosf(BreathTime));
		robotTread.setRotation(cosf(BreathTime));
		box.setRotation(2.5f*sinf(BreathTime));
	}
	else
	{
		robotArmOuter.setRotation(-3.14159f*1.46f*neg1);
		robotArmInner.setRotation(-3.14159f*1.46f*neg1);
	}
	//scene update
	if (neg1 < 0.0f) {

		if (landscape.getPosition().x > (-1950.0f))
		{
			sky.move(sf::Vector2f(neg1 * 0.005f, 0.0f));
			parallax.move(sf::Vector2f(neg1 * 0.0150f, 0.0f));
			landscape.move(sf::Vector2f(neg1 * 0.0250f, 0.0f));
			tower.move(sf::Vector2f(neg1 * 0.025f, 0.0f));
		}
	}
	else 
	{
		if (landscape.getPosition().x < (0.0f))
		{
			sky.move(sf::Vector2f(neg1 * 0.005f, 0.0f));
			parallax.move(sf::Vector2f(neg1 * 0.0150f, 0.0f));
			landscape.move(sf::Vector2f(neg1 * 0.0250f, 0.0f));
			tower.move(sf::Vector2f(neg1 * 0.025f, 0.0f));
		}
	}
}
bool SceneClass::sceneUpdateMovement(bool isRight, RobotClass& robo)
{
	if (isRight)
	{
		movementRobot(0.75f, robo);
	}
	else
	{
		movementRobot(-0.75f, robo);
	}
	return isRight;
}