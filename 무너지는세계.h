#pragma once
#include "SpellCard.h"
#include "Flower.h"
#include "Horming.h"
class �������¼��� :
	public SpellCard
{
public:
	Flower flower;
	Horming horming;
public:
	�������¼���();
	~�������¼���();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

