#include "Header.h"

void MachineClass::initialize()
{
	placedTower = false;
	position = sf::Vector2f(0.0f, 0.0f);
}
void MachineClass::setPlacement(bool place, sf::Vector2f pos)
{
	placedTower = place;
	position = pos;
	

}
