#pragma once
#include "Bullet.h"
#include "TimeCounter.h"
class Blt_LookPlayer :
	public Bullet
{
public:
	bool setting;

public:
	Blt_LookPlayer();
	virtual ~Blt_LookPlayer();

public:
	void Move() override;
};

