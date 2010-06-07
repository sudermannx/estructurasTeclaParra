#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../encabezados/interfazPerros.h"

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
	NodoL *p =NULL;
	for(p=inicio;p;p=p->sig)
             if(!(*igual)(p->info, key))
		return p;
	return p;
}

//=============================================

Perro *creaPerro( char nombre[100],
    char raza[100],
    int edad,
    char genero
)
{
   Perro *nvo;
   nvo=(Perro *)malloc(sizeof(Perro *));
   if(!nvo){
	puts("no hay memoria para un Perro");
        return (Perro *)NULL;
   }
   
   strcpy(nvo->nombre,nombre);
   strcpy(nvo->raza,raza);
   nvo->edad=edad;
   nvo->genero=genero;
   
   return nvo;
}

void imprimePerro(void *info){
   Perro *e=(Perro *)info;
   printf("nombre:");puts(e->nombre);
   printf("edad=%d\n",e->edad);
   printf("genero=%c\n",e->genero);
   printf("raza=%s\n",e->raza);
   printf("------------------\n");
}

void *clonaPerro(void *info){
    Perro *e=(Perro *)info;
   return creaPerro( e->nombre, e->raza, e->edad, e->genero);
}

int igualPerroNombre(void *p1, void *p2){
	Perro *e1=(Perro*)p1;
	Perro *e2=(Perro*)p2;
	return strcmp(e1->nombre, e2->nombre);
}

int igualPerroRaza(void *p1, void *p2){
	Perro *e1=(Perro*)p1;
	Perro *e2=(Perro*)p2;
	return strcmp(e1->raza, e2->raza);
}

int igualPerroGenero(void *p1, void *p2){
	Perro *e1=(Perro*)p1;
	Perro *e2=(Perro*)p2;
	return !(e1->genero == e2->genero);
}

int igualPerroEdad(void *p1, void *p2){
	Perro *e1=(Perro*)p1;
	Perro *e2=(Perro*)p2;
	return !(e1->edad == e2->edad);
}

