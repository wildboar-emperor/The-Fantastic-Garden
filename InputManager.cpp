#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager(void)
{
	// 메모리 초기화.
	memset(_byteNowKeyStateValue, 0, sizeof(_byteNowKeyStateValue));
	memset(_byteOldKeyStateValue, 0, sizeof(_byteOldKeyStateValue));
	memset(_byteNowMouseStateValue, 0, sizeof(_byteNowMouseStateValue));
	memset(_byteOldMouseStateValue, 0, sizeof(_byteOldMouseStateValue));
}
InputManager::~InputManager(void)
{
	if (_flagUseDevice & USE_KEYBOARD)
	{
		// 키보드의 제어권을 헤제한다.
		_lpDirectInputDeviceKeyboard->Unacquire();
		// 키보드 장치를 메모리에서 제거한다.
		SAFE_RELEASE(_lpDirectInputDeviceKeyboard);
	}
	if (_flagUseDevice & USE_MOUSE)
	{
		// 마우스의 제어권을 해제한다.
		_lpDirectInputDeviceMouse->Unacquire();
		// 마우스 장치를 메모리에서 제거한다.
		SAFE_RELEASE(_lpDirectInputDeviceMouse);
	}
	// DirectInput을 메모리에서 제거한다.
	_lpDirectInput->Release();
}
bool InputManager::Init(HWND hWnd, DWORD useDevice)
{
	// 인자값을 멤버변수에 대입한다.
	_hWnd = hWnd;
	_flagUseDevice = useDevice;
	// DirectInput 시스템을 등록하고 DirectInput 인터페이스에 포인터를 받아온다.
	// DirectInput8Create()함수의 인자 설명.
	// (자기자신의 인스턴스, 버전, 요구하는 인터페이스의 고유 식별번호(안시/유니코드), 인터페이스의 주소, IUnknown 인터페이스의 주소)
	HRESULT hr;
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&_lpDirectInput, NULL)))
	{
		return false;
	}
	if (_flagUseDevice & USE_KEYBOARD)
	{
		// 키보드 장치를 _lpDirectInputDeviceKeyboard 에 생성한다.
		if (FAILED(_lpDirectInput->CreateDevice(GUID_SysKeyboard, &_lpDirectInputDeviceKeyboard, NULL)))
		{
			return false;
		}
		// 어떠한 형태의 키보드를 사용할지 설정한다.
		if (FAILED(hr = _lpDirectInputDeviceKeyboard->SetDataFormat(&c_dfDIKeyboard)))
		{
			return false;
		}
		if (FAILED(hr = _lpDirectInputDeviceKeyboard->SetCooperativeLevel(_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
		{
			return false;
		}
	}

	if (_flagUseDevice & USE_MOUSE)
	{
		// 마우스 장치를 _lpDirectInputDeviceMouse 에 생성한다.
		if (FAILED(_lpDirectInput->CreateDevice(GUID_SysMouse, &_lpDirectInputDeviceMouse, NULL)))
		{
			return false;
		}
		// 어떠한 형태의 마우스를 사용할지 설정한다. (c_dfDIMouse : 3버튼, c_dfDIMouse2 : 4버튼)
		if (FAILED(hr = _lpDirectInputDeviceMouse->SetDataFormat(&c_dfDIMouse)))
		{
			return false;
		}
		if (FAILED(hr = _lpDirectInputDeviceMouse->SetCooperativeLevel(_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
		{
			return false;
		}
	}
	return true;
}
// 플래그에 따라 키보드와 마우스의 상태값을 받아온다.
VOID InputManager::Update()
{
	if (_flagUseDevice & USE_KEYBOARD)
	{
		GetKeyboard();
		SetKeyboard();
	}
	if (_flagUseDevice & USE_MOUSE)
	{
		GetMouse();
		SetMouse();
	}
}
VOID InputManager::GetKeyboard()
{
	// 키보드 장치가 있는지 확인 후 없으면 종료.
	if (NULL == _lpDirectInputDeviceKeyboard)
		return;
	// 키보드의 상태값을 저장할 배열을 초기화한다.
	ZeroMemory(&_byteNowKeyStateValue, sizeof(_byteNowKeyStateValue));
	HRESULT hr;
	// 현재의 상태를 읽기위해 장치를 조사한다.
	hr = _lpDirectInputDeviceKeyboard->Poll();
	if (FAILED(hr))
	{
		// 장치를 조사하는 동안 방해받았다면 다시 제어권을 얻는다.
		hr = _lpDirectInputDeviceKeyboard->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = _lpDirectInputDeviceKeyboard->Acquire();
	}
	// 키보드의 상태값을 저장한다.
	if (FAILED(hr = _lpDirectInputDeviceKeyboard->GetDeviceState(sizeof(_byteNowKeyStateValue), &_byteNowKeyStateValue)))
	{
		return; // 장치를 조사하는 동안 제어권을 얻지 못했을 수 있다.
	}
}
VOID InputManager::GetMouse()
{
	if (NULL == _lpDirectInputDeviceMouse)
		return;
	// 키보드의 상태값을 저장할 배열을 초기화한다.
	ZeroMemory(&_byteNowMouseStateValue, sizeof(_byteNowMouseStateValue));
	HRESULT hr;
	// 현재의 상태를 읽기위해 장치를 조사한다.
	hr = _lpDirectInputDeviceMouse->Poll();
	if (FAILED(hr))
	{
		// 장치를 조사하는 동안 방해받았다면 다시 제어권을 얻는다.
		hr = _lpDirectInputDeviceMouse->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = _lpDirectInputDeviceMouse->Acquire();
	}
	// 마우스의 상태값을 저장한다.
	DIMOUSESTATE MouseState;
	if (FAILED(hr = _lpDirectInputDeviceMouse->GetDeviceState(sizeof(DIMOUSESTATE), &MouseState)))
	{
		return; // 장치를 조사하는 동안 제어권을 얻지 못했을 수 있다.
	}
	_nMouseMovedX = (INT)(MouseState.lX);
	_nMouseMovedY = (INT)(MouseState.lY);
	_nMouseWheel = (INT)(MouseState.lZ);
	memcpy(_byteNowMouseStateValue, MouseState.rgbButtons, sizeof(_byteNowMouseStateValue));
}
VOID InputManager::SetKeyboard()
{
	DWORD dwTime = ::timeGetTime();
	// 상태정보를 구조체에 저장한다.
	for (INT i = 0; i < 256; i++)
	{
		if (_byteOldKeyStateValue[i] == 0 && _byteNowKeyStateValue[i] == 0)    _keyInfo[i].State = eInput_None;
		else if (_byteOldKeyStateValue[i] == 0 && _byteNowKeyStateValue[i] == 0x80)
			_keyInfo[i].State = eInput_Press;
		else if (_byteOldKeyStateValue[i] == 0x80 && _byteNowKeyStateValue[i] == 0) 
			_keyInfo[i].State = eInput_Release;
		else if (_byteOldKeyStateValue[i] == 0x80 && _byteNowKeyStateValue[i] == 0x80)
			_keyInfo[i].State = eInput_Pressing;
		// 키의 상태가 None일 경우, Pressed Time을 0으로 초기화한다.
		if (_keyInfo[i].State == eInput_None)
		{
			_keyInfo[i].dwPressedTime = 0;
			_keyInfo[i].dwPressingTime = 0;
		}
		// 키의 상태가 Press일 경우, Pressed Time에 현재 시간값을 저장한다.
		if (_keyInfo[i].State == eInput_Press)
			_keyInfo[i].dwPressedTime = dwTime;
		// 키의 상태가 Pressing 일 경우, 현재 시간값에서 Pressed Time을 빼서 Pressing Time을 구한다.
		if (_keyInfo[i].State == eInput_Pressing)
			_keyInfo[i].dwPressingTime = dwTime - _keyInfo[i].dwPressedTime;
	}
	// 현재 키의 상태를 이전 키 상태배열에 복사한다.
	memcpy(_byteOldKeyStateValue, _byteNowKeyStateValue, sizeof(_byteNowKeyStateValue));
}
VOID InputManager::SetMouse()
{
	// 현재 시간값(윈도우가 부팅한 이후의 카운트 값)을 얻어온다.
	DWORD dwTime = ::timeGetTime();
	// 모든 마우스에 대해서, 마우스보드 상태 정보를 구조체에 저장한다.
	for (INT i = 0; i < 3; i++)
	{
		if (_byteOldMouseStateValue[i] == 0 && _byteNowMouseStateValue[i] == 0)    _mouseInfo[i].State = eInput_None;
		else if (_byteOldMouseStateValue[i] == 0 && _byteNowMouseStateValue[i] == 0x80)  _mouseInfo[i].State = eInput_Press;
		else if (_byteOldMouseStateValue[i] == 0x80 && _byteNowMouseStateValue[i] == 0)  _mouseInfo[i].State = eInput_Release;
		else if (_byteOldMouseStateValue[i] == 0x80 && _byteNowMouseStateValue[i] == 0x80) _mouseInfo[i].State = eInput_Pressing;
		// 마우스의 상태가 None일 경우, Pressed Time을 0으로 초기화한다.
		if (_mouseInfo[i].State == eInput_None)
		{
			_mouseInfo[i].dwPressedTime = 0;
			_mouseInfo[i].dwPressingTime = 0;
		}
		// 마우스의 상태가 Press일 경우, Pressed Time에 현재 시간값을 저장한다.
		if (_mouseInfo[i].State == eInput_Press)
			_mouseInfo[i].dwPressedTime = dwTime;
		// 마우스의 상태가 Pressing 일 경우, 현재 시간값에서 Pressed Time을 빼서 Pressing Time을 구한다.
		if (_mouseInfo[i].State == eInput_Pressing)
			_mouseInfo[i].dwPressingTime = dwTime - _mouseInfo[i].dwPressedTime;
	}
	// 현재 마우스의 상태를 이전 마우스 상태배열에 복사한다.
	memcpy(_byteOldMouseStateValue, _byteNowMouseStateValue, sizeof(_byteNowMouseStateValue));
}
bool InputManager::IsKeyPressing(INT key) const
{
	if (_keyInfo[key].State == eInput_Pressing)
		return true;
	return false;
}
bool InputManager::IsKeyPress(INT key) const
{
	if (_keyInfo[key].State == eInput_Press)
		return true;
	return false;
}
bool InputManager::IsKeyRelease(INT key) const
{
	if (_keyInfo[key].State == eInput_Release)
		return true;
	return false;
}
DWORD InputManager::GetKeyPressingTime(INT key) const
{
	return _keyInfo[key].dwPressingTime;
}

bool InputManager::IsMousePressing(INT mouse) const
{
	if (_mouseInfo[mouse].State == eInput_Pressing)
		return true;
	return false;
}
bool InputManager::IsMousePress(INT mouse) const
{
	if (_mouseInfo[mouse].State == eInput_Press)
		return true;
	return false;
}
bool InputManager::IsMouseRelease(INT mouse) const
{
	if (_mouseInfo[mouse].State == eInput_Release)
		return true;
	return false;
}
DWORD InputManager::GetMousePressingTime(INT mouse) const
{
	return _mouseInfo[mouse].dwPressingTime;
}
INT  InputManager::IsMouseMovedX() const
{
	return _nMouseMovedX;
}
INT  InputManager::IsMouseMovedY() const
{
	return _nMouseMovedY;
}
INT InputManager::GetMouseWheelMoved() const
{
	return _nMouseWheel;
}

VOID InputManager::GetMouseMonitorPosition(POINT* pt) const
{
	// 모니터(바탕화면)을 기준으로 마우스의 위치를 얻는다.
	GetCursorPos(pt);
}
VOID InputManager::GetMouseWindowPosition(POINT* pt) const
{
	// 모니터(바탕화면)을 기준으로 마우스의 위치를 얻는다.
	GetCursorPos(pt);
	// 모니터 영역의 좌표를 클라이언트 영역의 좌표로 변경한다.
	ScreenToClient(_hWnd, pt);
}
