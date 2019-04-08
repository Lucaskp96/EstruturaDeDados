#include <stdlib.h>
#include <stdio.h>

typedef struct person{
  char nome[30];		// 30 bytes
  char data_nascimento[12];	// 12 bytes
  char cpf[12];			// 12 bytes
  char pad[10];			// +10 bytes de pad.
} Pessoa;			// 54 bytes + 10 bytes de preenchimento: 64 bytes!

Pessoa* inicia_estrutura(Pessoa* pessoa){
  pessoa = (Pessoa*) malloc(sizeof(Pessoa));
  printf("Nome: ");
  fgets(pessoa->nome,30,stdin);
  printf("Data de nascimento: ");
  fgets(pessoa->data_nascimento,12,stdin);
  printf("CPF: ");
  fgets(pessoa->cpf,12,stdin);
  return pessoa;
}

void imprime(Pessoa* pessoa){
  printf("\nNome: ");
  printf("%s", pessoa->nome);
  printf("Data de Nascimento: %s", pessoa->data_nascimento);
  printf("CPF: %s\n", pessoa->cpf);
}

int main(){
  Pessoa* pessoa;
  pessoa = inicia_estrutura(pessoa);
  imprime(pessoa);
  return 0;
}
