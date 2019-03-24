#include <stdlib.h>
#include <stdio.h>

typedef struct person{
  char nome[30];
  char data_nascimento[12];
  char cpf[12];
} Pessoa;

void inicia_estrutura(Pessoa* pessoa){
//  pessoa = (Pessoa*) malloc(sizeof(Pessoa));
  printf("Nome: ");
  fgets(pessoa->nome,30,stdin);
  printf("Data de nascimento: ");
  fgets(pessoa->data_nascimento,12,stdin);
  printf("CPF: ");
  fgets(pessoa->cpf,12,stdin);
}

void imprime(Pessoa* pessoa){
  printf("\nNome: ");
  printf("%s", pessoa->nome);
  printf("Data de Nascimento: %s", pessoa->data_nascimento);
  printf("CPF: %s\n", pessoa->cpf);
}

int main(){
  Pessoa pessoa;
  inicia_estrutura(&pessoa);
  imprime(&pessoa);
  return 0;
}
