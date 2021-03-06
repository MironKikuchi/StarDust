#include <iostream>
#include <vector>
#include "main.h"
#include "DirectX.h"
#include "floor.h"
#include "game1-1.h"
#include "sprite.h"


FLOOR_TYPE g_Floor_Type[3] =
{
	{
		{ 0, 0 }		//透明
	},
	{
		{ 0.6875f, 0.7497f }	//石畳
	},
	{
		{ 0.375f, 0.25f }		//石ブロック
	},
};

//グローバル変数の定義
static int g_TextureIndex;
COLBOX test;
std::vector <COLBOX> g_ColBoxes;


int g_Floor_Map1_1[FLOOR_SIZE_Y][FLOOR_SIZE_X] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0 },
	{ 0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


void InitFloor(void)
{
	g_TextureIndex = LoadTexture("texture/TileA2.png");

	for (int y = 0; y < FLOOR_SIZE_Y; y++)
	{
		for (int x = 0; x < FLOOR_SIZE_X; x++)
		{
			if (g_Floor_Map1_1[y][x] == 1)
			{
				test.posX = 16 + 32 * (x - 1);
				test.posY = 16 + 32 * (y - 1);
				test.height = 32;
				test.width = 32;
				g_ColBoxes.push_back(test);
			}
			std::cout << g_ColBoxes.size() << std::endl;
		}
	}

}


void UninitFloor()
{

}

void DrawFloor(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 34; x++)
		{
			if (g_Floor_Map1_1[y][x] == 0)
			{
				if (g_Floor_Map1_1[y][x] == 0)
				{
					DrawSpriteColor(g_TextureIndex, 16 + 32 * x, 16 + 32 * y,
						32, 32,
						g_Floor_Type[g_Floor_Map1_1[y][x]].uv[0], g_Floor_Type[g_Floor_Map1_1[y][x]].uv[1],
						0.0625f, 0.0833f, D3DXCOLOR(1, 1, 1, 0));
				}
			}
			else
			{

				DrawSpriteColor(g_TextureIndex, 16 + 32 * (x - 1), 16 + 32 * (y - 1),
					32, 32,
					g_Floor_Type[g_Floor_Map1_1[y][x]].uv[0], g_Floor_Type[g_Floor_Map1_1[y][x]].uv[1],
					0.0625f, 0.0833f, D3DXCOLOR(1, 1, 1, 1));
			}
		}
	}
}


int ColBoxArraySize()
{
	return g_ColBoxes.size();
}


COLBOX GetColBoxFloor(int index)
{
	return(g_ColBoxes[index]);
}
