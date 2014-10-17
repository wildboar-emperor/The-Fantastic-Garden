#include "stdafx.h"

#include "Managers.h"
#include "Sences.h"

#include "TimeCounter.h"


void Release()
{
	DirectX->Release();
	SENCE->Release();
	Sound->Release();
	Imgs->Release();

	delete (DirectX);
	delete (SENCE);
	delete (Sound);
	delete (PLAYER);
	delete (Imgs);
	delete (TIME);
	delete (INTERRUPT);

	ShowCursor(true);
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		DirectX->bIsRun = false;
		return 0;
		
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void LoadResource()
{
	//Intro
	Sound->Add("Intro", "./Resource/sounds/Intro.wav", FMOD_LOOP_OFF);
	Imgs->Add("Background_Intro", "./Resource/bg/intro.jpg");

	//TitleScreen
	Sound->Add("Main_Clicked", "./Resource/sounds/main_clicked.wav", FMOD_LOOP_OFF);
	Imgs->Add("BackGround_Title", "./Resource/bg/titlescreen.jpg");
	Imgs->Add("PressAnyKey", "./Resource/buttons/pressanykey.png");

	//MainMenu
	Sound->Add("Menu_Move", "./Resource/sounds/menu_move.wav", FMOD_LOOP_OFF);
	Sound->Add("Menu_Select", "./Resource/sounds/menu_select.wav", FMOD_LOOP_OFF);
	Imgs->Add("BackGround_Main", "./Resource/bg/mainmenu.jpg");
	Imgs->Add("Album_Cursor", "./Resource/buttons/album_cursor.png");
	Imgs->Add("Album_Normal", "./Resource/buttons/album_nomal.png");
	Imgs->Add("Gamestart_Cursor", "./Resource/buttons/gamestart_cursor.png");
	Imgs->Add("Gamestart_Normal", "./Resource/buttons/gamestart_nomal.png");
	Imgs->Add("Setup_Cursor", "./Resource/buttons/setup_cursor.png");
	Imgs->Add("Setup_Normal", "./Resource/buttons/setup_nomal.png");
	Imgs->Add("Exit_Noraml", "./Resource/buttons/exit_nomal.png");
	Imgs->Add("Exit_Cursor", "./Resource/buttons/exit_cursor.png");

	//Ingame
	Sound->Add("Hit", "./Resource/sounds/hit_enemy.wav", FMOD_LOOP_OFF);
	Sound->Add("E_Dead", "./Resource/sounds/dead_enemy.wav", FMOD_LOOP_OFF);
	Sound->Add("Boss_Dead", "./Resource/sounds/dead_enemy.wav", FMOD_LOOP_OFF);
	Sound->Add("Missile1", "./Resource/sounds/ÃÑ¾Ë¹ß»ç1.wav", FMOD_LOOP_OFF);
	Sound->Add("Missile2", "./Resource/sounds/ÃÑ¾Ë¹ß»ç2.wav", FMOD_LOOP_OFF);
	Sound->Add("Missile3", "./Resource/sounds/ÃÑ¾Ë¹ß»ç3.wav", FMOD_LOOP_OFF);
	Sound->Add("BGM1", "./Resource/bgms/china.mp3", FMOD_LOOP_NORMAL);

	Imgs->Add("Background_Ingame", "./Resource/bg/ingame.jpg");
	Imgs->Add("Bg_1", "./Resource/bg/game_scroll.jpg");
	Imgs->Add("Player_1", "./Resource/unit/player.png");
	Imgs->Add("Hotba", "./Resource/unit/udonge.png");
	Imgs->Add("Chirno", "./Resource/unit/utsuho.png");
	Imgs->Add("CC_Spot", "./Resource/cc_spot.png");
	Imgs->Add("HPBar", "./Resource/interface/enemy_hpbar.jpg");
	Imgs->Add("Blt_Player_1", "./Resource/bullet/player_blt_1.png");
	Imgs->Add("Blt_Enemy_1", "./Resource/bullet/enemy_blt_1.png");
	Imgs->Add("Blt_Enemy_2", "./Resource/bullet/enemy_blt_2.png");
	Imgs->Add("Blt_Enemy_3", "./Resource/bullet/enemy_blt_3.png");
	Imgs->Add("Blt_Enemy_4", "./Resource/bullet/enemy_blt_4.png");
	Imgs->Add("Needle_1", "./Resource/bullet/needle_blt_1.png");
	Imgs->Add("Player_Back", "./Resource/charback.png");
	Imgs->Add("Enemy_Searcher", "./Resource/interface/enemy_searcher.png");
	Imgs->Add("Interface_Border", "./Resource/interface/top_border.png");
	Imgs->Add("HPBar_Spell", "./Resource/interface/spell_hpbar.jpg");
	Imgs->Add("Interface_Border2", "./Resource/interface/bot_border.png");
	Imgs->Add("ÀÜ¸÷1", "./Resource/unit/Chen000.png");

	//GameOver
	Imgs->Add("Background_GameOver", "./Resource/bg/gameover.jpg");
	Imgs->Add("Gomain_Cursor", "./Resource/buttons/gomain_cursor.png");
	Imgs->Add("Gomain_Nomal", "./Resource/buttons/gomain_nomal.png");
	Imgs->Add("Retry_Normal", "./Resource/buttons/retry_nomal.png");
	Imgs->Add("Retry_Cursor", "./Resource/buttons/retry_cursor.png");
}

void initialize()
{
	ShowCursor(false);
	DirectX->initialize((LRESULT)MsgProc);
	Sound->initialize();
	TIME->InitTick();
	LoadResource();
	SENCE->initialize();
	INTERRUPT->Init(DirectX->g_hWnd, 1);

}
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	initialize();
	MSG msg;

	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT && DirectX->bIsRun == true)
	{
		DirectX->FPStimer.start();

		INTERRUPT->Update();

		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		{
			SENCE->sence->Run();
			DirectX->bIsRun = SENCE->Update();
		}

		//DirectX->c_fps = DirectX->FPStimer.FPSLock(APPLICATION_FPS);
		//TIME->CountTick();
		//Sleep(1);
	}

	UnregisterClass(sys_classname, DirectX->g_wc.hInstance);
	Release();
	_CrtDumpMemoryLeaks();
	return 0;
}
