#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

void enterRemove(char* name);

int main(){
	Pilha* pilha;
	char *op;
	Pessoa* pessoa;

	op = (char*) malloc(sizeof(char));
	pilha = (Pilha*) malloc(sizeof(Pilha));
	pessoa = (Pessoa*) malloc(sizeof(Pessoa));

	showMenu();

	do{
		setbuf(stdin,NULL);
		printf(": ");
		scanf("%c", op);
		getchar();
		switch(*op){
			case '1':
					RESET(pilha);
					if(EMPTY) printf(" Pilha iniciada!\n");
				break;
			case '2':
					printf("Digite os dados do novo elemento\n");
					printf(" Nome: ");
					setbuf(stdin,NULL);
					fgets(pessoa->name,32,stdin);
					enterRemove(pessoa->name);
					printf(" Idade: ");
					scanf("%d", &pessoa->idade);
					PUSH(pilha, pessoa);
				break;
			case '3':
					POP(pilha, pessoa);
				break;
			case '4':
					CLEAR(pilha);
				break;
			case '5':
					PRINT(pilha);
				break;
			case '6':
					printf(" Saindo...\n");
				break;
			default:
					printf(" Opção inválida\n");
		}
	}while(*op != '6');

	free(pilha);
	return 0;
}

void enterRemove(char* name){
		int i = 0;
		do{
			if(*name == '\n'){
					*name = '\0';
			}
			name++;
			i++;
		}while(i < 32);
}
