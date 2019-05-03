#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

void *pBuffer;
int *ntotal, *escolha, *cont, *cont2;
contato *pessoa,*aux;
char *achaNome;

void mostraMenu(void);
void insereContato (void);
void listaContato(void);
void deletaContato(void);
void procuraContato(void);

#endif // AGENDA_H_INCLUDED
