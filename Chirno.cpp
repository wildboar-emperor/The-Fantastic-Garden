#include "stdafx.h"
#include "Chirno.h"
#include "Managers.h"
#include"자아붕괴.h"
#include "무너지는세계.h"

Chirno::Chirno()
{
	sprintf_s(Name, sizeof(Name), "Chirno");
	Initalize("Chirno");
	Hit_Point_max = Hit_Point = 3000;
	단위속도 = 5.f;
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
			Spell = new 자아붕괴();
			Spell->Initialize(&Position, Img.Source, &Speed, &Angle, 단위속도, 2000);
			timer.start();
			pase = 1;
			break;
		case 1:
			Spell = new 무너지는세계();
			Spell->Initialize(&Position, Img.Source, &Speed, &Angle, 단위속도, 2000);
			timer.start();
			pase = 2;
			break;
		}
		leftSpell--;
		sprintf_s(leftSpellStr, sizeof(leftSpellStr), "%d", leftSpell+1);
		NextSpellEnable = false;
	}

}