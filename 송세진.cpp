#include "stdafx.h"
#include "�ۼ���.h"
#include "Managers.h"

�ۼ���::�ۼ���()
{
	sprintf_s(Name, sizeof(Name), "Hotba");
	Initalize("Hotba");
	Hit_Point_max = Hit_Point = 20;
	�����ӵ� = 3.f;
}


�ۼ���::~�ۼ���()
{
	SAFE_DELETE(Spell);
}

void �ۼ���::SpellManager()
{
		if (NextSpellEnable)
		{
			switch (pase)
			{
			case 0:
				Spell = new �ֹٻѸ���();
				Spell->Initialize(&Position, Img.Source, &Speed, &Angle, �����ӵ�, 20);
				timer.start();
				pase = 1;
				break;
			}
			NextSpellEnable = false;
		}
}