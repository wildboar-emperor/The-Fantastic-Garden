#pragma once
#include "Entity.h"
#include "Image.h"
class Button :
	public Entity
{
public:
	Image HImg;

public:
	Button();
	virtual ~Button();

public:
	void Initalize(const char* imgsrc);
	void Initalize(const char* imgsrc_nomal, const char* imgsrc_highlight);
	void Render(bool highlight);
	void Process() override;
	bool OnClickedEvent();
};

