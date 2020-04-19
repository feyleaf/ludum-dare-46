#pragma once
#include <SFML/Graphics.hpp>
#include "ControlClass.h"
#include "SceneClass.h"
#include "MachineClass.h"
#include "RobotClass.h"

enum gameState {
	title = 0,
	intro,
	mothership,
	objPlaceTower,
	airDropOpenMenu,
	airDropMenu,
	airDropCall,
	airDropSeek,
	armDown,
	holdingBox,
	placingBox,
	freePlay,
	moveRight,
	moveLeft,
	menuCursorInc,
	menuCursorDec
};