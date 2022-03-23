#pragma once

#include <d3dx9.h>
#include "DirectX.h"

#define MAX_TEXTURE_NUM 1000


int LoadTexture(char* fileName);
void UninitTexture(void);

LPDIRECT3DTEXTURE9 GetTexture(int index);
