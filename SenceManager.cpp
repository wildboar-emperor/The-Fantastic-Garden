#include "stdafx.h"
#include "SenceManager.h"
#include "Sences.h"

SenceManager::SenceManager()
{
}


SenceManager::~SenceManager()
{
	Release();
}

void SenceManager::initialize()
{
	LeftSence = SECNCE_START;
	NextSence = SENCE_INTRO;

	Update();

}

void SenceManager::Release()
{
	SAFE_DELETE(sence);
}

bool SenceManager::Update()
{
	if (LeftSence != NextSence)
	{
		SAFE_DELETE(sence);

		switch (NextSence)
		{
		case SENCE_EXIT:
			return false;

		case SENCE_INTRO:
			sence = new Intro;
			break;

		case SENCE_TITLE:
			sence = new TitleScreen;
			break;

		case SENCE_MENU:
			sence = new MainMenu;
			break;

		case SENCE_INGAME:
			sence = new InGame;
			break;

		case SENCE_GAMEOVER:
			sence = new GameOver;
			break;

		case SENCE_ALBUM:
			sence = new Album;
			break;

		case SENCE_SETUP:
			sence = new Setup;
			break;
		}

		sence->initialize();
		LeftSence = NextSence;
	}
	return true;
}