#include <windows.h>
#include <stdio.h>
#include "game1-1.h"
#include "texture.h"
#include "player.h"
#include "floor.h"



void InitGame1_1(void)
{
	InitFloor();
	InitPlayer();
}

void UninitGame1_1(void)
{
	UninitFloor();
	UninitPlayer();
}

void UpdateGame1_1(void)
{
	UpdatePlayer();
	UpdateCollision();
}

void DrawGame1_1(void)
{
	DrawFloor();
	DrawPlayer();
}