#pragma once
#include "ListaDuplaEstado.h"


int preencheMatriz(int mat[4][4], ListaDuplaEstado **lista);
int shuffleArray(int *array, int size);
int inversion_Parity(int *vetor, int tamanho);
int validaJogo(int mat[4][4], int *array);
void ImprimeJogo(int mat[4][4]);
int Move(int mat[4][4], char dir);