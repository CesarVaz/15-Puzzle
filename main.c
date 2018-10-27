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
	preencheMatriz(matriz, &lista);

	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	_getch();

	melhorCaminho(matriz, &lista);
	
	system("cls");
	ImprimeJogo(matriz);
	printf("MANHATAAAN  %d", ManhattanDistance(matriz));
	_getch();

    return 0;
}
