#pragma once
#include "BulletPattern.h"
#include "Blt_Normal.h"
class Circle :
	public BulletPattern
{
public:
	Magazine<Blt_Normal> Mgzn;
public:
	Circle();
	virtual ~Circle();

public:
	int Process(D3DXVECTOR3 Position, RECT ImgSource) override;
	void Render() override;
	void Move() override;
};

