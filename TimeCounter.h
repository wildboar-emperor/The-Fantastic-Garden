#pragma once
class TimeCounter
{
public:
	TimeCounter(void);
	~TimeCounter(void);

public:
	DWORD ���۽ð�, ����;
	DWORD target;
	bool online;

	void start();
	bool compare(int target);
	bool pass(float target);

	float FPSLock(int fps);
};