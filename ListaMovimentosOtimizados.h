#pragma once

typedef struct ListaMovimentosOtimizados
{
	int direcao;
	struct ListaMovimentosOtimizados *proximo;

} ListaMovimentosOtimizados;

int insert_ListaMovimentosOtimizados(ListaMovimentosOtimizados **lista, int direcao);
int removePosDirecao(ListaMovimentosOtimizados **lista, int pos);
int indiceDaDirecao(ListaMovimentosOtimizados *lista, int direcao);
int removeDirecao(ListaMovimentosOtimizados **lista, int direcao);
int tamanhoListaDirecao(ListaMovimentosOtimizados *lista);