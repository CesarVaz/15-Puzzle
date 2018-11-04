#pragma once

typedef struct ListaTravaPeca
{
	int peca;
	struct ListaTravaPeca *proximo;

} ListaTravaPeca;

int insert_ListaTravaPeca(ListaTravaPeca **lista, int peca);
int isPecaContidaNaLista(int peca, ListaTravaPeca *lista);
int isMoveuPecaTravada(int mat[4][4], ListaTravaPeca *lista);