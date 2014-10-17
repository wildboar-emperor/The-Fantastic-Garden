#pragma once
#include "Image.h"
class Entity
{
public:
	bool	Visible;
	LPD3DXSPRITE Sprite;
	Image Img;
	D3DXVECTOR3	Position;
	D3DXVECTOR3 Center;
	D3DXVECTOR3 Speed;
	int Angle, RealAngle;
	float Scale;
	float Opacity;
	float 단위속도;
	int retainCount;

public:
	Entity(void);
	virtual ~Entity(void);

public:
	virtual void Initalize(const char* imgsrc);
	virtual void Release();

	virtual void Render();
	virtual void Process();

	void SetPositionCenter();
	void SetCenter();

};