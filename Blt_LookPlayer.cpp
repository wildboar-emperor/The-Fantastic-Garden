#include "stdafx.h"
#include "Blt_LookPlayer.h"
#include "Player.h"
#include "Managers.h"

Blt_LookPlayer::Blt_LookPlayer()
{
	setting = true;
}


Blt_LookPlayer::~Blt_LookPlayer()
{
}

void Blt_LookPlayer::Move()
{
	if (setting)
	{
		LookPoint(PLAYER->CCRECT);
		setting = false;
	}

	if (�����ӵ� < 10)
	{
		�����ӵ� *= 1.5;
		if (�����ӵ� > 10)
		{
			�����ӵ� = 10;
		}
	}
}