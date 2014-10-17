// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")
#include <math.h>
#include <time.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <strsafe.h>

// DirectX Ȯ�� ���̺귯��
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")


#pragma warning( disable : 4996 ) // disable deprecated warning 
#pragma warning( default : 4996 ) 

static LPCSTR sys_classname = "�ҳ��� ��������";
static LPCSTR sys_windowname = "�������� ������";

#define APPLICATION_FPS 60
#define Math_PI 3.141592
#include "Utill.h"

#include <stdlib.h>
#include <crtdbg.h>

#define SAFE_RELEASE(x) if(x) {x->Release(); x=NULL;}
#define SAFE_DELETE(x) if(x) {delete x; x=NULL;}