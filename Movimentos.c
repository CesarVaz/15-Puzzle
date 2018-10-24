#include "Movimentos.h"
#include <conio.h>
#include <stdlib.h>

Ponto ReturnPos(int mat[4][4], int p)
{
	int i, j, pos;
	Ponto Coord;
	pos = p;

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (mat[i][j] == pos)
			{
				Coord.y = i;
				Coord.x = j;
			}
		}
	}
	return Coord;
}

void MoveUp(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	system("cls");

	if (Coord_xy.y > 0)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y - 1][Coord_xy.x];
		mat[Coord_xy.y - 1][Coord_xy.x] = 0;
	}
	return;
}

void MoveDown(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	system("cls");
	if (Coord_xy.y < 3)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y + 1][Coord_xy.x];
		mat[Coord_xy.y + 1][Coord_xy.x] = 0;
	}
	return;
}

void MoveLeft(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	system("cls");
	if (Coord_xy.x > 0)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y][Coord_xy.x - 1];
		mat[Coord_xy.y][Coord_xy.x - 1] = 0;
	}
	return;
}

void MoveRight(int mat[4][4])
{
	Ponto Coord_xy;
	Coord_xy = ReturnPos(mat, 0);
	system("cls");
	if (Coord_xy.x < 3)
	{
		mat[Coord_xy.y][Coord_xy.x] = mat[Coord_xy.y][Coord_xy.x + 1];
		mat[Coord_xy.y][Coord_xy.x + 1] = 0;
	}

	return;
}