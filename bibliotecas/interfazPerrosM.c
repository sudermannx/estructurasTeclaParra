#include<stdlib.h>
#include<stdio.h>
#include "../encabezados/interfazPerros.h"
#include "../encabezados/interfazArbolB.h"
#include "../encabezados/interfazPerrosM.h"


NodoOpera * creaArbOpera(char O, int ( *f ) (void *, void *))
{

  NodoOpera * nvo;
 
  nvo = (NodoOpera *) malloc(sizeof (NodoOpera *) * 1 );
  
      if(nvo)
      {
	
      ( nvo )->operador = O;
      (nvo)->f = f;
      
	  return nvo;
      }
      else
      {
      printf("\n\t==No hah memoria==\n\t");
	  return ( NodoOpera * ) NULL;
      }
 
}

int evalua(NodoArbol * raiz, NodoL * p, void * dato)
{
    if(  ( (NodoOpera *)raiz->dato )->operador == '&'  )
	    return evalua(raiz->ptr_izquierdo,p,dato) && evalua(raiz->ptr_derecho,p,dato);
    
      if(  ( (NodoOpera *)raiz->dato )->operador == '|'  )
	    return evalua(raiz->ptr_izquierdo,p,dato) || evalua(raiz->ptr_derecho,p,dato);
      
      if(  ( (NodoOpera *)raiz->dato )->operador == ' '  )
      {
	
	 if(  ( (NodoOpera *)raiz->dato )->f == igualPerroNombre )
			return ! igualPerroNombre(p->info,dato);
			
	 if(  ( (NodoOpera *)raiz->dato )->f == igualPerroRaza )
			return ! igualPerroRaza(p->info,dato);
			
	 if(  ( (NodoOpera *)raiz->dato )->f == igualPerroGenero )
			return ! igualPerroGenero(p->info,dato);
			
	 if(  ( (NodoOpera *)raiz->dato )->f == igualPerroEdad )
			return ! igualPerroEdad(p->info,dato);
	
      }

}

NodoL * findGeneral( NodoArbol * raiz, NodoL * inicio, void * key)
{
 NodoL * p;
 
      for(p=inicio;p;p=p->sig)
	    if( evalua(raiz,p,key) )
	      return p;

    return p;
  
}