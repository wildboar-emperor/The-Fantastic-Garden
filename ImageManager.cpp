#include "stdafx.h"
#include "ImageManager.h"


ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{

}

void ImageManager::Add(const char* label, const char* src)
{
	for (std::list<TextureMap>::iterator itr = LoadedImages.begin(); itr != LoadedImages.end(); itr++)
	{
		if (strcmp(itr->Label, label) == 0)
		{
			return;
		}
	}

	TextureMap *t_tex = new TextureMap;
	strcpy_s(t_tex->Label, 128, label);
	t_tex->img.LoadTexture(src);

	LoadedImages.push_back(*t_tex);
	SAFE_DELETE(t_tex);
}

Image ImageManager::Get(const char* label)
{

	for (std::list<TextureMap>::iterator itr = LoadedImages.begin(); itr != LoadedImages.end(); itr++)
	{
		if (strcmp(itr->Label, label) == 0)
		{
			return itr->img;
		}
	}
}

void ImageManager::Release()
{
	for (std::list<TextureMap>::iterator itr = LoadedImages.begin(); itr != LoadedImages.end(); itr++)
	{
		itr->img.Texture->Release();
	}
	LoadedImages.clear();
}