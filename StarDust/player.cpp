#include "DirectX.h"
#include "player.h"
#include "texture.h"


//プレイヤークラス
class PLAYER
{
public:

	D3DXVECTOR2 pos = { 5, 1 };		  				//プレイヤーの現在位置
	//D3DXVECTOR2 acceleration = { 5, 1 };	//XとYにかかる加速度
	//float		jumpSpeed = -7.5;			//ジャンプした時の上がり速度
	//COLBOX		colBox;
};

//グローバル変数の定義
static PLAYER g_Player;
static int g_TextureIndex;

void InitPlayer(void)
{
	g_Player.pos.x = (SCREEN_WIDTH / 2) - 100;
	g_Player.pos.y = (SCREEN_HEIGHT / 2) + 245;

	g_TextureIndex = LoadTexture("texture/player.png");
}

void UninitPlayer(void)
{

}

void UpdatePlayer(void)
{

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