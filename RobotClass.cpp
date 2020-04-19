#include "Header.h"

void RobotClass::initialize()
{
	isArmDrop = false;
	isCarrying = true;
	boxInHands = 6;
	sf::Vector2f ArmP = sf::Vector2f(34.0f, 89.0f);
	OuterArmPivotRight = ArmP;
	//34,89
	OuterArmPivotLeft = ArmP;
	OuterArmShoulderJointRight = sf::Vector2f(104.0f, 82.0f);
	OuterArmShoulderJointLeft = sf::Vector2f(146.0f, 82.0f);

	InnerArmPivotRight = ArmP;
	InnerArmPivotLeft = ArmP;
	InnerArmShoulderJointRight = sf::Vector2f(109.0f, 76.0f);
	InnerArmShoulderJointLeft = sf::Vector2f(152.0f, 76.0f);
	//104
	TreadPivotRight = sf::Vector2f(117.0f, 230.0f);
	TreadPivotLeft = sf::Vector2f(117.0f, 230.0f);
	LegTreadJointRight = sf::Vector2f(125.0f, 202.0f);
	LegTreadJointLeft = sf::Vector2f(125.0f, 202.0f);

	CabinPivotRight = sf::Vector2f(106.0f, 86.0f);
	CabinPivotLeft = sf::Vector2f(106.0f, 86.0f);
	CabinPlacementRight = sf::Vector2f(106.0f, 86.0f);
	CabinPlacementLeft = sf::Vector2f(144.0f, 86.0f);
	BodyCabinJointRight = sf::Vector2f(126.0f, 119.0f);
	BodyCabinJointLeft = sf::Vector2f(126.0f, 119.0f);

	BodyPivotRight = sf::Vector2f(128.0f, 128.0f);
	BodyPivotLeft = sf::Vector2f(128.0f, 128.0f);

	BoxPivotRight = sf::Vector2f(-60.0f, -30.0f);
	BoxPivotLeft = sf::Vector2f(150.0f, -30.0f);
	BoxPlacementRight = sf::Vector2f(110.0f, 79.0f);
	BoxPlacementLeft = sf::Vector2f(110.0f, 79.0f);
}
