#pragma once
#include "Stage.h"
class Stage2 :
	public Stage
{
public:
	Stage2();
	~Stage2();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

