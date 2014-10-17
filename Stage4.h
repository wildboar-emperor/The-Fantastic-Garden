#pragma once
#include "Stage.h"
class Stage4 :
	public Stage
{
public:
	Stage4();
	~Stage4();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

