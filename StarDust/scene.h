#pragma once

#include <Windows.h>

// 登録シーン一覧
enum SCENE
{
	SCENE_NONE,		//シーン処理なし
	SCENE_TITLE,	//タイトル
	SCENE_STAGESELECT,
	SCENE_GAME1_1,  //ゲーム
	SCENE_GAME1_2,	//ゲーム
	SCENE_GAME1_3,	//ゲーム
	SCENE_GAME2_1,	//ゲーム
	SCENE_GAME2_2,	//ゲーム
	SCENE_GAME2_3,	//ゲーム
	SCENE_GAME3_1,	//ゲーム
	SCENE_GAME3_2,	//ゲーム
	SCENE_GAME3_3,	//ゲーム
	SCENE_GAME4_1,	//ゲーム
	SCENE_GAME4_2,	//ゲーム
	SCENE_GAME4_3,	//ゲーム
	SCENE_GAME4_4,	//ゲーム
	SCENE_GAME4_5,	//ゲーム
	SCENE_CLEAR,	//クリア
	SCENE_DEATH,    //ゲームオーバー

	SCENE_MAX		//最後だとわかる奴をいれる
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void NextScene(void);
void ReviveScene(void);
