#include "Header.h"

void MachineClass::initialize(int _machineType)
{
	placed = false;
	machineType = _machineType;
	position = sf::Vector2f(0.0f, 0.0f);
	switch (machineType)
	{
	case eOxygen:
		oxygenIncreasePerSecond = 0.01f;
		break;
	case eSolar:
		energyIncreasePerSecond = 0.05f;
		break;
	case eVapor:
		waterIncreasePerSecond = 0.025f;
		energyIncreasePerSecond = -0.01f;
		oxygenIncreasePerSecond = -0.01f;
		break;
	case eTrash:
		oxygenIncreasePerSecond = -0.03f;
		energyIncreasePerSecond = -0.02f;
		radiationIncreasePerSecond = -0.01f;
		break;
	case eToxic:
		energyIncreasePerSecond = -0.1f;
		radiationIncreasePerSecond = -0.1f;
		break;
	case ePlanter:
		waterIncreasePerSecond = -0.05f;
		oxygenIncreasePerSecond = 0.1f;
		break;
	default:
		break;
	}
}
void MachineClass::setPlacement(bool place, sf::Vector2f pos)
{
	placed = place;
	position = pos;
	

}
