#include "stdafx.h"
#include "ExtraSpell.h"


ExtraSpell::ExtraSpell()
{
	strcpy_s(SplName, sizeof(SplName), "ExtraSpell");
	단위속초기화 = false;
	단위속도증감량 = 2;
}


ExtraSpell::~ExtraSpell()
{
}

void ExtraSpell::Cheak()
{
	if (단위속도 != 0 && 단위속초기화 == false)
	{
		X단위속 = Y단위속 = 단위속도 / 2;
		단위속초기화 = true;
	}
	else if (남은체력 >= 0)
	{
		// 숫자 키패드 5를 기준으로 한 방향

		switch (direction)
		{
		case 1:
			Speed->x = -단위속도 / 2;
			Speed->y = 단위속도 / 2;
			break;

		case 2:
			Speed->x = 0;
			Speed->y = 단위속도;
			break;

		case 3:
			Speed->x = 단위속도 / 2;
			Speed->y = 단위속도 / 2;
			break;

		case 4:
			Speed->x = -단위속도;
			Speed->y = 0;
			break;


		case 6:
			Speed->x = 단위속도;
			Speed->y = 0;
			break;

		case 7:
			Speed->x = -단위속도 / 2;
			Speed->y = 단위속도 / 2;
			break;

		case 8:
			Speed->x = 0;
			Speed->y = -단위속도;
			break;

		case 9:
			Speed->x = 단위속도 / 2;
			Speed->y = -단위속도 / 2;
			break;


			// 여기서부턴 대각선 이동입니다


		}

		if (Speed->x > 단위속도)
		{
			Speed->x = 단위속도;
		}
		else if (Speed->x <-단위속도)
		{
			Speed->x = -단위속도;
		}
		if (Speed->y > 단위속도)
		{
			Speed->y = 단위속도;
		}
		else if (Speed->y < -단위속도)
		{
			Speed->y = -단위속도;
		}

		switch (this->spelltype)
		{
		case 1:
			horming.Process(*Position, ImgSource);
		}

		horming.Move();

		Position->x += Speed->x;
		Position->y += Speed->y;
	}

}
void ExtraSpell::RenderBlt()
{
	horming.Render();
}
void ExtraSpell::Release()
{
	horming.Mgzn.ClearList();
}
