#include "stdafx.h"
#include "ÀÚ¾ÆºØ±«.h"
#include "Managers.h"

ÀÚ¾ÆºØ±«::ÀÚ¾ÆºØ±«()
{
	strcpy_s(SplName, sizeof(SplName), "ÀÚ¾ÆºØ±«");
	prntLBL = true;
	IsBoss = true;
}


ÀÚ¾ÆºØ±«::~ÀÚ¾ÆºØ±«()
{
}

void ÀÚ¾ÆºØ±«::Cheak()
{
	int cost = 0;

	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_3;
		e_Move->¸ñÇ¥xÁÂÇ¥ = (float)DirectX->Window_Source.w / 2 - ImgSource.right / 2;
		e_Move->¸ñÇ¥yÁÂÇ¥ = 150;
		e_Move->init(Angle, Position, ´ÜÀ§¼Óµµ, Speed);

		pase = 1;
		timer.start();
	}

	if (³²ÀºÃ¼·Â >= 0)
	{
		switch (pase)
		{
		case 1:
			cost = spiral.Process(*Position, ImgSource);
			break;
		}
		³²ÀºÃ¼·Â -= cost;
	}

	spiral.Move();
}

void ÀÚ¾ÆºØ±«::RenderBlt()
{
	spiral.Render();
}
void ÀÚ¾ÆºØ±«::Release()
{
	for (int i = 0; i < 4; i++)
		spiral.Mgzn_1[i].ClearList();
}