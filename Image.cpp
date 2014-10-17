#include "stdafx.h"
#include "Image.h"
#include "D3DManager.h"

Image::Image()
{
}


Image::~Image()
{
}


void Image::LoadTexture(const char* imgsrc)
{
	//D3DXCreateTextureFromFile(DirectX->g_pd3dDevice, imgsrc, &Texture);

	D3DFORMAT fmt = (TRUE || (0 != 0)) ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;

	D3DXCreateTextureFromFileEx(
		DirectX->g_pd3dDevice,
		imgsrc,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		0,
		fmt,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		&SrcInfo,
		NULL,
		&Texture
		);

	Source = { 0, 0, SrcInfo.Width, SrcInfo.Height };
}