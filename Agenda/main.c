#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"

int main(){
	void* buffer;
	Header* agenda;
	Contact* contato;

	agenda = (Header*) malloc(sizeof(Header));
	buffer = (void*) malloc(sizeof(void));
	contato = (Contact*) malloc(sizeof(Contact));

	

	showMenu();
	return 0;
}
