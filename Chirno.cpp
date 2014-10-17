#include "stdafx.h"
#include "Chirno.h"
#include "Managers.h"
#include"�ھƺر�.h"
#include "�������¼���.h"

Chirno::Chirno()
{
	sprintf_s(Name, sizeof(Name), "Chirno");
	Initalize("Chirno");
	Hit_Point_max = Hit_Point = 3000;
	�����ӵ� = 5.f;
	Position = { (float)DirectX->Window_Source.w / 2 - Img.Source.right / 2, 0, 0 };

	leftSpell = 2;
}


Chirno::~Chirno()
{
	SAFE_DELETE(Spell);
}


void Chirno::SpellManager()
{
	if (NextSpellEnable)
	{
		SAFE_DELETE(Spell);
		switch (pase)
		{
		case 0:
			Spell = new �ھƺر�();
			Spell->Initialize(&Position, Img.Source, &Speed, &Angle, �����ӵ�, 2000);
			timer.start();
			pase = 1;
			break;
		case 1:
			Spell = new �������¼���();
			Spell->Initialize(&Position, Img.Source, &Speed, &Angle, �����ӵ�, 2000);
			timer.start();
			pase = 2;
			break;
		}
		leftSpell--;
		sprintf_s(leftSpellStr, sizeof(leftSpellStr), "%d", leftSpell+1);
		NextSpellEnable = false;
	}

}