#pragma once
class Image
{
public:
	LPDIRECT3DTEXTURE9 Texture;
	D3DXIMAGE_INFO SrcInfo;
	RECT	 Source;

public:
	Image();
	virtual ~Image();

public:
	void LoadTexture(const char* imgsrc);
};

