#pragma once
#include "Movimentos.h"

typedef struct ListaDuplaInt
{
	Ponto coordenada;
    struct ListaDuplaInt *proximo;
    struct ListaDuplaInt *anterior;

} ListaDuplaInt;

/*funcoes basicas*/
int inverte(ListaDuplaInt **lista);
int insert(ListaDuplaInt **lista, Ponto coordenada);
Ponto get(ListaDuplaInt *lista, int posicao);
int tamanho(ListaDuplaInt *lista);
int removePos(ListaDuplaInt **lista, int posicao);

/*funcoes avancadas*/
int indexOf(ListaDuplaInt *lista, Ponto coordenada);
int removeCoord(ListaDuplaInt **lista, Ponto coordenada);
int addPos(ListaDuplaInt **lista, Ponto coordenada, int posicao);