#include "scene.h"
#include "game1-1.h"

//�O���[�o���ϐ��̒�`
static SCENE g_SceneIndex = SCENE_TITLE;
static SCENE g_ScenePrevIndex = g_SceneIndex;
static SCENE g_SceneNextIndex = g_SceneIndex;


void InitScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_GAME1_1:
		InitGame1_1();
		g_ScenePrevIndex = SCENE_GAME1_1;
		break;
	}
}


void UninitScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_GAME1_1:
		UninitGame1_1();
		break;

	}
}


void UpdateScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_GAME1_1:
		UpdateGame1_1();
		break;

	}
}


void DrawScene(void)
{

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_GAME1_1:
		DrawGame1_1();
		break;

	}
}


void SetScene(SCENE index)
{
	//�J�ڐ�V�[����ݒ肷��
	g_SceneNextIndex = index;
}


//���݂̃V�[�������̃V�[���ɐ؂�ւ���֐�
void NextScene(void)
{
	//���݂̃V�[���ƑJ�ڐ�V�[��������Ă�����
	if (g_SceneIndex != g_SceneNextIndex)
	{
		//���݂̃V�[�����I��������
		UninitScene();

		//�J�ڐ�V�[���̏������������s��
		InitScene(g_SceneNextIndex);
		DrawScene();
	}
}

/*------------------------------------------------------------------------------
GAMEOVER���Ɍ��݂̃V�[����ǂݍ��ފ֐�
------------------------------------------------------------------------------*/
void ReviveScene(void)
{
	UninitScene();
	InitScene(g_ScenePrevIndex);
	DrawScene();
}