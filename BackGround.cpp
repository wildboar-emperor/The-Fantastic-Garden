#include "stdafx.h"
#include "Background.h"
#include "Managers.h"

Background::Background()
{
	ScrollSpeed = 10;
}


Background::~Background()
{
}


void Background::Initalize(const char* str)
{
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);

	Img = Imgs->Get(str);

	Visible = true;
	Position = { 0, 0, 0 };
	ScrollVec = { 0, Position.y - Img.Source.bottom, 0 };
}

void Background::Render()
{
	if (Visible)
	{
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite->Draw(Img.Texture, &Img.Source, &Center, &Position, 0xffffffff);
		if (ScrollOn)
		{
			Sprite->Draw(Img.Texture, &Img.Source, &Center, &ScrollVec, 0xffffffff);
		}
		Sprite->End();
	}
}

void Background::Process()
{
	if (ScrollOn)
	{
		Position.y += ScrollSpeed;
		ScrollVec.y += ScrollSpeed;

		if (Position.y >= DirectX->Window_Source.h)
		{
			Position.y = -Img.Source.bottom;
		}
		if (ScrollVec.y >= DirectX->Window_Source.h)
		{
			ScrollVec.y = -Img.Source.bottom;
		}
	}
}