#include "stdafx.h"
#include "Unit.h"
#include "Managers.h"
#include "Utill.h"

Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::Render()
{
	if (Visible && 등장하다)
	{
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		DrawBullet();
		Sprite->Draw(Img.Texture, &Img.Source, &Center, &Position, 0xffffffff);
		Sprite->End();
	}
}

bool Unit::Unit_Cheak()
{

	if (Hit_Point <= 0)
	{
		return true;
	}

	return false;
}


void Unit::DrawBullet()
{

}