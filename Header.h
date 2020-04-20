#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ControlClass.h"
#include "GameManager.h"
#include "SceneClass.h"
#include "MachineClass.h"
#include "MachineList.h"
#include "RobotClass.h"

enum gameState {
	title = 0,
	intro,
	mothership,
	objPlaceTower,
	objPlaceMachine,
	airDropOpenMenu,
	airDropMenu,
	airDropCall,
	airDropSeek,
	armDown,
	armUpInit,
	holdingBox,
	placingBox,
	freePlay,
	moveRight,
	moveLeft,
	menuCursorInc,
	menuCursorDec,
	finished
};

enum machine {
	eOxygen=0,
	eSolar,
	eVapor,
	eTrash,
	eToxic,
	ePlanter,
	eRadio
};