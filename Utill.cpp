#include "stdafx.h"
#include "Utill.h"


bool RectToRectCrashCheak(RECT ���, RECT ����)
{
	if ((����.left < ���.left && ���.right < ����.right) &&
		(����.top < ���.top && ���.bottom < ����.bottom))
		return true;
	else
		return false;
}

bool RectToRectCrashCheakForBullet(RECT b, RECT e)
{
	//���ð��� �� �浹üũ, �簢���� ������ ���Ե��� �ʰ� ���ĵ� true��ȯ
	if ((e.left - (b.right - b.left) < b.left && b.right < e.right + (b.right - b.left)) &&
		(e.top < b.top && b.bottom < e.bottom))
		return true;
	else
		return false;
}

bool RectToPointCrashCheak(D3DXVECTOR3 ���, RECT ����)
{
	if ((����.left < ���.x && ����.right > ���.x) && (����.top < ���.y && ����.bottom > ���.y))
		return true;
	else
		return false;
}

void println(char *chString, ...)
{
	char outString[256];

	va_list args;
	va_start(args, chString);
	vsprintf_s(outString, chString, args);
	va_end(args);

	OutputDebugString(outString);
}

RECT newRECT(long left, long top, long right, long bottom)
{
	RECT temp = { left, top, right, bottom };

	return temp;
}