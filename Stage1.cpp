#include "stdafx.h"
#include "Stage1.h"


Stage1::Stage1()
{
	Initalize();
	EventTimer.start();
}


Stage1::~Stage1()
{
	Release();
}


void Stage1::Initalize()
{
	PLAYER->Initalize("Player_1");

	Sound->Play("BGM1", CHAN_BGM);
	PLAYER->Charback_Angle = 0;

	for (int i = 0; i < 5; i++)
		����[i].Position = { (float)50 + (DirectX->Window_Source.w - 100) / 5 * i, (float)-����[i].Img.Source.right, 0 };

	for (int i = 0; i < 10; i++)
	{
		�ܸ�Ÿ��1[i].Initalize("�ܸ�1");
		�ܸ�Ÿ��1[i].Spell->direction = 4;
		�ܸ�Ÿ��1[i].Position = { (float)DirectX->Window_Source.w, 200, 0 };
		�ܸ�Ÿ��1[i].Spell->spelltype = 1;
	}
	�ܸ�����ī���� = 0;
}

void Stage1::Release()
{
	Boss.Release();
	for (int i = 0; i < 5; i++)
		����[i].Release();
	Sound->Stop(CHAN_BGM);
}

int Stage1::Process()
{
	if (EventTimer.pass(15))
	{
		Boss.�����ϴ� = true;
	}
	else if (EventTimer.pass(10))
	{
		for (int i = 0; i < 5; i++)
			����[i].�����ϴ� = true;
	}
	else if (EventTimer.pass(3))
	{
		if (�ܸ�����Ÿ�̸�.online == false)
		{
			�ܸ�����Ÿ�̸�.start();
		}
		else if (�ܸ�����Ÿ�̸�.pass(0.75))
		{
			if (�ܸ�����ī���� < 10)
			{
				�ܸ�Ÿ��1[�ܸ�����ī����].�����ϴ� = true;
				�ܸ�����ī����++;
				�ܸ�����Ÿ�̸�.start();
				
			}
		}
	}


	PLAYER->Process();
	for (int i = 0; i < 5; i++)
		����[i].Process();
	Boss.Process();
	for (int i = 0; i < 10; i++)
		�ܸ�Ÿ��1[i].Process();

	if (Boss.Hit_Point <= 0 || Boss.leftSpell == -1)
	{
		ClearFlag = true;
	}

	if (ClearFlag)
		return 2;

	return 1;
}

void Stage1::Render()
{

	PLAYER->Render();
	
	for (int i = 0; i < 5; i++)
		if(����[i].�����ϴ�)	����[i].Render();
	if (Boss.�����ϴ�) Boss.Render();
	for (int i = 0; i < 10; i++)
		�ܸ�Ÿ��1[i].Render();
}