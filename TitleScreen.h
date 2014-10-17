#pragma once
#include "Sence.h"
#include "Button.h"
class TitleScreen :
	public Sence
{
public:
	Button pressAnyKey;
	bool CanKeyDown;
	TimeCounter FlashTimer;

public:
	TitleScreen();
	virtual ~TitleScreen();

public:
	void initialize() override;
	void Release() override;

	void draw() override;
	void Process() override;
	void KeyEvent() override;
};

