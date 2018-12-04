#pragma once
/*Lista de Int utilizada para as pecas que serao travadas por ja estarem no lugar destinado e para a lista de movimentos otimizados*/
typedef struct ListaInt
{
	int valor;
	struct ListaInt *proximo;

} ListaInt;

int insertListaInt(ListaInt **lista, int valor);
int removePosListaInt(ListaInt **lista, int posicao);
int indiceValor(ListaInt *lista, int valor);
int removeValor(ListaInt **lista, int valor);
int isContido(int valor, ListaInt *lista);
int tamanhoListaInt(ListaInt *lista);
void printListaInt(ListaInt *lista);