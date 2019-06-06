#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
#define MAX 3
/*--Define a estrutura Pessoa--*/
typedef struct pessoa{
	char name[32];
	int idade;
}Pessoa;
/*--Define a estrutura Pilha, que representa uma PILHA ESTÁTICA--*/
typedef struct pilha{
	Pessoa pessoas[MAX];
	int topo;
	int base;
	int limite;
}Pilha;
/*--Funções triviais de uma Pilha--*/
void RESET(Pilha* pilha);
bool EMPTY(Pilha* pilha);
bool FULL(Pilha* pilha);
bool PUSH(Pilha* pilha, Pessoa* pessoa);
void POP(Pilha* pilha, Pessoa* pessoa);
void CLEAR(Pilha* pilha);
void PRINT(Pilha* pilha);
void showMenu(void);
