#include <stdio.h>
#include <stdlib.h>

int* valores_entre(int* vetor, int n_elementos, int min, int max, int* qtd ){
  int* vetor_intervalo;                 // Vetor final com os valor do intervalo.
  int* vetor_auxiliar;                  // Utilizado para armazenar os valores do intervalo temporariamente.
  int* save;
  int* i = malloc(sizeof(int));         // Contador de valores no intervalo.
  *i = 0;

  vetor_intervalo = (int*)malloc(sizeof(int));               // vetor_intervalo inicializado com 1 posição.
  vetor_auxiliar = (int*)malloc(n_elementos*sizeof(int));    // vetor temporario que recebera os valores do intervalo.
    save = vetor_auxiliar;                      // Salva o endereço inicial do vetor auxiliar temporario.
  do{
    if((*vetor > min) && (*vetor <= max)){        // Se  min < vetor[a] <= max, faça:
      *vetor_auxiliar = *vetor;                   // vetor_invervalo[i] recebe vetor[a]
      (*i)++;                                     // Incrementa o contador de valores no intervalo.
      vetor_auxiliar++;                           // Incrementa posição do vetor auxiliar.
    }
    vetor++;                                      // Incrementa posição do vetor parâmentro.
    n_elementos--;                                // Decrementa indicador da quantidade de elementos do vetor.
  }while(n_elementos > 0);
    vetor_auxiliar = save;
  vetor_intervalo = (int*)malloc(*(i)*sizeof(int));     // Aloca vetor_intervalo com i posições do tipo int.

    for(int a = 0; a < (*i); a++){                      // Copia os valores do vetor temporário para o vetor_intervalo.
        vetor_intervalo[a] = vetor_auxiliar[a];
    }

  if((vetor_intervalo==NULL) || (*i)==0) return NULL;   // Se nao for possível alocar o vetor ou se não houver valores no intervalo, retorna NULL.
  *qtd = *i;                                            // Passa a quantidade de elementos do novo vetor para a variavel parâmetro.

  free(i);                                              // Liberação de memória.
  i = NULL;                                             // *                   *
  free(vetor_auxiliar);                                 // *                   *
  vetor_auxiliar = NULL;                                // *********************

  return vetor_intervalo;               // Retorna o endereço do novo vetor.
}

int main(){
  int vetor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};  // Vetor com valores pré-estabelicidos
  int* novo_vetor;                                      // Recebera o endereço do novo vetor.
  int qtd;                                              // Armazena quantidade de valores do vetor.
  int min, max;                                         // Armazena valores mínimo e máximo do intervalo.

  printf("Vetor = {");
  for(int i=0;i<15;i++){
    printf("%d, ", vetor[i]);
  }

  printf("\b\b}\n");
  printf("Digite o valor min: ");
  scanf("%d", &min);
  printf("Digite o valor max: ");
  scanf("%d", &max);

  novo_vetor = valores_entre(vetor,15,min,max,&qtd);    // Chamada a função valores_entre().

  if(qtd == 0){
    printf("\nNenhum valor nesse intervalo!\n");
  }else{
  printf("Valores entre %d e %d: {", min, max);
    for(int i=0; i<qtd; i++){                       // Imprime o novo vetor.
      printf("%d, ", novo_vetor[i]);
    }
    printf("\b\b}\n");
  }
  free(novo_vetor);         //  Libera memória alocada.
  novo_vetor = NULL;        //  Por segurança, faz-se com que o ponteiro aponte para um valor nulo de memória
                            // depois de desalocar seu espaço na memória.

  return 0;
}
