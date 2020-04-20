#include "Header.h"

void GameManager::initialize()
{
	blingBUFF.loadFromFile("assets/sound/Powerup7.wav");
	noise.setBuffer(blingBUFF);

	titleTEX.loadFromFile("assets/images/title-prelim.png");
	introTEX.loadFromFile("assets/images/intro-prelim.png");
	titleScreen.setTexture(titleTEX);
	introScreen.setTexture(introTEX);

	phase = title;

	oxyPercent = 0.015f;
	waterPercent = 0.0f;
	radPercent = 0.82f;
	energyPercent = 0.0f;

	receipt = -1;

	minecraft.loadFromFile("assets/font/Minecraft.ttf");
	HUD1.setFont(minecraft);
	HUD1.setCharacterSize(16);
	HUD1.setString(sf::String("Oxygen\nMoisture\nRadiation\nEnergy"));
	HUD1.setPosition(sf::Vector2f(8.0f, 15.0f));

	HUD2.setFont(minecraft);
	HUD2.setCharacterSize(16);
	HUD2.setString(sf::String("Air Drop: "));
	HUD2.setPosition(sf::Vector2f(245.0f, 15.0f));

	oxy.create(90, 20, sf::Color::White);
	oxyTEX.loadFromImage(oxy);
	oxygen.setTexture(oxyTEX);
	oxygen.setPosition(sf::Vector2f(100.0f, 4.0f));

	water.create(90, 20, sf::Color::White);
	waterTEX.loadFromImage(water);
	waterwater.setTexture(waterTEX);
	waterwater.setPosition(sf::Vector2f(100.0f, 26.0f));

	rad.create(90, 20, sf::Color::White);
	radTEX.loadFromImage(rad);
	radiation.setTexture(radTEX);
	radiation.setPosition(sf::Vector2f(100.0f, 48.0f));

	energy.create(90, 20, sf::Color::White);
	energyTEX.loadFromImage(energy);
	energySprite.setTexture(energyTEX);
	energySprite.setPosition(sf::Vector2f(100.0f, 70.0f));

	SelectorLocation[0] = sf::Vector2f(122.5f, 77.5f);
	SelectorLocation[1] = sf::Vector2f(242.5f, 77.5f);
	SelectorLocation[2] = sf::Vector2f(362.5f, 77.5f);
	SelectorLocation[3] = sf::Vector2f(122.5f, 197.5f);
	SelectorLocation[4] = sf::Vector2f(242.5f, 197.5f);
	SelectorLocation[5] = sf::Vector2f(362.5f, 197.5f);

	SelectorTEX.loadFromFile("assets/images/Selector-icon.png");
	Selector7UP.setTexture(SelectorTEX);
	Selector7UP.setPosition(SelectorLocation[0]);

	backgroundGUI.create(400, 250, sf::Color::White);
	backgroundGUITEX.loadFromImage(backgroundGUI);
	backgroundGUIS.setTexture(backgroundGUITEX);
	backgroundGUIS.setPosition(sf::Vector2f(100.0f, 70.0f));

	iconSize = sf::Vector2f(0.4287f, 0.4297f);
	headBob = false;
	faceRight = true;
	treadFrame = 0;
	mortalKombatClock.restart();

}

int GameManager::update(SceneClass& scene, RobotClass& robo)
{
	int roof = phase;
	if (oxyPercent > 0.25f) isLocked[eSolar] = false;
	if (energyPercent > 0.25f) isLocked[eVapor] = false;
	if (energyPercent > 0.75f && waterPercent > 0.25f) isLocked[eTrash] = false;
	if (energyPercent > 0.75f && waterPercent > 0.25f) isLocked[eToxic] = false;
	if (radPercent < 0.01f) isLocked[ePlanter] = false;
	if (mortalKombatClock.getElapsedTime().asSeconds() > 0.25f)
	{
		if (oxyPercent > 0.75f) scene.cleanupLikeSubZero();
		if (waterPercent > 0.75f && radPercent < 0.25f) scene.cleanupLikeScorpion();
		mortalKombatClock.restart();
	}

	if (scene.theColor.r < 3 && scene.skyColor.r < 3) return finished;
	//robot breathing functionality
	if (roof == armDown)
	{
		robo.isArmDrop = true;
	}
	if (roof == holdingBox)
	{
		robo.seekingBox = -1;
		HUD2.setString("Press \"Space\" to drop Package");
	}
	if (roof == armUpInit)
	{
		robo.isArmDrop = false;
		roof = freePlay;
		phase = freePlay;
	}
	if (robo.isArmDrop)
	{
		scene.robotArmOuter.setTexture(scene.outerArmExtendedTEX);
		scene.robotArmInner.setTexture(scene.innerArmExtendedTEX);
	}
	else
	{
		scene.robotArmOuter.setTexture(scene.outerArmTEX);
		scene.robotArmInner.setTexture(scene.innerArmTEX);
	}
	if (faceRight)
	{
		scene.robotArmInner.setOrigin(robo.InnerArmPivotRight);
		scene.robotArmInner.setPosition(scene.robotPos + robo.InnerArmShoulderJointRight);
		scene.robotBody.setOrigin(robo.BodyPivotRight);
		scene.robotBody.setPosition(scene.robotPos + robo.BodyCabinJointRight);
		scene.robotCabin.setOrigin(robo.CabinPivotRight);
		scene.robotCabin.setPosition(scene.robotPos + robo.CabinPlacementRight);
		scene.robotArmOuter.setOrigin(robo.OuterArmPivotRight);
		scene.robotArmOuter.setPosition(scene.robotPos + robo.OuterArmShoulderJointRight);
		scene.robotTread.setOrigin(robo.TreadPivotRight);
		scene.robotTread.setPosition(scene.robotPos + robo.LegTreadJointRight);
		scene.box.setOrigin(robo.BoxPivotRight);
		scene.box.setPosition(scene.robotPos + robo.BoxPlacementRight);
	}
	else
	{
		scene.robotArmInner.setOrigin(robo.InnerArmPivotLeft);
		scene.robotArmInner.setPosition(scene.robotPos + robo.InnerArmShoulderJointLeft);
		scene.robotBody.setOrigin(robo.BodyPivotLeft);
		scene.robotBody.setPosition(scene.robotPos + robo.BodyCabinJointLeft);
		scene.robotCabin.setOrigin(robo.CabinPivotLeft);
		scene.robotCabin.setPosition(scene.robotPos + robo.CabinPlacementLeft);
		scene.robotArmOuter.setOrigin(robo.OuterArmPivotLeft);
		scene.robotArmOuter.setPosition(scene.robotPos + robo.OuterArmShoulderJointLeft);
		scene.robotTread.setOrigin(robo.TreadPivotLeft);
		scene.robotTread.setPosition(scene.robotPos + robo.LegTreadJointLeft);
		scene.box.setOrigin(robo.BoxPivotLeft);
		scene.box.setPosition(scene.robotPos + robo.BoxPlacementLeft);
	}
	scene.oxygenator.setScale(iconSize);
	scene.oxygenator.setPosition(sf::Vector2f(125.0f, 80.0f));
	scene.solarPanel.setScale(iconSize);
	scene.solarPanel.setPosition(sf::Vector2f(245.0f, 80.0f));
	scene.vaporizer.setScale(iconSize);
	scene.vaporizer.setPosition(sf::Vector2f(365.0f, 80.0f));
	scene.trashCompactor.setScale(iconSize);
	scene.trashCompactor.setPosition(sf::Vector2f(125.0f, 200.0f));
	scene.toxicWaste.setScale(iconSize);
	scene.toxicWaste.setPosition(sf::Vector2f(245.0f, 200.0f));
	scene.planter.setScale(iconSize);
	scene.planter.setPosition(sf::Vector2f(365.0f, 200.0f));
	if (roof == airDropSeek)
	{
		if (robo.AirDropPlacement.x + scene.landscape.getPosition().x < -2250.0f)
		{
			robo.seekingBox = -1;
			robo.boxInHands = receipt;
			receipt = -1;
			robo.isCarrying = true;
			playSound();
			return holdingBox;
		}
	}
	if (roof == airDropOpenMenu)
	{
		cursor = 0;
		roof = airDropMenu;
	}
	if (roof == menuCursorInc)
	{
		cursor = (cursor + 1) % 6;
		if (isLocked[cursor]) cursor--;
		roof = airDropMenu;
	}
	if (roof == menuCursorDec)
	{
		cursor--;
		if (cursor < 0) cursor = 5;
		if (isLocked[cursor]) cursor = 0;
		roof = airDropMenu;
	}
	if (roof == airDropMenu)
	{
		receipt = cursor;
	}
	if (scene.bigTime.getElapsedTime().asSeconds() > scene.frameTime)
	{
		if (headBob)
		{
			scene.robotCabin.rotate(0.53f);
			headBob = false;
		}
		else
		{
			scene.robotCabin.rotate(-0.53f);
			headBob = true;
		}
		scene.frameTime = 1.45f + cosf(scene.breathingTime.getElapsedTime().asSeconds());
		scene.bigTime.restart();
	}
	if (phase == placingBox)
	{
		robo.isCarrying = false;
		return objPlaceTower;
	}
	if (phase == airDropCall) return mothership;

	if (phase == moveRight || phase == moveLeft)
	{
		if (phase == moveRight) faceRight = true; else faceRight = false;
		sceneUpdateMovement(scene, robo);
		if (treadFrame == 0){
			scene.robotTread.setTexture(scene.treadTEX1);
		}
		else if (treadFrame == 1) {
			scene.robotTread.setTexture(scene.treadTEX2);
		}
		else if (treadFrame == 2) {
			scene.robotTread.setTexture(scene.treadTEX3);
		}
	}
	if (treadTime.getElapsedTime().asSeconds() > 0.14f) {
		treadFrame = (treadFrame + 1) % 3;
		treadTime.restart();
	}

	if (oxyPercent < 0.5f)
		oxygen.setColor(sf::Color::Red);
	else if (oxyPercent < 0.8f)
		oxygen.setColor(sf::Color::Yellow);
	else oxygen.setColor(sf::Color::Green);
	oxygen.setScale(sf::Vector2f(oxyPercent, 1.0f));

	if (waterPercent < 0.5f)
		waterwater.setColor(sf::Color::Red);
	else if (waterPercent < 0.8f)
		waterwater.setColor(sf::Color::Yellow);
	else waterwater.setColor(sf::Color::Green);
	waterwater.setScale(sf::Vector2f(waterPercent, 1.0f));

	if (radPercent < 0.5f)
		radiation.setColor(sf::Color::Green);
	else if (radPercent < 0.8f)
		radiation.setColor(sf::Color::Yellow);
	else radiation.setColor(sf::Color::Red);
	radiation.setScale(sf::Vector2f(radPercent, 1.0f));

	if (energyPercent < 0.5f)
		energySprite.setColor(sf::Color::White);
	else if (energyPercent < 0.8f)
		energySprite.setColor(sf::Color::Cyan);
	else energySprite.setColor(sf::Color::Blue);
	energySprite.setScale(sf::Vector2f(energyPercent, 1.0f));


	return roof;
}

void GameManager::movementRobot(SceneClass& scene, RobotClass& robo, float sizeScale) {
	//robot update
	float neg1 = -1;
	float local = 0;
	//local = -1950.0f
	if (sizeScale > 0) {
		neg1 = -1;
		local = 0;
	}
	else {
		neg1 = 1;
	}
	float BreathTime = scene.breathingTime.getElapsedTime().asSeconds() * 10;
	scene.robotArmOuter.setScale(sizeScale, abs(sizeScale));
	scene.robotArmInner.setScale(sizeScale, abs(sizeScale));
	scene.robotBody.setScale(sizeScale, abs(sizeScale));
	scene.robotCabin.setScale(sizeScale, abs(sizeScale));
	scene.robotTread.setScale(sizeScale, abs(sizeScale));

	if (!robo.isArmDrop)
	{
		scene.robotArmOuter.setRotation(2.5f*sinf(BreathTime));
		scene.robotArmInner.setRotation(cosf(BreathTime));
		scene.robotTread.setRotation(cosf(BreathTime));
		scene.box.setRotation(2.5f*sinf(BreathTime));
	}
	else
	{
		scene.robotArmOuter.setRotation(-3.14159f*1.46f*neg1);
		scene.robotArmInner.setRotation(-3.14159f*1.46f*neg1);
	}
	//scene update
	if (neg1 < 0.0f) {

		if (scene.landscape.getPosition().x > (-1950.0f-2550.0f))
		{
			scene.sky.move(sf::Vector2f(neg1 * 0.005f, 0.0f));
			scene.parallax.move(sf::Vector2f(neg1 * 0.0150f, 0.0f));
			scene.landscape.move(sf::Vector2f(neg1 * 0.0250f, 0.0f));
//			scene.tower.move(sf::Vector2f(neg1 * 0.025f, 0.0f));
		}
	}
	else
	{
		if (scene.landscape.getPosition().x < (-2550.0f))
		{
			scene.sky.move(sf::Vector2f(neg1 * 0.005f, 0.0f));
			scene.parallax.move(sf::Vector2f(neg1 * 0.0150f, 0.0f));
			scene.landscape.move(sf::Vector2f(neg1 * 0.0250f, 0.0f));
	//		scene.tower.move(sf::Vector2f(neg1 * 0.025f, 0.0f));
		}
	}
}
bool GameManager::sceneUpdateMovement(SceneClass& scene, RobotClass& robo)
{
	if (faceRight)
	{
		movementRobot(scene, robo, 0.75f);
	}
	else
	{
		movementRobot(scene, robo, -0.75f);
	}
	return faceRight;
}

void GameManager::updateEnvironment(MachineList& ml)
{
	if (ml.environmentClock.getElapsedTime().asSeconds() > 1.0f)
	{
		ml.environmentClock.restart();
		oxyPercent += ml.effectOxygen();
		if (oxyPercent > 1) oxyPercent = 1.0f;
		if (oxyPercent < 0) oxyPercent = 0.0f;
		waterPercent += ml.effectWater();
		if (waterPercent > 1) waterPercent = 1.0f;
		if (waterPercent < 0) waterPercent = 0.0f;
		radPercent += ml.effectRadiation();
		if (radPercent > 1) radPercent = 1.0f;
		if (radPercent < 0) radPercent = 0.0f;
		energyPercent += ml.effectEnergy();
		if (energyPercent > 1) energyPercent = 1.0f;
		if (energyPercent < 0) energyPercent = 0.0f;
	}
}

void GameManager::updateMothership(MachineList& ml)
{
	if (phase == mothership)
	{
		MachineClass boxMachine;
		boxMachine.initialize(receipt);
		//TODO: fill this out
	}
	return;
}