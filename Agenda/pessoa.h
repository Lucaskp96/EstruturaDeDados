#ifndef PESSOA_H
#define PESSOA_H
typedef struct pessoa{
	char nome[20];
	int idade;
	int telefone;
}Pessoa;

void atualizar_ponteiros(void* buffer);

#endif