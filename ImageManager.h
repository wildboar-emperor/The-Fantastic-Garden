#pragma once
#include "Singleton.h"
#include <list>
#include <string>
#include "Image.h"
typedef struct {
	char Label[128];
	Image img;
}TextureMap;
class ImageManager :
	public Singleton<ImageManager>
{
public:
	std::list<TextureMap> LoadedImages;

public:
	ImageManager();
	~ImageManager();

public:
	void Release();

public:
	void Add(const char* label, const char* src);
	Image Get(const char* label);
};

#define Imgs ImageManager::getInstance()