#include "stdafx.h"
#include "Blt_Normal.h"
#include "Managers.h"

Blt_Normal::Blt_Normal()
{
}


Blt_Normal::~Blt_Normal()
{
}

void Blt_Normal::Move()
{
	if (단위속도 < 3)
	{
		단위속도 *= 1.1;
	}
}