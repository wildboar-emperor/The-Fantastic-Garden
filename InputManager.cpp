#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager(void)
{
	// �޸� �ʱ�ȭ.
	memset(_byteNowKeyStateValue, 0, sizeof(_byteNowKeyStateValue));
	memset(_byteOldKeyStateValue, 0, sizeof(_byteOldKeyStateValue));
	memset(_byteNowMouseStateValue, 0, sizeof(_byteNowMouseStateValue));
	memset(_byteOldMouseStateValue, 0, sizeof(_byteOldMouseStateValue));
}
InputManager::~InputManager(void)
{
	if (_flagUseDevice & USE_KEYBOARD)
	{
		// Ű������ ������� �����Ѵ�.
		_lpDirectInputDeviceKeyboard->Unacquire();
		// Ű���� ��ġ�� �޸𸮿��� �����Ѵ�.
		SAFE_RELEASE(_lpDirectInputDeviceKeyboard);
	}
	if (_flagUseDevice & USE_MOUSE)
	{
		// ���콺�� ������� �����Ѵ�.
		_lpDirectInputDeviceMouse->Unacquire();
		// ���콺 ��ġ�� �޸𸮿��� �����Ѵ�.
		SAFE_RELEASE(_lpDirectInputDeviceMouse);
	}
	// DirectInput�� �޸𸮿��� �����Ѵ�.
	_lpDirectInput->Release();
}
bool InputManager::Init(HWND hWnd, DWORD useDevice)
{
	// ���ڰ��� ��������� �����Ѵ�.
	_hWnd = hWnd;
	_flagUseDevice = useDevice;
	// DirectInput �ý����� ����ϰ� DirectInput �������̽��� �����͸� �޾ƿ´�.
	// DirectInput8Create()�Լ��� ���� ����.
	// (�ڱ��ڽ��� �ν��Ͻ�, ����, �䱸�ϴ� �������̽��� ���� �ĺ���ȣ(�Ƚ�/�����ڵ�), �������̽��� �ּ�, IUnknown �������̽��� �ּ�)
	HRESULT hr;
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&_lpDirectInput, NULL)))
	{
		return false;
	}
	if (_flagUseDevice & USE_KEYBOARD)
	{
		// Ű���� ��ġ�� _lpDirectInputDeviceKeyboard �� �����Ѵ�.
		if (FAILED(_lpDirectInput->CreateDevice(GUID_SysKeyboard, &_lpDirectInputDeviceKeyboard, NULL)))
		{
			return false;
		}
		// ��� ������ Ű���带 ������� �����Ѵ�.
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
		// ���콺 ��ġ�� _lpDirectInputDeviceMouse �� �����Ѵ�.
		if (FAILED(_lpDirectInput->CreateDevice(GUID_SysMouse, &_lpDirectInputDeviceMouse, NULL)))
		{
			return false;
		}
		// ��� ������ ���콺�� ������� �����Ѵ�. (c_dfDIMouse : 3��ư, c_dfDIMouse2 : 4��ư)
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
// �÷��׿� ���� Ű����� ���콺�� ���°��� �޾ƿ´�.
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
	// Ű���� ��ġ�� �ִ��� Ȯ�� �� ������ ����.
	if (NULL == _lpDirectInputDeviceKeyboard)
		return;
	// Ű������ ���°��� ������ �迭�� �ʱ�ȭ�Ѵ�.
	ZeroMemory(&_byteNowKeyStateValue, sizeof(_byteNowKeyStateValue));
	HRESULT hr;
	// ������ ���¸� �б����� ��ġ�� �����Ѵ�.
	hr = _lpDirectInputDeviceKeyboard->Poll();
	if (FAILED(hr))
	{
		// ��ġ�� �����ϴ� ���� ���ع޾Ҵٸ� �ٽ� ������� ��´�.
		hr = _lpDirectInputDeviceKeyboard->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = _lpDirectInputDeviceKeyboard->Acquire();
	}
	// Ű������ ���°��� �����Ѵ�.
	if (FAILED(hr = _lpDirectInputDeviceKeyboard->GetDeviceState(sizeof(_byteNowKeyStateValue), &_byteNowKeyStateValue)))
	{
		return; // ��ġ�� �����ϴ� ���� ������� ���� ������ �� �ִ�.
	}
}
VOID InputManager::GetMouse()
{
	if (NULL == _lpDirectInputDeviceMouse)
		return;
	// Ű������ ���°��� ������ �迭�� �ʱ�ȭ�Ѵ�.
	ZeroMemory(&_byteNowMouseStateValue, sizeof(_byteNowMouseStateValue));
	HRESULT hr;
	// ������ ���¸� �б����� ��ġ�� �����Ѵ�.
	hr = _lpDirectInputDeviceMouse->Poll();
	if (FAILED(hr))
	{
		// ��ġ�� �����ϴ� ���� ���ع޾Ҵٸ� �ٽ� ������� ��´�.
		hr = _lpDirectInputDeviceMouse->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = _lpDirectInputDeviceMouse->Acquire();
	}
	// ���콺�� ���°��� �����Ѵ�.
	DIMOUSESTATE MouseState;
	if (FAILED(hr = _lpDirectInputDeviceMouse->GetDeviceState(sizeof(DIMOUSESTATE), &MouseState)))
	{
		return; // ��ġ�� �����ϴ� ���� ������� ���� ������ �� �ִ�.
	}
	_nMouseMovedX = (INT)(MouseState.lX);
	_nMouseMovedY = (INT)(MouseState.lY);
	_nMouseWheel = (INT)(MouseState.lZ);
	memcpy(_byteNowMouseStateValue, MouseState.rgbButtons, sizeof(_byteNowMouseStateValue));
}
VOID InputManager::SetKeyboard()
{
	DWORD dwTime = ::timeGetTime();
	// ���������� ����ü�� �����Ѵ�.
	for (INT i = 0; i < 256; i++)
	{
		if (_byteOldKeyStateValue[i] == 0 && _byteNowKeyStateValue[i] == 0)    _keyInfo[i].State = eInput_None;
		else if (_byteOldKeyStateValue[i] == 0 && _byteNowKeyStateValue[i] == 0x80)
			_keyInfo[i].State = eInput_Press;
		else if (_byteOldKeyStateValue[i] == 0x80 && _byteNowKeyStateValue[i] == 0) 
			_keyInfo[i].State = eInput_Release;
		else if (_byteOldKeyStateValue[i] == 0x80 && _byteNowKeyStateValue[i] == 0x80)
			_keyInfo[i].State = eInput_Pressing;
		// Ű�� ���°� None�� ���, Pressed Time�� 0���� �ʱ�ȭ�Ѵ�.
		if (_keyInfo[i].State == eInput_None)
		{
			_keyInfo[i].dwPressedTime = 0;
			_keyInfo[i].dwPressingTime = 0;
		}
		// Ű�� ���°� Press�� ���, Pressed Time�� ���� �ð����� �����Ѵ�.
		if (_keyInfo[i].State == eInput_Press)
			_keyInfo[i].dwPressedTime = dwTime;
		// Ű�� ���°� Pressing �� ���, ���� �ð������� Pressed Time�� ���� Pressing Time�� ���Ѵ�.
		if (_keyInfo[i].State == eInput_Pressing)
			_keyInfo[i].dwPressingTime = dwTime - _keyInfo[i].dwPressedTime;
	}
	// ���� Ű�� ���¸� ���� Ű ���¹迭�� �����Ѵ�.
	memcpy(_byteOldKeyStateValue, _byteNowKeyStateValue, sizeof(_byteNowKeyStateValue));
}
VOID InputManager::SetMouse()
{
	// ���� �ð���(�����찡 ������ ������ ī��Ʈ ��)�� ���´�.
	DWORD dwTime = ::timeGetTime();
	// ��� ���콺�� ���ؼ�, ���콺���� ���� ������ ����ü�� �����Ѵ�.
	for (INT i = 0; i < 3; i++)
	{
		if (_byteOldMouseStateValue[i] == 0 && _byteNowMouseStateValue[i] == 0)    _mouseInfo[i].State = eInput_None;
		else if (_byteOldMouseStateValue[i] == 0 && _byteNowMouseStateValue[i] == 0x80)  _mouseInfo[i].State = eInput_Press;
		else if (_byteOldMouseStateValue[i] == 0x80 && _byteNowMouseStateValue[i] == 0)  _mouseInfo[i].State = eInput_Release;
		else if (_byteOldMouseStateValue[i] == 0x80 && _byteNowMouseStateValue[i] == 0x80) _mouseInfo[i].State = eInput_Pressing;
		// ���콺�� ���°� None�� ���, Pressed Time�� 0���� �ʱ�ȭ�Ѵ�.
		if (_mouseInfo[i].State == eInput_None)
		{
			_mouseInfo[i].dwPressedTime = 0;
			_mouseInfo[i].dwPressingTime = 0;
		}
		// ���콺�� ���°� Press�� ���, Pressed Time�� ���� �ð����� �����Ѵ�.
		if (_mouseInfo[i].State == eInput_Press)
			_mouseInfo[i].dwPressedTime = dwTime;
		// ���콺�� ���°� Pressing �� ���, ���� �ð������� Pressed Time�� ���� Pressing Time�� ���Ѵ�.
		if (_mouseInfo[i].State == eInput_Pressing)
			_mouseInfo[i].dwPressingTime = dwTime - _mouseInfo[i].dwPressedTime;
	}
	// ���� ���콺�� ���¸� ���� ���콺 ���¹迭�� �����Ѵ�.
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
	// �����(����ȭ��)�� �������� ���콺�� ��ġ�� ��´�.
	GetCursorPos(pt);
}
VOID InputManager::GetMouseWindowPosition(POINT* pt) const
{
	// �����(����ȭ��)�� �������� ���콺�� ��ġ�� ��´�.
	GetCursorPos(pt);
	// ����� ������ ��ǥ�� Ŭ���̾�Ʈ ������ ��ǥ�� �����Ѵ�.
	ScreenToClient(_hWnd, pt);
}
