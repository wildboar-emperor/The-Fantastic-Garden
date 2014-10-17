#include "stdafx.h"
#include "Intro.h"
#include "Managers.h"

Intro::Intro()
{
	bIsRun = true;
	bg.Initalize("Background_Intro");
	EventTimer.start();
	bg.Opacity = 0;
	Sound->Play("Intro", CHAN_EFFECT);
}

Intro::~Intro()
{
	bg.Release();
}

void Intro::Process()
{
	if (EventTimer.pass(3.2))
	{
		SENCE->NextSence = SENCE_TITLE;
	}
	else if (EventTimer.pass(2.5))
	{
		bg.Opacity -= 10;
		if (bg.Opacity < 0)	bg.Opacity = 0;
	}
	else if (EventTimer.pass(1.5))
	{
		bg.Opacity = 255;
	}
	else
	{
		bg.Opacity += 10;
		if (bg.Opacity > 255)	bg.Opacity = 255;
	}

	bg.Process();
}

void Intro::draw()
{
	bg.Render();
}

void Intro::KeyEvent()
{
	if (INTERRUPT->IsKeyPress(DIK_Z) || INTERRUPT->IsKeyPress(DIK_RETURN))
	{
		SENCE->NextSence = SENCE_TITLE;
	}
}