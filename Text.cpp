#include "stdafx.h"
#include "Text.h"
#include "Managers.h"

Text::Text()
{
}


Text::~Text()
{
}


void Text::initialize(int fontSize)
{
	this->fontSize = fontSize;
	D3DXCreateFont(DirectX->g_pd3dDevice, fontSize, 0, FW_NORMAL, 1, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "¸¼Àº °íµñ", &font);
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);


	SetPosition(0, 0);
	Visible = true;
}


void Text::Release()
{
}


void Text::OutPut(const char* str, int r = 255, int g = 255, int b = 255)
{
	if (Visible)
	{
		Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		font->DrawText(Sprite, str, -1, &Source, DT_NOCLIP, D3DCOLOR_XRGB(r, g, b));
		Sprite->End();
	}
}

void Text::SetPosition(int x, int y)
{
	Source = { x, y, 0, 0 };
}