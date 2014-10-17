#pragma once
#include "Boss.h"
#include "Chirno_PerfectFreeze.h"
class Chirno :
	public Boss
{
public:
	Chirno();
	virtual ~Chirno();

public:
	void SpellManager() override;
};

