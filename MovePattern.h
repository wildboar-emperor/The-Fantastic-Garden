#pragma once
#include "TimeCounter.h"
class MovePattern
{
public:
	int ��ǥx��ǥ;
	int ��ǥy��ǥ;

public:
	TimeCounter timer;
	int Type;
	float �����ӵ�;
	D3DXVECTOR3 *Position, *Speed;
	int *Angle;
	int MoveCount;

public:
	MovePattern();
	virtual ~MovePattern();

public:
	void init(int* Angle, D3DXVECTOR3* Position, float �����ӵ�, D3DXVECTOR3 *Speed);
	virtual void Process();
	void SetAngle(int Angle);
	void LookPoint(D3DXVECTOR3 Point);
	float MoveTime(D3DXVECTOR3 Point);
};

