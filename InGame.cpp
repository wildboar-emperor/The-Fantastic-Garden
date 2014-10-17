#include "stdafx.h"
#include "InGame.h"
#include "Managers.h"
#include "Text.h"
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"

InGame::InGame()
{
	stage_Now = 0;
	stage_Next = 1;
	stageProc();
}


InGame::~InGame()
{
	Release();
}

void InGame::initialize()
{
	bIsRun = true;
	needKeyState = KsDown;

	bg.Initalize("Bg_1");
	bg.ScrollOn = true;
	bg.SetPositionCenter();
}

void InGame::Release()
{
	bg.Release();
	SAFE_DELETE(stage);
}

void InGame::draw()
{
	bg.Render();
	if (stage != nullptr)	stage->Render();
}
void InGame::Process()
{
	bg.Process();
	stage_Next = stage->Process();
	stageProc();
}

void InGame::KeyEvent()
{
	if (PLAYER->CanMove)
	{
		if (INTERRUPT->IsKeyPressing(DIK_Z))
		{
			PLAYER->Mgzn.LunchBullet(D3DXVECTOR3(PLAYER->Position.x + PLAYER->Img.Source.right / 2, PLAYER->Position.y + PLAYER->Img.Source.bottom / 2, 0), 0, "Blt_Player_1");
		}

		if (INTERRUPT->IsKeyPressing(DIK_LEFT))
		{
			PLAYER->Position.x -= PLAYER->Speed.x;
		}

		if (INTERRUPT->IsKeyPressing(DIK_RIGHT))
		{
			PLAYER->Position.x += PLAYER->Speed.x;
		}

		if (INTERRUPT->IsKeyPressing(DIK_UP))
		{
			PLAYER->Position.y -= PLAYER->Speed.y;
		}

		if (INTERRUPT->IsKeyPressing(DIK_DOWN))
		{
			PLAYER->Position.y += PLAYER->Speed.y;
		}

		if (INTERRUPT->IsKeyPressing(DIK_LSHIFT))
		{
			PLAYER->Speed.x = PLAYER->Speed.y = 3.f;
			PLAYER->Shift = true;
			PLAYER->Mgzn.SetBullet(2.5, 30, 0.01f, -1, 0, &PLAYER->Position);
			PLAYER->Charback_Angle += 0.05;
		}
		else
		{
			PLAYER->Speed.x = PLAYER->Speed.y = 7.f;
			PLAYER->Shift = false;
			PLAYER->Mgzn.SetBullet(1, 30, 0.03f, -1, 0, &PLAYER->Position);
		}
	}
}

void InGame::stageProc()
{
	if (stage_Now != stage_Next)
	{
		SAFE_DELETE(stage);

		switch (stage_Next)
		{
		case 1:
			stage = new Stage1;
			break;
		case 2:
			stage = new Stage2;
			break;
		case 3:
			stage = new Stage3;
			break;
		case 4:
			stage = new Stage4;
			break;
		case 5:
			stage = new Stage5;
			break;
		case 6:
			SENCE->NextSence = SENCE_GAMEOVER;
			return;
		}

		stage->Initalize();
		stage_Now = stage_Next;
	}
}