#include "DirectX.h"
#include "collision.h"
#include "player.h"
#include "floor.h"
#include "scene.h"
#include <stdio.h>



void UninitCollision(void)
{

}


void UpdateCollision(void)
{

	//壁や床とプレイヤーの当たり判定
	for (int i = 0; i < ColBoxArraySize(); i++)
	{
		HitCheckPlayerVsGrand(GetPlayerColBox(), GetColBoxFloor(i));
	}
}



//ボックスコリジョン同士の衝突判定
int HitCheckPlayerVsGrand(COLBOX boxA, COLBOX boxB)
{
	int topA = boxA.posY - boxA.height / 2;
	int bottomA = boxA.posY + boxA.height / 2;

	int topB = boxB.posY - boxB.height / 2;
	int bottomB = boxB.posY + boxB.height / 2;

	if (topA > bottomB)
	{
		return 0;
	}

	//プレイヤーとタイルが離れてる場合
	if (bottomA < topB)
	{
		
		
	}
	else
	{
		PlayerIsGrand();
	}
	
}

int HitCheckPlayerVsWall(COLBOX boxA, COLBOX boxB)
{
	int leftA = boxA.posX - boxA.width / 2;
	int rightA = boxA.posX + boxA.width / 2;

	int leftB = boxB.posX - boxB.width / 2;
	int rightB = boxB.posX + boxB.width / 2;

	//「Aの右」と「Bの左」を比較して「Bの左」の方が大きい
	if (rightA < leftB)
	{
		//この条件が成り立っているときは当たっていない
		return 0;
	}
	else if (rightA > leftB)
	{
		HitTheWall(true);
		return 0;
	}

	if (leftA > rightB)
	{
		return 0;
	}
}

//int HitCheckPlayerVsWall(COLBOX boxA, COLBOX boxB)
//{
//	int topA = boxA.posY - boxA.height / 2;
//	int bottomA = boxA.posY + boxA.height / 2;
//	int leftA = boxA.posX - boxA.width / 2;
//	int rightA = boxA.posX + boxA.width / 2;
//
//	int topB = boxB.posY - boxB.height / 2;
//	int bottomB = boxB.posY + boxB.height / 2;
//	int leftB = boxB.posX - boxB.width / 2;
//	int rightB = boxB.posX + boxB.width / 2;
//
//	//「Aの右」と「Bの左」を比較して「Bの左」の方が大きい
//	if (rightA < leftB)
//	{
//		//この条件が成り立っているときは当たっていない
//		return 0;
//	}
//	else if (rightA > leftB)
//	{
//		HitTheWall(true);
//		return 0;
//	}
//
//	if (leftA > rightB)
//	{
//		return 0;
//	}
//
//	if (topA > bottomB)
//	{
//		return 0;
//	}
//
//	if (bottomA < topB)
//	{
//		return 0;
//	}
//	else
//	{
//		PlayerIsGrand();
//	}
//}