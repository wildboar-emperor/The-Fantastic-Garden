#pragma once
#include "BulletPattern.h"
#include "Blt_Normal.h"
class Flower :
	public BulletPattern
{
public:
	Magazine<Blt_Normal> Mgzn_1[2][4];
	float Angle2;

public:
	Flower();
	virtual ~Flower();
public:
	int Process(D3DXVECTOR3 Position, RECT ImgSource) override;
	void Render() override;
	void Move() override;
};

