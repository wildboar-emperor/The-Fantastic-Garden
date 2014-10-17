#include "stdafx.h"
#include "MainMenu.h"
#include "Managers.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
	Release();
}


void MainMenu::initialize()
{
	bIsRun = true;
	bg.Initalize("BackGround_Main");
	GameStart.Initalize("Gamestart_Normal", "Gamestart_Cursor");
	Album.Initalize("Album_Normal", "Album_Cursor");
	Setup.Initalize("Setup_Normal", "Setup_Cursor");
	Exit.Initalize("Exit_Noraml", "Exit_Cursor");

	GameStart.Position = { (float)DirectX->Window_Source.w - (GameStart.Img.Source.right - 30), (float)DirectX->Window_Source.h - 450, 0 };
	Album.Position = { (float)DirectX->Window_Source.w - (GameStart.Img.Source.right - 30), (float)DirectX->Window_Source.h - 390, 0 };
	Setup.Position = { (float)DirectX->Window_Source.w - (GameStart.Img.Source.right - 30), (float)DirectX->Window_Source.h - 330, 0 };
	Exit.Position = { (float)DirectX->Window_Source.w - (GameStart.Img.Source.right - 30), (float)DirectX->Window_Source.h - 270, 0 };

	EventTimer.start();
}
enum { s_menu_start, s_menu_album, s_menu_setup, s_menu_exit };

void MainMenu::Release()
{
	bg.Release();
	GameStart.Release();
	Album.Release();
	Setup.Release();
	Exit.Release();
}

void MainMenu::draw()
{
	bg.Render();
	GameStart.Render((menuCursor == s_menu_start));
	Album.Render((menuCursor == s_menu_album));
	Setup.Render((menuCursor == s_menu_setup));
	Exit.Render((menuCursor == s_menu_exit));
}

void MainMenu::Process()
{
	bg.Process();
	GameStart.Process();
	Album.Process();
	Setup.Process();
	Exit.Process();

	switch (menuCursor)
	{
	case s_menu_start:
		if (GameStart.Position.x >= DirectX->Window_Source.w - (GameStart.Img.Source.right))
		{
			GameStart.Position.x -= 3;
		}
		if (Album.Position.x <= DirectX->Window_Source.w - (Album.Img.Source.right - 30))
		{
			Album.Position.x += 3;
		}
		if (Setup.Position.x <= DirectX->Window_Source.w - (Setup.Img.Source.right - 30))
		{
			Setup.Position.x += 3;
		}
		if (Exit.Position.x <= DirectX->Window_Source.w - (Exit.Img.Source.right - 30))
		{
			Exit.Position.x += 3;
		}
		break;
	case s_menu_album:
		if (GameStart.Position.x <= DirectX->Window_Source.w - (GameStart.Img.Source.right - 30))
		{
			GameStart.Position.x += 3;
		}
		if (Album.Position.x >= DirectX->Window_Source.w - (Album.Img.Source.right))
		{
			Album.Position.x -= 3;
		}
		if (Setup.Position.x <= DirectX->Window_Source.w - (Setup.Img.Source.right - 30))
		{
			Setup.Position.x += 3;
		}
		if (Exit.Position.x <= DirectX->Window_Source.w - (Exit.Img.Source.right - 30))
		{
			Exit.Position.x += 3;
		}
		break;
	case s_menu_setup:
		if (GameStart.Position.x <= DirectX->Window_Source.w - (GameStart.Img.Source.right - 30))
		{
			GameStart.Position.x += 3;
		}
		if (Album.Position.x <= DirectX->Window_Source.w - (Album.Img.Source.right - 30))
		{
			Album.Position.x += 3;
		}
		if (Setup.Position.x >= DirectX->Window_Source.w - (Setup.Img.Source.right))
		{
			Setup.Position.x -= 3;
		}
		if (Exit.Position.x <= DirectX->Window_Source.w - (Exit.Img.Source.right - 30))
		{
			Exit.Position.x += 3;
		}
		break;
	case s_menu_exit:
		if (GameStart.Position.x <= DirectX->Window_Source.w - (GameStart.Img.Source.right - 30))
		{
			GameStart.Position.x += 3;
		}
		if (Album.Position.x <= DirectX->Window_Source.w - (Album.Img.Source.right - 30))
		{
			Album.Position.x += 3;
		}
		if (Setup.Position.x <= DirectX->Window_Source.w - (Setup.Img.Source.right - 30))
		{
			Setup.Position.x += 3;
		}
		if (Exit.Position.x >= DirectX->Window_Source.w - (Exit.Img.Source.right))
		{
			Exit.Position.x -= 3;
		}
		break;
	}
}
void MainMenu::KeyEvent()
{
	if (INTERRUPT->IsKeyPress(DIK_UP))
	{
		if (menuCursor > s_menu_start)
		{
			menuCursor--;
			Sound->Play("Menu_Move", CHAN_EFFECT);
		}
	}

	if (INTERRUPT->IsKeyPress(DIK_DOWN))
	{
		if (menuCursor < s_menu_exit)
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
		case s_menu_start:
			SENCE->NextSence = SENCE_INGAME;
			break;

		case s_menu_album:
			SENCE->NextSence = SENCE_ALBUM;
			break;

		case s_menu_setup:
			SENCE->NextSence = SENCE_SETUP;
			break;

		case s_menu_exit:
			SENCE->NextSence = SENCE_EXIT;
			break;
		}
	}
}