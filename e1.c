#include <stdio.h>
#include <stdlib.h>

int* preencher_vetor(int* vetor);

int main(){
  int* tamanho_vetor;
  int* vetor;

  tamanho_vetor = (int*)malloc(sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%d", tamanho_vetor);
  vetor = (int*)malloc(*tamanho_vetor*sizeof(int));
  vetor = preencher_vetor(vetor);
  printf("\n");
  do{
    printf("%d ", *vetor);
    vetor++;
    *tamanho_vetor--;
  }while(*tamanho_vetor > 0);
  printf("\n");
  free(tamanho_vetor);
  free(vetor);
  return 0;
}


int* preencher_vetor(int* vetor){
  int* inicio_vetor;
  inicio_vetor = vetor;
  printf("Digite os elementos para o vetor:\n");
  do{
    scanf("%d", vetor);
    vetor++;
  }while(*vetor!='\0');
  return inicio_vetor;
}
