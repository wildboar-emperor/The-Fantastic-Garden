#include "stdafx.h"
#include "Horming.h"


Horming::Horming()
{
	Mgzn.SetBullet(1, 1, 0.5f, 5, 1.f, &D3DXVECTOR3(0, 0, 0));
	Mgzn.Bullettimer.start();
	Mgzn.Bullettimer.시작시간 += Mgzn.BltDelay;
}


Horming::~Horming()
{
}

int Horming::Process(D3DXVECTOR3 Position, RECT ImgSource)
{
	if (Enable)
	{
		int proc = 0;
		if (Mgzn.LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), 0, "Needle_1"))
			proc++;
		nCountBullet++;
		return proc;
	}
}

void Horming::Render()
{
	Mgzn.DrawBullet();
}

void Horming::Move()
{
	Mgzn.MoveBullet();
}