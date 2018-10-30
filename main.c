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
	ListaDuplaEstado *lista = NULL;

	preencheMatriz(matriz);
	/*int matriz[4][4] = { {1,2,3,4}, {5,6,0,8}, {9,10,7,11}, {13,14,15,12} };*/

	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	_getch();

	melhorCaminho(matriz, &lista);
	
	system("cls");
	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	printf("\ntamanho da lista: %d", tamanho(lista));
	_getch();

    return 0;
}