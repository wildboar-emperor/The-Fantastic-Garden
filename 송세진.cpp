#include "stdafx.h"
#include "价技柳.h"
#include "Managers.h"

价技柳::价技柳()
{
	sprintf_s(Name, sizeof(Name), "Hotba");
	Initalize("Hotba");
	Hit_Point_max = Hit_Point = 20;
	窜困加档 = 3.f;
}


价技柳::~价技柳()
{
	SAFE_DELETE(Spell);
}

void 价技柳::SpellManager()
{
		if (NextSpellEnable)
		{
			switch (pase)
			{
			case 0:
				Spell = new 侵官谎府扁();
				Spell->Initialize(&Position, Img.Source, &Speed, &Angle, 窜困加档, 20);
				timer.start();
				pase = 1;
				break;
			}
			NextSpellEnable = false;
		}
}