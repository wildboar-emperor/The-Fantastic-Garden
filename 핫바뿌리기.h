#pragma once
#include "SpellCard.h"
#include "Horming.h"
class �ֹٻѸ��� :
	public SpellCard
{
public:
	Horming horming;

public:
	�ֹٻѸ���();
	virtual ~�ֹٻѸ���();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

