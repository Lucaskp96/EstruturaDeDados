#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

Pessoa* pessoa_1;
int* cp;
int* op;
int* contador;
float* a;

int main(){
	void* buffer=NULL;
    Pessoa* auxiliar;
    buffer = malloc(sizeof(int)+sizeof(int)+sizeof(Pessoa));
    contador = buffer;
    *contador = 0;
    op = buffer + sizeof(int);
    printf("Escolha a opcao no menu: \n");
    printf("1. Inserir na agenda.\n");
    printf("2. Imprimir agenda.\n");
    scanf("%d", op);
    getchar();
    switch(*op){
        case 1:
                pessoa_1 = (Pessoa*)buffer+2*(sizeof(int));
                printf("Nome: "); fgets(pessoa_1->nome,20,stdin);
                printf("Idade: "); scanf("%d", &pessoa_1->idade);
                printf("Telefone: "); scanf("%d", &pessoa_1->telefone);
                *contador++;
            break;
        case 2:

        default:
            break;
    }
	return 0;
}
