struct opera
 {
   char operador;
   int ( *f ) (void *, void *);
  
 };
 
typedef struct opera NodoOpera;

NodoOpera * creaArbOpera(char O, int ( *f ) (void *, void *));

int evalua(NodoArbol * raiz, NodoL * p, void * dato);

NodoL * findGeneral(NodoArbol * raiz, NodoL * inicio, void * key);






