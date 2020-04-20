#pragma once
#include "Header.h"

class SceneClass;
class RobotClass;
class MachineList;

class GameManager
{
public:
	sf::Texture titleTEX;
	sf::Texture introTEX;
	sf::Sprite titleScreen;
	sf::Sprite introScreen;
	sf::Clock paperClock;

	int phase;

	float oxyPercent;
	float waterPercent;
	float radPercent;
	float energyPercent;
	bool isLocked[6]{ false, true, true, true, true, true };

	sf::Clock mortalKombatClock;
	int cursor;
	int receipt;

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
	sf::Text HUD1;
	sf::Text HUD2;
	sf::Image oxy;
	sf::Texture oxyTEX;
	sf::Sprite oxygen;
	sf::Image water;
	sf::Texture waterTEX;
	sf::Sprite waterwater;
	sf::Image rad;
	sf::Texture radTEX;
	sf::Sprite radiation;
	sf::Image energy;
	sf::Texture energyTEX;
	sf::Sprite energySprite;

	sf::Texture SelectorTEX;
	sf::Sprite Selector7UP;
	sf::Vector2f SelectorLocation[6];

	sf::Image backgroundGUI;
	sf::Texture backgroundGUITEX;
	sf::Sprite backgroundGUIS;
	sf::Vector2f iconSize;

	bool headBob;
	bool faceRight;
	sf::Clock treadTime;
	int treadFrame;
	sf::Sound noise;
	sf::SoundBuffer blingBUFF;



	void initialize();
	int update(SceneClass& scene, RobotClass& robo);
	void updateEnvironment(MachineList& ml);
	void updateMothership(MachineList& ml);

	bool sceneUpdateMovement(SceneClass& scene, RobotClass& robo);
	void movementRobot(SceneClass& scene, RobotClass& robo, float sizeScale);
	void playSound() { noise.play(); }

};

