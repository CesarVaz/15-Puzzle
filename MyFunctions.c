#include "MyFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


int** alocarMatriz(int Linhas,int Colunas){
  int i,j,k;
  k=1;

  int **m = (int**)malloc(Linhas * sizeof(int*));

  for (i = 0; i < Linhas; i++){
       m[i] = (int*) malloc(Colunas * sizeof(int));
       for (j = 0; j < Colunas; j++){
            m[i][j] = k;
            k++;
            if(i== 3 && j==3)
            {
                m[i][j] = 0;
            }
       }
  }
  return m;
}

void ImprimeJogo(int **mat)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        printf("\n");
        for(j=0;j<4;j++)
        {
            printf("%d ",mat[i][j]);
        }
    }
}

Ponto ReturnPos(int **mat)
{
    int i,j;
    Ponto Coord;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
            {
                Coord.x = i;
                Coord.y = j;
            }


        }
    }
    return Coord;
}

void MoveUp(int **mat)
{
    Ponto Coord_xy;
    Coord_xy = ReturnPos(mat);
    system("cls");
    if(Coord_xy.x > 0)
    {
        mat[Coord_xy.x][Coord_xy.y] = mat[Coord_xy.x-1][Coord_xy.y];
        mat[Coord_xy.x-1][Coord_xy.y] = 0;
    }


}

void MoveDown(int **mat)
{
    Ponto Coord_xy;
    Coord_xy = ReturnPos(mat);
    system("cls");
    if(Coord_xy.x < 3)
    {
        mat[Coord_xy.x][Coord_xy.y] = mat[Coord_xy.x+1][Coord_xy.y];
        mat[Coord_xy.x+1][Coord_xy.y] = 0;
    }
}

void MoveLeft(int **mat)
{
    Ponto Coord_xy;
    Coord_xy = ReturnPos(mat);
    system("cls");
    if(Coord_xy.y > 0)
    {
        mat[Coord_xy.x][Coord_xy.y] = mat[Coord_xy.x][Coord_xy.y-1];
        mat[Coord_xy.x][Coord_xy.y-1] = 0;
    }
}

void MoveRight(int **mat)
{
    Ponto Coord_xy;
    Coord_xy = ReturnPos(mat);
    system("cls");
    if(Coord_xy.y < 3)
    {
        mat[Coord_xy.x][Coord_xy.y] = mat[Coord_xy.x][Coord_xy.y+1];
        mat[Coord_xy.x][Coord_xy.y+1] = 0;
    }
}

void Move(int **mat)
{

    char IsPressed;
    int sair = 1;

    do
    {
            IsPressed = getch();
            switch (IsPressed)
        {
        case 'w':
            MoveUp(mat);
            ImprimeJogo(mat);
            break;
        case 's':
            MoveDown(mat);
            ImprimeJogo(mat);
            break;
        case 'd':
            MoveRight(mat);
            ImprimeJogo(mat);
            break;
        case 'a':
            MoveLeft(mat);
            ImprimeJogo(mat);
            break;
        case 'q':
            sair = 0;
            break;

        }
    }while(sair);



}
