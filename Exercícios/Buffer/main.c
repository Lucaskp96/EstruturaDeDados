/************************
**Lucas Kuster Pereira***
************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i;
    float f;
    double d;
}Trio;

void imprimeBuffer(void* pBuffer, unsigned int nTotal){
    printf("\n");
    if(pBuffer!=NULL){
        for(int i=0; i < nTotal; i++){
            printf("%d ", ((Trio*)pBuffer)->i);
            printf("%g ", ((Trio*)pBuffer)->f);
            printf("%g\n", ((Trio*)pBuffer)->d);
            pBuffer = pBuffer + sizeof(Trio);
        }
    }else{
            printf("\nPonteiro nulo!\n");
    }
}

int main()
{
    void* buffer;
    void* aux;
    int nTrios;
    printf("Digite a quantidade de trios(int,float,double): ");
    scanf("%d", &nTrios);
    buffer = malloc(nTrios*sizeof(Trio));
    aux = buffer;
    printf("Digite os Trios: \n", nTrios);
    for(int i=0; i < nTrios; i++){
        printf("Trio %d: \n", i+1);
        scanf("%d", &((Trio*)aux)->i);
        scanf("%g", &((Trio*)aux)->f);
        scanf("%lf", &((Trio*)aux)->d);
        aux = aux + sizeof(Trio);
    }
   /*
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
    */
    imprimeBuffer(buffer,nTrios);
    free(buffer);
    buffer=NULL;
    return 0;
}
