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
	if (Position->y < ��ǥy��ǥ && ��ǥy��ǥ > 0)
	{
		Position->y += �����ӵ�;
	}

	if (Position->x < ��ǥx��ǥ && ��ǥx��ǥ > 0)
	{
		Position->x += �����ӵ�;
	}
}
