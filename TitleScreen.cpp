#include "stdafx.h"
#include "TitleScreen.h"
#include "Managers.h"

TitleScreen::TitleScreen()
{
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::initialize()
{
	bIsRun = true;
	needKeyState = KsDown;

	bg.Initalize("BackGround_Title");


	pressAnyKey.Initalize("PressAnyKey");
	pressAnyKey.Position.x = DirectX->Window_Source.w / 2 - pressAnyKey.Img.Source.right / 2;
	pressAnyKey.Position.y = DirectX->Window_Source.h / 2 - pressAnyKey.Img.Source.bottom / 2;

	EventTimer.start();
	FlashTimer.start();

}

void TitleScreen::Release()
{

	bg.Release();
	pressAnyKey.Release();
}

void TitleScreen::draw()
{
	bg.Render();
	pressAnyKey.Render(0);
}

void TitleScreen::Process()
{
	if (EventTimer.pass(2))
	{
		CanKeyDown = true;
	}
	if (FlashTimer.pass(0.6))
	{
		pressAnyKey.Visible = !pressAnyKey.Visible;
		FlashTimer.start();
	}
	bg.Process();
	pressAnyKey.Process();

}
void TitleScreen::KeyEvent()
{
	if (INTERRUPT->IsKeyPress(DIK_Z) || INTERRUPT->IsKeyPress(DIK_RETURN))
	{
		Sound->Play("Main_Clicked", CHAN_EFFECT);
		SENCE->NextSence = SENCE_MENU;
	}
}