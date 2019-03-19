#include <stdio.h>
#include <stdlib.h>
int* cria_vetor(int N);
void imprime_vetor(int* vetor, int tamanho);
void libera_mem(int* vetor);

int main(){
  int* vetor;
  int N;

  printf("Digite o tamanho para o vetor: ");
  scanf("%d", &N);
// chamada da função que inicia o vetor.
  vetor = cria_vetor(N);
// fragmento de leitura dos elementos para o vetor.
  printf("Insira os %d elementos:\n", N);
  for(int i = 0; i < N; i++){
    scanf("%d", &vetor[i]);
  }
// chamada da função que imprime os elementos.
  imprime_vetor(vetor, N);
// chamada da função que libera a memória alocada.
  libera_mem(vetor);
  printf("\n");
  return 0;
}

int* cria_vetor(int N){
  int* vetor;
  vetor = (int*) malloc(N*sizeof(int));
  // vetor de tamanho N alocado.
  return vetor;
}

void imprime_vetor(int* vetor, int tamanho){
  int* auxiliar = vetor;
  printf("\nVetor[%d]: ", tamanho);
  for(int i = 0; i < tamanho; i++){
    printf("%d ", *auxiliar);
    auxiliar++;
  }
}

void libera_mem(int* vetor){
  free(vetor);
}

/* Faça uma função que:
1- receba um valor N.
2- crie dinamicamente um vetor de N elementos.
3- retorne um ponteiro.
Faça uma função que:
1- receba um ponteiro para um vetor.
2- receba um valor N.
3- imprima os N elementos desse vetor.
Faça uma função que:
1- receba um ponteiro para um vetor.
2- libere a área de memória.
Por fim:
1- ler o tamanho N para o vetor.
2- ler os elementos para o vetor na função principal.
3- chamar função que imprime elementos.
4- chamar função que libera memória alocada.
*/
