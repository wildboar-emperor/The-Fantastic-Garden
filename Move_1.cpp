#include "stdafx.h"
#include "Move_1.h"
#include "Managers.h"

Move_1::Move_1()
{
	Type = 1;
	Movetimes = 0;
	i = -1;
	timer_c.start();
	timer_c.시작시간 -= 3000;
}


Move_1::~Move_1()
{
}

void Move_1::Process()
{
	static D3DXVECTOR3 points[4] = { { 0, 0, 0 }, { (float)DirectX->Window_Source.w - Imgs->Get("Chirno").Source.right, 0, 0 }, { (float)DirectX->Window_Source.w - Imgs->Get("Chirno").Source.right, (float)DirectX->Window_Source.h - Imgs->Get("Chirno").Source.bottom, 0 }, { 0, (float)DirectX->Window_Source.h - Imgs->Get("Chirno").Source.bottom, 0 } };

	단위속도 = 20;

	if (timer_c.pass(3))
	{
		if (Movetimes <= 0)
		{
			if(i!=-1)	timer_c.start();
			i++;
			Movetimes = MoveTime(points[i]);
			if (i == 4)
			{
				i = 0;
			}
		}
		else
		{
			LookPoint(points[i]);
		}

		this->Position->x += Speed->x;
		this->Position->y += Speed->y;
		Movetimes--;
	}
	else
	{

	}

}

