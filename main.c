#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MyFunctions.h"

int main(void)
{
    srand(time(NULL));
    int **MatrizPuzzle;
    MatrizPuzzle = alocarMatriz(4,4);
    ImprimeJogo(MatrizPuzzle);
    Move(MatrizPuzzle);

    return 0;
}
