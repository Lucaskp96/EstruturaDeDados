#include <stdio.h>
#include <stdlib.h>

// Variavel global para o tamanho do vetor
int n = 10;

// Função que verifica se o vetor está ordenado
void Is_ordered(int* vetor){
    int* leitor;
    leitor = vetor;
    int flag = 0;
    // Verifica se o elemento atual é menor que todos os posteriores
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(*(leitor+i) > *(leitor+j)){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        printf("DESORDENADO\n");
    }else{
        printf("ORDENADO\n");
    }
}


int main(){
    int* vetor;
    int* escritor;
    vetor = (int*)malloc(n*sizeof(int));
    escritor = vetor;
    printf("Digite os %d elementos do vetor: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", escritor);
        escritor++;
    }
 
    Is_ordered(vetor);

    free(vetor);

    return 0;
}
