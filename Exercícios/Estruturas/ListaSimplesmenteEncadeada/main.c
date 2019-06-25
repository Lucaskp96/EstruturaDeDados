/*-- LISTA SIMPLESMENTE ENCADEADA --*/
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
  Header* list = (Header*) malloc(sizeof(Header));
  Node* writer;
  char op;

  showMenu();

  do{
		setbuf(stdin,NULL);
		printf(": ");
		scanf("%c", &op);
		getchar();
		switch(op){
			case '1':
					RESET(list);
					if(EMPTY(list)) printf(" Estrutura iniciada!\n");
				break;
			case '2':
					printf("Digite os dados do novo elemento\n");
					printf(" Inteiro: ");
                    writer = readElement();
                    setbuf(stdin,NULL);
					//fgets(pessoa->name,32,stdin);
					//enterRemove(pessoa->name);
					//printf(" Idade: ");
					//scanf("%d", &pessoa->idade);
					PUSH(list, writer);
				break;
			case '3':
					//POP(list, writer);
				break;
			case '4':
					printf("%d ",CLEAR(list));
				break;
			case '5':
					PRINT(list);
				break;
			case '6':
					printf(" Saindo...\n");
				break;
			default:
					printf(" Opção inválida\n");
		}
	}while(op != '6');


  free(list);

  return 0;
}
