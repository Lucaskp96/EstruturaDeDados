#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(){
	Pilha* pilha;
	int *op;
	Pessoa* pessoa;

	op = (int*) malloc(sizeof(int));
	pilha = (Pilha*) malloc(sizeof(Pilha));
	pessoa = (Pessoa*) malloc(sizeof(Pessoa));

	showMenu();
	while(*op != 6){
		scanf("%d", op);
		switch(*op){
			case 1: RESET(pilha);
					if(EMPTY) printf("Pilha iniciada!\n");
				break;
			case 2:	printf("Digite os dados do novo elemento\n");
					printf("Nome: ");
					fgets(pessoa->name,32,stdin);
					printf("Idade: ");
					scanf("%d", &pessoa->idade);
					PUSH(pilha, pessoa);
				break;
			case 3: POP(pilha, pessoa);
				break;
			case 4: CLEAR(pilha);
				break;
			case 5: PRINT(pilha);
				break;
			case 6: printf("Saindo...\n");
				break;
			default: printf("Opção inválida\n");
				break;
		}
	}

	free(pilha);
	return 0;
}