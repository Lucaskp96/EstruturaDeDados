#include <stdio.h>
#include <stdlib.h>

int main(){
    int* vetor, *aux;
    int flag=0, i=0, tam;

    printf("Tamanho do vetor a ser inserido: ");
    scanf("%d\n", &tam);

    vetor = malloc(tam*sizeof(int));
    aux=vetor;

    for(int a = 0; a < tam; a++){
        scanf("%d", aux);
        aux++;
    }

    while(i<tam){
        if(*vetor > *(vetor+1)){
            flag=1;
            break;
        }
        i++;
        vetor++;
    }
    if(flag==1)
        printf("DESORDENADO!\n");
    else
        printf("ORDENADO!\n");

    return 0;
}
