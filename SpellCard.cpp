#include "stdafx.h"
#include "SpellCard.h"
#include "Managers.h"

SpellCard::SpellCard()
{
	IsBoss = false;
}


SpellCard::~SpellCard()
{
	SAFE_DELETE(e_Move);
	SAFE_RELEASE(Sprite);
	//SpellLabel.Release();
}

void SpellCard::Initialize(D3DXVECTOR3* Position, RECT ImgSource, D3DXVECTOR3 *Speed, int *Angle, float 단위속도, int 체력)
{
	this->Position = Position;
	this->ImgSource = ImgSource;
	this->Speed = Speed;
	this->Angle = Angle;
	this->단위속도 = 단위속도;
	총체력 = 남은체력 = 체력;
	SpellLabel.initialize(20);
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);
	Hpbar = Imgs->Get("HPBar_Spell");
	Hpbar_rectRight = Hpbar.Source.right;
	SpellLabel.SetPosition(290, 45);
}
bool SpellCard::Process()
{
	Cheak();
	Move();

	if (남은체력 <= 0)
	{
		return true;
	}

	return false;

}

void SpellCard::Move()
{
	if (e_Move) e_Move->Process();
}

void SpellCard::Cheak()
{

}

void SpellCard::Rdr()
{
	
	RenderBlt();
	
	if (IsBoss)
	{
		Hpbar.Source.right = (Hpbar_rectRight)* 남은체력 / 총체력;
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite->Draw(Hpbar.Texture, &Hpbar.Source, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(DirectX->Window_Source.w - Hpbar_rectRight, 16, 0), 0xffffffff);
		Sprite->End();

		if (prntLBL)
		{
			SpellLabel.OutPut(SplName, 255, 255, 255);
		}
	}
}

void SpellCard::Release()
{

}

void SpellCard::RenderBlt()
{

}