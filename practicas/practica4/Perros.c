#include "../../encabezados/interfazPerros.h"
#include<stdio.h>
#include "../../encabezados/DBPerros.h"
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
    
    printf("\n\t\t\t.::PROGRAMA DE TIPOS DE DATOS PERROS::.\n");
    printf("\nlista de perros almacenados: \n\n");
    
    Perro *e;
    i=0;
    while( i<30 )
    {
      e=creaPerro( perritos[i].nombre, perritos[i].raza, perritos[i].edad, perritos[i].genero );
      cab=creaNodoL((void *)e,cab);
      i++;
    }
    
    imprime(cab,imprimePerro);

    //===================================================    
    puts("\n===Clona la Lista de los perros===");
      clonar(cab,&cab1,clonaPerro);
    puts("\n====Esta es la lista de perros clonada===");
      imprime(cab1,imprimePerro);
    
      printf("\nhago una consulta de cuantos perros se llaman igual a %s: \n\n",perritos[0].nombre);

      do
      {
	    if( ! (enc=find(cab1,(void *)&perritos[0],igualPerroNombre)) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab1,enc);
		 satis1=creaNodoL((void *) enc->info, satis1);
	    }
      }while(enc);
      
//===================================================      
      
      puts("\n===Clona la Lista de los perros===");
      clonar(cab,&cab2,clonaPerro);
      
       printf("\nhago una consulta de cuantos perros coinciden con la raza: %s: \n\n",perritos[10].raza);

      do
      {
	    if( ! (enc=find(cab2,(void *)&perritos[10],igualPerroRaza)) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab2,enc);
		 satis2=creaNodoL((void * )enc->info, satis2);
	    }
      }while(enc);

//===================================================    

       puts("\n===Clona la Lista de los perros===");
      clonar(cab,&cab3,clonaPerro);
      
       printf("\nhago una consulta de cuantos perros coinciden con la edad: %d: \n\n",perritos[10].edad);

      do
      {
	    if( ! (enc=find(cab3,(void *)&perritos[10],igualPerroEdad)) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab3,enc);
		 satis3=creaNodoL((void * )enc->info, satis3);
	    }
      }while(enc);
      
//===================================================    

     puts("\n===Clona la Lista de los perros===");
      clonar(cab,&cab4,clonaPerro);
      
       printf("\nhago una consulta de cuantos perros coinciden con el genero: %c: \n\n",perritos[10].genero);

      do
      {
	    if( ! (enc=find(cab4,(void *)&perritos[10],igualPerroGenero)) )
		  printf("\nLla no hay mas elemetos elemetos \n\n");
	    else
	    {
		imprimePerro(enc->info);
		 remueve_(&cab4,enc);
		 satis4=creaNodoL((void * )enc->info, satis4);
	    }
      }while(enc);
      
//===================================================    

        printf("Resultados de las busquedas en listas de los elementos que cumplieron la condicion\n");
	
	 printf("==NOMBRES IGUALES==\n\n");imprime(satis1,imprimePerro);puts("\n\n");
	 printf("==RAZAS IGUALES==\n\n");imprime(satis2,imprimePerro); puts("\n\n");
	 printf("==EDADES IGUALES==\n\n");imprime(satis3,imprimePerro);puts("\n\n");
	 printf("==GENEROS IGUALES==\n\n");imprime(satis4,imprimePerro);puts("\n\n");
	
    
    return 0;
  }
  
  