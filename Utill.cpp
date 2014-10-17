#include "stdafx.h"
#include "Utill.h"


bool RectToRectCrashCheak(RECT 대상, RECT 범위)
{
	if ((범위.left < 대상.left && 대상.right < 범위.right) &&
		(범위.top < 대상.top && 대상.bottom < 범위.bottom))
		return true;
	else
		return false;
}

bool RectToRectCrashCheakForBullet(RECT b, RECT e)
{
	//슈팅게임 용 충돌체크, 사각형이 완전히 포함되지 않고 걸쳐도 true반환
	if ((e.left - (b.right - b.left) < b.left && b.right < e.right + (b.right - b.left)) &&
		(e.top < b.top && b.bottom < e.bottom))
		return true;
	else
		return false;
}

bool RectToPointCrashCheak(D3DXVECTOR3 대상, RECT 범위)
{
	if ((범위.left < 대상.x && 범위.right > 대상.x) && (범위.top < 대상.y && 범위.bottom > 대상.y))
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