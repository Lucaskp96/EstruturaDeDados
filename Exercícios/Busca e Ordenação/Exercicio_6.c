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
    vetor = (int*) calloc(tam,sizeof(int));
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &numero);
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
    int i = 0;
    vetor = (int*) realloc(vetor, (tam+1)*sizeof(int));
    if(num > vetor[tam-1]){
        vetor[tam] = num;
    }else{
        if(num <= vetor[0]){
                for(int a = 0; a < tam; a++)
                    vetor[tam-a] = vetor[tam-a-1];
                vetor[0] = num;
        }else{
            while(i < tam){
                if(num < vetor[i]){
                    for(int a = 0; a <= i; a++){
                        vetor[tam-a] = vetor[tam-a-1];
                    }
                    vetor[i] = num;
                    break;
                }
                i++;
            }
        }
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
