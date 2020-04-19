#include "Header.h"


int main()
{
	//bool IsPlaying = true;
	sf::Clock safeClock;

	float safeTime = 0.25;
	
	ControlClass controls;
	controls.initialize();
	SceneClass scene;
	MachineClass tower;
	RobotClass myRobot;
	myRobot.initialize();
	scene.initialize();
	tower.initialize();

	gameState phase = title;
	sf::Texture titleTEX;
	titleTEX.loadFromFile("title-prelim.png");
	sf::Texture introTEX;
	introTEX.loadFromFile("intro-prelim.png");
	sf::Sprite titleScreen;
	titleScreen.setTexture(titleTEX);
	sf::Sprite introScreen;
	introScreen.setTexture(introTEX);
	sf::Clock paperClock;

	float oxyPercent = 0.015f;
	float waterPercent = 0.0f;
	float radPercent = 0.82f;

	int cursor = 0;
	int receipt = -1;

	sf::String itemDelivered[6] =
	{
		sf::String("Oxygenator"),
		sf::String("Solar Panel"),
		sf::String("Vaporizer"),
		sf::String("Trash Compactor"),
		sf::String("Toxic Waste Disposal"),
		sf::String("Planter")
	};

	sf::Font minecraft;
	minecraft.loadFromFile("Minecraft.ttf");
	sf::Text HUD1;
	HUD1.setFont(minecraft);
	HUD1.setCharacterSize(16);
	HUD1.setString(sf::String("Oxygen\nMoisture\nRadiation"));
	HUD1.setPosition(sf::Vector2f(8.0f, 15.0f));

	sf::Text HUD2;
	HUD2.setFont(minecraft);
	HUD2.setCharacterSize(16);
	HUD2.setString(sf::String("Air Drop: "));
	HUD2.setPosition(sf::Vector2f(245.0f, 15.0f));

	sf::Image oxy;
	oxy.create(90, 20, sf::Color::White);
	sf::Texture oxyTEX;
	oxyTEX.loadFromImage(oxy);
	sf::Sprite oxygen;
	oxygen.setTexture(oxyTEX);
	oxygen.setPosition(sf::Vector2f(100.0f, 4.0f));

	sf::Image water;
	water.create(90, 20, sf::Color::White);
	sf::Texture waterTEX;
	waterTEX.loadFromImage(water);
	sf::Sprite waterwater;
	waterwater.setTexture(waterTEX);
	waterwater.setPosition(sf::Vector2f(100.0f, 26.0f));

	sf::Image rad;
	rad.create(90, 20, sf::Color::White);
	sf::Texture radTEX;
	radTEX.loadFromImage(rad);
	sf::Sprite radiation;
	radiation.setTexture(radTEX);
	radiation.setPosition(sf::Vector2f(100.0f, 48.0f));

	//GUI
	sf::Image backgroundGUI;
	backgroundGUI.create(400, 250, sf::Color::White);
	sf::Texture backgroundGUITEX;
	backgroundGUITEX.loadFromImage(backgroundGUI);
	sf::Sprite backgroundGUIS;
	backgroundGUIS.setTexture(backgroundGUITEX);
	backgroundGUIS.setPosition(sf::Vector2f(100.0f, 70.0f));
	sf::Vector2f iconSize = sf::Vector2f (0.4287f, 0.4297f);

	sf::Vector2f SelectorLocation[6] = 
	{
	sf::Vector2f(122.5f, 77.5f),
	sf::Vector2f(242.5f, 77.5f),
	sf::Vector2f(362.5f, 77.5f), 
	sf::Vector2f(122.5f, 197.5f),
	sf::Vector2f(242.5f, 197.5f),
	sf::Vector2f(362.5f, 197.5f)
	};




	sf::Texture SelectorTEX;
	SelectorTEX.loadFromFile("Selector-icon.png");
	sf::Sprite Selector7UP;
	Selector7UP.setTexture(SelectorTEX);
	Selector7UP.setPosition(SelectorLocation[cursor]);



		
	//86,68
	unsigned int width = 600;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "The Umbrella - Ludum Dare 46 | TEAM WATT ");

	sf::Clock treadTime;


	//robot "breathing" monitor
	bool alt = false;

	//robot facing direction
	bool faceRight = true;
	

	unsigned int LetsGo = 0;

	//robot "breathing" timer
	scene.breathingTime.restart();
	sf::Vector2f myScale = sf::Vector2f(0.75f, 0.75f);

	scene.robotArmInner.setScale(myScale);
	scene.robotArmOuter.setScale(myScale);
	scene.robotBody.setScale(myScale);
	scene.robotCabin.setScale(myScale);
	scene.robotTread.setScale(myScale);

	//game main
	paperClock.restart();
	while (window.isOpen())
	{

		//sf::Event event;
		//sf::Keyboard keys;


		//robot breathing functionality
		if (scene.bigTime.getElapsedTime().asSeconds() > scene.frameTime)
		{
			if (alt)
			{
				scene.robotCabin.rotate(0.3f);
				alt = false;
				oxyPercent += 0.1f;
				if (oxyPercent > 1.0f) oxyPercent = 1.0f;
			}
			else
			{
				scene.robotCabin.rotate(-0.3f);
				alt = true;
			}
			scene.frameTime = 1.45f + cosf(scene.breathingTime.getElapsedTime().asSeconds());
			scene.bigTime.restart();
		}
		radPercent = 0.75f + 0.06f*sinf(scene.breathingTime.getElapsedTime().asSeconds());

		//game main
		window.clear();
		if (phase == title) window.draw(titleScreen);
		else if (phase == intro) window.draw(introScreen);
		else if (phase == moveRight || phase==moveLeft)
		{
			if (phase == moveRight) faceRight = true; else faceRight = false;
			scene.sceneUpdateMovement(faceRight, myRobot);
			if (LetsGo == 0)
			{
				scene.robotTread.setTexture(scene.treadTEX1);
			}
			else if (LetsGo == 1) {
				scene.robotTread.setTexture(scene.treadTEX2);
			}
			else if (LetsGo == 2) {
				scene.robotTread.setTexture(scene.treadTEX3);
			}
		}
		else if (phase == freePlay)
		{
			
			//drawing main
			window.draw(scene.sky);
			window.draw(scene.parallax);
			window.draw(scene.landscape);
			scene.tower.setPosition(tower.position + scene.landscape.getPosition());
			if (tower.placedTower) window.draw(scene.tower);

			//updating robot sprites and drawing them
			if (treadTime.getElapsedTime().asSeconds() > 0.14f) {
				LetsGo = (LetsGo + 1) % 3;
				treadTime.restart();
			}
			if (myRobot.isArmDrop)
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
				scene.robotArmInner.setOrigin(myRobot.InnerArmPivotRight);
				scene.robotArmInner.setPosition(scene.robotPos + myRobot.InnerArmShoulderJointRight);
				scene.robotBody.setOrigin(myRobot.BodyPivotRight);
				scene.robotBody.setPosition(scene.robotPos + myRobot.BodyCabinJointRight);
				scene.robotCabin.setOrigin(myRobot.CabinPivotRight);
				scene.robotCabin.setPosition(scene.robotPos + myRobot.CabinPlacementRight);
				scene.robotArmOuter.setOrigin(myRobot.OuterArmPivotRight);
				scene.robotArmOuter.setPosition(scene.robotPos + myRobot.OuterArmShoulderJointRight);
				scene.robotTread.setOrigin(myRobot.TreadPivotRight);
				scene.robotTread.setPosition(scene.robotPos + myRobot.LegTreadJointRight);
				scene.box.setOrigin(myRobot.BoxPivotRight);
				scene.box.setPosition(scene.robotPos + myRobot.BoxPlacementRight);
			}
			else
			{
				scene.robotArmInner.setOrigin(myRobot.InnerArmPivotLeft);
				scene.robotArmInner.setPosition(scene.robotPos + myRobot.InnerArmShoulderJointLeft);
				scene.robotBody.setOrigin(myRobot.BodyPivotLeft);
				scene.robotBody.setPosition(scene.robotPos + myRobot.BodyCabinJointLeft);
				scene.robotCabin.setOrigin(myRobot.CabinPivotLeft);
				scene.robotCabin.setPosition(scene.robotPos + myRobot.CabinPlacementLeft);
				scene.robotArmOuter.setOrigin(myRobot.OuterArmPivotLeft);
				scene.robotArmOuter.setPosition(scene.robotPos + myRobot.OuterArmShoulderJointLeft);
				scene.robotTread.setOrigin(myRobot.TreadPivotLeft);
				scene.robotTread.setPosition(scene.robotPos + myRobot.LegTreadJointLeft);
				scene.box.setOrigin(myRobot.BoxPivotLeft);
				scene.box.setPosition(scene.robotPos + myRobot.BoxPlacementLeft);
			}
			window.draw(scene.robotArmInner);
			window.draw(scene.robotBody);
			window.draw(scene.robotCabin);
			window.draw(scene.robotTread);
			if (myRobot.isCarrying)
			{
				window.draw(scene.box);
			}
			window.draw(scene.robotArmOuter);

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

			window.draw(HUD1);

			if (receipt > -1)
			{
				HUD2.setString(sf::String("Air Drop: " + itemDelivered[receipt]));
				window.draw(HUD2);
			}
			window.draw(oxygen);
			window.draw(waterwater);
			window.draw(radiation);
		}
		//draw GUI
		if (phase==airDropMenu)
		{
			window.draw(backgroundGUIS);

			scene.oxygenator.setScale(iconSize);
			scene.oxygenator.setPosition(sf::Vector2f(125.0f, 80.0f));
			window.draw(scene.oxygenator);

			scene.solarPanel.setScale(iconSize);
			scene.solarPanel.setPosition(sf::Vector2f(245.0f, 80.0f));
			window.draw(scene.solarPanel);

			scene.vaporizer.setScale(iconSize);
			scene.vaporizer.setPosition(sf::Vector2f(365.0f, 80.0f));
			window.draw(scene.vaporizer);

			scene.trashCompactor.setScale(iconSize);
			scene.trashCompactor.setPosition(sf::Vector2f(125.0f, 200.0f));
			window.draw(scene.trashCompactor);

			scene.toxicWaste.setScale(iconSize);
			scene.toxicWaste.setPosition(sf::Vector2f(245.0f, 200.0f));
			window.draw(scene.toxicWaste);

			scene.planter.setScale(iconSize);
			scene.planter.setPosition(sf::Vector2f(365.0f, 200.0f));
			window.draw(scene.planter);

			//draw selector
			Selector7UP.setPosition(SelectorLocation[cursor]);
			window.draw(Selector7UP);
		}


		//drawing main
		window.display();

		
	}
	return 0;
}