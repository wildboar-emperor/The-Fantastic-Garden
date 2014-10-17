#pragma once
#include "Bullet.h"
class Blt_Normal :
	public Bullet
{
public:
	Blt_Normal();
	virtual ~Blt_Normal();

public:
	void Move() override;
};

