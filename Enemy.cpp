#include "stdafx.h"
#include "Enemy.h"
#include "Managers.h"
#include "Player.h"

Enemy::Enemy()
{
	p_Mgzn = &(PLAYER->Mgzn);

	e_Position temp;
	temp.Position = &CCRECT;
	temp.Visible = &Visible;
	PLAYER->e_pos.push_back(temp);
	등장하다 = false;
	NextSpellEnable = true;
}


Enemy::~Enemy()
{
	SAFE_RELEASE(tName.Sprite);
	SAFE_DELETE(Spell);
}



void Enemy::Process()
{
	if (Visible && 등장하다)
	{

		if (Hit_Point <= 0)
		{
			if (deadzen.online == false)
			{
				/*
				deadzen.start();
			}
			else if (deadzen.pass(2))
			{
			*/
				Visible = false;
				Sound->Play("E_Dead", CHAN_ENEMY);
			}
		}

		// 플레이어 탄막과의 충돌체크
		for (std::list<Player_Blt_1>::iterator itr = p_Mgzn->list.begin(); itr != p_Mgzn->list.end(); itr++)
		{
			if (RectToRectCrashCheakForBullet(
				newRECT(itr->Position.x, itr->Position.y, itr->Position.x + itr->Img.Source.right, itr->Position.y + itr->Img.Source.bottom),
				newRECT(Position.x, Position.y, Position.x + Img.Source.right, Position.y + Img.Source.bottom)))
			{
				Hit_Point -= p_Mgzn->Attack_Damage;
				itr->Visible = false;
				Sound->Play("Hit", CHAN_ENEMY);
			}

		}
		CCRECT.x = Position.x + Img.Source.right / 2;
		CCRECT.y = Position.y + Img.Source.bottom / 2;

		addProc();

		// 스펠카드 관리
		SpellManager();
		if (Spell)
		{
			if (Spell->Process())
			{
				if (spellezen.online == false)
					spellezen.start();
			}
		}

		if (spellezen.online)
		{
			if (spellezen.pass(4))
			{
				NextSpellEnable = true;
				spellezen.online = false;
			}
		}
	}
}
void Enemy::SpellManager()
{

}

void Enemy::GetP_Mgzn(Magazine<Player_Blt_1> *p_Mgzn)
{
	this->p_Mgzn = p_Mgzn;
}

void Enemy::addProc()
{

}

void Enemy::DrawBullet()
{
	if (Spell)	Spell->Rdr();
}