//encabezados

//Definicon de una pila de enteros

	struct pila
	{
	 int tope;
	 char * eltos;
	 int size;
	};

   typedef struct pila Pila;
   
   Pila * fcreaP( int size );
   Pila * fpush(Pila * P, char dato);
   int fvacia(Pila * P);
   char ftop(Pila * P);
   void destruye(Pila * P);
   Pila * fpop(Pila * P);