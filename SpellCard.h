#pragma once
#include "MovePattern.h"
#include "Magazine.h"
#include "TimeCounter.h"
#include "Text.h"
#include "Image.h"
class SpellCard
{
public:
	bool IsBoss;
	Image Hpbar;
	int 남은체력;
	int 총체력;
	int pase;
	LPD3DXSPRITE Sprite;
	int Hpbar_rectRight;

	//extra spell parameter
	int direction;
	int spelltype;
	int 단위속초기화;
	
	MovePattern *e_Move;

	TimeCounter timer, lunchTimer;

	D3DXVECTOR3 *Position;
	D3DXVECTOR3 *Speed;
	RECT ImgSource;
	float 단위속도;
	int *Angle;

public:
	bool prntLBL;
	Text SpellLabel;
	char SplName[48];
	

public:
	SpellCard();
	virtual ~SpellCard();

public:
	virtual void Initialize(D3DXVECTOR3* Position, RECT ImgSource, D3DXVECTOR3 *Speed, int *Angle, float 단위속도, int 체력);
	bool Process();
	void Move();
	virtual void Cheak();
	void Lunch();
	void Rdr();
	virtual void Release();
	virtual void RenderBlt();
};

