
#include "../../encabezados/interfazArbolB.h"
#include <stdio.h>
#include<string.h>

int main(void)
{
      
      NodoArbol * ptr_NodoActual = (NodoArbol *) NULL;
     
      printf("\n\t\t\t.::PROGRAMA DE ARBOL BINARIO QUE ADIVINA UN ANIMAL::.");
     printf("\n\t\t\t\t\t(introduce 'q' para salir)\n");
    
      ptr_NodoActual=arbInicial();
      
      do
      printf("[Raiz]");
     while (Recursiva(&ptr_NodoActual));
       
    
    
	printf("\n");
 
     return 0; 
 
}
