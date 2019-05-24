#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int search(int* vetor, int tam, int valor);
void imprime(int* vetor, int tam);
void preenche(int* vetor, int tam);
int isOrdered(int* vetor, int tam);

int main(){
    int* vetor, tam, numero, found;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int*) malloc(tam*sizeof(int));

    for(int i = 0; i < tam; i++){
        vetor[i] = (i+1)*2;
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &numero);

    found = search(vetor,tam,numero);

    if(found == numero){
        printf("Valor encontrado!\n");
    }else{
        printf("Valor não encontrado!\n");
    }

    free(vetor);
    vetor = NULL;

    return 0;
}

int search(int* vetor, int tam, int valor){
    int index;
    if(isOrdered){
        for(index = 0; index < tam; index++){
            if(vetor[index] == valor){
                return vetor[index];
                break;
            }
        }
    }else{
        printf("Falha! Vetor não está ordenado!\n");
        return FALSE;
    }
}

int isOrdered(int* vetor, int tam){
    int i, a, flag;
    for(i = 0; i < tam; i++){
        for(a = i; a < tam; a++){
            if(!(vetor[i] <= vetor[a]))
                flag = 1;
        }
    }
    if(flag==0){
        return TRUE;
    }else{
        return FALSE;
    }
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

