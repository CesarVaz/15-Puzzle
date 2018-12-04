#pragma once

/*-Cria as peças do 15 Puzzle em array unidimensional (para embaralhar depois);
-Embaralha (Inversion_Parity == 0 significa que o jogo esta praticamente solucionado, portanto nao eh permitido);
-Passa o Array 1D para um Array 2D (matriz);
-Valida jogo torna o jogo solucionavel de acordo com regras citadas abaixo, caso este ja nao esteja.*/
int preencheMatriz(int mat[4][4]);

/*-Embaralha array 1D.*/
int shuffleArray(int *array, int size);

/*-Verifica inversoes (a soma de cada peca menor que a atual que esta localizada em posicoes a frente);*/
int inversion_Parity(int *vetor, int tamanho);
int inversion_Parity2D(int mat[4][4]);

/*-Se o jogo nao eh solucionavel esta funcao a torna solucionavel com a seguinte logica: 
Em um Puzzle de dimensao NxN (no caso 4x4), se N for par, ele é solucionável apenas se: 
1. O bloco branco ('0') encontra-se numa linha par, contando de baixo para cima;
2. O numero de inversoes do tabuleiro eh impar
ou
1. O bloco branco ('0') encontra-se numa linha impar, contando de baixo para cima;
2. O numero de inversoes do tabuleiro eh par*/
int validaJogo(int mat[4][4], int *array);

/*-Apenas imprime o jogo na tela*/
void ImprimeJogo(int mat[4][4]);

/*-Executa o movimento passado por parametro*/
int Move(int mat[4][4], int dir);