#pragma once
#include "GameEvent.h"
class GameEvent_CreatureChangeDir :  public GameEvent
{
	DECLARE_CHILD(GameEvent_CreatureChangeDir, GameEvent);
public:
	int FromDir;
	int ToDir;


};

