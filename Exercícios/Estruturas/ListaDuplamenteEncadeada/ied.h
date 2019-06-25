#ifndef IED_H_INCLUDED
#define IED_H_INCLUDED
#define bool int
#define true 1
#define false 0
#include "itad.h"
/*** Célula da lista ***/
typedef struct no{
    struct no* previous;
    struct no* next;
    Person* contact;
}Node;
/*** Cabeçalho da lista ***/
typedef struct{
    Node* starts;
    Node* ends;
}Header;

/*** Inicializa a lista ***/
Header* create_list();
/*** Mostra o menu ***/
void showMenu();
/*** Retorna True se a lista estiver vazia ***/
bool is_empty(Header* list);
/*** Insere um novo contato na lista ***/
bool insert_contact(Header* list, Person* newContact);
/*** Imprime os elementos da lista ***/
void print_list(Header* list);
/*** Remove um determinado contato da lista ***/
bool remove_contact(Header* list, Person* contact);
/*** Busca elemento na lista pelo nome ***/
Node* search_by_name(Header* list, char* name);
/*** Busca elemento na lista pela idade ***/
Node* search_by_age(Header* list, int age);

#endif // IED_H_INCLUDED
