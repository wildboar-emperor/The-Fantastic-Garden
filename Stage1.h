#pragma once
#include "Stage.h"
#include "�ܸ�1.h"
class Stage1 :
	public Stage
{
public:
	bool ClearFlag;
	Chirno Boss;
	�ۼ��� ����[5];
	�ܸ�1 �ܸ�Ÿ��1[10];
	TimeCounter �ܸ�����Ÿ�̸�;
	int �ܸ�����ī����;

public:
	Stage1();
	~Stage1();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

