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
	LPDIRECTINPUT8   _lpDirectInput;      // DirectInput ��ü.
	LPDIRECTINPUTDEVICE8 _lpDirectInputDeviceKeyboard;  // Ű���� ��ġ.
	LPDIRECTINPUTDEVICE8 _lpDirectInputDeviceMouse;   // ���콺 ��ġ.
	HWND     _hWnd;     // ���� �������� �ڵ�.
	DWORD     _flagUseDevice;   // Ű����, ���콺 ��� �÷���
	enum eInputState { eInput_None, eInput_Press, eInput_Release, eInput_Pressing };
	// ���� ����.
	struct tagInputInfo
	{
		DWORD  dwPressedTime;   // Ű�� ���� �ð� -> Pressed Time.
		DWORD  dwPressingTime;   // Ű�� �������ִ� �ð�. -> Pressing Time.
		eInputState State;     // ���� Ű�� ����.
	}_keyInfo[256], _mouseInfo[3];
	BYTE _byteNowKeyStateValue[256];  // ���� Ű�� ���¸� ������ ����.
	BYTE _byteOldKeyStateValue[256];  // ���� Ű�� ���¸� ������ ����.
	BYTE _byteNowMouseStateValue[3];
	BYTE _byteOldMouseStateValue[3];
	INT _nMouseMovedX;      // ���콺�� X������ ������ ����.
	INT _nMouseMovedY;      // ���콺�� Y������ ������ ����.
	INT _nMouseWheel;      // ���콺 ���� ������ ����.
public:
	//��ǲ �ʱ�ȭ.
	bool Init(HWND hWnd, DWORD useDevice);

	//���� �������� loop �ֻ�ܿ� �׻� ������ �Ѵ�.
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
	//��ġ�� �����´�.
	VOID GetMouse();
	VOID SetMouse();
public:
	bool IsMousePressing(INT mouse) const;
	bool IsMousePress(INT mouse) const;
	bool IsMouseRelease(INT mouse) const;
	INT IsMouseMovedX() const;
	INT IsMouseMovedY() const;
	DWORD GetMousePressingTime(INT mouse) const;
	//���̷�Ʈ�δ� �Ұ����ϹǷ� API�� ����Ͽ� �����..
	VOID GetMouseWindowPosition(POINT* pt) const;
	VOID GetMouseMonitorPosition(POINT* pt) const;
	INT GetMouseWheelMoved() const;

public:
	InputManager();
	~InputManager();
};

#define INTERRUPT InputManager::getInstance()