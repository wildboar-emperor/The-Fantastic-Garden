#pragma once
#include "SpellCard.h"
#include "Horming.h"
class ExtraSpell :
	public SpellCard
{
public:
	Horming horming;
	bool �������ʱ�ȭ;
	float X������, Y������;
	float �����ӵ�������;

public:
	ExtraSpell();
	~ExtraSpell();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

