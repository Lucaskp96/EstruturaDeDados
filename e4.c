#include <stdio.h>
#include <stdlib.h>
#define L 4
#define C 5

int* cria_matriz(int linha, int coluna){
    int* colunas;
    int* linhas;
    colunas = (int*) malloc(coluna*sizeof(int));
    linhas = (int*) malloc(linha*coluna*sizeof(int));



}

int main(){

  return 0;
}

/* Construa um programa que:
1- aloque em tempo de execução uma matriz de ordem L x C, usando duas chamadas de malloc.
2- crie uma função que recebe os parâmetros L e C, aloque uma matriz LxC e retorne um ponteiro para ela.
3- crie uma função para liberar a àrea de memória alocada pela matriz.
4- implemente testes, no programa principal, para as funções criadas.
*/
