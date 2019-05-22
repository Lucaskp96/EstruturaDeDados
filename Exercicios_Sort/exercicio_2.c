#include <stdio.h>
#include <stdlib.h>

int tam = 5;

void ordena_decrescente(int* vetor, int* n){
    int *i, *j, *temp;

    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));
    temp = (int*)malloc(sizeof(int));

    for(*i = 1; *i < *n; (*i)++){
        *temp = vetor[*i];
        for(*j = *i; (*j > 0) && (*temp > vetor[(*j)-1]); (*j)--){
            vetor[*j] = vetor[(*j)-1];
        }
        vetor[*j] = *temp;
    }

    free(i); free(j); free(temp);
    i = NULL; j = NULL; temp = NULL;
}

int main(){
int *vetor = (int*)malloc(tam*sizeof(int));
    int *aux;
    aux = vetor;

    printf("Digite os %d elementos do vetor: \n", tam);

    for(int i = 0; i < tam; i++){
        scanf("%d", vetor);
        vetor++;
    }
    vetor = aux;

    ordena_decrescente(vetor,&tam);
    printf("\n");
    for(int i = 0; i < tam; i++){
        printf("%d ", *aux);
        aux++;
    }

    free(vetor);

    return 0;
}

