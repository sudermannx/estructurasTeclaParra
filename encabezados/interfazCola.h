//Definicon de la esctuctura de un NodoCola

	struct nodoCola
	{
	  void * dato;
	  struct nodoCola * ptr_Siguiente;
	};
	 
	 typedef struct nodoCola NodoCola;

NodoCola * f_agragarNodo(NodoCola ** ptr_Head, NodoCola ** ptr_Tail, void * dato);

void * f_eliminarNodo(NodoCola ** ptr_Head, NodoCola ** ptr_Tail);

void f_imprimeCola(NodoCola ** ptr_Head, void (*f)(void *) );


