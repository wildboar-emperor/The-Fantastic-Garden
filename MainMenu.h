#pragma once
#include "Sence.h"
#include "Button.h"
class MainMenu :
	public Sence
{
public:
	int menuCursor;
	Button GameStart;
	Button Album;
	Button Setup;
	Button Exit;

public:
	MainMenu();
	virtual ~MainMenu();

public:
	void initialize() override;
	void Release() override;

	void draw() override;
	void Process() override;
	void KeyEvent() override;
};

