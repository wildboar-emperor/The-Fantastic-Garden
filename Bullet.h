#pragma once
#include "Entity.h"
#include "TimeCounter.h"
class Bullet :
	public Entity
{
public:
	int Attack_Damage;

	D3DXVECTOR3 *Mother;
	TimeCounter timer; 
	bool MoveLock;
	D3DXVECTOR3 nextPoint;

public:
	Bullet();
	virtual ~Bullet();

public:
	void Process() override;
	virtual void CrashCheak();
	virtual void Move();
	void SetAngle(int Angle);
	float MoveTime(D3DXVECTOR3 Point);
	void LookPoint(D3DXVECTOR3 Point);
	D3DXVECTOR3 SpinMe();
};

