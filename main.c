#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Jogo.h"

int main(void)
{
	srand(time(NULL));
	int matriz[4][4];

	preencheMatriz(matriz);
	ImprimeJogo(matriz);

	Move(matriz);

    return 0;
}
