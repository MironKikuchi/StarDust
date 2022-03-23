#pragma once
#include <d3dx9.h>


// �E�B���h�E�̃T�C�Y
#define SCREEN_WIDTH  1024	//��
#define SCREEN_HEIGHT 576	//����


#define CLASS_NAME     "GameWindow"
#define WINDOW_CAPTION "Star Dust"


//window�̃C�x���g����������֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void UpdateMain(HWND hWnd);
void DrawMain(void);

// �QD�|���S�����_�\����
typedef struct Vertex2D_tag
{
	D3DXVECTOR4 position; // ���_���W�i���W�ϊ��ςݒ��_�j
	D3DCOLOR	color;
	D3DXVECTOR2 texCoord;
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1) // �QD�|���S�����_�t�H�[�}�b�g