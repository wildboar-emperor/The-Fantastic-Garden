#pragma once
#include "TimeCounter.h"
class MovePattern
{
public:
	int 목표x좌표;
	int 목표y좌표;

public:
	TimeCounter timer;
	int Type;
	float 단위속도;
	D3DXVECTOR3 *Position, *Speed;
	int *Angle;
	int MoveCount;

public:
	MovePattern();
	virtual ~MovePattern();

public:
	void init(int* Angle, D3DXVECTOR3* Position, float 단위속도, D3DXVECTOR3 *Speed);
	virtual void Process();
	void SetAngle(int Angle);
	void LookPoint(D3DXVECTOR3 Point);
	float MoveTime(D3DXVECTOR3 Point);
};

