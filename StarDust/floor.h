#pragma once

#include "collision.h"

#define FLOOR_SIZE_X 34
#define FLOOR_SIZE_Y 20

struct FLOOR_TYPE
{
	D3DXVECTOR2 uv;
	COLBOX colBox;
};


enum MAPTYPE
{
	NONE = 0,
	STONE_FLOOR = 1,
	GOAL_FLOOR = 2
};

int ColBoxArraySize(void);
void InitFloor(void);
void UninitFloor(void);
void DrawFloor(void);

COLBOX GetColBoxFloor(int index);