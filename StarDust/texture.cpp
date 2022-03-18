#include "DirectX.h"
#include "texture.h"


//�O���[�o���ϐ��̒�`
static LPDIRECT3DTEXTURE9	g_Texture[MAX_TEXTURE_NUM] = { 0 };	//�e�N�X�`���z��
static unsigned int g_TextureIndex = 0;

//�v���C���[�e�N�X�`���̓ǂݍ���
int LoadTexture(char* fileName)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//�ǂݍ��ݍő吔�𒴂��Ă����畉�̒l��Ԃ�
	if (g_TextureIndex == MAX_TEXTURE_NUM)
	{
		return -1;
	}

	//�t�@�C������e�N�X�`����ǂݍ���
	if (S_OK != D3DXCreateTextureFromFile(
		pDevice,
		fileName,
		&g_Texture[g_TextureIndex])
		)
	{
		//�ǂݍ��݂Ɏ��s�����ꍇ�A���̒l��Ԃ�
		return -1;
	}

	int retIndex = g_TextureIndex;

	//�C���f�b�N�X����i�߂�
	g_TextureIndex++;

	return retIndex;
}

void UninitTexture(void)
{
	for (int i = 0; i < (int)g_TextureIndex; i++)
	{
		if (g_Texture[i] != NULL)
		{
			g_Texture[i]->Release();
			g_Texture[i] = NULL;
		}
	}
}


//�e�N�X�`���̃Q�b�^�[
LPDIRECT3DTEXTURE9 GetTexture(int index)
{
	//index�̕s���l�`�F�b�N(���̒l)
	if (index < 0)
		return NULL;

	//index�̕s���l�`�F�b�N(�ő吔�I�[�o�[)
	if (index >= (int)g_TextureIndex)
		return NULL;

	return g_Texture[index];
}
