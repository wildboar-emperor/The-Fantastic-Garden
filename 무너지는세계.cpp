#include "stdafx.h"
#include "무너지는세계.h"
#include "Managers.h"
#include "Move_0.h"

무너지는세계::무너지는세계()
{
	strcpy_s(SplName, sizeof(SplName), "무너지는 세계");
	prntLBL = true;
	IsBoss = true;
}


무너지는세계::~무너지는세계()
{
}

void 무너지는세계::Cheak()
{
	int cost = 0;

	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_0;
		e_Move->init(Angle, Position, 단위속도, Speed);

		pase = 1;
		timer.start();
	}

	if (남은체력 >= 0)
	{
		switch (pase)
		{
		case 1:
			cost = flower.Process(*Position, ImgSource);
			cost += horming.Process(*Position, ImgSource);
			break;
		}
		남은체력 -= cost;
	}

	flower.Move();
	horming.Move();
}

void 무너지는세계::RenderBlt()
{
	flower.Render();
	horming.Render();
}
void 무너지는세계::Release()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		flower.Mgzn_1[i][j].ClearList();

	horming.Mgzn.ClearList();
}