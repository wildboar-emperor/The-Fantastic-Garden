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
		º´½Å[i].Position = { (float)50 + (DirectX->Window_Source.w - 100) / 5 * i, (float)-º´½Å[i].Img.Source.right, 0 };

	for (int i = 0; i < 10; i++)
	{
		ÀÜ¸÷Å¸ÀÔ1[i].Initalize("ÀÜ¸÷1");
		ÀÜ¸÷Å¸ÀÔ1[i].Spell->direction = 4;
		ÀÜ¸÷Å¸ÀÔ1[i].Position = { (float)DirectX->Window_Source.w, 200, 0 };
		ÀÜ¸÷Å¸ÀÔ1[i].Spell->spelltype = 1;
	}
	ÀÜ¸÷µîÀåÄ«¿îÅÍ = 0;
}

void Stage1::Release()
{
	Boss.Release();
	for (int i = 0; i < 5; i++)
		º´½Å[i].Release();
	Sound->Stop(CHAN_BGM);
}

int Stage1::Process()
{
	if (EventTimer.pass(15))
	{
		Boss.µîÀåÇÏ´Ù = true;
	}
	else if (EventTimer.pass(10))
	{
		for (int i = 0; i < 5; i++)
			º´½Å[i].µîÀåÇÏ´Ù = true;
	}
	else if (EventTimer.pass(3))
	{
		if (ÀÜ¸÷µîÀåÅ¸ÀÌ¸Ó.online == false)
		{
			ÀÜ¸÷µîÀåÅ¸ÀÌ¸Ó.start();
		}
		else if (ÀÜ¸÷µîÀåÅ¸ÀÌ¸Ó.pass(0.75))
		{
			if (ÀÜ¸÷µîÀåÄ«¿îÅÍ < 10)
			{
				ÀÜ¸÷Å¸ÀÔ1[ÀÜ¸÷µîÀåÄ«¿îÅÍ].µîÀåÇÏ´Ù = true;
				ÀÜ¸÷µîÀåÄ«¿îÅÍ++;
				ÀÜ¸÷µîÀåÅ¸ÀÌ¸Ó.start();
				
			}
		}
	}


	PLAYER->Process();
	for (int i = 0; i < 5; i++)
		º´½Å[i].Process();
	Boss.Process();
	for (int i = 0; i < 10; i++)
		ÀÜ¸÷Å¸ÀÔ1[i].Process();

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
		if(º´½Å[i].µîÀåÇÏ´Ù)	º´½Å[i].Render();
	if (Boss.µîÀåÇÏ´Ù) Boss.Render();
	for (int i = 0; i < 10; i++)
		ÀÜ¸÷Å¸ÀÔ1[i].Render();
}