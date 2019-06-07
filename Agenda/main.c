#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(){
	void* buffer;
	int* aux_int;
	float* aux_float;
	char* aux_char;
	Header* aux_header;
	Contact* aux_contact;

	buffer = (void*) malloc(sizeof(char)+sizeof(int)+sizeof(float)+sizeof(Header)+10*sizeof(Contact));
	aux_char = (char*) buffer;
	aux_int = (int*) buffer + sizeof(int);
	aux_float = (float*) aux_int + sizeof(float);
	aux_header = (Header*) aux_float + sizeof(Header);
	aux_contact = (Contact*) aux_header + sizeof(Contact);

	aux_header->first = (Contact*) aux_contact;
	aux_header->last = (Contact*) aux_contact;
	initAgenda(aux_header);
	scanf("%[^\n]s", aux_contact->name);
	scanf("%d", &aux_contact->tel);

	insertContact(aux_header,aux_contact);
	setbuf(stdin,NULL);
	scanf("%[^\n]s", aux_contact->name);
	scanf("%d", &aux_contact->tel);
	insertContact(aux_header,aux_contact);
	printContacts(aux_header);

//	showMenu();
	return 0;
}
