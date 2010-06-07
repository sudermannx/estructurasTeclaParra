//Directivas

#include "../encabezados/interfazPila.h"

#include<stdlib.h>
#include<stdio.h>

#define MAL -1

#define BIEN 0


//Difinicion de funciones

/* Funcion para verificar si la pila esta vacia */

	int
	fvacia(Pila * P)
	{
		return (P->tope==0);
	
	}


/*Funcion para crear una pila*/

	Pila *
	fcreaP( int size )
	{
	 
	 Pila * nvo;
	 
	 nvo = ( Pila * ) malloc ( sizeof ( Pila ) * 1 );
	 
	 	if(nvo == NULL)
	 	{
	 		puts("\n\t<<fallo malloc nvo>>");
	 		return( (Pila *)MAL);
	 	} 
	 
	 	nvo -> eltos = ( char * ) malloc ( sizeof( char ) * size );
	 
	 	
	 	if ( nvo -> eltos == NULL )
	 		puts("\n\t<<fallo malloc nvo->eltos>>");
	 	
	 	else
	 	 {	
	 	  nvo -> size = size;
	 	  nvo -> tope = 0;
	 	  puts("\n\t<<pila hecha>>");
	 	 } 
	 	 
	 	return nvo;
	
	}
	

/*Funcion para colocar un elemento en la pila*/ 

	Pila *
	fpush(Pila * P, char dato)
	{
	
		//verificar que la pila no este llena
		if(P -> tope == P -> size-1)
		{
		 puts("\n\t<<la pila esta llena>>");
		 return (Pila *) NULL;
		} 
		
		else 
		{
		 
		 P -> eltos[P->tope]=dato;
		 P -> tope = P -> tope+1;
		 printf("\n\t<<se grabo un elemento %c en la pila>>",dato);
		 return P;
		
		}
		 
	}

/*Funcion para moverse por la pila */

	Pila *
	fpop(Pila * P )
	{
		if(fvacia(P))
		{
			puts(",\n\t<<la pila esta vacia>>");
			 return (Pila *) NULL;	
		} 
		
		P->tope=P->tope-1;
		return P;
		
	}

/*Funcion para obtener el valor que hay en la pocisicion actual de la pila*/

	char 
	ftop(Pila * P)
	{	
		return P->eltos[P->tope-1];
	}




/*Funcion que libera la memoria y destruye la pila */

	void 
	destruye(Pila *P)
	{
	 free(P->eltos);
	 free(P);
	puts("\n\t<<memoria libre :) >>\n");
	} 
