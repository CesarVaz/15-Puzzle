#pragma once

#include "ListaDuplaEstado.h"
#include "ListaInt.h"
/*-Estrutura contendo o valor heuristico (manhattan e numero de inversoes) e a direcao do movimento*/
typedef struct movimento
{
	int heuristica;
	int dir;
} movimento;

/*-Funcao que procura o caminho para a solucao*/
int encontraCaminho(int matriz[4][4], ListaDuplaEstado **listaEstado, ListaDuplaEstado **listaEstadosDefinitivos, ListaInt **listaPecasTravadas);
/*-Funcao que avalia os valores heuristicos dos proximos passos*/
void avaliaProximosPassos(int matriz[4][4], movimento opcoes[], ListaDuplaEstado *listaEstado, ListaInt *listaPecasTravadas);
/*-Retorna o valor de manhattan do estado passado por parametro*/
int ManhattanDistance(int matriz[4][4]);

/*move a peca pra direcao contraria a a do parametro*/
void desfazMovimento(int matriz[4][4], int direcao);
/*retorna a distancia da peca passada como parametro*/
int distanciaDaPeca(int matriz[4][4], int peca);
/*organiza o vetor de movimentos possiveis em ordem crescente do menor ao maior valor heuristico. Utiliza o metodo Selection Sort*/
void selectSortHeuristica(movimento vetor[], int size);
/*troca valores do tipo struct movimento*/
void swap(movimento *a, movimento *b);
/*trava pecas que ja estao no local destinado a elas*/
void travaPecas(int matriz[4][4], ListaInt **listaPecasTravadas);
/*verifica se a peca movida esta na lista de pecas travadas*/
int isMoveuPecaTravada(int mat[4][4], ListaInt *lista);

/*prepara para a otimizacao dos movimentos e chama a funcao que executa a otimizacao*/
int setDoOtimizarMovimentos(ListaDuplaEstado *listaEstado, ListaInt **listaMovimentosOtimizados);
/*-Otimiza os movimentos procurando atalhos entre as primeiras e as ultimas posicoes da lista*/
int otimizarMovimentos(int estadoInicial[4][4], ListaDuplaEstado *listaEstado, ListaInt **listaMovimentosOtimizados, int indice);

/*demonstra a solucao do Puzzle executando a lista de movimentos na matriz inicial*/
int resolver(int matriz[4][4], ListaInt **listaMovimentosOtimizados);