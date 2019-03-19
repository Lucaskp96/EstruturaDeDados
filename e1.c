#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int* vetor, int x);

int main(){
  int* tamanho_vetor;
  int* vetor;
	int* auxiliar;

  tamanho_vetor = (int*)malloc(sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%d", tamanho_vetor);
  vetor = (int*)malloc((*tamanho_vetor)*sizeof(int));
	auxiliar = vetor;

  preencher_vetor(vetor,(*tamanho_vetor));

  printf("\n");
  do{
    printf("%d ", *vetor);
    vetor++;
    (*tamanho_vetor)--;
  }while((*tamanho_vetor) > 0);
  printf("\n");

  free(tamanho_vetor);
	tamanho_vetor = NULL;
  free(auxiliar);
	auxiliar = NULL;

  return 0;
}


void preencher_vetor(int* vetor, int tamanho){
  int* inicio_vetor;
  inicio_vetor = vetor;
  printf("Digite os elementos para o vetor:\n");
  do{
    scanf("%d", vetor);
    vetor++;
	tamanho--;
  }while(tamanho > 0);
}

/* Fazer um programa que leia um valor N e crie dinamicamente um vetor de N elementos.
Passe esse vetor para uma função que vai ler os elementos para o vetor.
No programa principal, imprima o vetor. Além disso, antes de finalizar o programa,
deve-se liberar a área de memória alocada. */
