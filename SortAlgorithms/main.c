#include <stdio.h>
#include <stdlib.h>
#include "sorting.c"

int main()
{
    int n = 6;
    int vetor[n];

    printf("Digite os %d elementos do vetor: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("vetor[%d]: {", n);
    for(int i = 0; i < n; i++){
        printf("%d, ", vetor[i]);
    }
    printf("\b\b}\n");

    //bubbleSort(vetor, &n);
    //selectionSort(vetor, &n);
    insertionSort(vetor, &n);

    printf("vetor[%d]: {", n);
    for(int i = 0; i < n; i++){
        printf("%d, ", vetor[i]);
    }
    printf("\b\b}\n");

    return 0;
}
