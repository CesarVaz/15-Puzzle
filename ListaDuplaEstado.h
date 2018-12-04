#pragma once
/*Lista de estados (estados sao configuracoes da matriz que representa o tabuleiro)*/
typedef struct ListaDuplaEstado
{
	int estado[4][4];
    struct ListaDuplaEstado *proximo;
    struct ListaDuplaEstado *anterior;

} ListaDuplaEstado;

/*funcoes basicas*/
int inverte(ListaDuplaEstado **lista);
int insert(ListaDuplaEstado **lista, int mat[4][4]);
int tamanho(ListaDuplaEstado *lista);
int removePos(ListaDuplaEstado **lista, int posicao);

/*funcoes avancadas*/
int indiceDoEstado(ListaDuplaEstado *lista, int mat[4][4]);
int removeEstado(ListaDuplaEstado **lista, int mat[4][4]);
int addPos(ListaDuplaEstado **lista, int mat[4][4], int posicao);

int isMatrizContida(int mat[4][4], ListaDuplaEstado *lista);

int getEstadoFromPos(int mat[4][4], ListaDuplaEstado *lista, int posicao);
void limpaLista(ListaDuplaEstado **lista);