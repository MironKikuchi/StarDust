#pragma once

//ボックスコリジョン構造体
typedef struct COLBOX
{
	int posX;		//中心座標_X
	int posY;		//中心座標_Y
	int width;		//矩形の幅
	int height;		//矩形の高さ

} COLBOX;

void UninitCollision(void);
void UpdateCollision(void);

int HitCheckPlayerVsGrand(COLBOX boxA, COLBOX boxB);
int HitCheckPlayerVsWall(COLBOX boxA, COLBOX boxB);