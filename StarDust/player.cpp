#include "main.h"
#include "player.h"
#include "input.h"
#include "texture.h"


//グローバル変数の定義
static PLAYER g_Player;
static int g_TextureIndex;

void InitPlayer(void)
{
	g_Player.pos.x = (SCREEN_WIDTH / 2) - 100;
	g_Player.pos.y = (SCREEN_HEIGHT / 2) + 245;
	g_Player.isJamp = false;
	g_Player.isWall = false;
	g_Player.IsGrandCheck = true;

	g_TextureIndex = LoadTexture("texture/player.png");

	g_Player.colBox.width = (PLAYER_SIZE_X / 2);
	g_Player.colBox.height = (PLAYER_SIZE_Y / 2) + 12;
}

void UninitPlayer(void)
{

}

void UpdatePlayer(void)
{
	g_Player.CheckToJamp();

	/*if (g_Player.pos.y >= SCREEN_HEIGHT)
	{
		g_Player.pos.y = (SCREEN_HEIGHT - PLAYER_SIZE_Y);
	}*/

	g_Player.colBox.posX = g_Player.pos.x;
	g_Player.colBox.posY = g_Player.pos.y;
}

void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// 頂点データ
	Vertex2D v[] = {
		{//左上
			D3DXVECTOR4((float)g_Player.pos.x - (PLAYER_SIZE_X / 2), (float)g_Player.pos.y - (PLAYER_SIZE_Y / 2), 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//右上
			D3DXVECTOR4((float)g_Player.pos.x + (PLAYER_SIZE_X / 2), (float)g_Player.pos.y - (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//左下
			D3DXVECTOR4((float)g_Player.pos.x - (PLAYER_SIZE_X / 2), (float)g_Player.pos.y + (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//右下
			D3DXVECTOR4((float)g_Player.pos.x + (PLAYER_SIZE_X / 2), (float)g_Player.pos.y + (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};

	//ポリゴンとテクスチャを対応させる
	LPDIRECT3DTEXTURE9 pTexture;
	//欲しいテクスチャの整理番号を伝える
	pTexture = GetTexture(g_TextureIndex);
	pDevice->SetTexture(0, pTexture);
	pDevice->SetFVF(FVF_VERTEX2D);

	pDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		2,
		v,
		sizeof(Vertex2D)
	);
}

void PlayerIsGrand(void)
{
	g_Player.pos.y = g_Player.pos.y;
	/*char str[256];
	sprintf_s(str, "PosY: %d\n", g_Player.pos.y);
	OutputDebugString(str);*/
}

//void PlayerIsGrand(bool flag)
//{
//	
//	if (g_Player.IsGrandCheck == true)
//	{
//		g_Player.pos.y = g_Player.pos.y;
//		g_Player.isJamp = false;
//		g_Player.isWall = false;
//	}
//	else if (g_Player.IsGrandCheck == false)
//	{
//		return;
//	}
//	char str[256];
//	sprintf_s(str, "PosY: %d\n", g_Player.IsGrandCheck);
//	OutputDebugString(str);
//}

//void HitTheWall(void)
//{
//	g_Player.pos.x == g_Player.pos.x;
//	g_Player.pos.y += 1;
//}


void HitTheWall(bool flag)
{
	g_Player.isWall = flag;

	if (g_Player.isWall == true)
	{
		g_Player.pos.x == g_Player.pos.x;
		g_Player.pos.y += 1;
	}
	else
	{
		return;
	}

}
COLBOX GetPlayerColBox(void)
{
	return (g_Player.colBox);
}