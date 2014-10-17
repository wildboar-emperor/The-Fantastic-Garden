#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
{
	Mgzn.SetBullet(1, 0.1, 0.1f, 5, 1.f, &D3DXVECTOR3(0, 0, 0));
	Mgzn.Bullettimer.start();
	Mgzn.Bullettimer.시작시간 += Mgzn.BltDelay;
}


Circle::~Circle()
{
}

int Circle::Process(D3DXVECTOR3 Position, RECT ImgSource)
{
	if (Enable)
	{
		int proc = 0;

		if (Mgzn.Bullettimer.pass(Mgzn.BltDelay))
		{
			for (Mgzn.Angle = 0; Mgzn.Angle < 360; Mgzn.Angle += 12)
			{
				if (Mgzn.LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), Mgzn.Angle, "Blt_Enemy_2", true))
				{
					nCountBullet++;
					proc++;
				}
			}
			Mgzn.Bullettimer.start();
			Mgzn.발사횟수++;
		}

		return proc;
	}
}

void Circle::Render()
{
	Mgzn.DrawBullet();
}

void Circle::Move()
{
	Mgzn.MoveBullet();
}