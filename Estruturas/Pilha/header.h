#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define bool int
#define TRUE 1
#define FALSE 0

typedef struct pessoa Pessoa;
typedef struct agenda Agenda;

void StackCopy(Pessoa* oldPessoas, int oldLimit, Pessoa* newPessoas, int newLimit);
void LIST(Agenda* agenda);
void RESET(Agenda* agenda);
bool EMPTY(Agenda* agenda);
bool FULL(Agenda* agenda);
bool PUSH(Agenda* agenda, Pessoa* individuo);
bool POP(Agenda* agenda, Pessoa* individuo);
void CLEAR(Agenda* agenda);


#endif // HEADER_H_INCLUDED
