#include<stdio.h>

#include "../../encabezados/interfazPila.h"
#define TAM 1000
	
	int main(int argc, char * argv [])
	{
		
		int alerta1=0, alerta2=0;		
		char caracter ;
		Pila * pilita1; //Almacena los parentesis Abiertos 
		Pila * pilita2; //Almacena las llaves Abiertas
		
		FILE * stream;
		
	   	   printf("\n\t\t\t.::PROGRAMA DE ANALISIS DE ARCHIVO::.\n");
				
			pilita1=fcreaP(TAM);
			pilita2=fcreaP(TAM);
			
			
			if( ( stream=fopen(argv[1] ,"r") ) == NULL )
			{
				printf("\n\tNo se pudo leer el archivo\n\n");
				return -1;
			}
			else
			{

				
				while(!feof(stream))
				
					if( (caracter=fgetc(stream)) == '(' ) 
						pilita1=fpush(pilita1,caracter); 
				
				
				rewind(stream); 
				while(!feof(stream))

					if( (caracter=fgetc(stream)) == '{' ) 
						 pilita2=fpush(pilita2,caracter); 

				
				rewind(stream);			
				while(!feof(stream))
					
					if( (caracter=fgetc(stream)) == ')') 
					{	
						if( fvacia(pilita1) )
							alerta1=1;
						else 
							pilita1=fpop(pilita1);
					}
	

				rewind(stream);			
				while(!feof(stream))
					
					if( (caracter=fgetc(stream)) == '}') 
					{	
						if( fvacia(pilita2) )
							alerta2=1;
						else 
							pilita2=fpop(pilita2);
					}	
						
				
				
				if ( alerta1 == 1 )
					printf("\n\n\t\t -Existen Parentesis Inconsistentes *-\n");
				else
					if(fvacia(pilita1))
						printf("\n\n\t\t -Todos Los Parentesis Son Consistentes-\n ");
					else
						printf("\n\n\t\t -Existen Parentesis Inconsistentes-\n");
				
				if ( alerta2 == 1 )
					printf("\n\n\t\t -Exixten Llaves Inconsistentes *-\n\n");
				else
					if(fvacia(pilita2))
						printf("\n\n\t\t -Todas Las Lleves Son Consistentes-\n\n");
					else
						printf("\n\n\t\t -Exixten Llaves Inconsistentes-\n\n");
				
						
		
			}
			
			fclose(stream);
			
			destruye(pilita1);
			destruye(pilita2);
		
			printf("\n");				
		 	return 0;	
	}
