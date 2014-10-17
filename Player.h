#pragma once
#include "Unit.h"
#include "Singleton.h"
#include "TimeCounter.h"
#include <list>
#include "Player_Blt_1.h"
#include "Player_Blt_LookEnemy.h"
typedef struct
{
	bool Inited;
	D3DXVECTOR3 *Position;
	bool *Visible;
} e_Position;
class Player :
	public Unit, public Singleton<Player>
{
public:
	bool Shift;
	//Magazine<Player_Blt_LookEnemy> Mgzn;
	Magazine<Player_Blt_1> Mgzn;
	Image Charback;
	D3DXVECTOR3 CharbackRECT;
	float Charback_Angle;
	LPD3DXSPRITE CharbackSprite;
	int State;
	TimeCounter timer;
	int deadvisiblecounter;
	bool CanMove;
	std::list<e_Position> e_pos;
	e_Position e_pos_targetPos;

public:

	Player();
	~Player();
	
public:
	void Process() override;
	void Render() override;
	void DrawBullet() override;
	void Initalize(const char* src) override;
	void Release() override;
	void Hit(int ad);
};

#define PLAYER Player::getInstance()
