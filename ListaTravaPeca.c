#include "ListaTravaPeca.h"
#include <stdlib.h>

int insert_ListaTravaPeca(ListaTravaPeca **lista, int peca)
{
	ListaTravaPeca *novo = malloc(sizeof(ListaTravaPeca));
	novo->proximo = NULL;
	novo->peca = peca;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaTravaPeca *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;

	iterador->proximo = novo;

	return 0;
}

/*retorna 1 se a matriz eh contida na lista ou 0 se nao*/
int isPecaContidaNaLista(int peca, ListaTravaPeca *lista)
{
	if (lista == NULL)
		return 0;

	int igual = 0;
	while (lista != NULL && igual == 0)
	{
		igual = 1;
		if (peca != lista->peca)
			igual = 0;

		lista = lista->proximo;
	}
	return igual;
}

int isMoveuPecaTravada(int mat[4][4], ListaTravaPeca *lista)
{
	while (lista != NULL)
	{
		if (distanciaDaPeca(mat, lista->peca) != 0)
			return 1;
		lista = lista->proximo;
	}
	return 0;
}