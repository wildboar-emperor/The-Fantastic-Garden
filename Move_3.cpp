#include "stdafx.h"
#include "Move_3.h"
#include "Managers.h"

Move_3::Move_3()
{
	Type = 3;
	timer.start();
}


Move_3::~Move_3()
{
}

void Move_3::Process()
{
	if (Position->y < 목표y좌표 && 목표y좌표 > 0)
	{
		Position->y += 단위속도;
	}

	if (Position->x < 목표x좌표 && 목표x좌표 > 0)
	{
		Position->x += 단위속도;
	}
}
