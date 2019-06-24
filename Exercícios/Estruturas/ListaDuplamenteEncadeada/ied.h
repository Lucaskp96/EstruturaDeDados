#ifndef IED_H_INCLUDED
#define IED_H_INCLUDED
#define bool int
#define true 1
#define false 0
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


bool is_empty(Header* list);
void insert_contact(Header* list, Person* newContact);
void print_list(Header* list);
bool remove_contact(Header* list, Person* contact);
Person* find_by_name(Header* list, char* name);
Person* find_by_age(Header* list, int age);

#endif // IED_H_INCLUDED
