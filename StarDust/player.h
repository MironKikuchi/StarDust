#pragma once

#include <windows.h>
#include <stdio.h>
#include "main.h"

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32

////�O���[�o���ϐ��̒�`
//static PLAYER g_Player;
//static int g_TextureIndex;

////�v���C���[�N���X
//class PLAYER
//{
//public:
//	
//	D3DXVECTOR2 pos;		  				//�v���C���[�̌��݈ʒu
//	//D3DXVECTOR2 acceleration = { 5, 1 };	//X��Y�ɂ���������x
//	//float		jumpSpeed = -7.5;			//�W�����v�������̏オ�葬�x
//	//COLBOX		colBox;
//};

void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);