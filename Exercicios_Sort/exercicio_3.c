/* Recebe um vetor ordenado e um número extra. Depois, faz a inserçao deste número
na devida posição dentro do vetor, de forma que permaneça ordenado.*/
#include <stdio.h>
#include <stdlib.h>

void insere(int* vetor, int tam, int num);
void imprime(int* vetor, int tam);
void preenche(int* vetor, int tam);

int main(){
    int* vetor;
    int numero, tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &numero);
    vetor = (int*) calloc(tam,sizeof(int));

    printf("Digite um vetor ordenado de tamanho %d\n", tam);
    preenche(vetor,tam);

    imprime(vetor,tam);

    insere(vetor,tam,numero);

    imprime(vetor,tam+1);
    free(vetor);
    vetor = NULL;

    return 0;
}

void insere(int* vetor, int tam, int num){
    //
}

void imprime(int* vetor, int tam){
    int* reader = vetor;
    for(int i=0; i<tam; i++){
        printf("%d ", *reader);
        reader++;
    }
    printf("\n");
    reader = NULL;
}

void preenche(int* vetor, int tam){
    int* writer = vetor;
    for(int i=0; i < tam; i++){
        scanf("%d", writer);
        writer++;
    }
    writer = NULL;
}
