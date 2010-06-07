#include "../../encabezados/interfazCola.h"
#include "../../encabezados/imprimeTipos.h"

#include<stdio.h>

	int main(void)
	{
		NodoCola * ptr_Cabezita = NULL;
		NodoCola * ptr_Talonsito = NULL;
		int i;
		char * cadena = "RicardoOctavio"; 

		printf("\n\t\t\t.::PROGRAMA DE COLA ABSTRACTA::.\n");

		printf("\n\tPrimero grabo la cadena [ %s ] en la pila\n\n\t ",cadena);
		
		i=0;		
		while( *(cadena+i) )
			f_agragarNodo( &ptr_Cabezita, &ptr_Talonsito,(void *) (cadena+(i++)) );
		
		f_imprimeCola( &ptr_Cabezita, imprime_char);
		
		printf("\n\tDespues quito uno a uno los elementos de la pila\n\n\t ");
		
		f_eliminarNodo(&ptr_Cabezita, &ptr_Talonsito);	
		
		f_imprimeCola( &ptr_Cabezita, imprime_char);
		

		//while(ptr_Cabezita)
		//{
		  //cosa=f_eliminarNodo(&ptr_Cabezita, &ptr_Talonsito);	

		//printf("\n\tel valor que se elimino de la Cola fue %c\n\t", *((char *)cosa) );

		 //	f_imprimeCola( &ptr_Cabezita, imprime_char);				
			
		
		
	
		//}

	 return 0;
	}
