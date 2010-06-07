 
 struct nodoArbol
 {
  struct nodoArbol * ptr_izquierdo;
  void * dato;
  struct nodoArbol * ptr_derecho;
 };
 
 typedef struct nodoArbol NodoArbol;
 
 
 NodoArbol * 
 CreaNodoArb(void * dato, NodoArbol * ptr_izquierdo, NodoArbol * ptr_derecho);
 
 NodoArbol * arbInicial(void);
 
 NodoArbol * Recursiva(NodoArbol ** NodoActual);

 

 
 
 