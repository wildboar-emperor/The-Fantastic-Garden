#pragma once
#include "Bullet.h"
#include "TimeCounter.h"
class Player_Blt_LookEnemy :
	public Bullet
{
public:
	Player_Blt_LookEnemy();
	virtual ~Player_Blt_LookEnemy();

public:
	void Process() override;
};

