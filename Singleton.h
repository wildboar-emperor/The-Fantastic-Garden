#pragma once
#include "stdafx.h"
template <class T>
class Singleton
{
protected:
	static T* instance;

protected:
	Singleton(void){}
	virtual ~Singleton(void){}

public:
	static T* getInstance(void)
	{
		if (instance == nullptr)
		{
			instance = new T;
		}
		return instance;
	}

};

template <class T> T* Singleton<T>::instance = 0;