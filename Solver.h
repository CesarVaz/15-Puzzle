#pragma once

#include "ListaDuplaEstado.h"
#include "ListaTravaPeca.h"

typedef struct movimento
{
	int Manhattan;
	int dir;
} movimento;

int melhorCaminho(int mat[4][4], ListaDuplaEstado **lista, ListaTravaPeca **listaTravaPeca);
void avaliaProximosPassos(int mat[4][4], movimento opcoes[], ListaDuplaEstado *lista, ListaTravaPeca *listaTravaPeca);
int ManhattanDistance(int mat[4][4]);

void desfazMovimento(int mat[4][4], int direcao);
int distanciaDaPeca(int mat[4][4], int valor);
void selectSortManhattan(movimento vetor[], int size);
void swap(movimento *a, movimento *b);
void travaPecas(int mat[4][4], ListaTravaPeca **listaPecasTravadas);