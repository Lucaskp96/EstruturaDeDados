#include <stdio.h>
#include <stdlib.h>
#include "itad.h"

/*** Inicializa uma estrutura Person ***/
Person* create_contact(){
    Person* newContact = (Person*) malloc (sizeof(Person));
    if(newContact != NULL){
        set_contact(newContact);
        return newContact;
    }else{
        printf("Não foi possível criar contato!\n\n");
        return NULL;
    }
}
/*** Lista os dados do contato ***/
bool get_contact(Person* person){
    if(person != NULL){
        printf("Nome: %s.\tIdade: %d.\n\n", person->name, person->age);
        return true;
    }else{
        return false;
    }
}
/*** Pega, do usuário, os dados do contato ***/
bool set_contact(Person* person){
    if(person != NULL){
        printf("Nome: ");
        scanf("%s", person->name);
        printf("Idade: ");
        scanf("%d", &person->age);
        return true;
    }else{
        return false;
    }
}
/*** Libera memória alocada para uma estrutura Person ***/
bool destroy_contact(Person* person){
    if(person != NULL){
        free(person);
        person = NULL;
        return true;
    }else{
        return false;
    }
}
