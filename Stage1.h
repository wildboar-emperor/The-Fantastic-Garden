#pragma once
#include "Stage.h"
#include "ÀÜ¸÷1.h"
class Stage1 :
	public Stage
{
public:
	bool ClearFlag;
	Chirno Boss;
	¼Û¼¼Áø º´½Å[5];
	ÀÜ¸÷1 ÀÜ¸÷Å¸ÀÔ1[10];
	TimeCounter ÀÜ¸÷µîÀåÅ¸ÀÌ¸Ó;
	int ÀÜ¸÷µîÀåÄ«¿îÅÍ;

public:
	Stage1();
	~Stage1();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

