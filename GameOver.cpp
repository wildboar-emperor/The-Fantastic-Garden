#include "stdafx.h"
#include "GameOver.h"
#include "Managers.h"

GameOver::GameOver()
{
}


GameOver::~GameOver()
{
	Release();
}

void GameOver::initialize()
{
	bIsRun = true;
	needKeyState = KsDown;
	menuCursor = 0;

	bg.Initalize("Background_GameOver");

	btnRetry.Initalize("Retry_Normal", "Retry_Cursor");
	btnRetry.Position.x = DirectX->Window_Source.w / 2 - btnRetry.Img.Source.right / 2;
	btnRetry.Position.y = DirectX->Window_Source.h / 2 - btnRetry.Img.Source.bottom / 2 - 100;

	btnExit.Initalize("Gomain_Nomal", "Gomain_Cursor");
	btnExit.Position.x = DirectX->Window_Source.w / 2 - btnExit.Img.Source.right / 2;
	btnExit.Position.y = DirectX->Window_Source.h / 2 - btnExit.Img.Source.bottom / 2 + 100;
}

enum { s_gov_RETRY, s_gov_EXIT};

void GameOver::Release()
{
	bg.Release();
	btnRetry.Release();
	btnExit.Release();
}

void GameOver::draw()
{
	bg.Render();
	btnRetry.Render((menuCursor == s_gov_RETRY));
	btnExit.Render((menuCursor == s_gov_EXIT));
}
void GameOver::Process()
{
	bg.Process();
	btnRetry.Process();
	btnExit.Process();

}
void GameOver::KeyEvent()
{
	if (INTERRUPT->IsKeyPress(DIK_UP))
	{
		if (menuCursor > s_gov_RETRY)
		{
			menuCursor--;
			Sound->Play("Menu_Move", CHAN_EFFECT);
		}
	}

	if (INTERRUPT->IsKeyPress(DIK_DOWN))
	{
		if (menuCursor < s_gov_EXIT)
		{
			menuCursor++;
			Sound->Play("Menu_Move", CHAN_EFFECT);
		}
	}

	if (INTERRUPT->IsKeyPress(DIK_RETURN) || INTERRUPT->IsKeyPress(DIK_Z))
	{
		Sound->Play("Menu_Select", CHAN_EFFECT);
		switch (menuCursor)
		{
		case s_gov_RETRY:
			SENCE->NextSence = SENCE_INTRO;
			break;

		case s_gov_EXIT:
			SENCE->NextSence = SENCE_MENU;
			break;
		}
	}
}