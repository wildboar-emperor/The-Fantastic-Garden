#include "stdafx.h"
#include "�������¼���.h"
#include "Managers.h"
#include "Move_0.h"

�������¼���::�������¼���()
{
	strcpy_s(SplName, sizeof(SplName), "�������� ����");
	prntLBL = true;
	IsBoss = true;
}


�������¼���::~�������¼���()
{
}

void �������¼���::Cheak()
{
	int cost = 0;

	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_0;
		e_Move->init(Angle, Position, �����ӵ�, Speed);

		pase = 1;
		timer.start();
	}

	if (����ü�� >= 0)
	{
		switch (pase)
		{
		case 1:
			cost = flower.Process(*Position, ImgSource);
			cost += horming.Process(*Position, ImgSource);
			break;
		}
		����ü�� -= cost;
	}

	flower.Move();
	horming.Move();
}

void �������¼���::RenderBlt()
{
	flower.Render();
	horming.Render();
}
void �������¼���::Release()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		flower.Mgzn_1[i][j].ClearList();

	horming.Mgzn.ClearList();
}