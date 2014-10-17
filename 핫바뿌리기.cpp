#include "stdafx.h"
#include "ÇÖ¹Ù»Ñ¸®±â.h"
#include "Move_3.h"

ÇÖ¹Ù»Ñ¸®±â::ÇÖ¹Ù»Ñ¸®±â() 
{
	strcpy_s(SplName, sizeof(SplName), "ÇÖ¹Ù»Ñ¸®±â");
}


ÇÖ¹Ù»Ñ¸®±â::~ÇÖ¹Ù»Ñ¸®±â()
{
}

void ÇÖ¹Ù»Ñ¸®±â::Cheak()
{
	if (timer.online == false)
	{
		SAFE_DELETE(e_Move);
		e_Move = new Move_3;
		e_Move->¸ñÇ¥yÁÂÇ¥ = 50;
		e_Move->¸ñÇ¥xÁÂÇ¥ = -1;
		e_Move->init(Angle, Position, ´ÜÀ§¼Óµµ, Speed);

		pase = 1;
		timer.start();
	}

	if (³²ÀºÃ¼·Â >= 0)
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

void ÇÖ¹Ù»Ñ¸®±â::RenderBlt()
{
	horming.Render();
}
void ÇÖ¹Ù»Ñ¸®±â::Release()
{
	horming.Mgzn.ClearList();
}