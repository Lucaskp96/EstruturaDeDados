// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Algoritmo de ordenação Insertion Sort para ser utilizado na função mediana.
// Foi escolhido este algoritmo pois ele é eficiente para conjuntos de dados pequenos.
void ordena(int* vetor, int n){
    int *j, *temp, *i;
    // Alocação de memória para os ponteiros.
    j    = (int*) malloc(sizeof(int));
    temp = (int*) malloc(sizeof(int));
    i    = (int*) malloc(sizeof(int));
    // Implementação do Insertion Sort.
    for(*i = 1; *i < n; (*i)++){
        *temp = vetor[*i];
        for(*j = *i; ((*j)>0) && ((*temp) < (vetor[(*j)-1])); (*j)--){
            vetor[*j] = vetor[(*j) - 1];
        }
        vetor[*j] = *temp;
    }
    // Liberação de memória alocada pelos ponteiros.
    free(j); free(temp); free(i);
}

// mediana : recebe um vetor desordenado e seu tamanho e retorna o valor da mediana dos valor. Assuma que o tamanho eh sempre impar.
int mediana(int * vetor, int tamanho) {
    ordena(vetor,tamanho);
    return vetor[tamanho / 2];
}

// numNotificacoes : recebe um vetor, seu tamanho e o tamanho do intervalo.
// Retorna o numero de notificacoes que o cliente ira receber segundo o criterio estabelecido na especificacao do problema
int numNotificacoes(int * vetor, int tamanho, int intervalo) {
    int resultado = 0, i = 0, val_mediana, offset = 0;
    int* vetor_aux;
    vetor_aux = (int*) malloc(intervalo*sizeof(int));

    if(tamanho > intervalo){
        while(offset < (tamanho-intervalo)){
            for(int i = 0; i < intervalo; i++){
                vetor_aux[i] = vetor[i+offset];
            }
            val_mediana = mediana(vetor_aux,intervalo);
            if(vetor[intervalo+offset] >= 2*val_mediana){
                resultado++;
            }

            offset++;
        }
    }
    free(vetor_aux);

    return resultado;
}

int main() {
    int tamanho, intervalo, resultado;
    int * vetor;

    printf("---Testes de Validacao---\n");
    printf("1. ");

    tamanho = 9;
    intervalo = 5;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 2;
    vetor[1] = 3;
    vetor[2] = 4;
    vetor[3] = 2;
    vetor[4] = 3;
    vetor[5] = 6;
    vetor[6] = 8;
    vetor[7] = 4;
    vetor[8] = 5;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 2\n" RESET, resultado);
    }
    free(vetor);

    printf("2. ");

    tamanho = 5;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 4;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 0\n" RESET, resultado);
    }
    free(vetor);

    printf("3. ");

    tamanho = 12;
    intervalo = 7;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 17;
    vetor[1] = 23;
    vetor[2] = 44;
    vetor[3] = 11;
    vetor[4] = 3;
    vetor[5] = 17;
    vetor[6] = 31;
    vetor[7] = 55;
    vetor[8] = 12;
    vetor[9] = 91;
    vetor[10] = 47;
    vetor[11] = 19;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);

    printf("4. ");

    tamanho = 27;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = (i * 4) + 1;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 1\n" RESET, resultado);
    }
    free(vetor);

    printf("5. ");

    tamanho = 12;
    intervalo = 1;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = i * i;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);

    return 0;
}
