#pragma once

typedef struct ListaTravaPeca
{
	int peca;
	struct ListaTravaPeca *proximo;

} ListaTravaPeca;

int insert_ListaTravaPeca(ListaTravaPeca **lista, int peca);
int removePosListaTravaPeca(ListaTravaPeca **lista, int pos);
int indicePecaTravada(ListaTravaPeca *lista, int peca);
int removePecaTravada(ListaTravaPeca **lista, int peca);
int isPecaContidaNaLista(int peca, ListaTravaPeca *lista);
int isMoveuPecaTravada(int mat[4][4], ListaTravaPeca *lista);
int tamanhoListaTravaPeca(ListaTravaPeca *lista);
void printListaTravaPeca(ListaTravaPeca *lista);