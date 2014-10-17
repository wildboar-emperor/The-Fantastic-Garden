#pragma once
#include "SpellCard.h"
#include "Horming.h"
class ExtraSpell :
	public SpellCard
{
public:
	Horming horming;
	bool 단위속초기화;
	float X단위속, Y단위속;
	float 단위속도증감량;

public:
	ExtraSpell();
	~ExtraSpell();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

