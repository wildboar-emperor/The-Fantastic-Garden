#include "stdafx.h"
#include "Button.h"
#include "Managers.h"

Button::Button()
{
}


Button::~Button()
{
}
void Button::Initalize(const char* imgsrc)
{
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);

	Img = Imgs->Get(imgsrc);

	Visible = true;
	this->Position = Position;
}

void Button::Initalize(const char* imgsrc_nomal, const char* imgsrc_highlight)
{
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);

	Img = Imgs->Get(imgsrc_nomal);
	HImg = Imgs->Get(imgsrc_highlight);

	Visible = true;
	this->Position = Position;
}

void Button::Render(bool highlight)
{
	if (Visible)
	{
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite->Draw((highlight) ? HImg.Texture: Img.Texture, &Img.Source, &Center, &Position, 0xffffffff);
		Sprite->End();
	}
}

void Button::Process()
{
	if (Visible)
	{
		if (OnClickedEvent())
		{
			;
		}
	}
}

bool Button::OnClickedEvent()
{
	return true;
}