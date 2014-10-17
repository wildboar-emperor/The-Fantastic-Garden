#pragma once
#include "BulletPattern.h"
#include "Blt_Normal.h"
class Spiral :
	public BulletPattern
{
public:
	Magazine<Blt_Normal> Mgzn_1[4];

public:
	Spiral();
	virtual ~Spiral();

public:
	int Process(D3DXVECTOR3 Position, RECT ImgSource) override;
	void Render() override;
	void Move() override;
};