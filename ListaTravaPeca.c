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

int removePosListaTravaPeca(ListaTravaPeca **lista, int pos)
{
	if (*lista == NULL || pos > tamanhoListaTravaPeca(*lista) || pos < 0)
		return -1;
	
	ListaTravaPeca *excluir = malloc(sizeof(ListaTravaPeca));
	if (pos == 0)
	{
		excluir = *lista;
		*lista = (*lista)->proximo;
		free(excluir);
		return 0;
	}
	ListaTravaPeca *iterador = *lista;
	int cont = 0;
	while (cont < pos)
	{
		iterador = iterador->proximo;
		cont++;
	}
	excluir = iterador;
	iterador = iterador->proximo;
	free(excluir);

	return 0;
}

int indicePecaTravada(ListaTravaPeca *lista, int peca)
{
	int pos = -1;
	while (lista != NULL)
	{
		pos++;
		if (peca = lista->peca)
			return pos;
		lista = lista->proximo;
	}
	return pos;
}

int removePecaTravada(ListaTravaPeca **lista, int peca)
{
	removePosListaTravaPeca(lista, indicePecaTravada(*lista, peca));
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

int tamanhoListaTravaPeca(ListaTravaPeca *lista)
{
	int tamanho = 0;
	while (lista != NULL)
	{
		lista = lista->proximo;
		tamanho++;
	}
	return tamanho;
}

void printListaTravaPeca(ListaTravaPeca *lista)
{
	printf("\n");
	while (lista != NULL)
	{
		printf("%d", lista->peca);
		if(lista->proximo != NULL)
			printf("<->");
		lista = lista->proximo;
	}
	printf("\n");
	return;
}