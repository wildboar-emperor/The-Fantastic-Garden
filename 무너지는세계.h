#pragma once
#include "SpellCard.h"
#include "Flower.h"
#include "Horming.h"
class 무너지는세계 :
	public SpellCard
{
public:
	Flower flower;
	Horming horming;
public:
	무너지는세계();
	~무너지는세계();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

