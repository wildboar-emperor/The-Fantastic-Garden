#pragma once
#include "Singleton.h"
#include "TimeCounter.h"
#include "Text.h"
class D3DManager :
	public Singleton<D3DManager>
{
public:
	bool bIsRun;

	HWND g_hWnd; // 핸들 윈도우
	WNDCLASSEX g_wc;
	struct AABBRECT {
		int x, y, w, h;
	} Window_Source;

	LPDIRECT3D9             g_pD3D = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Rendering device

	TimeCounter FPStimer;
	float c_fps;
	Text tOutFPS;
	bool FPSDebug;

public:
	D3DManager();
	~D3DManager();

public:
	void initialize(LRESULT MsgProc);
	void Release();

private:
	void InitDX();
	void InitWindow(LRESULT MsgProc);
	HRESULT InitD3D();
};

#define DirectX D3DManager::getInstance()