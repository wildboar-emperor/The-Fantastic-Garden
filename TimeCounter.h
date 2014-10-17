#pragma once
class TimeCounter
{
public:
	TimeCounter(void);
	~TimeCounter(void);

public:
	DWORD 시작시간, 시차;
	DWORD target;
	bool online;

	void start();
	bool compare(int target);
	bool pass(float target);

	float FPSLock(int fps);
};