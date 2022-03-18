#include "DirectX.h"
#include "player.h"
#include "texture.h"


//�v���C���[�N���X
class PLAYER
{
public:

	D3DXVECTOR2 pos = { 5, 1 };		  				//�v���C���[�̌��݈ʒu
	//D3DXVECTOR2 acceleration = { 5, 1 };	//X��Y�ɂ���������x
	//float		jumpSpeed = -7.5;			//�W�����v�������̏オ�葬�x
	//COLBOX		colBox;
};

//�O���[�o���ϐ��̒�`
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

	// ���_�f�[�^
	Vertex2D v[] = {
		{//����
			D3DXVECTOR4((float)g_Player.pos.x - (PLAYER_SIZE_X / 2), (float)g_Player.pos.y - (PLAYER_SIZE_Y / 2), 0.0f, 1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,0.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_Player.pos.x + (PLAYER_SIZE_X / 2), (float)g_Player.pos.y - (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,0.0f),
		},
		{//����
			D3DXVECTOR4((float)g_Player.pos.x - (PLAYER_SIZE_X / 2), (float)g_Player.pos.y + (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(0.0f,1.0f),
		},
		{//�E��
			D3DXVECTOR4((float)g_Player.pos.x + (PLAYER_SIZE_X / 2), (float)g_Player.pos.y + (PLAYER_SIZE_Y / 2),0.0f,1.0f),
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f),
			D3DXVECTOR2(1.0f,1.0f),
		}
	};

	//�|���S���ƃe�N�X�`����Ή�������
	LPDIRECT3DTEXTURE9 pTexture;
	//�~�����e�N�X�`���̐����ԍ���`����
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