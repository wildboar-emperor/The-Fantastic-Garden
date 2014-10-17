// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")
#include <math.h>
#include <time.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <strsafe.h>

// DirectX 확장 라이브러리
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")


#pragma warning( disable : 4996 ) // disable deprecated warning 
#pragma warning( default : 4996 ) 

static LPCSTR sys_classname = "소녀의 공상정원";
static LPCSTR sys_windowname = "공상정원 의존증";

#define APPLICATION_FPS 60
#define Math_PI 3.141592
#include "Utill.h"

#include <stdlib.h>
#include <crtdbg.h>

#define SAFE_RELEASE(x) if(x) {x->Release(); x=NULL;}
#define SAFE_DELETE(x) if(x) {delete x; x=NULL;}