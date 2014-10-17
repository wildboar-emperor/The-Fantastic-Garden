#include "stdafx.h"
#include "Player_Blt_LookEnemy.h"
#include "Managers.h"
#include "Player.h"

Player_Blt_LookEnemy::Player_Blt_LookEnemy()
{
	//timer.start();
}


Player_Blt_LookEnemy::~Player_Blt_LookEnemy()
{

}

void Player_Blt_LookEnemy::Process()
{
	if (PLAYER->e_pos_targetPos.Inited)
	{
		LookPoint(*(PLAYER->e_pos_targetPos.Position));
	}

	if (Position.y > DirectX->Window_Source.h + 40.0f)
	{
		Visible = false;
	}
	else if (Position.y < -40.0f)
	{
		Visible = false;
	}
	if (Position.x > DirectX->Window_Source.w + 40.0f)
	{
		Visible = false;
	}
	else if (Position.x < -40.f)
	{
		Visible = false;
	}

	Position.x += Speed.x;
	Position.y += Speed.y;

}