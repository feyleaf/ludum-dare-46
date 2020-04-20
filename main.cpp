#include "Header.h"


int main()
{
	ControlClass controls;
	GameManager game;
	SceneClass scene;
	MachineClass machine;
	RobotClass myRobot;
	MachineList allThem;
	float boxHeight = -2000.0f;



	sf::Texture spaceTEX;
	sf::Sprite space;
	spaceTEX.loadFromFile("assets/images/space.png");
	space.setTexture(spaceTEX);
	space.setScale(30.0f, 30.0f);
	space.setPosition(-2550.0f, -3550.0f);

	allThem.initialize();

	controls.initialize();
	myRobot.initialize();
	scene.initialize();
	game.initialize();

	unsigned int width = 600;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "The Umbrella - Ludum Dare 46 | TEAM WATT ");
	sf::View theView = window.getView();

	sf::Music bkSong;
	bkSong.openFromFile("assets/sound/bksong.ogg");
	bkSong.setVolume(9);
	bkSong.setLoop(true);
	bkSong.play();

	//scene.sceneMachineBridge(machine);
	//game main
	while (controls.handleQuit(window))
	{

		game.phase = controls.handleKeys(game.phase, myRobot);
		game.phase = game.update(scene, myRobot);
		game.updateEnvironment(allThem);

		//game main
		window.clear();

		if (game.phase != mothership)
		{
			window.draw(scene.sky);
			window.draw(scene.parallax);
			window.draw(scene.landscape);


			if (game.phase == title) window.draw(game.titleScreen);
			if (game.phase == intro) window.draw(game.introScreen);
			if (game.phase == freePlay || game.phase == moveLeft || game.phase == objPlaceTower || game.phase==airDropSeek ||
				game.phase == moveRight || game.phase == armDown || game.phase == holdingBox || game.phase == placingBox || game.phase==finished)
			{
				//window.setView(sf::View(sf::Vector2f(2550.0f / 2.0f, -2337 / 2.0f), sf::Vector2f(6000.0f, 3000.0f)));
				window.setView(theView);
				//drawing main
				if (game.phase == objPlaceTower)
				{
					machine.initialize(myRobot.boxInHands);
					//scene.sceneMachineBridge(machine);
					machine.setPlacement(true, scene.robotPos-scene.landscape.getPosition()-sf::Vector2f(0.0f, 15.0f));
					allThem.add(machine);
					game.phase = freePlay;
					myRobot.isArmDrop = false;
					myRobot.boxInHands = -1;
					game.receipt = -1;
					myRobot.isCarrying = false;
				}
				//if (machine.placed) {
				//	scene.tower.setPosition(machine.position + scene.landscape.getPosition());
				//	window.draw(scene.tower);
				//}
				//TODO: game needs an "update" for MachineClass objects

				//updating robot sprites and drawing them
				allThem.drawAll(window, scene);
				if (game.phase == airDropSeek || myRobot.seekingBox>-1)
				{
					scene.airDropSprite.setPosition(myRobot.AirDropPlacement+sf::Vector2f(scene.landscape.getPosition().x+2550.0f, 340.0f));
					window.draw(scene.airDropSprite);
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

				window.draw(game.HUD1);

				if (game.receipt > -1)
				{
					game.HUD2.setString(sf::String("Air Drop: " + game.itemDelivered[game.receipt]));
					myRobot.seekingBox = game.receipt;
					window.draw(game.HUD2);
				}
				if (game.phase == holdingBox)
				{
					window.draw(game.HUD2);
				}
				if (allThem.communicate() && game.phase == freePlay)
				{
					game.HUD2.setString("Press \"X\" to Call the Mothership");
					window.draw(game.HUD2);
				}
				if (game.phase==finished)
				{
					game.HUD2.setString("Mission Successful: You Kept it Alive!");
					window.draw(game.HUD2);
				}
				window.draw(game.oxygen);
				window.draw(game.waterwater);
				window.draw(game.radiation);
				window.draw(game.energySprite);
			}
			//draw GUI
			if (game.phase == airDropMenu || game.phase == airDropOpenMenu || game.phase == menuCursorInc || game.phase == menuCursorDec)
			{
				window.draw(game.backgroundGUIS);

				if (game.isLocked[eOxygen]) scene.oxygenator.setColor(sf::Color(128, 128, 128, 86)); else scene.oxygenator.setColor(sf::Color::White);
				window.draw(scene.oxygenator);
				if (game.isLocked[eSolar]) scene.solarPanel.setColor(sf::Color(128, 128, 128, 86)); else scene.solarPanel.setColor(sf::Color::White);
				window.draw(scene.solarPanel);
				if (game.isLocked[eVapor]) scene.vaporizer.setColor(sf::Color(128, 128, 128, 86)); else scene.vaporizer.setColor(sf::Color::White);
				window.draw(scene.vaporizer);
				if (game.isLocked[eTrash]) scene.trashCompactor.setColor(sf::Color(128, 128, 128, 86)); else scene.trashCompactor.setColor(sf::Color::White);
				window.draw(scene.trashCompactor);
				if (game.isLocked[eToxic]) scene.toxicWaste.setColor(sf::Color(128, 128, 128, 86)); else scene.toxicWaste.setColor(sf::Color::White);
				window.draw(scene.toxicWaste);
				if (game.isLocked[ePlanter]) scene.planter.setColor(sf::Color(128, 128, 128, 86)); else scene.planter.setColor(sf::Color::White);
				window.draw(scene.planter);

				//draw selector
				game.Selector7UP.setPosition(game.SelectorLocation[game.cursor]);
				window.draw(game.Selector7UP);

				//window.display();
			}
		}
		else
		{
			if (game.paperClock.getElapsedTime().asSeconds() > 0.03f)
			{
				boxHeight = boxHeight + 12.0f;
				game.paperClock.restart();
			}
			if (boxHeight > 0.0f) {
				game.phase = airDropSeek;
				//myRobot.seekingBox = game.receipt;
				myRobot.AirDropPlacement = sf::Vector2f(scene.airDropSprite.getPosition().x+float(rand()%500), -150.0f);
				if (scene.airDropSprite.getPosition().x < 3000.0f) scene.airDropSprite.setPosition(sf::Vector2f(3000.0f, myRobot.AirDropPlacement.y));
				boxHeight = -2000.0f;
			}
			window.setView(sf::View(sf::Vector2f(2550.0f / 2.0f, -2337 / 2.0f), sf::Vector2f(6000.0f, 3000.0f)));
			window.draw(space);
			window.draw(scene.parallax);
			window.draw(scene.landscape);
			scene.spaceShip.setPosition(sf::Vector2f(0.0f, -2300.0f));
			scene.spaceShip.setScale(sf::Vector2f(3.0f, 3.0f));
			window.draw(scene.spaceShip);
			scene.airDropSprite.setPosition(sf::Vector2f(scene.robotPos.x, boxHeight));
			window.draw(scene.airDropSprite);
		}
		//drawing main
		window.display();

		
	}
	return 0;
}