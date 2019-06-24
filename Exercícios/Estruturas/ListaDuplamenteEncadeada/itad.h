#ifndef ITAD_H_INCLUDED
#define ITAD_H_INCLUDED
#define bool int
#define true 1
#define false 0

typedef struct{
    char name[32];
    int age;
}Person;

//typedef Person* Contact;

/*** Inicializa uma estrutura Person ***/
Person* create_contact();
/*** Lista os dados do contato ***/
bool get_contact(Person* person);
/*** Pega, do usuário, os dados do contato ***/
bool set_contact(Person* person);
/*** Libera memória alocada para uma estrutura Person ***/
bool destroy_contact(Person* person);


#endif // ITAD_H_INCLUDED
