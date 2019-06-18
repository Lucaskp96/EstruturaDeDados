/*-- LISTA SIMPLESMENTE ENCADEADA --*/
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

void RESET(Header* list);
bool EMPTY(Header* list);
//bool FULL(Header* list); não faz sentido para essa estrutura.
bool PUSH(Header* list, Node* newElement);
void POP(Header* list, Node* element);
bool CLEAR(Header* list);
void PRINT(Header* list);
bool FIND(Header* list, int num);
void showMenu(void);
Node* readElement();


#endif // LISTA_INCLUDlist
