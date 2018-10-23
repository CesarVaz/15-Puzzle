#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED


typedef struct Coordenadas
{
    int x,y;
}Ponto;

int preencheMatriz(int mat[4][4]);
int shuffleArray(int *array, int size);
int inversion_Parity(int *vetor, int tamanho);
int validaJogo(int mat[4][4], int *array);
void ImprimeJogo(int mat[4][4]);

Ponto ReturnPos(int mat[4][4]);

void MoveUp(int mat[4][4]);
void MoveDown(int mat[4][4]);
void MoveLeft(int mat[4][4]);
void MoveRight(int mat[4][4]);
void Move(int mat[4][4]);


#endif // MYFUNCTIONS_H_INCLUDED
