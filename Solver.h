#pragma once

#include "ListaDuplaEstado.h"
#include "ListaTravaPeca.h"
#include "ListaMovimentosOtimizados.h"

typedef struct movimento
{
	int Manhattan;
	int dir;
} movimento;

int melhorCaminho(int matriz[4][4], ListaDuplaEstado **listaEstado, ListaDuplaEstado **listaEstadosDefinitivos, ListaTravaPeca **listaPecasTravadas);
void avaliaProximosPassos(int matriz[4][4], movimento opcoes[], ListaDuplaEstado *listaEstado, ListaTravaPeca *listaPecasTravadas);
int ManhattanDistance(int matriz[4][4]);

void desfazMovimento(int matriz[4][4], int direcao);
int distanciaDaPeca(int matriz[4][4], int valor);
void selectSortManhattan(movimento vetor[], int size);
void swap(movimento *a, movimento *b);
void travaPecas(int matriz[4][4], ListaTravaPeca **listaPecasTravadas);

int setDoOtimizarMovimentos(ListaDuplaEstado *listaEstado, ListaMovimentosOtimizados **listaMovimentosOtimizados);
int otimizarMovimentos(int estadoInicial[4][4], ListaDuplaEstado *listaEstado, ListaMovimentosOtimizados **listaMovimentosOtimizados, int indice);
int resolver(int matriz[4][4], ListaMovimentosOtimizados **listaMovimentosOtimizados);