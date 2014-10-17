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
	���۽ð� = timeGetTime();
	online = true;
}

bool TimeCounter::compare(int target)
{
	���� = timeGetTime() - ���۽ð�;
	if ((int)���� / 10000 == target)
		return true;
	else
		return false;
}

bool TimeCounter::pass(float target)
{
	���� = timeGetTime() - ���۽ð�;
	if (���� / 1000.f >= target)
		return true;
	else
		return false;
}

float TimeCounter::FPSLock(int fps)
{
	float ��ǥ�����ð� = 1000.f / fps;
	���� = timeGetTime() - ���۽ð�;

	if (��ǥ�����ð� > ����)
	{
		//println("�ð� ���� : %.2d ms\n", (DWORD)(����));
		//println("������: %.2d fps\n", (����!=0) ? (DWORD)(1000 / ����) : fps);

		Sleep((DWORD)(��ǥ�����ð� - ����));
	}

	if (���� == 0) return 0;
	return 1000.0f / ����;
}