#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


// Algoritmo de ordenação BubbleSort utilizando ponteiros e alocação dinâmica.
// ****************************************************************************
void bubbleSort(int* vetor, int* n){
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
    temp = NULL; houveTroca = NULL; tam = NULL;
}


// Algoritmo de ordenação SelectionSort utilizando ponteiros e alocação dinâmica.
// *******************************************************************************
void selectionSort(int* vetor, int* n){
    int* i, *j, *menor, *temp;

    i = malloc(sizeof(int));
    j = malloc(sizeof(int));
    menor = malloc(sizeof(int));
    temp = malloc(sizeof(int));

    for(*i = 0; *i < (*n)-1; (*i)++){
        *menor = *i;
        for(*j = *i + 1; *j < *n; (*j)++){
            if(vetor[*j] < vetor[*menor]){
                *menor = *j;
            }
        }
        if(*i != *menor){
            *temp = vetor[*i];
            vetor[*i] = vetor[*menor];
            vetor[*menor] = *temp;
        }
    }
    free(i); free(j); free(menor); free(temp);
    i = NULL; j = NULL; menor = NULL; temp = NULL;
}


// Algoritmo de ordenação InsertionSort utilizando ponteiros e alocação dinâmica.
// *******************************************************************************
void insertionSort(int* vetor, int* n){
    int *i, *j, *temp;

    i = malloc(sizeof(int));
    j = malloc(sizeof(int));
    temp = malloc(sizeof(int));

    for(*i = 1; *i < *n; (*i)++){
        *temp = vetor[*i];
        for(*j = *i; (*j > 0) && (*temp < vetor[(*j)-1]); (*j)--){
            vetor[*j] = vetor[(*j)-1];
        }
        vetor[*j] = *temp;
    }

    free(i); free(j); free(temp);
    i = NULL; j = NULL; temp = NULL;
}

// Algoritmo de ordenação QuickSort utilizando ponteiros e alocação dinâmica.
// *******************************************************************************
int particiona(int* vetor, int* inicio, int* fim){
    int *esquerda, *direita, *pivo, *aux;
    esquerda = malloc(sizeof(int));
    direita = malloc(sizeof(int));
    pivo = malloc(sizeof(int));
    aux = malloc(sizeof(int));
    *esquerda = *inicio;
    *direita = *fim;
    *pivo = vetor[*inicio];
    while(*esquerda < *direita){
        while(vetor[*esquerda] <= *pivo){
            (*esquerda)++;
        }
        while(vetor[*direita] > *pivo){
            (*direita)--;
        }
        if(*esquerda < *direita){
            *aux = vetor[*esquerda];
            vetor[*esquerda] = vetor[*direita];
            vetor[*direita] = *aux;
        }
    }
    vetor[*inicio] = vetor[*direita];
    vetor[*direita] = *pivo;
    free(esquerda); free(pivo); free(aux);
    esquerda = NULL; pivo = NULL; aux = NULL;
    return *direita;
}
void quickSort(int* vetor, int inicio, int fim){
    int* pivo;
    pivo = malloc(sizeof(int));
    if(fim > inicio){
        *pivo = particiona(vetor, &inicio, &fim);
        quickSort(vetor, inicio, (*pivo)-1);
        quickSort(vetor, (*pivo)+1, fim);
    }
    free(pivo);
    pivo = NULL;
}
