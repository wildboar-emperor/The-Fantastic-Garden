#pragma once
#include "Enemy.h"
#include "ExtraSpell.h"
class �ܸ�1 :
	public Enemy
{
public:
	ExtraSpell ex;

public:
	�ܸ�1();
	~�ܸ�1();

public:
	void SpellManager() override;
};

