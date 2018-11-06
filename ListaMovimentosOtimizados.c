#include <stdlib.h>
#include "ListaMovimentosOtimizados.h"

int insert_ListaMovimentosOtimizados(ListaMovimentosOtimizados **lista, int direcao)
{
	ListaMovimentosOtimizados *novo = malloc(sizeof(ListaMovimentosOtimizados));
	novo->proximo = NULL;
	novo->direcao = direcao;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaMovimentosOtimizados *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;

	iterador->proximo = novo;

	return 0;
}

int removePosDirecao(ListaMovimentosOtimizados **lista, int pos)
{
	if (*lista == NULL || pos > tamanhoListaDirecao(*lista) || pos < 0)
		return -1;

	ListaMovimentosOtimizados *excluir = malloc(sizeof(ListaMovimentosOtimizados));
	if (pos == 0)
	{
		excluir = *lista;
		*lista = (*lista)->proximo;
		free(excluir);
		return 0;
	}
	ListaMovimentosOtimizados *iterador = *lista;
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

int indiceDaDirecao(ListaMovimentosOtimizados *lista, int direcao)
{
	int pos = -1;
	while (lista != NULL)
	{
		pos++;
		if (direcao = lista->direcao)
			return pos;
		lista = lista->proximo;
	}
	return pos;
}

int removeDirecao(ListaMovimentosOtimizados **lista, int direcao)
{
	removePosDirecao(lista, indiceDaDirecao(*lista, direcao));
}

int tamanhoListaDirecao(ListaMovimentosOtimizados *lista)
{
	int tamanho = 0;
	while (lista != NULL)
	{
		lista = lista->proximo;
		tamanho++;
	}
	return tamanho;
}