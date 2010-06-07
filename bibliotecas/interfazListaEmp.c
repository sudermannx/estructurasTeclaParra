#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../encabezados/interfazListaEmp.h"

//==================================

NodoL *creaNodoL(void *info, NodoL *sig ){
   NodoL *nvo;
   nvo=(NodoL *)malloc(sizeof(NodoL));
   if(!nvo){
	puts("no hay memoria para crear NodoL");
        return (NodoL *)NULL;
   }
   nvo->info=info;
   nvo->sig=sig;
   return nvo;
}

NodoL *remueve(NodoL **cab)
{
   NodoL *p;
   if(!*cab){
      puts("remueve: lista vacia");
      return (NodoL *)NULL;
   }
   p=*cab;
   *cab=p->sig;
   p->sig=(NodoL *)NULL;
   return p;
}

NodoL *remueve_(NodoL **cab,  NodoL *p)
{
   NodoL *q,*r;
   if(!*cab){
      puts("remueve: lista vacia");
      return (NodoL *)NULL;
   }
   if(p==*cab){
	*cab=p->sig;
	p->sig=(NodoL *)NULL;  
        return *cab;  
   }
   for(q=(*cab) , r=q->sig; r ;q=q->sig,r=r->sig){
	if(p==r){
             q->sig=r->sig;
             r->sig=(NodoL *)NULL;
             return *cab;
	}
   }
   return *cab;  
}

void imprime(NodoL *inicio, void (*f)(void *)){
   NodoL *p;
   
    if(!inicio){
      puts("imprime:lista vacia");
      return ;
   }
   for(p=inicio;p;p=p->sig)
      (*f)(p->info);
}


void clonar(NodoL *inicio1, NodoL **inicio2,void *(*copyInfo)(void *)){
   NodoL *p;
   
    if(!inicio1){
      puts("imprime:lista vacia");
      return ;
   }
   *inicio2=(NodoL *)NULL;
   for(p=inicio1;p;p=p->sig){
      *inicio2=creaNodoL((*copyInfo)(p->info), *inicio2);
   }
}

NodoL *find(NodoL  *inicio, void *key, int (*igual)(void *, void *)){
	NodoL *p;
	for(p=inicio;p;p=p->sig)
             if(!(*igual)(p->info, key))
		return p;
	return p;
}

//=============================================

Empleado *creaEmpleado( char nombre[100],
   int edad,
   float salario,
   float bono
)
{
   Empleado *nvo;
   nvo=(Empleado *)malloc(sizeof(Empleado));
   if(!nvo){
	puts("no hay memoria para un Empleado");
        return (Empleado *)NULL;
   }
   strcpy(nvo->nombre,nombre);
   nvo->edad=edad;
   nvo->salario=salario;
   nvo->bono=bono;
   return nvo;
}

void imprimeEmp(void *info){
   Empleado *e=(Empleado *)info;
   puts(e->nombre);
   printf("edad=%d\n",e->edad);
   printf("salario=%f\n",e->salario);
   printf("bono=%f\n",e->bono);
}

void *clonaEmple(void *info){
    Empleado *e=(Empleado *)info;
   return creaEmpleado( e->nombre, e->edad, e->salario, e->bono);
}

int igualEmpleado(void *p1, void *p2){
	Empleado *e1=(Empleado*)p1;
	Empleado *e2=(Empleado*)p2;
	return strcmp(e1->nombre, e2->nombre);
}

/*
NodoL *creaPila(NodoL **stack){
	*stack=(NodoL *)NULL;
	return *stack;
}

int estaVacia(NodoL *stack){
	return !stack;
}

NodoL *push(NodoL **stack, void *dato){
	*stack=creaNodoL(dato, *stack );
       return *stack; 
}

void *top(NodoL *stack){
	return stack->info;
}

NodoL *pop(NodoL **stack){
	return remueve(stack);
	
}
*/