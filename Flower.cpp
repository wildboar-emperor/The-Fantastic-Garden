#include "stdafx.h"
#include "Flower.h"


Flower::Flower()
{
	for (int i = 0; i < 4; i++)
	{
		Mgzn_1[0][i].SetBullet(1, 0.1, 0.1f, -1, 0, &D3DXVECTOR3(0, 0, 0));
		Mgzn_1[0][i].Bullettimer.start();
		Mgzn_1[0][i].Bullettimer.시작시간 += Mgzn_1[0][i].BltDelay;
		Mgzn_1[0][i].Angle = i * 90;
		Mgzn_1[1][i].SetBullet(1, 0.1, 0.1f, -1, 0, &D3DXVECTOR3(0, 0, 0));
		Mgzn_1[1][i].Bullettimer.start();
		Mgzn_1[1][i].Bullettimer.시작시간 += Mgzn_1[1][i].BltDelay;
		Mgzn_1[1][i].Angle = i * 90;
	}
}


Flower::~Flower()
{
}


int Flower::Process(D3DXVECTOR3 Position, RECT ImgSource)
{
	if (Enable)
	{
		int proc = 0;
		for (int i = 0; i < 4; i++)
		{
			if (Mgzn_1[0][i].Bullettimer.pass(Mgzn_1[0][i].BltDelay))
			{
				if (Mgzn_1[0][i].LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), Mgzn_1[0][i].Angle, "Blt_Enemy_2"))	 proc++;
				Mgzn_1[0][i].Angle += 5;
				nCountBullet++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (Mgzn_1[1][i].Bullettimer.pass(Mgzn_1[1][i].BltDelay))
			{
				if (Mgzn_1[1][i].LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), Mgzn_1[1][i].Angle, "Blt_Enemy_3")) proc++;
				Mgzn_1[1][i].Angle -= 5;
				nCountBullet++;
			}
		}

		return proc;
	}

}

void Flower::Render()
{
	Mgzn_1[0][0].DrawBullet();
	Mgzn_1[0][1].DrawBullet();
	Mgzn_1[0][2].DrawBullet();
	Mgzn_1[0][3].DrawBullet();
	Mgzn_1[1][0].DrawBullet();
	Mgzn_1[1][1].DrawBullet();
	Mgzn_1[1][2].DrawBullet();
	Mgzn_1[1][3].DrawBullet();
}

void Flower::Move()
{
	Mgzn_1[0][0].MoveBullet();
	Mgzn_1[0][1].MoveBullet();
	Mgzn_1[0][2].MoveBullet();
	Mgzn_1[0][3].MoveBullet();
	Mgzn_1[1][0].MoveBullet();
	Mgzn_1[1][1].MoveBullet();
	Mgzn_1[1][2].MoveBullet();
	Mgzn_1[1][3].MoveBullet();
}