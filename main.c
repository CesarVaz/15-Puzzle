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
	//int matriz[4][4];
	ListaDuplaEstado *listaEstado = NULL;
	ListaTravaPeca *listaTravaPeca = NULL;

	//preencheMatriz(matriz);
	/*
	pra testar casos especificos:
	int matriz[4][4] = { { 5,12,6,10 },{ 15,13,14,9 },{ 2,3,11,0 },{ 8,7,4,1 } }; //O PROGRAMA NAO SOLUCIONA ESSE
	int matriz[4][4] = { { 1,2,3,4 },{ 5,6,0,8 },{ 9,10,7,11 },{ 13,14,15,12 } }; //O PROGRAMA SOLUCIONA ESSE
	*/
	int matriz[4][4] = { { 2,9,11,15 },{ 5,7,0,6 },{ 12,13,3,8 },{ 10,1,4,14 } }; //O PROGRAMA SOLUCIONA ESSE

	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	printf("\nSoma inversoes:%d\n", inversion_Parity2D(matriz));
	_getch();

	melhorCaminho(matriz, &listaEstado, &listaTravaPeca);
	
	system("cls");
	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	printf("\ntamanho da lista: %d", tamanho(listaEstado));
	_getch();

    return 0;
}