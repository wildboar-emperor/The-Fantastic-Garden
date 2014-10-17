#pragma once
#include "Enemy.h"
#include "ExtraSpell.h"
class 接光1 :
	public Enemy
{
public:
	ExtraSpell ex;

public:
	接光1();
	~接光1();

public:
	void SpellManager() override;
};

