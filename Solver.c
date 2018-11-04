#include <stdlib.h>
#include "Solver.h"
#include "Jogo.h"

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista, ListaTravaPeca **listaPecasTravadas)
{
	if (ManhattanDistance(mat) == 0)
		return 1;

	if (isMatrizContida(mat, *lista) == 0)
		insert(lista, mat);

	travaPecas(mat, listaPecasTravadas);
	int i = 0;
	movimento opcoes[4];
	for (i = 0; i < 4; i++)
		opcoes[i].dir = i;

	avaliaProximosPassos(mat, opcoes, *lista, *listaPecasTravadas);
	selectSortManhattan(opcoes, 4);
	for (i = 0; i < 4; i++)
	{
		if(opcoes[i].Manhattan != -1)
		{
			Move(mat, opcoes[i].dir);
			
			if(melhorCaminho(mat, lista, listaPecasTravadas) == 1)
				return 1;

			desfazMovimento(mat, opcoes[i].dir);
		}
	}

	return 0;
}

void avaliaProximosPassos(int mat[4][4], movimento opcoes[], ListaDuplaEstado *lista, ListaTravaPeca *listaTravaPeca)
{
	for (int i = 0; i < 4; i++)
	{
		if (Move(mat, i) == 1)
		{
			if (isMatrizContida(mat, lista) == 0 && isMoveuPecaTravada(mat, listaTravaPeca) == 0)
			{
				opcoes[i].Manhattan = (ManhattanDistance(mat) * 2);
				opcoes[i].Manhattan += (inversion_Parity2D(mat) * 1);
			}
			else
				opcoes[i].Manhattan = -1;

			desfazMovimento(mat, opcoes[i].dir);
		}
		else
			opcoes[i].Manhattan = -1;
	}
	return;
}

int ManhattanDistance(int mat[4][4])
{
	int somaDist = 0;
	int valor = 1;

	while(valor < 16)
		somaDist += distanciaDaPeca(mat, valor++);

	return somaDist;
}

void desfazMovimento(int mat[4][4], int direcao)
{
	if (direcao % 2 == 0)
		Move(mat, direcao + 1);
	else
		Move(mat, direcao - 1);

	return;
}

int distanciaDaPeca(int mat[4][4], int valor)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (mat[i][j] == valor)
				return abs(i - ((valor - 1) / 4)) + abs(j - ((valor - 1) % 4));
	return -1;
}

void selectSortManhattan(movimento vetor[], int size)
{
	if (size <= 1)
		return;

	int posMenor = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[posMenor].Manhattan > vetor[i].Manhattan)
			posMenor = i;
	}
	swap(&(vetor[posMenor]), &(vetor[0]));
	selectSortManhattan(&(vetor[1]), size - 1);

	return;
}

void swap(movimento *a, movimento *b)
{
	movimento aux = *a;
	*a = *b;
	*b = aux;

	return;
}

void travaPecas(int mat[4][4], ListaTravaPeca **listaPecasTravadas)
{
	int i = 1;
	while (distanciaDaPeca(mat, i) == 0 && i < 16)
	{
		if (i < 9 && isPecaContidaNaLista(i, *listaPecasTravadas) == 0)
		{
			if(i == 3 && isPecaContidaNaLista(4, *listaPecasTravadas) == 0)
			{
				insert_ListaTravaPeca(listaPecasTravadas, 3);
				insert_ListaTravaPeca(listaPecasTravadas, 4);
			}
			else
			if (i == 7 && isPecaContidaNaLista(i + 1, *listaPecasTravadas) == 0)
			{
				insert_ListaTravaPeca(listaPecasTravadas, 7);
				insert_ListaTravaPeca(listaPecasTravadas, 8);
			}
			else
			insert_ListaTravaPeca(listaPecasTravadas, i);
		}
		i++;
	}
	return;
}