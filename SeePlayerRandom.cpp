#include "stdafx.h"
#include "SeePlayerRandom.h"
#include "Player.h"

SeePlayerRandom::SeePlayerRandom()
{
	Mgzn.SetBullet(1, 0.05, 0.01f, 100, 1.f, &D3DXVECTOR3(0, 0, 0));
	Mgzn.Bullettimer.start();
	Mgzn.Bullettimer.시작시간 += Mgzn.BltDelay;
}


SeePlayerRandom::~SeePlayerRandom()
{
}

int SeePlayerRandom::Process(D3DXVECTOR3 Position, RECT ImgSource)
{
	if (Enable)
	{
		int proc = 0;
		Mgzn.Angle = atan2(
			(Position.y - PLAYER->Position.y),
			(Position.x - PLAYER->Position.x)
			) * 180 / Math_PI - 90;

		if (Mgzn.LunchBullet(D3DXVECTOR3(Position.x + ImgSource.right / 2, Position.y + ImgSource.bottom / 2, 0), Mgzn.Angle + rand() % 90 - 45, "Blt_Enemy_3"))
			proc++;
		nCountBullet++;
		return proc;
	}
}

void SeePlayerRandom::Render()
{
	Mgzn.DrawBullet();
}

void SeePlayerRandom::Move()
{
	Mgzn.MoveBullet();
}