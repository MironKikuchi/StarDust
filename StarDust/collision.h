#pragma once

//�{�b�N�X�R���W�����\����
typedef struct COLBOX
{
	int posX;		//���S���W_X
	int posY;		//���S���W_Y
	int width;		//��`�̕�
	int height;		//��`�̍���

} COLBOX;

void UninitCollision(void);
void UpdateCollision(void);

int HitCheckCollisionBox(COLBOX boxA, COLBOX boxB);
int HitCheckPlayerVsGrand(COLBOX boxA, COLBOX boxB);
int HitCheckPlayerVsWall(COLBOX boxA, COLBOX boxB);