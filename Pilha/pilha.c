#include "pilha.h"
/*
struct pessoa;

struct pilha;
*/
/*--Mostra o menu--*/
void showMenu(){
	printf("/*---- Menu principal ----*/\n");
	printf(" 1. Iniciar pilha.\n");
	printf(" 2. Adicionar elemento.\n");
	printf(" 3. Retirar elemento.\n");
	printf(" 4. Limpar pilha.\n");
	printf(" 5. Imprimir elementos.\n");
	printf(" 6. Sair.\n");
}
/*--Inicializa a pilha--*/
void RESET(Pilha* pilha){
	pilha->topo = 0;
	pilha->base = 0;
	pilha->limite = MAX;
}
/*--Verifica se a pilha está vazia--*/
bool EMPTY(Pilha* pilha){
	return pilha->topo == 0;
}
/*--Verifica se a pilha está cheia--*/
bool FULL(Pilha* pilha){
	return pilha->topo == pilha->limite-1;
}
/*--Realiza um PUSH na pilha(empilha)--*/
bool PUSH(Pilha* pilha, Pessoa* pessoa){
	if(!FULL(pilha)){
		pilha->pessoas[pilha->topo] = *pessoa;
		pilha->topo++;
		return true;
	}else{
		return false;
	}
}

/*--Realiza um POP na pilha(desempilha)--*/
void POP(Pilha* pilha, Pessoa* pessoa){
	if(!EMPTY(pilha)){
		pilha->topo--;
		*pessoa = pilha->pessoas[pilha->topo];
	}else{
		printf(" Não é possível desempilhar. Pilha está vazia!\n");
	}
}
/*--Limpa a pilha--*/
void CLEAR(Pilha* pilha){
	char c;
	printf("\n Tem certeza que deseja limpar a pilha(y/n)?\n- ");
	setbuf(stdin,NULL);
	scanf("%c", &c);
	getchar();
	if(c == 'y'){
		pilha->topo = pilha->base;
		printf(" Pilha limpa!\n");
	}else{
		printf(" Nenhuma operação realizada!\n");
	}
}
/*--Imprime elementos da pilha--*/
void PRINT(Pilha* pilha){
	Pessoa* pessoa;
	pessoa = (Pessoa*) malloc(sizeof(Pessoa));
	printf(" Listando...\n");
	while(!EMPTY(pilha)){
		POP(pilha, pessoa);
		printf("    %s - %i\n", pessoa->name, pessoa->idade);
	}
	free(pessoa);
}
