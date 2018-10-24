#include "Jogo.h"
#include "Movimentos.h"
#include <stdio.h>
#include <stdlib.h>

int preencheMatriz(int mat[4][4])
{
	int i, j, k = 0;
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	while(inversion_Parity(array, 16) == 2)
		shuffleArray(array, 16);

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			mat[i][j] = array[k++];

	validaJogo(mat, array);

	return 0;
}

int inversion_Parity(int *array, int size)
{
	int cont = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j] && array[j] != 0)
				cont++;
		}

	if (cont > 0)
		return cont % 2;

	return 2;
}

int shuffleArray(int *array, int size)
{
	int random = rand() % (size);
	int temp;

	temp = array[size - 1];
	array[size - 1] = array[random];
	array[random] = temp;

	if (size > 1)
		shuffleArray(array, size - 1);

	return 0;
}

int validaJogo(int mat[4][4], int *array)
{
	int i = 0, j = 0;
	if (ReturnPos(mat, 0).y % 2 == inversion_Parity(array, 16))
	{
		while (mat[i][j] < mat[i][j + 1] || mat[i][j + 1] == 0)
		{
			j++;
			if (j == 4)
			{
				j = 0;
				i++;
			}
		}
		int temp = mat[i][j];
		mat[i][j] = mat[i][j + 1];
		mat[i][j + 1] = temp;
	}

	return 0;
}

void ImprimeJogo(int mat[4][4])
{
    int i,j;
    for(i = 0 ; i < 4; i++)
    {
        for(j=0;j<4;j++)
        {
			if(mat[i][j] < 10)
				printf("%d  ",mat[i][j]);
			else
				printf("%d ", mat[i][j]);
        }
		printf("\n");
    }
	return;
}

void Move(int mat[4][4])
{

	char IsPressed;
	int sair = 1;

	do
	{
		IsPressed = getch();
		switch (IsPressed)
		{
		case 'w':
			MoveUp(mat);
			ImprimeJogo(mat);
			break;
		case 's':
			MoveDown(mat);
			ImprimeJogo(mat);
			break;
		case 'd':
			MoveRight(mat);
			ImprimeJogo(mat);
			break;
		case 'a':
			MoveLeft(mat);
			ImprimeJogo(mat);
			break;
		case 'q':
			sair = 0;
			break;

		}
	} while (sair);

	return;
}

