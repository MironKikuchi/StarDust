#pragma once

#include <Windows.h>

// �o�^�V�[���ꗗ
enum SCENE
{
	SCENE_NONE,		//�V�[�������Ȃ�
	SCENE_TITLE,	//�^�C�g��
	SCENE_STAGESELECT,
	SCENE_GAME1_1,  //�Q�[��
	SCENE_GAME1_2,	//�Q�[��
	SCENE_GAME1_3,	//�Q�[��
	SCENE_GAME2_1,	//�Q�[��
	SCENE_GAME2_2,	//�Q�[��
	SCENE_GAME2_3,	//�Q�[��
	SCENE_GAME3_1,	//�Q�[��
	SCENE_GAME3_2,	//�Q�[��
	SCENE_GAME3_3,	//�Q�[��
	SCENE_GAME4_1,	//�Q�[��
	SCENE_GAME4_2,	//�Q�[��
	SCENE_GAME4_3,	//�Q�[��
	SCENE_GAME4_4,	//�Q�[��
	SCENE_GAME4_5,	//�Q�[��
	SCENE_CLEAR,	//�N���A
	SCENE_DEATH,    //�Q�[���I�[�o�[

	SCENE_MAX		//�Ōゾ�Ƃ킩��z�������
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void NextScene(void);
void ReviveScene(void);
