#include "stdafx.h"
#include "Entity.h"
#include "Managers.h"


Entity::Entity()
{
	Center = { 0, 0, 0 };
	//Initalize();
	retainCount = 0;
	Opacity = 255;
}


Entity::~Entity()
{
	Release();
}


void Entity::Initalize(const char* imgsrc)
{

	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);

	Img = Imgs->Get(imgsrc);
	Visible = true;

}


void Entity::Render()
{
	if (Visible)
	{
		D3DXMATRIX World;
		D3DXMatrixTransformation2D(&World, &D3DXVECTOR2(0, 0), 0,
			0, &D3DXVECTOR2(Position.x + Img.Source.right / 2, Position.y + Img.Source.bottom / 2), RealAngle, &D3DXVECTOR2(0, 0));
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite->SetTransform(&World);
		Sprite->Draw(Img.Texture, &Img.Source, &Center, &Position, D3DCOLOR_ARGB((int)Opacity, 0xff, 0xff, 0xff));
		Sprite->End();
	}
}


void Entity::Process()
{
	
}


void Entity::Release()
{
	if (retainCount == 0)
	{
		SAFE_RELEASE(Sprite);
	}
	else
	{
		retainCount--;
	}
}

void Entity::SetPositionCenter()
{
	Position = {
		(float)(DirectX->Window_Source.w / 2 - Img.Source.right / 2),
		(float)(DirectX->Window_Source.h / 2 - Img.Source.bottom / 2),
		0
	};

	SetCenter();
}

void Entity::SetCenter()
{
	//Center = { Position.x + Img.Source.right / 2, Position.y + Img.Source.bottom / 2, 0 };

	Center = { 0, 0, 0 };
}