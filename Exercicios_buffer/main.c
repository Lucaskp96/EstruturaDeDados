#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i;
    float f;
    double d;
}Trio;

void imprimeBuffer(void* pBuffer, unsigned int nTotal){
    for(int i=0; i < nTotal; i++){
        printf("%d ", ((Trio*)pBuffer)->i);
        printf("%g ", ((Trio*)pBuffer)->f);
        printf("%g", ((Trio*)pBuffer)->d);
        printf("\n");
        pBuffer = pBuffer + sizeof(Trio);
    }
}

int main()
{
    void* buffer;
    void* aux;
    buffer = malloc(3*sizeof(Trio));
    ((Trio*)buffer)->i = 4;
    ((Trio*)buffer)->f = 4.587;
    ((Trio*)buffer)->d = 4.8798;
    aux = buffer + sizeof(Trio);
    ((Trio*)aux)->i = 5;
    ((Trio*)aux)->f = 5.587;
    ((Trio*)aux)->d = 5.8798;
    aux = aux + sizeof(Trio);
    ((Trio*)aux)->i = 6;
    ((Trio*)aux)->f = 6.587;
    ((Trio*)aux)->d = 7.98;

    imprimeBuffer(buffer,3);
    return 0;
}
