#include <stdio.h>
#include <stdlib.h>
#include "header.h"

typedef struct pessoa{
    int index;
    char* nome;
    int idade;
    int telefone;
}Pessoa;

typedef struct agenda{
    Pessoa* pessoas;
    Pessoa* topo;
    Pessoa* base;
    int limite;
}Agenda;


void LIST(Agenda* agenda){
    while(!EMPTY(agenda)){
        Pessoa pessoa;
        POP(agenda, &pessoa);
        printf("\n%i\t%s\t%i anos\ttelefone: %i\n", pessoa->index,pessoa->nome,pessoa->idade,pessoa->telefone);
    }
}

void RESET(Agenda* agenda){
    agenda->base = NULL;
    agenda->topo = NULL;
    agenda->pessoas = NULL;
    agenda->limite = 0;
}

bool EMPTY(Agenda* agenda){
    return agenda->pessoas == NULL;
}

bool FULL(Agenda* agenda){
    return FALSE;
}

bool PUSH(Agenda* agenda, Pessoa* individuo){
    Pessoa* pessoas;

    agenda->limite++;
    pessoas = (Pessoa*) malloc(sizeof(Pessoa)*agenda->limite);

    if(!pessoas){
        printf("Erro ao alocar memória!\n");
        return FALSE;
    }

    StackCopy(pessoas, agenda->limite, agenda->pessoas, agenda->limite-1);

    if(agenda->pessoas){
        free(agenda->pessoas);
    }

    agenda->pessoas = pessoas;

    agenda->pessoas[agenda->limite-1] = *individuo;
    agenda->topo = &agenda->pessoas[agenda->limite-1];
    agenda->base = agenda->pessoas;

    return TRUE;
}

bool POP(Agenda* agenda, Pessoa* individuo){
    if(EMPTY(agenda))   return FALSE;

    individuo = agenda->topo;

    Pessoa* pessoas;
    agenda->limite--;

    if(agenda->limite == 0){
        free(agenda->pessoas);
        RESET(agenda);
        return FALSE;
    }

    size_t size = sizeof(Pessoa)*agenda->limite;
    pessoas = (Pessoa*) malloc(size);

    if(!pessoas){
        printf("Erro ao alocar memória\n", );
        return FALSE;
    }

    StackCopy(pessoas, agenda->limite, agenda->pessoas, agenda->limite+1);

    free(agenda->pessoas);

    agenda->pessoas = pessoas;
    agenda->topo = &agenda->pessoas[agenda->limite-1];
    agenda->base = agenda->pessoas;

    return TRUE;
}

void CLEAR(Agenda* agenda){
    Pessoa* auxiliar;
    for(auxiliar = agenda->topo; agenda->topo >= agenda->base; agenda->topo = agenda->topo--)
        free(auxiliar);
    agenda->limite = 0;
/*
    auxiliar = agenda->base;

    for(int i = 0; i < agenda->limite; i++){
        free(auxiliar);
        auxiliar = auxiliar + sizeof(Pessoa);
    }
*/
}

void StackCopy(Pessoa* newPessoas, int oldLimit, Pessoa* oldPessoas, int newLimit){
    for(int i = 0; i < newLimit; i++){
        
    }
}
