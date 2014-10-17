#pragma once
#include "Stage.h"
class Stage5 :
	public Stage
{
public:
	Stage5();
	~Stage5();

public:
	void Initalize() override;
	void Release() override;
	void Render() override;
	int Process() override;
};

