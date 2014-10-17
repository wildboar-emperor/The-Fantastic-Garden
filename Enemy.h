#pragma once
#include "Unit.h"
#include "SpellCard.h"
#include "TimeCounter.h"
#include "Magazine.h"
#include "Player_Blt_1.h"
#include "Player_Blt_LookEnemy.h"
class Enemy :
	public Unit
{
public:
	SpellCard *Spell;
	bool NextSpellEnable;

	int pase;
	TimeCounter timer;
	Magazine<Player_Blt_1> *p_Mgzn;

private:
	TimeCounter spellezen;
	TimeCounter deadzen;

public:
	Enemy();
	virtual ~Enemy();

public:
	void Process() override;
	virtual void addProc();
	virtual void SpellManager();
	void GetP_Mgzn(Magazine<Player_Blt_1> *p_Mgzn);
	void DrawBullet();
};

