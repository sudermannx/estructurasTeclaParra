 
struct nodoL {
   void *info;
   struct nodoL *sig;
};

typedef struct nodoL NodoL;

struct empleado {
   char nombre[100];
   int edad;
   float salario;
   float bono;
};

typedef struct empleado Empleado;

//===================================

NodoL *creaNodoL(void *info, NodoL *sig );

NodoL *remueve(NodoL **cab);

NodoL *remueve_(NodoL **cab,  NodoL *p);

void imprime(NodoL *inicio, void (*f)(void *));

void clonar(NodoL *inicio1, NodoL **inicio2,void *(*copyInfo)(void *));

NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *));

//=================================

Empleado *creaEmpleado( char nombre[100],
   int edad,
   float salario,
   float bono
);

void imprimeEmp(void *info);

void *clonaEmple(void *info);

int igualEmpleado(void *p1, void *p2);

/*
NodoL *creaPila(NodoL **stack);

int estaVacia(NodoL *stack);

NodoL *push(NodoL **stack, void *dato);

void *top(NodoL *stack);

NodoL *pop(NodoL **stack);
*/


