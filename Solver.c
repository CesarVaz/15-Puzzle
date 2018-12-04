#include <stdlib.h>
#include "Solver.h"
#include "Jogo.h"
#include "Movimentos.h"

int encontraCaminho(int matriz[4][4], ListaDuplaEstado **listaEstado, ListaDuplaEstado **listaEstadosDefinitivos, ListaInt **listaPecasTravadas)
{
	if (isMatrizContida(matriz, *listaEstado) == 0)
	{
		insert(listaEstado, matriz);
		insert(listaEstadosDefinitivos, matriz);
	}
		
	if (ManhattanDistance(matriz) == 0)
		return 1;

	travaPecas(matriz, listaPecasTravadas);
	int i = 0;
	movimento opcoes[4];
	for (i = 0; i < 4; i++)
		opcoes[i].dir = i;

	avaliaProximosPassos(matriz, opcoes, *listaEstado, *listaPecasTravadas);
	selectSortHeuristica(opcoes, 4);
	for (i = 0; i < 4; i++)
	{
		if(opcoes[i].heuristica != -1)
		{

			Move(matriz, opcoes[i].dir);
			if(encontraCaminho(matriz, listaEstado, listaEstadosDefinitivos, listaPecasTravadas) == 1)
				return 1;

			removeEstado(listaEstadosDefinitivos, matriz);
			desfazMovimento(matriz, opcoes[i].dir);
		}
	}
	return 0;
}

void avaliaProximosPassos(int mat[4][4], movimento opcoes[], ListaDuplaEstado *listaEstado, ListaInt *listaTravaPeca)
{
	for (int i = 0; i < 4; i++)
	{
		if (Move(mat, i) == 1)
		{
			if (isMatrizContida(mat, listaEstado) == 0 && isMoveuPecaTravada(mat, listaTravaPeca) == 0)
			{
				opcoes[i].heuristica = (ManhattanDistance(mat) * 1);
				opcoes[i].heuristica += (inversion_Parity2D(mat) * 1);
			}
			else
				opcoes[i].heuristica = -1;

			desfazMovimento(mat, opcoes[i].dir);
		}
		else
			opcoes[i].heuristica = -1;
	}
	return;
}

int ManhattanDistance(int mat[4][4])
{
	int somaDist = 0;
	int valor = 1;

	while(valor < 16)
		somaDist += distanciaDaPeca(mat, valor++);

	return somaDist;
}

void desfazMovimento(int mat[4][4], int direcao)
{
	if (direcao % 2 == 0)
		Move(mat, direcao + 1);
	else
		Move(mat, direcao - 1);

	return;
}

int distanciaDaPeca(int mat[4][4], int valor)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (mat[i][j] == valor)
				return abs(i - ((valor - 1) / 4)) + abs(j - ((valor - 1) % 4));
	return -1;
}

void selectSortHeuristica(movimento vetor[], int size)
{
	if (size <= 1)
		return;

	int posMenor = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[posMenor].heuristica > vetor[i].heuristica)
			posMenor = i;
	}
	swap(&(vetor[posMenor]), &(vetor[0]));
	selectSortHeuristica(&(vetor[1]), size - 1);

	return;
}

void swap(movimento *a, movimento *b)
{
	movimento aux = *a;
	*a = *b;
	*b = aux;

	return;
}

void travaPecas(int mat[4][4], ListaInt **listaPecasTravadas)
{
	int i = 1;
	while (distanciaDaPeca(mat, i) == 0 && i < 16)
	{
		if (i < 9 && isContido(i, *listaPecasTravadas) == 0)
		{
			if (i == 3 || i == 7)
			{
				if (distanciaDaPeca(mat, i + 1) == 0)
				{
					insertListaInt(listaPecasTravadas, i);
					insertListaInt(listaPecasTravadas, i + 1);
				}
			}
			else
			insertListaInt(listaPecasTravadas, i);
		}
		i++;
	}
	return;
}

int isMoveuPecaTravada(int mat[4][4], ListaInt *lista)
{
	while (lista != NULL)
	{
		if (distanciaDaPeca(mat, lista->valor) != 0)
			return 1;
		lista = lista->proximo;
	}
	return 0;
}

int setDoOtimizarMovimentos(ListaDuplaEstado *listaEstado, ListaInt **listaMovimentosOtimizados)
{
	int estadoInicial[4][4];
	getEstadoFromPos(estadoInicial, listaEstado, 0);

	return otimizarMovimentos(estadoInicial, listaEstado, listaMovimentosOtimizados, 0);
}

int otimizarMovimentos(int estadoAtual[4][4], ListaDuplaEstado *listaEstado, ListaInt **listaMovimentosOtimizados, int indice)
{
	int direcao = -1;
	for (int i = 0; i < 4; i++)
	{
		if (Move(estadoAtual, i) == 1)
		{
			if(indice < indiceDoEstado(listaEstado, estadoAtual))
			{ 
				indice = indiceDoEstado(listaEstado, estadoAtual);
				direcao = i;
			}
			desfazMovimento(estadoAtual, i);
		}
	}
	if (direcao != -1)
	{
		insertListaInt(listaMovimentosOtimizados, direcao);
		getEstadoFromPos(estadoAtual, listaEstado, indice);
		if (indice == tamanho(listaEstado) - 1)
			return 1;
	}
	else
		return 0;

	return otimizarMovimentos(estadoAtual, listaEstado, listaMovimentosOtimizados, indice);
}

int resolver(int matriz[4][4], ListaInt **listaMovimentosOtimizados)
{
	int tamanho = tamanhoListaInt(*listaMovimentosOtimizados);

system("cls");
ImprimeJogo(matriz);

	while (tamanho > 0)
	{
		Move(matriz, (*listaMovimentosOtimizados)->valor);

system("cls");
ImprimeJogo(matriz);

		removePosListaInt(listaMovimentosOtimizados, 0);
		tamanho--;
	}
	return 0;
}