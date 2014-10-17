#pragma once
#include "Bullet.h"
class Player_Blt_1 :
	public Bullet
{
public:
	Player_Blt_1();
	virtual ~Player_Blt_1();

public:
	void Process() override;
};

