#include "stdafx.h"
#include "�ܸ�1.h"
#include "D3DManager.h"

�ܸ�1::�ܸ�1()
{
	Hit_Point_max = Hit_Point = 20;
	�����ӵ� = 3.f;
	Spell = new ExtraSpell();
	Spell->Initialize(&Position, Img.Source, &Speed, &Angle, �����ӵ�, 1000);
	timer.start();
}


�ܸ�1::~�ܸ�1()
{
	SAFE_DELETE(Spell);
}

void �ܸ�1::SpellManager()
{

}