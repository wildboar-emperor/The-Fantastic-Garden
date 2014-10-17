#pragma once
#include "Sence.h"
#include "Player.h"
#include "Stage.h"
class InGame :
	public Sence
{
private:
	Stage *stage;

public:
	int stage_Now, stage_Next;

public:
	InGame();
	virtual ~InGame();

public:
	void initialize() override;
	void Release() override;

	void draw() override;
	void Process() override;
	void KeyEvent() override;
	void stageProc();
	
};

