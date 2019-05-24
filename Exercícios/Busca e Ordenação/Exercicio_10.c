#include <stdlib.h>
#include <stdio.h>

void quickSort(int* vector, int left, int right){
    int pivo, aux, i, j;
    i = left; j = right; pivo = vector[(left+right)/2];
    do{
        while(vector[i] < pivo) i++;
        while(pivo < vector[j]) j--;
        if(i <= j){
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++; j--;
        }
    }while(i <= j);
    if(left < j)    quickSort(vector,left,j);
    if(i < right)   quickSort(vector,i,right);
}

int main(){
    int vector[12] = {26,65,45,73,10,18,78,93,70,49,23,22};

    quickSort(vector,0,11);

    for(int a = 0; a < 12; a++) printf("%d  ", vector[a]);


    return 0;
}
