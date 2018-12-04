#pragma once

typedef struct Coordenadas
{
	int x, y;
}Ponto;

/*-Retorna a coordenada da peca passada por parametro, eh utilizada para realizar os movimentos e tambem para validar o jogo*/
Ponto ReturnPos(int mat[4][4], int valor);

/*-Movem a peca vazia ('0') em diferentes direcoes.*/
int MoveUp(int mat[4][4]);
int MoveDown(int mat[4][4]);
int MoveLeft(int mat[4][4]);
int MoveRight(int mat[4][4]);