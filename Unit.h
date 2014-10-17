#pragma once
#include "Entity.h"
#include "Magazine.h"
#include "Text.h"
class Unit :
	public Entity
{
public:
	bool 등장하다;
	char Name[128];
	Text tName;
	int Hit_Point, Hit_Point_max;
	Image CC;
	D3DXVECTOR3 CCRECT;


public:
	Unit();
	virtual ~Unit();

public:
	void Render() override;
	bool Unit_Cheak();
	virtual void DrawBullet();
};

