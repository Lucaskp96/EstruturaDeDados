#ifndef PESSOA_H
#define PESSOA_H
typedef struct pessoa{
	char nome[32];
	char telefone[12];
	char padding[20];
}Pessoa; // 64 bytes

void atualizar_ponteiros(void* buffer);

#endif
