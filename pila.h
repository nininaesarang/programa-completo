/*Inclusión de las librerías necesarias*/
#include <stdlib.h>
/*Definición del tamaño de la pila*/
#define MAX_ELEMENTOS 10

/*Declaración de la pila para int*/
typedef struct pilaInt
{
    int datosInt[MAX_ELEMENTOS];
    int totalInt;
    int indiceInt;
}PilaInt;
/*Función para agregar a la pilaInt*/
int push_int(PilaInt *pila_num, int dato)
{
    if(pila_num->totalInt<MAX_ELEMENTOS)
    {
        pila_num->datosInt[pila_num->indiceInt]=dato;
        pila_num->indiceInt++;
        pila_num->totalInt++;
        return 1;
    }   
    else{return 0;}
}

/*Función para eliminar un elemento de la pilaInt*/
int pop_int(PilaInt *pila_num)
{
    int x;
    if(pila_num->totalInt>0)
    {
        x=pila_num->datosInt[pila_num->indiceInt-1];
        pila_num->indiceInt--;
        pila_num->totalInt--;
        return x;
    }
    else{return -1;}
}

/*Declaración de la pila para chart*/

typedef struct pila
{
    int indice;
    int total;
    char datos[MAX_ELEMENTOS];
}Pila;

/*Declaración del tamaño de la pila*/

Pila * crear()
{
    Pila *p;
    p=(Pila *)malloc(sizeof(Pila));
    p->indice=0;
    p->total=0;
    return p;
}

/*Función para definir si la pila está vacía o no*/

int vacio(Pila pila)
{
    if(pila.total==0){return 1;}
    else{return 0;}
}

/*Función para definir si la pila está llena*/

int lleno(Pila pila)
{
    if(pila.total==MAX_ELEMENTOS){return 1;}
    else{return 0;}
}

/*Función para ingresar elementos a la pila*/

int push(Pila *pila, char dato)
{
    if(pila->total<MAX_ELEMENTOS)
    {
        pila->datos[pila->indice]=dato;
        pila->indice++;
        pila->total++;
        return 1;
        
    }
    else{return 0;}
}

/*Función para eliminar un elemento de la pila*/

char pop(Pila *pila)
{
    int aux;
    if(pila->total>0)
    {
        aux=pila->datos[pila->indice-1];
        pila->indice--;
        pila->total--;
        return aux;
    }
    else{return -1;}
}