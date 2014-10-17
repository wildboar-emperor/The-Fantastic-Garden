#include "stdafx.h"
#include "Boss.h"
#include "Managers.h"
#include "Player.h"

Boss::Boss()
{
	Hpbar = Imgs->Get("HPBar");
	Hpbar_border = Imgs->Get("Interface_Border");
	Hpbar_rectRight = Hpbar.Source.right;
	EnemySearcher = Imgs->Get("Enemy_Searcher");
	bot_border = Imgs->Get("Interface_Border2");
	tName.initialize(20);
	tName.SetPosition(200, 45);
	leftSPellLabel.initialize(50);
	leftSPellLabel.SetPosition(20, 5);
}


Boss::~Boss()
{

	SAFE_RELEASE(leftSPellLabel.Sprite);
}

void Boss::Render()
{
	if (Visible && 등장하다)
	{
		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Sprite->Draw(bot_border.Texture, &bot_border.Source, &Center, &D3DXVECTOR3(0, DirectX->Window_Source.h - bot_border.Source.bottom*2+30, 0), 0xffffffff);
		DrawBullet();
		Sprite->Draw(Img.Texture, &Img.Source, &Center, &Position, 0xffffffff);
		Sprite->Draw(Hpbar.Texture, &Hpbar.Source, &Center, &D3DXVECTOR3(DirectX->Window_Source.w - Hpbar_rectRight, 0, 0), 0xffffffff);
		Sprite->Draw(Hpbar_border.Texture, &Hpbar_border.Source, &Center, &D3DXVECTOR3(0, 0, 0), 0xffffffff);
		Sprite->Draw(EnemySearcher.Texture, &EnemySearcher.Source, &Center, &EnemySearcher_RECT, 0xffffffff);
		Sprite->End();

		tName.OutPut(Name, 255, 255, 255);
		leftSPellLabel.OutPut(leftSpellStr, 255, 0, 0);
	}
}

void Boss::addProc()
{
	EnemySearcher_RECT = { Position.x, (float)DirectX->Window_Source.h - EnemySearcher.Source.bottom, 0 };

	// HPBAR 갱신
	Hpbar.Source.right = (Hpbar_rectRight)* Hit_Point / Hit_Point_max;

	
}