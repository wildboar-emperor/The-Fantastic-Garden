#pragma once
#include "Magazine.h"
class BulletPattern
{
public:
	bool Enable;
	int nCountBullet;

public:
	BulletPattern();
	virtual ~BulletPattern();

public:
	virtual int Process(D3DXVECTOR3 Position, RECT ImgSource);
	virtual void Render();
	virtual void Move();
};

