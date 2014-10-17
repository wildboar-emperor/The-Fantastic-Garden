#pragma once
#include "SpellCard.h"
#include "Spiral.h"
#include "Circle.h"
#include "SeePlayerRandom.h"
#include "Horming.h"
#include "Flower.h"
class Chirno_PerfectFreeze :
	public SpellCard
{
public:
	Spiral spiral;
	Circle circle;
	SeePlayerRandom SPR;
	Horming horming;
	Flower flower;

public:
	Chirno_PerfectFreeze();
	virtual ~Chirno_PerfectFreeze();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

