#include "stdafx.h"
#include "TimeCounter.h"
#include "Managers.h"
#include "Text.h"
#include "Utill.h"


TimeCounter::TimeCounter(void)
{
	online = false;
}


TimeCounter::~TimeCounter(void)
{
}

void TimeCounter::start()
{
	시작시간 = timeGetTime();
	online = true;
}

bool TimeCounter::compare(int target)
{
	시차 = timeGetTime() - 시작시간;
	if ((int)시차 / 10000 == target)
		return true;
	else
		return false;
}

bool TimeCounter::pass(float target)
{
	시차 = timeGetTime() - 시작시간;
	if (시차 / 1000.f >= target)
		return true;
	else
		return false;
}

float TimeCounter::FPSLock(int fps)
{
	float 목표지연시간 = 1000.f / fps;
	시차 = timeGetTime() - 시작시간;

	if (목표지연시간 > 시차)
	{
		//println("시간 지연 : %.2d ms\n", (DWORD)(시차));
		//println("프레임: %.2d fps\n", (시차!=0) ? (DWORD)(1000 / 시차) : fps);

		Sleep((DWORD)(목표지연시간 - 시차));
	}

	if (시차 == 0) return 0;
	return 1000.0f / 시차;
}