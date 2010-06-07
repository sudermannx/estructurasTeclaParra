#include<stdio.h>
#include "../../encabezados/interfazPerros.h"
#include "../../encabezados/interfazArbolB.h"
#include "../../encabezados/interfazPerrosM.h"
#include "../../encabezados/DBPerrosExtend.h"


int i=0;

NodoL *cab=NULL;
NodoL *cab1=NULL, *cab2=NULL, *cab3=NULL, *cab4=NULL;
NodoL *satis=NULL;
NodoL *satis1=NULL;
NodoL *satis2=NULL;
NodoL *satis3=NULL;
NodoL *satis4=NULL;
 
 int main(void)
  {
    NodoL *enc;
    NodoArbol * a1, * a2, * a3;
    
    printf("\n\t\t\t.::PERROS APLICACION DE ARBOL DE OPERACIONES::.\n");
    printf("\nlista de perros almacenados: \n\n");
    
    Perro *e;
    i=0;
    while( i < 60 )
    {
      e=creaPerro( perritos[i].nombre, perritos[i].raza, perritos[i].edad, perritos[i].genero );
      cab=creaNodoL((void *)e,cab);
      i++;
    }
    imprime(cab,imprimePerro);
    
       //==================================================================================>  
    
    puts("\n\n\t\t\t\t===Creo un nuevo arbol de proposiciones logicas de la forma:===");
    puts("\n\t\t\t   ===( igualPerroEdad ) |  [ ( igualPerroRaza )&( igualPerroGenero ) ]===\n\n");
    
    a1 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a2 = CreaNodoArb(creaArbOpera(' ',igualPerroRaza), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a3 = CreaNodoArb(creaArbOpera(' ',igualPerroGenero), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    
    a2 = CreaNodoArb(creaArbOpera('&', NULL), ( NodoArbol * ) a2, ( NodoArbol *) a3 );
    a1 = CreaNodoArb(creaArbOpera('|',NULL), ( NodoArbol * ) a1, ( NodoArbol *) a2 );
    
    puts("\n\t\t\t\t\t\t===Clono la Lista de los Perros===");
    clonar(cab,&cab1,clonaPerro);
    
     printf("\nEl Perro llave de Busqueda es el Siguiente:\n\n");
     printf("------------------\n");
     printf("nombre: %s\n", perritos[10].nombre);
     printf("edad=%d\n", perritos[10].edad);
     printf("genero=%c\n", perritos[10].genero);
     printf("raza=%s\n", perritos[10].raza);
     printf("------------------\n\n");
     
    puts("\n\t\t\t\t   ===Entonces la Proposicion de busqueda queda asi:===");
    printf("\n\t ==[ Buscar Todos los Perros que Tengan %d Anios O Perros que sean de razas %s Y sean %c ]==\n\n", perritos[10].edad, perritos[10].raza, perritos[10].genero );
      
    do
      {
	    if( ! ( enc=findGeneral( ( NodoArbol *)a1, (NodoL *)cab1, (void *)&perritos[10] )) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab1,enc);
		 satis1=creaNodoL((void *) enc->info, satis1);
	    }
      }while(enc);
    
       //==================================================================================>    
    
    puts("\n\n\t\t\t\t===Creo un nuevo arbol de proposiciones logicas de la forma:===");
    puts("\n\t\t\t   ===( igualPerroEdad ) |  [ ( igualPerroEdad )&( igualPerroGenero ) ]===\n\n");
    
    a1 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a2 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a3 = CreaNodoArb(creaArbOpera(' ',igualPerroGenero), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    
    a2 = CreaNodoArb(creaArbOpera('&', NULL), ( NodoArbol * ) a2, ( NodoArbol *) a3 );
    a1 = CreaNodoArb(creaArbOpera('|',NULL), ( NodoArbol * ) a1, ( NodoArbol *) a2 );
    
    puts("\n\t\t\t\t\t\t===Clono la Lista de los Perros===");
    clonar(cab,&cab2,clonaPerro);
    
     printf("\nEl Perro llave de Busqueda es el Siguiente:\n\n");
     printf("------------------\n");
     printf("nombre: %s\n", perritos[20].nombre);
     printf("edad=%d\n", perritos[20].edad);
     printf("genero=%c\n", perritos[20].genero);
     printf("raza=%s\n", perritos[20].raza);
     printf("------------------\n\n");
     
    puts("\n\t\t\t\t   ===Entonces la Proposicion de busqueda queda asi:===");
    printf("\n\t ==[ Buscar Todos los Perros que Tengan %d Anios O Perros que sean de edades %d Y sean %c ]==\n\n", perritos[20].edad, perritos[20].edad, perritos[20].genero );
      
    do
      {
	    if( ! ( enc=findGeneral( ( NodoArbol *)a1, (NodoL *)cab2, (void *)&perritos[20] )) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab2,enc);
		 satis2=creaNodoL((void *) enc->info, satis2);
	    }
      }while(enc);
    
             //==================================================================================>    
    
    puts("\n\n\t\t\t\t===Creo un nuevo arbol de proposiciones logicas de la forma:===");
    puts("\n\t\t\t   ===( igualPerroEdad ) &  [ ( igualPerroRaza ) | ( igualPerroGenero ) ]===\n\n");
    
    a1 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a2 = CreaNodoArb(creaArbOpera(' ',igualPerroRaza), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a3 = CreaNodoArb(creaArbOpera(' ',igualPerroGenero), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    
    a2 = CreaNodoArb(creaArbOpera('|', NULL), ( NodoArbol * ) a2, ( NodoArbol *) a3 );
    a1 = CreaNodoArb(creaArbOpera('&',NULL), ( NodoArbol * ) a1, ( NodoArbol *) a2 );
    
    puts("\n\t\t\t\t\t\t===Clono la Lista de los Perros===");
    clonar(cab,&cab3,clonaPerro);
    
     printf("\nEl Perro llave de Busqueda es el Siguiente:\n\n");
     printf("------------------\n");
     printf("nombre: %s\n", perritos[30].nombre);
     printf("edad=%d\n", perritos[30].edad);
     printf("genero=%c\n", perritos[30].genero);
     printf("raza=%s\n", perritos[30].raza);
     printf("------------------\n\n");
     
    puts("\n\t\t\t\t   ===Entonces la Proposicion de busqueda queda asi:===");
    printf("\n\t ==[ Buscar Todos los Perros que Tengan %d Anios Y Perros que sean de razas %s O sean %c ]==\n\n", perritos[30].edad, perritos[30].raza, perritos[30].genero );
      
    do
      {
	    if( ! ( enc=findGeneral( ( NodoArbol *)a1, (NodoL *)cab3, (void *)&perritos[30] )) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab3,enc);
		 satis3=creaNodoL((void *) enc->info, satis3);
	    }
      }while(enc);
    
      //==================================================================================>    
    
    puts("\n\n\t\t\t\t===Creo un nuevo arbol de proposiciones logicas de la forma:===");
    puts("\n\t\t\t   ===( igualPerroEdad ) &  [ ( igualPerroEdad )&( igualPerroGenero ) ]===\n\n");
    
    a1 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a2 = CreaNodoArb(creaArbOpera(' ',igualPerroEdad), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    a3 = CreaNodoArb(creaArbOpera(' ',igualPerroGenero), ( NodoArbol * ) NULL, ( NodoArbol *) NULL );
    
    a2 = CreaNodoArb(creaArbOpera('&', NULL), ( NodoArbol * ) a2, ( NodoArbol *) a3 );
    a1 = CreaNodoArb(creaArbOpera('&',NULL), ( NodoArbol * ) a1, ( NodoArbol *) a2 );
    
    puts("\n\t\t\t\t\t\t===Clono la Lista de los Perros===");
    clonar(cab,&cab4,clonaPerro);
    
     printf("\nEl Perro llave de Busqueda es el Siguiente:\n\n");
     printf("------------------\n");
     printf("nombre: %s\n", perritos[40].nombre);
     printf("edad=%d\n", perritos[40].edad);
     printf("genero=%c\n", perritos[40].genero);
     printf("raza=%s\n", perritos[40].raza);
     printf("------------------\n\n");
     
    puts("\n\t\t\t\t   ===Entonces la Proposicion de busqueda queda asi:===");
    printf("\n\t ==[ Buscar Todos los Perros que Tengan %d Anios Y Perros que sean de edades %d Y sean %c ]==\n\n", perritos[40].edad, perritos[40].edad, perritos[40].genero );
      
    do
      {
	    if( ! ( enc=findGeneral( ( NodoArbol *)a1, (NodoL *)cab4, (void *)&perritos[40] )) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab4,enc);
		 satis4=creaNodoL((void *) enc->info, satis4);
	    }
      }while(enc);
    
             //==================================================================================>   
    
    
    return 0;
  }
  
  
  