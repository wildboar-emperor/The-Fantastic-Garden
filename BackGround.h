#pragma once
#include "Entity.h"
#include "Image.h"
class Background :
	public Entity
{
public:
	bool ScrollOn;
	Image Scroll;
	int ScrollSpeed;
	D3DXVECTOR3 ScrollVec;
	D3DXVECTOR3 Bottom;

public:
	Background();
	virtual ~Background();
	
public:
	void Initalize(const char* imgsrc);
	void Render() override;
	void Process() override;
};

