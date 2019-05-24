#include <stdio.h>
#include <stdlib.h>

/* Criar uma função que preencha um vetor alocado dinamicamente. */

void preencher_vetor(int* vetor, int x);

int main(){
  int* tamanho_vetor;
  int* vetor;
  int* auxiliar;
// alocação do vetor e da variável tamanho do vetor.
  tamanho_vetor = (int*)malloc(sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%d", tamanho_vetor);
  vetor = (int*)malloc((*tamanho_vetor)*sizeof(int));
	auxiliar = vetor; // guarda o endereço do vetor.
// lê dados para o vetor:
  preencher_vetor(vetor,(*tamanho_vetor));
// imprime vetor:
  printf("\nVetor: ");
  do{
    printf("%d ", *vetor);
    vetor++;
    (*tamanho_vetor)--;
  }while((*tamanho_vetor) > 0);
  printf("\n");
// libera a memória alocada durante o programa:
  free(tamanho_vetor);
	tamanho_vetor = NULL;
  free(auxiliar);
	auxiliar = NULL;

  return 0;
}

// função que pedirá os dados ao usuário para o vetor:
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
