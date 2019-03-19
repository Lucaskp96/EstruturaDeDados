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
printf("auxiliar:%p\n", auxiliar);
  preencher_vetor(vetor,(*tamanho_vetor));
  printf("\n");
  do{
    printf("%d ", *vetor);
    vetor++;
    (*tamanho_vetor)--;
  }while((*tamanho_vetor) > 0);
  printf("\n");
	printf("tm:%p\n", tamanho_vetor);
  free(tamanho_vetor);
	printf("tm1:%p\n", tamanho_vetor);
	tamanho_vetor = NULL;
	printf("tm2:%p\n", tamanho_vetor);
	printf("auxiliar:%p\n", auxiliar);
  free(auxiliar);
	printf("auxiliar1:%p\n", auxiliar);
	auxiliar = NULL;
	printf("auxiliar2:%p\n", auxiliar);
	printf("vetor:%p\n", vetor);

  return 0;
}


void preencher_vetor(int* vetor, int tamanho){
  int* inicio_vetor;
  inicio_vetor = (int*)vetor;
  printf("Digite os elementos para o vetor:\n");
  do{
    scanf("%d", vetor);
    vetor++;
	tamanho--;
  }while(tamanho > 0);
  //return (int*)inicio_vetor;
}
