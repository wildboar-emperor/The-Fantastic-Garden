#include "stdafx.h"
#include "D3DManager.h"


D3DManager::D3DManager()
{
}

D3DManager::~D3DManager()
{
}

void D3DManager::initialize(LRESULT MsgProc)
{
	InitWindow(MsgProc);
	InitDX();
	
	srand((unsigned)time(NULL));
	tOutFPS.initialize(20);
	tOutFPS.Visible = true;

	ShowWindow(g_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(g_hWnd);

	bIsRun = true;
}

void D3DManager::Release()
{
	tOutFPS.Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();
}

void D3DManager::InitDX()
{
	InitD3D();
	FPSDebug = false;
}

HRESULT D3DManager::InitD3D()
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	return S_OK;
}

void D3DManager::InitWindow(LRESULT MsgProc)
{
	// ������ Ŭ���� ����
	WNDCLASSEX g_wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, (WNDPROC) MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		sys_classname, NULL
	};

	Window_Source = { 0, 0, 600, 800 };
	// â�� �߾ӿ� ��ġ��Ŵ

	/* ���ø����̼��� �÷��� ��ġ ���� */
	HWND shell;		// �۾� ǥ���ٰ� ���ø����̼� �������� �ڵ�
	RECT shell_rect;	// �۾�ǥ���� â�� ����
	shell = FindWindowA("Shell_TrayWnd", NULL);	// �۾� ǥ����(���ؿ��ִ� ���۹�ư�մ�â)�� ã�´�
	GetWindowRect(shell, &shell_rect);	// �۾� ǥ���� â�� ������ ���س���

	Window_Source.x = shell_rect.right / 2 - Window_Source.w / 2;
	Window_Source.y = shell_rect.bottom / 2 - Window_Source.h / 2;

	//Window_Source = { 0, 0, 600, 800 };

	RegisterClassEx(&g_wc);

	// ������ ����
	g_hWnd = CreateWindow(
		sys_classname, sys_windowname, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		Window_Source.x, Window_Source.y, Window_Source.w, Window_Source.h,
		NULL, NULL, g_wc.hInstance, NULL);
}