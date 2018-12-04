#include "ListaInt.h"
#include <stdlib.h>

int insertListaInt(ListaInt **lista, int peca)
{
	ListaInt *novo = malloc(sizeof(ListaInt));
	novo->proximo = NULL;
	novo->valor = peca;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaInt *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;

	iterador->proximo = novo;

	return 0;
}

int removePosListaInt(ListaInt **lista, int pos)
{
	if (*lista == NULL || pos > tamanhoListaInt(*lista) || pos < 0)
		return -1;
	
	ListaInt *excluir = malloc(sizeof(ListaInt));
	if (pos == 0)
	{
		excluir = *lista;
		*lista = (*lista)->proximo;
		free(excluir);
		return 0;
	}
	ListaInt *iterador = *lista;
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

int indiceValor(ListaInt *lista, int peca)
{
	int pos = -1;
	while (lista != NULL)
	{
		pos++;
		if (peca = lista->valor)
			return pos;
		lista = lista->proximo;
	}
	return pos;
}

int removeValor(ListaInt **lista, int peca)
{
	removePosListaInt(lista, indiceValor(*lista, peca));
}

/*retorna 1 se a matriz eh contida na lista ou 0 se nao*/
int isContido(int peca, ListaInt *lista)
{
	if (lista == NULL)
		return 0;

	int igual = 0;
	while (lista != NULL && igual == 0)
	{
		igual = 1;
		if (peca != lista->valor)
			igual = 0;

		lista = lista->proximo;
	}
	return igual;
}

int tamanhoListaInt(ListaInt *lista)
{
	int tamanho = 0;
	while (lista != NULL)
	{
		lista = lista->proximo;
		tamanho++;
	}
	return tamanho;
}

void printListaInt(ListaInt *lista)
{
	printf("\n");
	while (lista != NULL)
	{
		printf("%d", lista->valor);
		if(lista->proximo != NULL)
			printf("<->");
		lista = lista->proximo;
	}
	printf("\n");
	return;
}