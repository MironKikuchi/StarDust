#pragma once

#include <windows.h>
#include <stdio.h>
#include "main.h"

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32

////グローバル変数の定義
//static PLAYER g_Player;
//static int g_TextureIndex;

////プレイヤークラス
//class PLAYER
//{
//public:
//	
//	D3DXVECTOR2 pos;		  				//プレイヤーの現在位置
//	//D3DXVECTOR2 acceleration = { 5, 1 };	//XとYにかかる加速度
//	//float		jumpSpeed = -7.5;			//ジャンプした時の上がり速度
//	//COLBOX		colBox;
//};

void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);