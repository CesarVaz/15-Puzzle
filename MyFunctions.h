#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED


typedef struct Coordenadas
{
    int x,y;
}Ponto;


int** alocarMatriz(int Linhas,int Colunas);

void ImprimeJogo(int **mat);

Ponto ReturnPos(int **mat);

void MoveUp(int **mat);

void MoveDown(int **mat);

void MoveLeft(int **mat);

void MoveRight(int **mat);

void Move(int **mat);




#endif // MYFUNCTIONS_H_INCLUDED
