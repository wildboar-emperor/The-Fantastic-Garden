#pragma once
#include "MovePattern.h"
class Move_1 :
	public MovePattern
{
public:
	float Movetimes;
	int i;
	TimeCounter timer_c;

public:
	Move_1();
	virtual ~Move_1();

public:
	void Process() override;
};

