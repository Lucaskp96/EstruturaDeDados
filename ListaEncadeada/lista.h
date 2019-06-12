#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED
#define bool int
#define true 1
#define false 0

typedef struct node{
  struct node* next;
  int element;
}Node;

typedef struct header{
  Node* starts;
  Node* ends;
  int nElements;
}Header;

//typedef struct header Header;
//typedef struct node Node;

void printList(Header* list);
bool insertElement(Header* list, Node* newElement);
Node* readElement();
void resetList(Header* head);

#endif // LISTA_INCLUDED
