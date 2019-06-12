#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
  Header* list = (Header*) malloc(sizeof(Header));
  Node* writer;

  resetList(list);
  writer = readElement();
  printf("%d\n", insertElement(list, writer));
  writer = readElement();
  printf("%d\n", insertElement(list, writer));
  printList(list);
  printf("%d\n",list->nElements);

  free(list);

  return 0;
}
