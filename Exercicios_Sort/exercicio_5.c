#include <stdio.h>
#include <stdlib.h>
#define tam 10

int insertionSort(int* vetor, int n);

int main(){
    int vetor[tam] = {72,12,62,69,27,67,41,56,33,74};

    printf("Quantidade de copias: %d\n", insertionSort(vetor,tam)) ;

    return 0;
}

int insertionSort(int* vetor, int n){
    int i, j, aux, n_copias=0;

    for(i = 1; i < n; i++){
        aux = vetor[i];
        for(j = i; (j > 0) && (aux < vetor[j - 1]); j--){
            vetor[j] = vetor[j - 1];
            n_copias++;
        }
        vetor[j] = aux;
    }
    return n_copias;
}
