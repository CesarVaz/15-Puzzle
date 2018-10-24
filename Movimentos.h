#pragma once

typedef struct Coordenadas
{
	int x, y;
}Ponto;

Ponto ReturnPos(int mat[4][4], int p);

void MoveUp(int mat[4][4]);
void MoveDown(int mat[4][4]);
void MoveLeft(int mat[4][4]);
void MoveRight(int mat[4][4]);