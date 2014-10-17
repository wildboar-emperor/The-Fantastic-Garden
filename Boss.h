#pragma once
#include "Enemy.h"
#include "Image.h"
#include "Text.h"
class Boss :
	public Enemy
{
public:
	Image Hpbar, Hpbar_border, bot_border;
	Image EnemySearcher;
	D3DXVECTOR3 EnemySearcher_RECT;
	int Hpbar_rectRight;
	int leftSpell;
	Text leftSPellLabel;
	char leftSpellStr[8];

public:
	Boss();
	virtual ~Boss();

public:
	void Render() override;
	void addProc() override;

};