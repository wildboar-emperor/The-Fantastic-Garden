#include "stdafx.h"
#include "Player.h"
#include "Managers.h"


Player::Player()
{
	State = 0;
	CanMove = true;
	e_pos_targetPos.Inited = false;
}


Player::~Player()
{
}

void Player::Render()
{
	if (Visible)
	{
		D3DXMATRIX World;

		D3DXMatrixTransformation2D(&World, &D3DXVECTOR2(0, 0), 0,
			0, &D3DXVECTOR2(Position.x + Img.Source.right / 2, Position.y + Img.Source.bottom / 2), Charback_Angle, &D3DXVECTOR2(0, 0));

		CharbackSprite->Begin(D3DXSPRITE_ALPHABLEND);
		CharbackSprite->SetTransform(&World);
		if (Shift) CharbackSprite->Draw(Charback.Texture, &Charback.Source, &Center, &CharbackRECT, 0xffffffff);;
		CharbackSprite->End();

		Sprite->Begin(D3DXSPRITE_ALPHABLEND);
		DrawBullet();

		Sprite->Draw(Img.Texture, &Img.Source, &Center, &Position, 0xffffffff);
		Sprite->Draw(CC.Texture, &CC.Source, &Center, &CCRECT, 0xffffffff);
		Sprite->End();
	}
}

void Player::Process()
{
	if (Hit_Point <= 0)
	{
		Visible = false;
		Sound->Play("E_Dead", CHAN_PLAYER);
		SENCE->NextSence = SENCE_GAMEOVER;
		State = 0;
		e_pos.clear();
		e_pos_targetPos.Visible = nullptr;
		e_pos_targetPos.Inited = false;
	}


	switch (State)
	{
	case 0:

		if (Position.y > DirectX->Window_Source.h * 8 / 10 - PLAYER->Img.Source.bottom / 2)
		{
			Position.y -= 2.5;
			CanMove = false;
		}
		else
		{
			CanMove = true;
			State = 1;
			timer.start();
		}
		break;

	case 1:
		deadvisiblecounter = 0;

		
		/*
		// 호밍 미사일
		for (std::list<e_Position>::iterator itr = e_pos.begin(); itr != e_pos.end();)
		{
			if (*(itr->Visible) == false)
			{
				itr = e_pos.erase(itr);
				continue;
			}

			if (e_pos_targetPos.Inited == false
				|| *(e_pos_targetPos.Visible) == false
				||	sqrt(
					pow(Position.x - itr->Position->x, 2) +
					pow(Position.y - itr->Position->y, 2))
				<	sqrt(
					pow(Position.x - e_pos_targetPos.Position->x, 2) +
					pow(Position.y - e_pos_targetPos.Position->y, 2))
				)
			{
				e_pos_targetPos.Position = itr->Position;
				e_pos_targetPos.Visible = itr->Visible;
				e_pos_targetPos.Inited = true;
			}

			itr++;
		}*/
		
		Visible = true;

		break;

	case 2:
		e_pos.clear();
		e_pos_targetPos.Visible = nullptr;
		if (Position.y > DirectX->Window_Source.h * 8 / 10 - PLAYER->Img.Source.bottom / 2)
		{
			Position.y -= 2.5;
			CanMove = false;
		}
		else
			CanMove = true;

		if (deadvisiblecounter > 10)
		{
			State = 1;
		}
		else
		{
			if (timer.pass(0.2))
			{
				deadvisiblecounter++;
				Visible =! Visible;
				timer.start();
			}
		}
	}

	if (Position.x < 0) Position.x = 0;
	else if (Position.x >(float)(DirectX->Window_Source.w - Img.Source.right)) Position.x = (float)(DirectX->Window_Source.w - Img.Source.right);

	if (Position.y < 0) Position.y = 0;
	else if (Position.y >(float)(DirectX->Window_Source.h - Img.Source.bottom)) Position.y = (float)(DirectX->Window_Source.h - Img.Source.bottom);

	CCRECT.x = Position.x + Img.Source.right / 2 - CC.Source.right / 2;
	CCRECT.y = Position.y + Img.Source.bottom / 2 - CC.Source.bottom / 2;

	CharbackRECT.x = CCRECT.x - Charback.Source.right / 2;
	CharbackRECT.y = CCRECT.y - Charback.Source.bottom / 2;

	Mgzn.MoveBullet();
}

void Player::DrawBullet()
{
	Mgzn.DrawBullet();
}

void Player::Initalize(const char* src)
{
	Img = Imgs->Get(src);
	D3DXCreateSprite(DirectX->g_pd3dDevice, &Sprite);
	D3DXCreateSprite(DirectX->g_pd3dDevice, &CharbackSprite);
	Img.LoadTexture(src);
	CC = Imgs->Get("CC_Spot");
	Charback = Imgs->Get("Player_Back");
	Visible = true;
	Hit_Point = 3;
	PLAYER->Mgzn.SetBullet(1, 30, 0.03f, 1, 0, &PLAYER->Position);
	Speed.x = Speed.y = 7.f;
	SetPositionCenter();
	Position.y = (float)(DirectX->Window_Source.h * 8 / 10 - PLAYER->Img.Source.bottom / 2);
	Mgzn.Bullettimer.start();
	e_pos_targetPos.Visible = nullptr;
	e_pos_targetPos.Inited = false;
}

void Player::Release()
{
	if (Sprite)
		Sprite->Release();
	Mgzn.ClearList();
}

void Player::Hit(int ad)
{
	Sound->Play("Hit", CHAN_PLAYER);
	Hit_Point -= ad;
	State = 2;
	SetPositionCenter();
	Position.y = DirectX->Window_Source.h;

	CCRECT.x = Position.x + Img.Source.right / 2 - CC.Source.right / 2;
	CCRECT.y = Position.y + Img.Source.bottom / 2 - CC.Source.bottom / 2;

	CharbackRECT.x = CCRECT.x - Charback.Source.right / 2;
	CharbackRECT.y = CCRECT.y - Charback.Source.bottom / 2;

	Shift = false;
	Mgzn.ClearList();
}