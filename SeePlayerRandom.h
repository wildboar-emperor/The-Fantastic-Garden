#pragma once
#include "BulletPattern.h"
#include "Blt_Normal.h"
class SeePlayerRandom :
	public BulletPattern
{
public:
	Magazine<Blt_Normal> Mgzn;
public:
	SeePlayerRandom();
	virtual ~SeePlayerRandom();
public:
	int Process(D3DXVECTOR3 Position, RECT ImgSource) override;
	void Render() override;
	void Move() override;
};

