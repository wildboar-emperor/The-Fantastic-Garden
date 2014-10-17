#pragma once
#include "Enemys.h"
#include "Managers.h"
#include "Player.h"
typedef enum
{
	ST_EXIT, ST_START, ST_1, ST_2, ST_3, ST_4, ST_5
}StageType;
class Stage
{
public:
	TimeCounter EventTimer;

public:
	Stage();
	virtual ~Stage();

public:
	virtual void Initalize();
	virtual void Release();

	virtual void Render();
	virtual int Process();
};

