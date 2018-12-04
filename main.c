#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Jogo.h"
#include "ListaDuplaEstado.h"
#include "Solver.h"
int main(void)
{
	srand(time(NULL));
	int matriz[4][4];
	ListaDuplaEstado *listaEstado = NULL;
	ListaDuplaEstado *listaEstadosDefinitivos = NULL;
	ListaInt *listaPecasTravadas = NULL;
	ListaInt *listaMovimentosOtimizados = NULL;
	/*
	pra testar casos especificos:
	int matriz[4][4] = { { 5,12,6,10 },{ 15,13,14,9 },{ 2,3,11,0 },{ 8,7,4,1 } }; //O PROGRAMA NAO SOLUCIONA ESSE
	int matriz[4][4] = { { 1,2,3,4 },{ 5,6,0,8 },{ 9,10,7,11 },{ 13,14,15,12 } }; //O PROGRAMA SOLUCIONA ESSE
	int matriz[4][4] = { { 2,9,11,15 },{ 5,7,0,6 },{ 12,13,3,8 },{ 10,1,4,14 } }; //O PROGRAMA SOLUCIONA ESSE
	int matriz[4][4] = { { 5,12,6,10 },{ 15,13,14,9 },{ 2,3,11,0 },{ 8,7,4,1 } }; //O PROGRAMA NAO SOLUCIONA ESSE	
	int matriz[4][4] = { { 2,9,11,15 },{ 5,7,0,6 },{ 12,13,3,8 },{ 10,1,4,14 } }; //O PROGRAMA SOLUCIONA ESSE
	*/

	preencheMatriz(matriz);
	encontraCaminho(matriz, &listaEstado, &listaEstadosDefinitivos, &listaPecasTravadas);

printf("tamanho listaEstado: %d\n", tamanho(listaEstado));
printf("tamanho listaEstadosDefinitivos: %d\n", tamanho(listaEstadosDefinitivos));

	getEstadoFromPos(matriz, listaEstado, 0);
	limpaLista(&listaEstado);
	setDoOtimizarMovimentos(listaEstadosDefinitivos, &listaMovimentosOtimizados);

printf("tamanho listaMovimentosOtimizados: %d\n", tamanhoListaInt(listaMovimentosOtimizados));
_getch();

	resolver(matriz, &listaMovimentosOtimizados);

	_getch();
    return 0;
}