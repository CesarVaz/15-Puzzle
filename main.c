#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MyFunctions.h"
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int matriz[4][4];

	preencheMatriz(matriz);
	ImprimeJogo(matriz);

	Move(matriz);

	_getch();
    return 0;
}
