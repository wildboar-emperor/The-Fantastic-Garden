#pragma once
#include "Sence.h"
#include "Button.h"
class GameOver :
	public Sence
{
public:
	Button btnRetry;
	Button btnExit;	
	int menuCursor;

public:
	GameOver();
	virtual ~GameOver();

public:
	void initialize() override;
	void Release() override;

	void draw() override;
	void Process() override;
	void KeyEvent() override;
};

