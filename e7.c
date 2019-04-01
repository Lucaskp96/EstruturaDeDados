#include <stdio.h>
#include <stdlib.h>

int* valores_entre(int* vetor, int n_elementos, int min, int max, int* qtd ){
  int* vetor_intervalo;
  int* vetor_auxiliar;
  int i=0;

  vetor_intervalo = (int*)malloc(sizeof(int));
  vetor_auxiliar = vetor;

  do{
    if((*vetor_auxiliar > min) && (*vetor_auxiliar <= max)){
      vetor_intervalo[i] = *vetor_auxiliar;
      i++;
      vetor_intervalo = (int*)realloc(vetor_intervalo, i*sizeof(int));
    }
    vetor_auxiliar++;
    n_elementos--;
  }while(n_elementos > 0);

  if(vetor_intervalo==NULL) return NULL;
  *qtd = i;
  return vetor_intervalo;
}

int main(){
  int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int* novo_vetor;
  int qtd;
  int min, max;

  printf("Vetor = {");
  for(int i=0;i<15;i++){
    printf("%d, ", vetor[i]);
  }
  printf("\b\b}\n");
  printf("Digite o valor min: ");
  scanf("%d", &min);
  printf("Digite o valor max: ");
  scanf("%d", &max);
  novo_vetor = valores_entre(vetor,15,min,max,&qtd);
  if(qtd == 0){
    printf("\nNenhum valor nesse intervalo!\n");
  }else{
  printf("Valores entre %d e %d: {", min, max);
    for(int i=0; i<qtd; i++){
      printf("%d, ", novo_vetor[i]);
    }
    printf("\b\b}\n");
  }
  free(novo_vetor);
  return 0;
}
