#include "stdafx.h"
#include "�ֹٻѸ���.h"
#include "Move_3.h"

�ֹٻѸ���::�ֹٻѸ���() 
{
	strcpy_s(SplName, sizeof(SplName), "�ֹٻѸ���");
}


�ֹٻѸ���::~�ֹٻѸ���()
{
}

void �ֹٻѸ���::Cheak()
{
	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_3;
		e_Move->��ǥy��ǥ = 50;
		e_Move->��ǥx��ǥ = -1;
		e_Move->init(Angle, Position, �����ӵ�, Speed);

		pase = 1;
		timer.start();
	}

	if (����ü�� >= 0)
	{

		switch (pase)
		{
		case 1:
			horming.Process(*Position, ImgSource);
			break;
		}
	}

	horming.Move();
}

void �ֹٻѸ���::RenderBlt()
{
	horming.Render();
}
void �ֹٻѸ���::Release()
{
	horming.Mgzn.ClearList();
}