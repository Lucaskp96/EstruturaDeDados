#include <stdio.h>
#include <stdlib.h>
#define nL 4
#define nC 4

int** aloca_matriz(int l, int c){
  int* L;
  int** C;

  C = (int**) malloc(c*sizeof(int*));
  for(int i = 0; i < c; i++){
    C[i] = (int*) malloc(l*sizeof(int));
  }
  return C;
}

void libera_mem(int** matriz){
  free(matriz);
}


int main(){
  int** matriz;

  matriz = aloca_matriz(nL,nC);
  printf("Digite os elementos para a matriz %dx%d:\n", nL, nC);
  for(int i=0; i < nC; i++){
    for(int a=0; a < nL; a++){
      scanf("%d", &matriz[a][i]);
    }
    printf("\n");
  }
  for(int i=0; i < nC; i++){
    for(int a=0; a < nL; a++){
      printf("%d ", matriz[a][i]);
    }
    printf("\n");
  }
  libera_mem(matriz);
  matriz=NULL;

  return 0;
}

/* Contrua um programa que:
1- aloque dinamicamente uma matriz de ordem L x C, usando 1+L chamadas a função malloc.
2- contrua uma função que receba os valores L e C, aloque uma matriz L x C e retorne um ponteiro pra mesma.
3- contrua uma função para liberar a memória alocada pela matriz.
4- crie um novo programa (main) que teste/use as duas funções criadas. */

/* Em um ponteiro para ponteiro, cada nível de ponteiro permite criar uma nova dimensão no Array.
int*   >>> permite criar um array de int.
int**  >>> permite criar um array de int*. */
