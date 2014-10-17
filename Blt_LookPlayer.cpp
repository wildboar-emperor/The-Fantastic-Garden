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

	if (단위속도 < 10)
	{
		단위속도 *= 1.5;
		if (단위속도 > 10)
		{
			단위속도 = 10;
		}
	}
}