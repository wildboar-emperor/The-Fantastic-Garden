#pragma once
#include "Singleton.h"
#include "Sence.h"
typedef enum SENCETYPE {
	SENCE_EXIT = -1, SECNCE_START, SENCE_INTRO, SENCE_TITLE, SENCE_MENU, SENCE_INGAME, SENCE_GAMEOVER, SENCE_ALBUM, SENCE_SETUP
};
typedef struct {
	UINT msg;
	WPARAM wParam;
	LPARAM lParam;
}WindowMsg;
class SenceManager :
	public Singleton<SenceManager>
{
public:
	Sence *sence;

	int LeftSence;
	int NextSence;


public:
	SenceManager();
	~SenceManager();

public:
	void initialize();
	void Release();
	bool Update();
};

#define SENCE SenceManager::getInstance()