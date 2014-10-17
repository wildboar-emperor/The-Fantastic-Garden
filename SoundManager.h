#pragma once
#include "Singleton.h"
#include <list>
#include <fmod.hpp>
#pragma comment (lib, "fmodex_vc.lib")
typedef enum {
	CHAN_BGM, CHAN_PLAYER, CHAN_PLAYER_BLT, CHAN_ENEMY, CHAN_ENEMY_BLT, CHAN_EFFECT, CHAN_MAX
}CHANNELTYPE;
typedef struct
{
	char Label[128];
	FMOD::Sound *Snd;
}SoundMap;
class SoundManager :
	public Singleton<SoundManager>
{
public:
	FMOD::System *SndSystem;
	FMOD::Channel *Channel[CHAN_MAX];
	std::list<SoundMap> LoadedSounds;

public:
	SoundManager();
	~SoundManager();

public:
	void initialize();
	void Release();

public:
	void Add(const char* label, const char* src, DWORD loop);
	void Play(const char* label, CHANNELTYPE channel);
	void Pause(CHANNELTYPE channel);
	void Stop(CHANNELTYPE channel);
	void CleanUp();
};

#define Sound SoundManager::getInstance()