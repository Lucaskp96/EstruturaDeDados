#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

typedef struct contato Contact;
typedef struct agenda Header;
/*
void *pBuffer;
int *ntotal, *escolha, *cont, *cont2;
contato *pessoa,*aux;
char *achaNome;
*/
void initContact(Contact* contact);
void initAgenda(Header* header);
void showMenu(void);
void insertContact(Header* agenda, Contact* newContact);
void printContacts(Header* agenda);
void getContact(Contact* contact);
void setContact(Contact* contact);
void removeContact(Header* agenda);
void findContact(Header* agenda, Contact* contact);
void findAndRemove(Header* agenda, Contact* contact);

#endif // AGENDA_H_INCLUDED
