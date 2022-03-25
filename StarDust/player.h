#pragma once

#include <windows.h>
#include <stdio.h>
#include "collision.h"
#include "input.h"


#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32


//プレイヤークラス
class PLAYER
{
public:
	
	D3DXVECTOR2 pos;		  					//プレイヤーの現在位置
	D3DXVECTOR2 oldPos;		  					//プレイヤーの過去位置
	D3DXVECTOR2 acceleration	= { 0, 0 };		//XとYにかかる加速度
	D3DXVECTOR2	isJumpSpeed		= { 0, -7.5 };	//ジャンプした時の上がり速度
	float		isJumpGravity	= 0.275;		//ジャンプ後にかかる重力
	COLBOX		colBox;
	int			isJump;
	int			isWall;
	int			IsGrandCheck;


	void IsGravity(void)
	{
		if (acceleration.y != 0)
		{
			acceleration.y += isJumpGravity;
		}
	}
	void CheckToJump(void)
	{
		if (Keyboard_IsTrigger(DIK_SPACE))
		{
			/*isJump = true;
			IsGrandCheck = false;
			acceleration.y = isJumpSpeed.y;*/
			if (isJump == false)
			{
				isJump = true;
				IsGrandCheck = false;
				acceleration.y = isJumpSpeed.y;
				
			}
			else
			{
				return;
			}
		}

		if (isJump != false)
		{
			acceleration.x = 0;
			if (Keyboard_IsPress(DIK_LEFT))
			{
				acceleration.x = -5;
			}
			if (Keyboard_IsPress(DIK_RIGHT))
			{
				acceleration.x = 5;
			}
			if (Keyboard_IsPress(DIK_RIGHT) && Keyboard_IsPress(DIK_LEFT))
			{
				acceleration.x = 0;
			}
			IsGravity();
			pos += acceleration;
		}
	}
};

void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

void PlayerIsGrand(void);
void PlayerIsNotGrand(void);
//void PlayerIsGrand(bool flag);
void HitTheWall(bool flag);
COLBOX GetPlayerColBox(void);
COLBOX GetOldColBoxPlayer(void);