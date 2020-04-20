#include "MachineList.h"

void MachineList::add(MachineClass& mach)
{
	switch (mach.machineType)
	{
	case eOxygen:
		machOxygenatorTEX.loadFromFile("assets/images/mach-oxygen.png");
		mach.drw.setTexture(machOxygenatorTEX);
		break;
	case eVapor:
		mach.drw.setTexture(machVaporizerTEX);
		break;
	case eTrash:
		mach.drw.setTexture(machTrashCompactorTEX);
		break;
	case eSolar:
		mach.drw.setTexture(machSolarPanelTEX);
		break;
	case eToxic:
		mach.drw.setTexture(machToxicWasteTEX);
		break;
	case eRadio:
		mach.drw.setTexture(machRadioTowerTEX);
		break;
	case ePlanter:
	default:
		mach.drw.setTexture(machPlanterTEX);
		break;
	}
	mach.drw.setColor(sf::Color::White);
	mach.drw.setPosition(mach.position);
	mach.placed = true;
	machines.push_back(mach);
}

bool MachineList::communicate()
{
	bool ret = false;
	for (size_t i = 0; i < machines.size(); i++)
	{
		if (machines.at(i).machineType == eRadio)
			ret = true;
	}
	return ret;
}

float MachineList::effectEnergy()
{
	float energyUp = 0.0f;
	for (size_t i = 0; i < machines.size(); i++)
	{
		energyUp = machines.at(i).energyIncreasePerSecond;
	}
	return energyUp;

}
float MachineList::effectOxygen()
{
	float oxygenUp = 0.0f;
	for (size_t i = 0; i < machines.size(); i++)
	{
		oxygenUp = machines.at(i).oxygenIncreasePerSecond;
	}
	return oxygenUp;


}
float MachineList::effectWater()
{
	float waterUp = 0.0f;
	for (size_t i = 0; i < machines.size(); i++)
	{
		waterUp = machines.at(i).waterIncreasePerSecond;
	}
	return waterUp;


}
float MachineList::effectRadiation()
{
	float radUp = 0.0f;
	for (size_t i = 0; i < machines.size(); i++)
	{
		radUp = machines.at(i).radiationIncreasePerSecond;
	}
	return radUp;


}

void MachineList::initialize()
{
	while (!machines.empty())
	{
		machines.pop_back();
	}
	machRadioTowerTEX.loadFromFile("assets/images/tower-5g.png");
	machOxygenatorTEX.loadFromFile("assets/images/mach-oxygen.png");
	machPlanterTEX.loadFromFile("assets/images/mach-planter.png");
	machSolarPanelTEX.loadFromFile("assets/images/mach-solar.png");
	machToxicWasteTEX.loadFromFile("assets/images/mach-toxic.png");
	machTrashCompactorTEX.loadFromFile("assets/images/mach-incinerator.png");
	machVaporizerTEX.loadFromFile("assets/images/mach-vapor.png");

}

void MachineList::drawAll(sf::RenderWindow& app, SceneClass& scene)
{
	for (size_t i = 0; i < machines.size(); i++)
	{
		if (machines.at(i).placed)
		{
			machines.at(i).drw.setPosition(machines.at(i).position + scene.landscape.getPosition());
			app.draw(machines.at(i).drw);
		}
	}
}
