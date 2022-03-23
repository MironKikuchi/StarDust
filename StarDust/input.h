#pragma once

#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>

#define	NUM_KEY_MAX			(256)	// ÉLÅ[ÇÃç≈ëÂêî

bool initialize(HINSTANCE hInstance);
void finalize(void);
bool Keyboard_Initialize(HINSTANCE hInstance, HWND hWnd);
void Keyboard_Finalize(void);
void Keyboard_Update(void);

bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);