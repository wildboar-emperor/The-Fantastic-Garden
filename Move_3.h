#pragma once
#include "MovePattern.h"
class Move_3 :
	public MovePattern
{

public:
	Move_3();
	virtual ~Move_3();

public:
	void Process() override;
};

