#include "stdafx.h"
#include "ExtraSpell.h"


ExtraSpell::ExtraSpell()
{
	strcpy_s(SplName, sizeof(SplName), "ExtraSpell");
	�������ʱ�ȭ = false;
	�����ӵ������� = 2;
}


ExtraSpell::~ExtraSpell()
{
}

void ExtraSpell::Cheak()
{
	if (�����ӵ� != 0 && �������ʱ�ȭ == false)
	{
		X������ = Y������ = �����ӵ� / 2;
		�������ʱ�ȭ = true;
	}
	else if (����ü�� >= 0)
	{
		// ���� Ű�е� 5�� �������� �� ����

		switch (direction)
		{
		case 1:
			Speed->x = -�����ӵ� / 2;
			Speed->y = �����ӵ� / 2;
			break;

		case 2:
			Speed->x = 0;
			Speed->y = �����ӵ�;
			break;

		case 3:
			Speed->x = �����ӵ� / 2;
			Speed->y = �����ӵ� / 2;
			break;

		case 4:
			Speed->x = -�����ӵ�;
			Speed->y = 0;
			break;


		case 6:
			Speed->x = �����ӵ�;
			Speed->y = 0;
			break;

		case 7:
			Speed->x = -�����ӵ� / 2;
			Speed->y = �����ӵ� / 2;
			break;

		case 8:
			Speed->x = 0;
			Speed->y = -�����ӵ�;
			break;

		case 9:
			Speed->x = �����ӵ� / 2;
			Speed->y = -�����ӵ� / 2;
			break;


			// ���⼭���� �밢�� �̵��Դϴ�


		}

		if (Speed->x > �����ӵ�)
		{
			Speed->x = �����ӵ�;
		}
		else if (Speed->x <-�����ӵ�)
		{
			Speed->x = -�����ӵ�;
		}
		if (Speed->y > �����ӵ�)
		{
			Speed->y = �����ӵ�;
		}
		else if (Speed->y < -�����ӵ�)
		{
			Speed->y = -�����ӵ�;
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
