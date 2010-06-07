#include "../encabezados/interfazArbolB.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

NodoArbol * 
CreaNodoArb(void * dato, NodoArbol * ptr_izquierdo, NodoArbol * ptr_derecho)
 {
  
  NodoArbol * nvo;
  nvo = ( NodoArbol *) malloc( sizeof( NodoArbol * )  );
  
    if(nvo)
    {
      
      ( nvo )->dato =  (void *)dato; 
      ( nvo )->ptr_izquierdo = ptr_izquierdo;
     
      (  nvo )->ptr_derecho = ptr_derecho;
      
      return nvo;
    }
    else
    {
      printf("\n\t==No hah memoria==\n\t");
      return ( NodoArbol * ) NULL;
    }
  
 }
 
 NodoArbol *
 arbInicial(void)
 {
  
   NodoArbol * h1, * h2, * h3; //Hojas iniciales del Arbol
   NodoArbol * n1, * n2; //Nodos Inciales para las dos preguntas
   char * a1, * a2, * a3, *p1, *p2;  //Animales y pregutas iniciales

   a1 = strdup("Leon"); 
   a2 = strdup("Cebra");
   a3 = strdup("Delfin");
   
   h1 = CreaNodoArb( (void *) a1, ( NodoArbol * ) NULL, (NodoArbol * ) NULL); 
   h2 = CreaNodoArb( (void *) a2, ( NodoArbol * ) NULL, (NodoArbol * ) NULL);
   h3 = CreaNodoArb( (void *) a3, ( NodoArbol * ) NULL, (NodoArbol * ) NULL);
   
   p1 = strdup("Terrestre");
   p2 = strdup("Carnivoro ");
   
   n2 = CreaNodoArb( (void *) p2, h1, h2);
   n1 = CreaNodoArb( (void *) p1, n2, h3);
   
   return n1;
   
 }

NodoArbol * Recursiva(NodoArbol ** ptr_NodoActual)
{
  char opc='\0';
  char animalNvo[100], preguntaNvo[100];
  char * preguntaN, * animalN;
    
  NodoArbol * ptr_NodoPadreNvo = (NodoArbol *) NULL;
  NodoArbol * ptr_NodoHijoNvo = (NodoArbol *) NULL;
   
    if(   ( (*ptr_NodoActual)->ptr_izquierdo) && ( (*ptr_NodoActual)->ptr_derecho)  ) //si llego a una pregunta
      {  
	
	do{
		printf("[PREGUNTA]");
		
		printf("\n\n\t==>Es un Animal -%s- ?[ s/n ]",(char *) (*ptr_NodoActual)->dato );
		printf("-->"); 
	     opc=getc(stdin);
	     while(getchar()!='\n');
		 switch( opc )
		{
		  
		  case 's' ://(*ptr_NodoActual)->ptr_izquierdo=
		     return Recursiva(&((*ptr_NodoActual)->ptr_izquierdo));
		  break;
		  
		  case 'n' ://(*ptr_NodoActual)->ptr_derecho=
		    return Recursiva(&((*ptr_NodoActual)->ptr_derecho) );
		  break;
		  
		  case 'q':
		    return (NodoArbol *) NULL;
		  break;
		  
		  default:printf("\n<Opcion Incorrecta>\n");
		}
		
	}while( 1 );
	
      }
      else //si llego a una hoja
      {
		
	do{
		printf("[HOJA]");
		printf("\n\n\t(Hoja)El animal que pensaste es -%s- ?[ s/n ]",(char *) ((*ptr_NodoActual)->dato));
		printf("-->"); //scanf("%c",&opc); 
	   
	     opc=getc(stdin);
	     while(getchar()!='\n');
		 switch( opc )
		{
		   
		    case 's' : printf("\n\t\t~El programa adivino exitosamente el animal que pensaste~\n");return *ptr_NodoActual; 
		     break;
		  
		    case 'n' :
		      printf("\n\t\t=>Ok, en que animal pensaste-->");
				  scanf("%s",animalNvo);
		      printf("\n\t\t=>Menciona una dierencia entre %s y %s-->",(char * ) (*ptr_NodoActual)->dato, animalNvo);
				  scanf("%s",preguntaNvo);
		     
				   preguntaN = strdup(&preguntaNvo);
				   animalN = strdup(&animalNvo);
		      
			  ptr_NodoHijoNvo = CreaNodoArb( (void *) (animalN), (NodoArbol * ) NULL ,  (NodoArbol * )NULL );
			  ptr_NodoPadreNvo = CreaNodoArb( (void *) (preguntaN), ptr_NodoHijoNvo,  *ptr_NodoActual);
					      
			  *ptr_NodoActual =  ptr_NodoPadreNvo;
					
					      
			printf("\n\t\t~El programa a aprendido un nuevo animal llamado %s y es %s~\n\n",  animalN, preguntaN);
				
				return *ptr_NodoActual;
		  break;
		  
		    case 'q':
			    return (NodoArbol *) NULL;
		    break;
		  
		    default:printf("\n<Opcion Incorrecta>\n");
		}
		
	}while( 1 );
	
      }
      
  }
 
 
 
