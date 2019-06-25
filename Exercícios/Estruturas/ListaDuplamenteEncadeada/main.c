#include <stdio.h>
#include <stdlib.h>
#include "ied.h"

int main(){
    Header* list;
    Node* temp;
	char *op;
    char name[32];
    int age;
	Person* person;

	op = (char*) malloc(sizeof(char));
	list = create_list();

	showMenu();

	do{
		setbuf(stdin,NULL);
		printf(": ");
		scanf("%c", op);
		getchar();
		switch(*op){
			case '1':
                person = create_contact();
                insert_contact(list,person);
				break;
			case '2':
                person = create_contact();
                remove_contact(list,person);
				break;
			case '3':
                print_list(list);
				break;
			case '4':

				break;
			case '5':
                printf("Nome: ");
                setbuf(stdin,NULL);
                scanf("%s", name);
                temp = search_by_name(list, name);
                if(temp == NULL) break;
                get_contact(temp->contact);
				break;
            case '6':
                printf("Idade: ");
                setbuf(stdin,NULL);
                scanf("%d", &age);
                temp = search_by_age(list, age);
                if(temp == NULL) break;
                get_contact(temp->contact);
    			break;
			case '7':
					printf(" Saindo...\n");
				break;
			default:
					printf(" Opção inválida\n");
		}
	}while(*op != '7');

	free(list);
    free(op);
    free(person);

	return 0;
}
