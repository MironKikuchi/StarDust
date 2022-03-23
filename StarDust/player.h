#pragma once

#include <windows.h>
#include <stdio.h>
#include "collision.h"
#include "input.h"


#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32


//�v���C���[�N���X
class PLAYER
{
public:
	
	D3DXVECTOR2 pos;		  				//�v���C���[�̌��݈ʒu
	D3DXVECTOR2 acceleration	= { 5, 1 };	//X��Y�ɂ���������x
	D3DXVECTOR2	isJumpSpeed		= { 0, -7.5 };	//�W�����v�������̏オ�葬�x
	float		isJampGravity	= 0.275;		//�W�����v��ɂ�����d��
	COLBOX		colBox;
	int			isJamp;
	int			isWall;
	int			IsGrandCheck;


	void IsGravity(void)
	{
		if (acceleration.y != 0)
		{
			acceleration.y += isJampGravity;
		}
	}
	void CheckToJamp(void)
	{
		if (Keyboard_IsTrigger(DIK_SPACE))
		{
			
			if (isJamp == false)
			{
				isJamp = true;
				IsGrandCheck = false;
				acceleration.y = isJumpSpeed.y;
				
			}
			else
			{
				return;
			}
		}

		if (isJamp != false)
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
void PlayerIsGrand(bool flag);
void HitTheWall(bool flag);
COLBOX GetPlayerColBox(void);