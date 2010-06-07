 #include<stdio.h>
  #include "../../encabezados/interfazListaEmp.h"
 
 Empleado emps[]={
{"Alejandro",10,0.0,0.0},
{"Benito",20,20.0,15.0},
{"Carlos",30,20.0,0.0},
{"Damian",40,10.0,15.0},
{"Ernesto",30,0.0,0.0},
{"Fabian",30,10.0,0.0},
{"Gabriel", 30, 20.0, 15.0},
{"Homero",40, 10.0, 0.0},
{"Juan", 10, 0.0, 10.0},
{"Gabriel", 30, 20.0, 10.0},
{"Miguel",20,20.0,0.0},
{"Oscar",50,20.0,0.0},
{"Pablo",40,10.0,0.0},
{"Rafael",30,0.0,0.0},
{"Simon",30,10.0,0.0},
{"Tobias",30,20.0,15.0},
};

NodoL *cab=NULL;
NodoL *cab1=NULL;
NodoL *satis=NULL;
NodoL *satis1=NULL;
NodoL *satis2=NULL;
NodoL *satis3=NULL;
NodoL *satis4=NULL;



int main(main)
{
    Empleado *e;
    NodoL *enc;
    
    e=creaEmpleado( emps[0].nombre, emps[0].edad,emps[0].salario, emps[0].bono );
    cab=creaNodoL((void *)e,cab);
    e=creaEmpleado( emps[1].nombre, emps[1].edad,emps[1].salario, emps[1].bono );
    cab=creaNodoL((void *)e,cab);
    e=creaEmpleado( emps[2].nombre, emps[2].edad,emps[2].salario, emps[2].bono );  
    cab=creaNodoL((void *)e,cab);
    e=creaEmpleado( emps[3].nombre, emps[3].edad,emps[3].salario, emps[3].bono );
    cab=creaNodoL((void *)e,cab);
    
    imprime(cab,imprimeEmp);
    
    puts("clona");
    clonar(cab,&cab1,clonaEmple);
    imprime(cab1,imprimeEmp);
    
  
    enc=find(cab,(void *)&emps[2],igualEmpleado);
    imprimeEmp(enc->info);
    enc=find(cab,(void *)&emps[3],igualEmpleado);
    imprimeEmp(enc->info);
    
    putchar('\n');
    remueve(&cab);
    imprime(cab,imprimeEmp);
    
    putchar('\n');
    remueve(&cab);
    imprime(cab,imprimeEmp);
    
    putchar('\n');
    remueve(&cab);
    imprime(cab,imprimeEmp);
    
    putchar('\n');
    remueve(&cab);
    imprime(cab,imprimeEmp);
    
    remueve(&cab);
    
    return 0;
}

/*
int main()
{
    Empleado *e;
    creaPila(&cab);
    e=creaEmpleado( emps[0].nombre, emps[0].edad,emps[0].salario,emps[0].bono);
    push(&cab,e);
    e=creaEmpleado( emps[1].nombre, emps[1].edad,emps[1].salario,emps[1].bono);
    push(&cab,e);
    e=creaEmpleado( emps[2].nombre, emps[2].edad,emps[2].salario,emps[2].bono);
    push(&cab,e);
    e=creaEmpleado( emps[3].nombre, emps[3].edad,emps[3].salario,emps[3].bono);
    push(&cab,e);
    imprimeEmp(pop(&cab)->info);
    imprimeEmp(pop(&cab)->info);
    imprimeEmp(pop(&cab)->info);
    imprimeEmp(pop(&cab)->info);
}
*/
