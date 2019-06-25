#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ied.h"

Header* create_list(){
    Header* list = (Header*) malloc ( sizeof (Header) );
    list->starts = NULL;
    list->ends = NULL;
    return list;
}
/*--Mostra o menu--*/
void showMenu(){
	printf("/*---- Menu principal ----*/\n");
	printf(" 1. Adicionar elemento.\n");
	printf(" 2. Retirar elemento.\n");
	printf(" 3. Imprimir elementos.\n");
	printf(" 4. Limpar lista.\n");
	printf(" 5. Buscar elemento por nome.\n");
	printf(" 6. Buscar elemento por idade.\n");
    printf(" 7. Sair.\n");
}

/*** Retorna True se a lista estiver vazia ***/
bool is_empty(Header* list){
    if(list == NULL){
        return true;
    }
    else{
        if(list->starts == NULL)
            return true;
        else
            return false;
    }
}

/*** Imprime os elementos da lista ***/
void print_list(Header* list){
    if((list != NULL) && (list->starts != NULL)){
        Node* getter = list->starts;
        do{
            get_contact(getter->contact);
            getter = getter->next;
        }while(getter != NULL);
    }else{
        printf("Nothing to be done here!\n\n");
    }
}

/*** Insere um novo contato na lista no inicio da lista ***/
bool insert_contact(Header* list, Person* newContact){
    if(list != NULL){
        Node* newNode = (Node*) malloc(sizeof(Node));
        if(list->starts == NULL){
            newNode->contact = newContact;
            list->starts = newNode;
            newNode->previous = NULL;
            newNode->next = NULL;
        }else{
            newNode->contact = newContact;
            newNode->next = list->starts;
            list->starts->previous = newNode;
            list->starts = newNode;
        }
        return true;
    }else{
        printf("Lista não existe!\n\n");
        return false;
    }
}

/*** Busca elemento na lista pelo nome ***/
Node* search_by_name(Header* list, char* name){
    if(list != NULL){
        Node* getter = list->starts;
        do{
            if((strcmp(getter->contact->name,name) == 0)){
                return getter;
            }
            getter = getter->next;
        }while(getter != NULL);
        printf("Contato não encontrado!\n\n");
        return NULL;
    }else{
        printf("Lista não existe!\n\n");
    }
}

/*** Busca elemento na lista pela idade ***/
Node* search_by_age(Header* list, int age){
    if(list != NULL){
        Node* getter = list->starts;
        do{
            if(getter->contact->age == age){
                return getter;
            }
            getter = getter->next;
        }while(getter != NULL);
        printf("Contato não encontrado!\n\n");
        return NULL;
    }else{
        printf("Lista não existe!\n\n");
        return NULL;
    }
}

/*** Remove um determinado contato da lista ***/
bool remove_contact(Header* list, Person* contact){
    if(list != NULL){
        Node* temp, *before, *after;
        temp = search_by_name(list, contact->name);
        if(temp == NULL){
            return false;
        }
        before = temp->previous;
        after = temp->next;
        if(before == NULL){
            list->starts = temp->next;
            if(after == NULL)
                list->starts = NULL;
        }else{
            before->next = after;
            if(after == NULL)
                before->next = NULL;
            else{
                after->previous = before;
            }
        }

        free(temp);
        temp = NULL;

        return true;
    }else{
        printf("Lista não existe!\n\n");
        return false;
    }
}
