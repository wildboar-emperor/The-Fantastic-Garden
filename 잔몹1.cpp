#include "stdafx.h"
#include "儡各1.h"
#include "D3DManager.h"

儡各1::儡各1()
{
	Hit_Point_max = Hit_Point = 20;
	窜困加档 = 3.f;
	Spell = new ExtraSpell();
	Spell->Initialize(&Position, Img.Source, &Speed, &Angle, 窜困加档, 1000);
	timer.start();
}


儡各1::~儡各1()
{
	SAFE_DELETE(Spell);
}

void 儡各1::SpellManager()
{

}