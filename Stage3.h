#pragma once
#include "Stage.h"
class Stage3 :
	public Stage
{
public:
	Stage3();
	~Stage3();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

