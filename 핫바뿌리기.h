#pragma once
#include "SpellCard.h"
#include "Horming.h"
class ÇÖ¹Ù»Ñ¸®±â :
	public SpellCard
{
public:
	Horming horming;

public:
	ÇÖ¹Ù»Ñ¸®±â();
	virtual ~ÇÖ¹Ù»Ñ¸®±â();

public:
	void Cheak() override;
	void RenderBlt() override;
	void Release() override;
};

