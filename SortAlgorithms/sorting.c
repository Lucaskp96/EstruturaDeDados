#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


// Algoritmo de ordenação BubbleSort utilizando ponteiros e alocação dinâmica.
// ****************************************************************************
void bubbleSort(int *vetor, int* n){
    int *temp, *houveTroca, *i, *tam;

    temp = malloc(sizeof(int));
    houveTroca = malloc(sizeof(int));
    tam = malloc(sizeof(int));

    (*tam) = (*n);
    (*houveTroca) = 1;

    while((*houveTroca) == 1){
        (*houveTroca) = 0;
        for((*i) = 0; (*i) < (*tam) - 1; (*i)++){
            if(vetor[*i] > vetor[*i + 1]){
                (*temp) = vetor[*i];
                vetor[*i] = vetor[(*i) + 1];
                vetor[(*i) + 1] = *temp;
                (*houveTroca) = 1;
            }
        }
        (*tam)--;
    }

    free(temp); free(houveTroca); free(tam);
}


// Algoritmo de ordenação SelectionSort utilizando ponteiros e alocação dinâmica.
// *******************************************************************************
void selectionSort(int *vetor, int* n){

}
