#include "../encabezados/interfazCola.h"
#include<stdlib.h>
#include<stdio.h>

NodoCola * 
f_agragarNodo(NodoCola ** ptr_Head, NodoCola ** ptr_Tail, void * dato)
{
   NodoCola * nuevo; //Una variable apuntador a Tipo NodoCola
   nuevo = ( NodoCola * ) malloc( sizeof(NodoCola) *1 ); //Asigno la direccion de la nueva memoria reservada.
	
   if(nuevo)
   {
	nuevo->dato = dato;
	nuevo->ptr_Siguiente = NULL;

	if( !(*ptr_Head) )
	 	(*ptr_Head) = nuevo;
	else
		(*ptr_Tail)->ptr_Siguiente = nuevo;

	(*ptr_Tail) = nuevo;

	return nuevo;



   }
   else
   {
     printf("\n\t<No hay suficiente memoria para crear un nodo>");
     return (NodoCola *) NULL;
   }

	
}

void * 
f_eliminarNodo(NodoCola ** ptr_Head, NodoCola ** ptr_Tail)
{
   NodoCola * temporal;
   void * valor;

	valor = (*ptr_Head)->dato;
	temporal = (*ptr_Head);
	
	(*ptr_Head) = (*ptr_Head)->ptr_Siguiente;

	if( !(*ptr_Head) )
		(*ptr_Tail) = NULL;
	
	free(temporal);

	return valor;	

}

void f_imprimeCola(NodoCola ** ptr_Head, void (*f)(void *) )
{

   NodoCola * nuevo;

   if(!(*ptr_Head))
	printf("\n\nLA Cola Abstracta esta vacia !");
   else
   {	
	nuevo = (*ptr_Head);	
	while( nuevo )
	{
	  
	  (*f)( nuevo->dato );		 
		
	 nuevo= nuevo->ptr_Siguiente;
	}

	printf(" NULL \n\n");
   }
}


