//AED1 - Trabalho Prático 3
//Lucas Kuster Pereira
//Lista Simplesmente Encadeada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[31];
	struct node *next;
};

struct node *newNode();
void printList(struct node *head);
void insertInOrder(struct node *head, char *name);
void delete(struct node *head, char *name);
int isEmpty(struct node *head);

int main(){
	struct node *head = newNode();
	head->next = NULL;
	int option;
	char name[31];

	do{
		printf("1 - Insert\n2 - Delete\n3 - Print List\n0 - Exit\n");
		scanf("%d", &option);
		getchar();

		switch(option){
			case 1:
				printf("Name: ");
				fgets(name, 31, stdin);
				//scanf("%s", word);
				insertInOrder(head, name);
				printf("\n");
				break;

			case 2:
				if(isEmpty(head)){
					printf("Lista vazia\n\n");
				}
				else{
					printf("Name: ");
					fgets(name, 31, stdin);
					//scanf("%s", word);
					delete(head, name);
				}

				break;

			case 3:
				printList(head);
				break;

			default:
				break;
		}

	} while(option != 0);

	free(head);
	return 0;
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
void insertInOrder(struct node *head, char *name){
/*- Aloca memória para o novo nó -*/
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
/*- Ponteiro auxiliar para as operações -*/
	struct node* auxiliar = head;
/*- Copia o parâmetro passado para o novo nó -*/
	strcpy(newNode->name,name);
/*- Se a lista estiver vazia, adicionará o elemento na próxima posição -*/
	if(isEmpty(head)){
		head->next = newNode;
		newNode->next = NULL;
	}
/*- Caso contrário, necessário fazer alguns testes -*/
	else{
/*- Enquanto 'auxiliar' não estiver no endereço do último elemento -*/
		while(auxiliar->next != NULL){
/*- Verifica se o novo nome é maior que o PRÓXIMO nome na lista -*/
			if((strcmp(newNode->name, auxiliar->next->name) >= 0) && (auxiliar->next != NULL)){
/*- Se for maior, apenas avança para a próxima posição -*/
				auxiliar = auxiliar->next;
			}
/*- Se for menor, significa que o novo nome deve ser colocado nesta posição -*/
			else{
				newNode->next = auxiliar->next;
				auxiliar->next = newNode;
				break;
			}
		}
/*- Se, depois do laço anterior, auxiliar->next não for igual newNode:
 1. Auxiliar está na última posição da lista.
 2. Então, newNode deve ser colocado aqui. -*/
		if(auxiliar->next != newNode){
			auxiliar->next = newNode;
			newNode->next = NULL;
		}
	}
}

//VOCÊS DEVEM COMPLETAR ESTA FUNÇÃO
void delete(struct node *head, char *name){
/*- Variáveis necessárias -*/
	struct node* searcher, *temp;
	int found = 0;
/*- searcher aponta para o inicio da lista -*/
	searcher = head;
/*- Enquanto o elemento não for encontrado e não chegar no fim da lista:
 1. Compara o nome passado por parâmetro com o nome na PRÓXIMA posição da Lista.
 2. Se for igual, 'temp' aponta para o este nó.
 3. Os ponteiros são atualizados.
 4. End.Memória apontado por 'temp' é liberado e nó é apagado.
 5. Variável 'found' sinaliza que a operação foi realizada. -*/
	while((found == 0) && (searcher->next != NULL)){
		if(strcmp(searcher->next->name,name) == 0){
			temp = searcher->next;
			searcher->next = searcher->next->next;
			free(temp);
			found = 1;
		}
/*- Se o elemento não for encontrado, avança pra próxima posição. -*/
		else{
			searcher = searcher->next;
		}
	}
/*- Se chegar no fim da lista e a variável 'found' não sinalizar a operação,
 imprime mensagem dizendo que nome não foi encontrado. -*/
	if(found == 0) printf("Nome não encontrado!\n");
}

int isEmpty(struct node *head){
	if(head->next == NULL)
		return 1;
	else return 0;
}

void printList(struct node *head){
	if(head->next == NULL){
		printf("Lista vazia\n\n");
		return;
	}

	struct node *printer = head->next;

	printf("StormTroopers:\n");

	while(printer != NULL){
		printf("\t%s", printer->name);
		printer = printer->next;
	}

	printf("\n");
}

struct node *newNode(){
	struct node *new = malloc (sizeof (struct node));
	return new;
}
