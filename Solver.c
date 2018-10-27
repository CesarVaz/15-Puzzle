#include <stdlib.h>
#include "Solver.h"
#include "Jogo.h"
#include "Movimentos.h"

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista)
{
	insert(&(*lista), mat);
	int menorManhattan = 9999;
	char dir;
	int check_Dir = -1;
	int volta = -1;

	volta = Move(mat, 'w');
	if (comparaMatrizes(mat, *lista) != 0)
	{
		menorManhattan = ManhattanDistance(mat);
		dir = 'w';
		check_Dir = 0;
	}
	if (volta == 0)
	{
		Move(mat, 's');
		volta = -1;
	}

	volta = Move(mat, 's');
	if (menorManhattan > ManhattanDistance(mat) && comparaMatrizes(mat, *lista) != 0)
	{
		menorManhattan = ManhattanDistance(mat);
		dir = 's';
		check_Dir = 0;
	}
	if (volta == 0)
	{
		Move(mat, 'w');
		volta = -1;
	}

	volta = Move(mat, 'd');
	if (menorManhattan > ManhattanDistance(mat) && comparaMatrizes(mat, *lista) != 0)
	{
		menorManhattan = ManhattanDistance(mat);
		dir = 'd';
		check_Dir = 0;
	}
	if (volta == 0)
	{
		Move(mat, 'a');
		volta = -1;
	}

	volta = Move(mat, 'a');
	if (menorManhattan > ManhattanDistance(mat) && comparaMatrizes(mat, *lista) != 0)
	{
		menorManhattan = ManhattanDistance(mat);
		dir = 'a';
		check_Dir = 0;
	}
	if (volta == 0)
	{
		Move(mat, 'd');
		volta = -1;
	}

	if (check_Dir == -1)
		return 0;

	Move(mat, dir);

	if (melhorCaminho(mat, &(*lista)) == 1)
		return 1;

	removeEstado(&(*lista), mat);

	return 0;
}

/*POR ENQUANTO ESTOU TRABALHANDO NA melhorCaminho, NAO NA melhorCaminho2*/
int melhorCaminho2(int mat[4][4], ListaDuplaEstado **lista)
{
	insert(&(*lista), mat);
	int volta = -1;

	volta = Move(mat, 'w');
	if (comparaMatrizes(mat, *lista) != 0)
	{
		system("cls");
		ImprimeJogo(mat);

		if (melhorCaminho2(mat, &(*lista)) == 1)
			return 1;
	}
	if (volta == 0)
	{
		Move(mat, 's');
		volta = -1;
	}

	volta = Move(mat, 's');
	if (comparaMatrizes(mat, *lista) != 0)
	{
		system("cls");
		ImprimeJogo(mat);

		if (melhorCaminho2(mat, &(*lista)) == 1)
			return 1;
	}
	if (volta == 0)
	{
		Move(mat, 'w');
		volta = -1;
	}

	volta = Move(mat, 'd');
	if (comparaMatrizes(mat, *lista) != 0)
	{
		system("cls");
		ImprimeJogo(mat);

		if (melhorCaminho2(mat, &(*lista)) == 1)
			return 1;
	}
	if (volta == 0)
	{
		Move(mat, 'a');
		volta = -1;
	}

	volta = Move(mat, 'a');
	if (comparaMatrizes(mat, *lista) != 0)
	{
		system("cls");
		ImprimeJogo(mat);

		if (melhorCaminho2(mat, &(*lista)) == 1)
			return 1;
	}
	if (volta == 0)
	{
		Move(mat, 'd');
		volta = -1;
	}

	return 0;
}


int ManhattanDistance(int mat[4][4])
{
	int somaDist = 0;
	int valor = 1;

	while(valor < 16)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mat[i][j] == valor)
				{
					somaDist += abs(i - ((valor - 1) / 4)) + abs(j - ((valor - 1) % 4));
					valor++;
				}
			}
		}
	}
	return somaDist;
}