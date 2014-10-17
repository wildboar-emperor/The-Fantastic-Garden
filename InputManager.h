#pragma once
#include "Singleton.h"
#define DIRECTINPUT_VERSION 0x0800
#include <DInput.h>
#pragma comment(lib, "DInput8.lib")
#pragma comment(lib, "Dxguid.lib")
enum DIMOUSE { DIM_LEFT, DIM_RIGHT, DIM_MIDDLE };
class InputManager :
	public Singleton<InputManager>
{
public:
	enum eInputType { USE_NONE, USE_KEYBOARD, USE_MOUSE };
private:
	LPDIRECTINPUT8   _lpDirectInput;      // DirectInput 객체.
	LPDIRECTINPUTDEVICE8 _lpDirectInputDeviceKeyboard;  // 키보드 장치.
	LPDIRECTINPUTDEVICE8 _lpDirectInputDeviceMouse;   // 마우스 장치.
	HWND     _hWnd;     // 메인 윈도우의 핸들.
	DWORD     _flagUseDevice;   // 키보드, 마우스 사용 플래그
	enum eInputState { eInput_None, eInput_Press, eInput_Release, eInput_Pressing };
	// 상태 정보.
	struct tagInputInfo
	{
		DWORD  dwPressedTime;   // 키가 눌린 시간 -> Pressed Time.
		DWORD  dwPressingTime;   // 키가 눌려져있는 시간. -> Pressing Time.
		eInputState State;     // 현재 키의 상태.
	}_keyInfo[256], _mouseInfo[3];
	BYTE _byteNowKeyStateValue[256];  // 현재 키의 상태를 저장할 변수.
	BYTE _byteOldKeyStateValue[256];  // 이전 키의 상태를 저장할 변수.
	BYTE _byteNowMouseStateValue[3];
	BYTE _byteOldMouseStateValue[3];
	INT _nMouseMovedX;      // 마우스가 X축으로 움직인 정도.
	INT _nMouseMovedY;      // 마우스가 Y축으로 움직인 정도.
	INT _nMouseWheel;      // 마우스 휠을 움직인 정도.
public:
	//인풋 초기화.
	bool Init(HWND hWnd, DWORD useDevice);

	//값을 가져오는 loop 최상단에 항상 놓여야 한다.
	VOID Update();
private:
	VOID GetKeyboard();
	VOID SetKeyboard();
public:
	bool IsKeyPressing(INT key) const;
	bool IsKeyPress(INT key) const;
	bool IsKeyRelease(INT key) const;
	DWORD GetKeyPressingTime(INT key) const;
private:
	//장치를 가져온다.
	VOID GetMouse();
	VOID SetMouse();
public:
	bool IsMousePressing(INT mouse) const;
	bool IsMousePress(INT mouse) const;
	bool IsMouseRelease(INT mouse) const;
	INT IsMouseMovedX() const;
	INT IsMouseMovedY() const;
	DWORD GetMousePressingTime(INT mouse) const;
	//다이렉트로는 불가능하므로 API를 사용하여 맞춘다..
	VOID GetMouseWindowPosition(POINT* pt) const;
	VOID GetMouseMonitorPosition(POINT* pt) const;
	INT GetMouseWheelMoved() const;

public:
	InputManager();
	~InputManager();
};

#define INTERRUPT InputManager::getInstance()