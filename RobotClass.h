#pragma once
#include "Header.h"
class RobotClass
{
public:
	sf::Vector2f InnerArmShoulderJointRight;
	sf::Vector2f InnerArmShoulderJointLeft;
	sf::Vector2f OuterArmShoulderJointRight;
	sf::Vector2f OuterArmShoulderJointLeft;
	sf::Vector2f BodyCabinJointRight;
	sf::Vector2f BodyCabinJointLeft;
	sf::Vector2f LegTreadJointRight;
	sf::Vector2f LegTreadJointLeft;
	sf::Vector2f CabinPlacementRight;
	sf::Vector2f CabinPlacementLeft;

	sf::Vector2f InnerArmPivotRight;
	sf::Vector2f InnerArmPivotLeft;
	sf::Vector2f OuterArmPivotRight;
	sf::Vector2f OuterArmPivotLeft;
	sf::Vector2f CabinPivotRight;
	sf::Vector2f CabinPivotLeft;
	sf::Vector2f BodyPivotRight;
	sf::Vector2f BodyPivotLeft;
	sf::Vector2f TreadPivotRight;
	sf::Vector2f TreadPivotLeft;

	sf::Vector2f BoxPivotRight;
	sf::Vector2f BoxPivotLeft;
	sf::Vector2f BoxPlacementRight;
	sf::Vector2f BoxPlacementLeft;

	bool isArmDrop;
	bool isCarrying;
	int boxInHands;

	void initialize();
};

