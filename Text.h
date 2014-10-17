#pragma once
class Text
{
public:

	bool	Visible;
	LPD3DXSPRITE Sprite;
	ID3DXFont *font;
	RECT	 Source;
	D3DXVECTOR3	Position;
	D3DXVECTOR3 Center;

	int fontSize;

public:
	Text();
	virtual ~Text();

public:
	void initialize(int fontSize);
	void Release();

	void OutPut(const char* str, int r , int g , int b );
	void SetPosition(int x, int y);
};

