#pragma once
#include "BulletPattern.h"
#include "Blt_LookPlayer.h"
class Horming :
	public BulletPattern
{
public:
	Magazine<Blt_LookPlayer> Mgzn;
public:
	Horming();
	virtual ~Horming();
public:
	int Process(D3DXVECTOR3 Position, RECT ImgSource) override;
	void Render() override;
	void Move() override;
};

