#include "stdafx.h"
#include "Chirno_PerfectFreeze.h"
#include "Move_0.h"
#include "Move_1.h"
#include "Move_3.h"

Chirno_PerfectFreeze::Chirno_PerfectFreeze()
{
	strcpy_s(SplName, sizeof(SplName), "PerfectFreeze");
	prntLBL = true;
	IsBoss = true;
}


Chirno_PerfectFreeze::~Chirno_PerfectFreeze()
{
}


void Chirno_PerfectFreeze::Cheak()
{
	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_3;
		e_Move->목표y좌표 = 150;
		e_Move->init(Angle, Position, 단위속도, Speed);

		timer.start();
	}
	else if (timer.pass(1) && pase == 0)
	{
		pase++;
	}
	else if (timer.pass(15) && pase == 1)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_0;
		e_Move->init(Angle, Position, 단위속도, Speed);
		pase++;
	}
	else if (timer.pass(30) && pase == 2)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_1;
		e_Move->init(Angle, Position, 단위속도, Speed);
		pase++;
	}

	switch (pase)
	{
	case 1:
		flower.Process(*Position, ImgSource);
		//circle.Process(*Position, ImgSource);
		horming.Process(*Position, ImgSource);
		break;
	case 2:
		spiral.Process(*Position, ImgSource);
		break;
	case 3:
		SPR.Process(*Position, ImgSource);
		break;
	}

	circle.Move();
	spiral.Move();
	SPR.Move();
	horming.Move();
	flower.Move();
}

void Chirno_PerfectFreeze::RenderBlt()
{
	spiral.Render();
	circle.Render();
	SPR.Render();
	horming.Render();
	flower.Render();
}

void Chirno_PerfectFreeze::Release()
{
	for (int i = 0; i < 4; i++)
	{
		spiral.Mgzn_1[i].ClearList();
	}
	circle.Mgzn.ClearList();
	SPR.Mgzn.ClearList();
	horming.Mgzn.ClearList();
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			flower.Mgzn_1[i][j].ClearList();
		}
	}
}