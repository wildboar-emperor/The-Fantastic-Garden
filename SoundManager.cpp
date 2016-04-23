#include "stdafx.h"
#include "SoundManager.h"


SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::initialize()
{
	FMOD::System_Create(&SndSystem);
	SndSystem->init(CHAN_MAX, FMOD_INIT_NORMAL, NULL);
}

void SoundManager::Release()
{
	CleanUp();
	SndSystem->release();
}

void SoundManager::CleanUp()
{
	for (std::list<SoundMap>::iterator itr = LoadedSounds.begin(); itr != LoadedSounds.end();)
	{
		itr->Snd->release();
		itr = LoadedSounds.erase(itr);
	}
}

void SoundManager::Add(const char* label, const char* src, DWORD loop)
{
	for (std::list<SoundMap>::iterator itr = LoadedSounds.begin(); itr != LoadedSounds.end(); itr++)
	{
		if (strcmp(itr->Label, label) == 0)
		{
			return;
		}
	}

	SoundMap t_snd;
	strcpy_s(t_snd.Label, 128, label);
	SndSystem->createSound(src, loop, 0, &t_snd.Snd);
	
	LoadedSounds.push_back(t_snd);
}

void SoundManager::Play(const char* label, CHANNELTYPE channel)
{
	for (std::list<SoundMap>::iterator itr = LoadedSounds.begin(); itr != LoadedSounds.end(); itr++)
	{
		if (strcmp(itr->Label, label) == 0)
		{
			//SndSystem->playSound(FMOD_CHANNEL_REUSE, itr->Snd, 0, &Channel[channel]); // no works
			SndSystem->playSound( itr->Snd, 0, 0, &Channel[channel]); 
			return;
		}
	}
}

void SoundManager::Pause(CHANNELTYPE channel)
{
	bool bIspaused;

	Channel[channel]->getPaused(&bIspaused);
	Channel[channel]->setPaused(!bIspaused);
}

void SoundManager::Stop(CHANNELTYPE channel)
{
	bool bisPlaying;

	Channel[channel]->isPlaying(&bisPlaying);
	if (bisPlaying)
	{
		Channel[channel]->stop();
	}
}
