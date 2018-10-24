#include "ListaDuplaPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverte(ListaDuplaInt **lista)
{
	if (*lista == NULL || (*lista)->proximo == NULL)
		return 0;

	while ((*lista)->proximo != NULL)
	{
		*lista = (*lista)->proximo;
		if ((*lista)->anterior->anterior == NULL)
			(*lista)->anterior->proximo = NULL;
		else
			(*lista)->anterior->proximo = (*lista)->anterior->anterior;
		(*lista)->anterior->anterior = *lista;
	}
	(*lista)->proximo = (*lista)->anterior;
	(*lista)->anterior = NULL;
	
	return 0;
}


/**
 * Insere um valor na lista
 * @param lista Lista
 * @param valor Valor a ser inserido
 * @return Sucesso da operação
 */
int insert(ListaDuplaInt **lista, Ponto coordenada)
{
	ListaDuplaInt *novo = malloc(sizeof(ListaDuplaInt));
	novo->proximo = NULL;
	novo->anterior = NULL;
	novo->coordenada = coordenada;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	ListaDuplaInt *iterador = *lista;
	while (iterador->proximo != NULL)
		iterador = iterador->proximo;
	
	novo->anterior = iterador;
	iterador->proximo = novo;

    return 0;
}

/**
 * Retorna o valor contido na lista na posição pedida
 * @param lista Lista
 * @param posicao Posição do elemento desejado
 * @return Valor contido na posição
 */
Ponto get(ListaDuplaInt *lista, int posicao) 
{
	int cont = 0;
	while (cont != posicao)
	{
		lista = lista->proximo;
		cont++;
	}

	return lista->coordenada;
}

/**
 * Conta o número de elementos na lista e retorna este valor
 * @param lista Lista
 * @return Número de elementos na lista
 */
int tamanho(ListaDuplaInt *lista)
{
	if (lista == NULL)
		return 0;

	int tam = 1;

	while (lista->proximo != NULL)
	{
		lista = lista->proximo;
		tam++;
	}

    return tam;
}

/**
 * Remove o elemento contido na lista na posição pedida
 * @param lista Lista
 * @param posicao Posição do elemento a ser excluído
 * @return Sucesso da operação
 */
int removePos(ListaDuplaInt **lista, int posicao)
{
	if (posicao >= tamanho(*lista) || posicao < 0)
		return -1;

	ListaDuplaInt *excluir = malloc(sizeof(ListaDuplaInt));
	if (posicao == 0)
	{
		excluir = *lista;
		*lista = (*lista)->proximo;
		(*lista)->anterior = NULL;
		free(excluir);
		return 0;
	}
	ListaDuplaInt *iterador = *lista;
	int cont = 0;
	while(cont < posicao)
	{
		iterador = iterador->proximo;
		cont++;
	}

	if (posicao == tamanho(*lista) - 1)
	{
		excluir = iterador;
		(iterador->anterior)->proximo = NULL;
		free(excluir);
		return 0;
	}
	else
	{ 
		excluir = iterador;
		(iterador->proximo)->anterior = iterador->anterior;
		(iterador->anterior)->proximo = iterador->proximo;
		free(excluir);
		return 0;
	}
}

/**
 * Retorna a posição da primeira ocorrência na lista de um valor
 * @param lista Lista
 * @param valor Valor a ser buscado na lista
 * @return Posição do valor. Caso não haja ocorrências, retorna -1
 */
int indexOf(ListaDuplaInt *lista, Ponto coordenada)
{
	if (lista == NULL)
		return -1;

	int pos = -1, cont = 0;
	while (lista != NULL && pos == -1)
	{
		if (lista->coordenada.x == coordenada.x && lista->coordenada.y == coordenada.y)
			pos = cont;

		lista = lista->proximo;
		cont++;
	}

    return pos;
}

/**
 * Remove o  primeiro elemento contido na lista cujo valor
 * é o valor pedido
 * @param lista Lista
 * @param posicao Valor a ser excluído
 * @return Sucesso da operação
 */
int removeCoord(ListaDuplaInt **lista, Ponto coordenada)
{
	return removePos(lista, indexOf(*lista, coordenada));
}

/**
 * Adiciona um valor na lista em uma posição específica
 * @param lista Lista
 * @param valor Valor a ser inserido
 * @param posicao Posição a ser inserida
 * @return Sucesso da operação
 */
int addPos(ListaDuplaInt **lista, Ponto coordenada, int posicao)
{
	ListaDuplaInt *novo = malloc(sizeof(ListaDuplaInt));
	novo->coordenada = coordenada;
	novo->anterior = NULL;
	novo->proximo = NULL;

	if (*lista == NULL)
	{
		*lista = novo;
		return 0;
	}

	if (posicao == 0)
	{
		(*lista)->anterior = novo;
		novo->proximo = *lista;
		*lista = novo;
		return 0;
	}

	ListaDuplaInt *iterador = *lista;
	int cont = 0;
	while (cont < posicao && iterador->proximo != NULL)
	{
		iterador = iterador->proximo;
		cont++;
	}
	
	if (posicao >= tamanho(*lista))
	{
		iterador->proximo = novo;
		novo->anterior = iterador;
		return 0;
	}
	else
	{
		novo->anterior = iterador->anterior;
		novo->proximo = iterador;
		iterador->anterior->proximo = novo;
		iterador->anterior = novo;

		return 0;
	}

}
