#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void resetList(Header* head){
  head->starts = NULL;
  head->ends = NULL;
  head->nElements = 0;
}

Node* readElement(){
  Node* newElement = (Node*) malloc(sizeof(Node));
  printf("Int element: ");
  scanf("%d", &newElement->element);
  setbuf(stdin, NULL);
  newElement->next = NULL;

  return newElement;
}

bool insertElement(Header* list, Node* newElement){
  if(list != NULL){
    if(list->starts == NULL){
      list->starts = newElement;
      list->ends = newElement;
      list->nElements = 1;
    }else{
      newElement->next = NULL;
      list->ends = newElement;
      list->nElements++;
    }
    return true;
  }else{
    printf(" Erro! Lista não existe!\n");
    return false;
  }
}

void printList(Header* list){
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
