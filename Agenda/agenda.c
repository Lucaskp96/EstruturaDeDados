#include <string.h>
#include "Agenda.h"

struct contato{
    struct contato* next;
    struct contato* previous;
    char name[32];
    int tel;
};

struct agenda{
    Contact* first;
    Contact* last;
};

/*--Inicializa uma agenda--*/
void initAgenda(Header* header){
    header->first = NULL;
    header->last = NULL;
}
/*--Inicializa um contato--*/
void initContact(Contact* contact){
    contact->next = NULL;
    contact->previous = NULL;
    strcpy("\0",contact->name);
    contact->tel = 0;
}
/*--Insere um contato já inicializado na agenda--*/
void insertContact(Header* agenda, Contact* newContact){
    if(agenda->first == NULL){ // Se a lista estiver vazia, adiciona no inicio da lista.
        newContact->previous = newContact;
        newContact->next = NULL;
        agenda->first = newContact;
        agenda->last = newContact;
    }else{  // Se a lista NÃO estiver vazia, adiciona no fim da lista.
        newContact->previous = agenda->last;
        newContact->next = NULL;
        agenda->last = newContact;
    }
}
/*--Imprime os contatos da agenda--*/
void printContacts(Header* agenda){
    Contact* printer;
    printer = agenda->first;
    if(agenda->first){ // Se a lista NÃO estiver vazia, imprime.
        do{
            getContact(printer);
            printer = printer->next;
        }while(printer != NULL);
    }else{ // Se estiver vazia, retorna msg de erro.
        printf("\nA agenda não possui nenhum contato.\n");
    }
}
/*--Imprime os dados de um contato--*/
void getContact(Contact* contact){
    printf("\n%s\t%i\n", contact->name, contact->tel);
}
/*--Insere os dados de um contato--*/
void setContact(Contact* contact){
    printf("Digite o nome: ");
    fgets(contact->name, 32, stdin);
    printf("Digite o telefone: ");
    scanf("%d", &contact->tel);
    printf("Contato Salvo!\n");
}
/*--Remove o último contato da agenda--*/
void removeContact(Header* agenda){
    Contact* selector;
    selector = agenda->last;
    agenda->last = agenda->last->previous;
    agenda->last->next = NULL;
    free(selector);
}
void findContact(Header* agenda, Contact* contact);
void findAndRemove(Header* agenda, Contact* contact);

/*--Mostra menu com as opções disponíveis para a agenda--*/
void showMenu(void){
    printf("/*--\t Agenda 2019 \t--*/\n");
    printf(" 1. Listar contatos;\n");
    printf(" 2. Inserir contato;\n");
    printf(" 3. Remover último contato;\n");
    printf(" 4. Encontrar contato;\n");
    printf(" 5. Encontrar e remover contato;\n");
    printf(" 6. Sair;\n");
}
