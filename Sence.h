#pragma once
#include "BackGround.h"
#include "TimeCounter.h"
typedef enum KEYTYPE {
	EK_LEFT =		0x00000001,
	EK_RIGHT =	0x00000010,
	EK_UP =		0x00000100,
	EK_DOWN =	0x00001000,
	EK_Z =			0x00010000,
	EK_X =			0x00100000,
	EK_SHIFT =	0x01000000,
	EK_ENTER =	0x10000000,
};
typedef enum KEYSTATE {
	KsDown = 1, KsUp = 0
};
class Sence
{
public:
	bool bIsRun;
	KEYSTATE needKeyState;
	TimeCounter EventTimer;

protected:
	Background bg;

public:
	Sence();
	virtual ~Sence();

public:
	virtual void initialize();
	virtual void Release();

	void Render();
	virtual void Process();
	virtual void KeyEvent();

	unsigned long Input(KEYSTATE kst);
	virtual void draw();

	void Run();
};
