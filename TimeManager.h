#pragma once
#include "Singleton.h"
class TimeManager :
	public Singleton<TimeManager>
{
private:
	DWORD Tick;

public:
	TimeManager();
	~TimeManager();

public:
	void InitTick();
	void CountTick();
	DWORD GetTick();
};

#define TIME TimeManager::getInstance()

