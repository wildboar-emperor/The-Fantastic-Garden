#pragma once
#include "SpellCard.h"
#include "Spiral.h"
#include "Move_3.h"
class �ھƺر� :
	public SpellCard
{
public:
	Spiral spiral;

public:
	�ھƺر�();
	~�ھƺر�();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

