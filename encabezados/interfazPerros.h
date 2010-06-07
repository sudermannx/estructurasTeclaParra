struct nodoL 
{
   void *info;
   struct nodoL *sig;
};

typedef struct nodoL NodoL;

struct perro 
{
   char nombre[100];
   char raza[100];
   int edad;
   char genero;
   
};

typedef struct perro Perro;

//================================

NodoL *creaNodoL(void *info, NodoL *sig );

NodoL *remueve(NodoL **cab);

NodoL *remueve_(NodoL **cab,  NodoL *p);

void imprime(NodoL *inicio, void (*f)(void *));

void clonar(NodoL *inicio1, NodoL **inicio2,void *(*copyInfo)(void *));

NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *));

//================================

Perro *creaPerro( char nombre[100],
   char raza[100],
   int edad,
   char genero
);

void imprimePerro(void *info);

void *clonaPerro(void *info);

int igualPerroNombre(void *p1, void *p2);
int igualPerroRaza(void *p1, void *p2);
int igualPerroGenero(void *p1, void *p2);
int igualPerroEdad(void *p1, void *p2);
