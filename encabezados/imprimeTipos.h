#include<stdio.h>

void 
imprime_int(void * dato)
{
	int * nuevo;
	nuevo = (int *) (dato);
		printf("\%d-->",*nuevo);
}

void 
imprime_char(void * dato)
{
	char * nuevo;
	nuevo = (char *) (dato);
		printf("\%c-->",*nuevo);
}
