#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "Managers.h"


Bullet::Bullet()
{
	MoveLock = false;
}


Bullet::~Bullet()
{
	Entity::~Entity();
}

void Bullet::Process()
{
	if (Visible)
	{
		CrashCheak();
		Move();
	}
}

void Bullet::CrashCheak()
{
	//플레이어의 피탄 판정
	if (PLAYER->State == 1)
	{
		if (RectToRectCrashCheakForBullet(
			newRECT(PLAYER->CCRECT.x, PLAYER->CCRECT.y, PLAYER->CCRECT.x + PLAYER->CC.Source.right, PLAYER->CCRECT.y + PLAYER->CC.Source.bottom),
			newRECT(Position.x, Position.y, Position.x + Img.Source.right, Position.y + Img.Source.bottom)))
		{
			//PLAYER->Hit(Attack_Damage);
			Release();
			Visible = false;
		}
	}

	//총알이 화면 밖으로 나갔는지 확인
	if (Position.y > DirectX->Window_Source.h + 40.0f
		|| Position.y < -40.0f
		|| Position.x > DirectX->Window_Source.w + 40.0f
		|| Position.x < -40.f
	)
	{
		Visible = false;
		Release();
		return;
	}

	Position.y += Speed.y;
	Position.x += Speed.x;
}

void Bullet::Move()
{

}

void Bullet::SetAngle(int Angle)
{
	Angle %= 360;
	this->Angle = Angle;

	Speed.x = cosf((Angle-90)	* Math_PI / 180) * 단위속도;
	Speed.y = sinf((Angle-90)	* Math_PI / 180) * 단위속도;
}

float Bullet::MoveTime(D3DXVECTOR3 Point)
{
	return sqrt(
		pow(Point.x - Position.x, 2) +
		pow(Point.y - Position.y, 2)) / 단위속도 / 60;
}

void Bullet::LookPoint(D3DXVECTOR3 Point)
{
	double Angle = atan2(
		(Position.y - Point.y),
		(Position.x - Point.x)
		) * 180 / Math_PI -90;
	
	SetAngle(ceil(Angle));
}

D3DXVECTOR3 Bullet::SpinMe()
{
	double distance = sqrt(pow(Position.x - Mother->x, 2) + pow(Position.y - Mother->y, 2));

	nextPoint.x = cosf(Angle-90 * Math_PI / 180) * distance/2 + Mother->x;
	nextPoint.y = sinf(Angle++-90  * Math_PI / 180) * distance / 2 + Mother->x;

	return nextPoint;
}