#include "stdafx.h"
#include "TimeManager.h"


TimeManager::TimeManager()
{
}


TimeManager::~TimeManager()
{
}

void TimeManager::InitTick()
{
	Tick = 0;
}

void TimeManager::CountTick()
{
	Tick++;

	println("%d", Tick);
}

DWORD TimeManager::GetTick()
{
	return Tick;
}