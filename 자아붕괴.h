#pragma once
#include "SpellCard.h"
#include "Spiral.h"
#include "Move_3.h"
class ÀÚ¾ÆºØ±« :
	public SpellCard
{
public:
	Spiral spiral;

public:
	ÀÚ¾ÆºØ±«();
	~ÀÚ¾ÆºØ±«();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

