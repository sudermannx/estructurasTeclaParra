#include<stdio.h>

#include "../../encabezados/interfazPila.h"
#define TAM 100
	
	int main(void)
	{
	
		char cadena[TAM];
		int i;
		Pila *pilita;
		int ascii,ascii2;
		
		
	   	   printf("\n\t\t\t.::PROGRAMA DE PALINDROMO::.\n");
			
		   printf("\n\t Introduce una cadena--->");
				
				if( gets(cadena)!= NULL )
					printf("\n\n\tLA CADENA ES :%s",cadena);
				else
					printf("\n\tLa cadena no se obtuvo");
				
			pilita=fcreaP(TAM);
			
		   printf("\n\tAsisgnando valores a la pila");
			 
			 
			i=0;				
			while(cadena[i]!= '\0') //este ciclo es para no filtrar los espacios
			{
				
				if(cadena[i]!=' ')
				
				   pilita=fpush(pilita,cadena[i]);			
			
				++i;
			}
			
		   printf("\n\tTermino el proceso de asignacion");
		   printf("\n\n\tel elemento de la cima es:%c",ftop(pilita));			
			
		   printf("\n\n\tProceso de comprobacion:");
			
			
			i=0;				
			while(!(fvacia(pilita) ) ) //este ciclo es para recorrer la pila mientras no se vacie
			{
				
				if(cadena[i]!=' ') //con esto ago que solo se comparen los caracteres y se ignore los espacios
				{
				
				
				//===============================Filtra las mayusculas y las pasa a minusculas
				ascii= (int) ( cadena[i] );
					
					if(ascii >= 65 && ascii <= 90) //si se cumple entonces es mayuscula
					{
					 ascii=ascii+32; //lo convierte a minuscula 
					}

				ascii2= (int) (ftop(pilita));
					
					if(ascii2 >= 65 && ascii2 <= 90) //si se cumple entonces es mayuscula
					{

					 ascii2=ascii2+32; //lo convierte a minuscula
					}

				//=============================>
					
				  // if( ( ftop( pilita ) )!= cadena[i] ) //obtiene el elemento de la pila siguiente y si es diferente con la cadena quiere decir que no es palindromo
				  
				   if( ( ascii2 )!= ascii ) //obtiene el elemento de la pila siguiente y si es diferente con la cadena quiere decir que no es palindromo
				   {
					printf("\n\n\t--->Se rompio la condicion PLT Esta cadena NO es un palindromo<---");
					printf("\n\t--->caracter # %d-->%c del arreglo, NO coincide con el caracter # %d--%c de la pila <---\n", i+1, cadena[i], pilita->tope, pilita->eltos[pilita->tope-1]);
					destruye(pilita);
					return 0;
				   }  
				
				   else
					printf("\n\t--->caracter # %d-->%c del arreglo, si coincide con el caracter # %d-->%c de la pila <---", i+1, cadena[i], pilita->tope, pilita->eltos[pilita->tope-1]);
		
				pilita=fpop(pilita);
			
				} 
			i++;		
			}	
			
		   printf("%s","\n\n\t\t<<--El proceso termino con exito por lo tanto SI ES PALINDROMO-->>");
			
			
			destruye(pilita);		
			printf("\n");				
		 	return 0;	
	}
