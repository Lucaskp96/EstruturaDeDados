/*-- LISTA SIMPLESMENTE ENCADEADA --*/
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void RESET(Header* list){
  list->starts = NULL;
  list->ends = NULL;
  list->nElements = 0;
}

Node* readElement(){
  Node* newElement = (Node*) malloc(sizeof(Node));
  scanf("%d", &newElement->element);
  setbuf(stdin, NULL);
  newElement->next = NULL;

  return newElement;
}

bool PUSH(Header* list, Node* newElement){
  if(list != NULL){
    if(list->starts == NULL){
      list->starts = newElement;
      newElement->next = NULL;
      list->nElements = 1;
      list->ends = newElement;
    }else{
      newElement->next = list->starts;
      list->starts = newElement;
      list->nElements++;
      list->ends = newElement;
    }
    return true;
  }else{
    printf(" Erro! Lista não existe!\n");
    return false;
  }
}

void PRINT(Header* list){
  Node* printer;
  printer = list->starts;
  if(list->starts != NULL){
    printf("Lista: ");
    do{
      printf("%d ", printer->element);
      printer = printer->next;
    }while(printer != NULL);
    printf("\n");
  }else{
    printf("Lista vazia!\n");
  }
}

bool EMPTY(Header* list){
    if((list->starts == NULL) && list->nElements == 0)
        return true;
    else
        return false;
}

bool CLEAR(Header* list){
    Node* temp;

    do{
        temp = list->starts;
        list->starts = list->starts->next;
        free(temp);
    }while(list->starts != NULL);
    free(list->starts);
    list->starts = NULL;
    return true;
}

bool FIND(Header* list, int num){
    Node* reader = list->starts;
    do{
        if(reader->element == num){
            return true;
        }else{
            reader = reader->next;
        }
    }while(reader != NULL);
    return false;
}

void showMenu(){
	printf("/*---- Menu principal ----*/\n");
	printf(" 1. Iniciar pilha.\n");
	printf(" 2. Adicionar elemento.\n");
	printf(" 3. Retirar elemento.\n");
	printf(" 4. Limpar pilha.\n");
	printf(" 5. Imprimir elementos.\n");
	printf(" 6. Sair.\n");
}
