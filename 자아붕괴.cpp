#include "stdafx.h"
#include "�ھƺر�.h"
#include "Managers.h"

�ھƺر�::�ھƺر�()
{
	strcpy_s(SplName, sizeof(SplName), "�ھƺر�");
	prntLBL = true;
	IsBoss = true;
}


�ھƺر�::~�ھƺر�()
{
}

void �ھƺر�::Cheak()
{
	int cost = 0;

	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_3;
		e_Move->��ǥx��ǥ = (float)DirectX->Window_Source.w / 2 - ImgSource.right / 2;
		e_Move->��ǥy��ǥ = 150;
		e_Move->init(Angle, Position, �����ӵ�, Speed);

		pase = 1;
		timer.start();
	}

	if (����ü�� >= 0)
	{
		switch (pase)
		{
		case 1:
			cost = spiral.Process(*Position, ImgSource);
			break;
		}
		����ü�� -= cost;
	}

	spiral.Move();
}

void �ھƺر�::RenderBlt()
{
	spiral.Render();
}
void �ھƺر�::Release()
{
	for (int i = 0; i < 4; i++)
		spiral.Mgzn_1[i].ClearList();
}