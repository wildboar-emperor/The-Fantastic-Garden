#include "stdafx.h"
#include "Sence.h"
#include "Managers.h"
#include "Player.h"
Sence::Sence()
{
}


Sence::~Sence()
{
	Release();
}


void Sence::initialize()
{

}

void Sence::Release()
{

}
	    
void Sence::Render()
{
	// Clear the backbuffer to a blue color
	DirectX->g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0xff, 0xff, 0xff), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(DirectX->g_pd3dDevice->BeginScene()))
	{
		draw();

		//DirectX->FPSOutPut();

		// End the scene
		DirectX->g_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	DirectX->g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void Sence::draw()
{

}

void Sence::Process()
{

}

void Sence::KeyEvent()
{

}

unsigned long Sence::Input(KEYSTATE kst)
{
	unsigned long et = 0;
	DWORD keyState = (kst == KsDown) ? 0x8000 : 0x0001;

	if (GetKeyState(0x5a) &				keyState)		et |= EK_Z;
	if (GetKeyState(0x5b) &				keyState)		et |= EK_X;
	if (GetKeyState(VK_LEFT) &		keyState)		et |= EK_LEFT;
	if (GetKeyState(VK_RIGHT) &		keyState)		et |= EK_RIGHT;
	if (GetKeyState(VK_UP) &			keyState)		et |= EK_UP;
	if (GetKeyState(VK_DOWN) &	keyState)		et |= EK_DOWN;
	if (GetKeyState(VK_LSHIFT) &	keyState)		et |= EK_SHIFT;
	//if (GetKeyState(VK_ESCAPE) &	keyState)		et |= EK_escap;
	if (GetKeyState(VK_RETURN) &	keyState)		et |= EK_ENTER;

	return et;
}

void Sence::Run()
{							
	KeyEvent();	
	Process();			
	Render();
							
}
