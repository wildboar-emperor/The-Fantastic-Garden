#include "stdafx.h"
#include "Spiral.h"


Spiral::Spiral()
{
	for (int i = 0; i < 4; i++)
	{
		Mgzn_1[i].SetBullet(1, 0.1, 0.03f, -1, 0, &D3DXVECTOR3(0, 0, 0));
		Mgzn_1[i].Bullettimer.start();
		Mgzn_1[i].Bullettimer.시작시간 += Mgzn_1[i].BltDelay;
		Mgzn_1[i].Angle = i * 90;
	}
}


Spiral::~Spiral()
{
}

int Spiral::Process(D3DXVECTOR3 Position, RECT ImgSource)
{
	int proc = 0;
	if (Enable)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Mgzn_1[i].Bullettimer.pass(Mgzn_1[i].BltDelay))
			{
				if (Mgzn_1[i].LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), Mgzn_1[i].Angle += 17, "Blt_Enemy_1")) proc++;
				nCountBullet++;
			}
		}
	}
	return proc;

}

void Spiral::Render()
{
	for (int i = 0; i < 4; i++)
	{
		Mgzn_1[i].DrawBullet();
	}
}

void Spiral::Move()
{
	Mgzn_1[0].MoveBullet();
	Mgzn_1[1].MoveBullet();
	Mgzn_1[2].MoveBullet();
	Mgzn_1[3].MoveBullet();
}