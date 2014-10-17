#pragma once
#include "Sence.h"
class Intro :
	public Sence
{
public:
	Intro();
	virtual ~Intro();

public:
	void Process() override;
	void draw() override;
	void KeyEvent() override;
};

