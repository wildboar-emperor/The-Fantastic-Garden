#include "stdafx.h"
#include "Player_Blt_1.h"
#include "Managers.h"

Player_Blt_1::Player_Blt_1()
{
}


Player_Blt_1::~Player_Blt_1()
{
}

void Player_Blt_1::Process()
{
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