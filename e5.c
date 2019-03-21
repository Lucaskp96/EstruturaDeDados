#include <stdlib.h>
#include <stdio.h>

typedef struct person{
  char nome[20];
  int data_nascimento;
  int cpf;
} Pessoa;

Pessoa* inicia_estrutura(Pessoa* pessoa){
  pessoa = (Pessoa*) malloc(sizeof(Pessoa));
  printf("Nome: ");
  fgets(pessoa->nome,20,stdin);
  printf("Data de nascimento: ");
  scanf("%d", &pessoa->data_nascimento);
  printf("CPF: ");
  scanf("%d", &pessoa->cpf);
  return pessoa;
}

void imprime(Pessoa* pessoa){
  printf("\nNome: ");
  printf("%s", pessoa->nome);
  printf("Data de Nascimento: %d\n", pessoa->data_nascimento);
  printf("CPF: %d\n", pessoa->cpf);
}

int main(){
  Pessoa* pessoa;
  pessoa = inicia_estrutura(pessoa);
  imprime(pessoa);
  return 0;
}
