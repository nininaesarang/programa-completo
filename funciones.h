/*Inclusión de librerías y la pila para el funcionamiento del código*/
#include "pila.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Función para declara el nivel de importancia de los operadores*/
int importancia(char operador)
{
    int nivel=0;
    switch(operador)
    {
        case '(': nivel = 0;
        break;
        case '+': nivel = 1;
        break;
        case '-': nivel = 1;
        break;
        case '*': nivel = 2;
        break;
        case '/': nivel = 2;
        break;
        case '^': nivel = 3;
    }
    return nivel;
}

/*Función para comparar los operadores*/
int prioridad(char operador1, char operador2)
{
    int primerOperador = importancia(operador1);
    int segundoOperador = importancia(operador2);
    if(primerOperador>=segundoOperador){return 1;}
    else{return 0;}
}

/*Función para definir si es un número o un operador*/
int esOperador(char elemento)
{
    if(elemento == '+' || elemento == '-' || elemento == '*' || elemento == '/' || elemento == '^'){return 1;}
    else{return 0;}
}

/*Función para definir si un número es mayor a cero y menor que nueve*/
int esNumero(char elemento)
{
    if(elemento >= '0' && elemento <= '9'){return 1;}
    else{return 0;}
}

/*Función para evaluar si el resultado de la operación es menor que nueve*/
int evaluar_postfija(char *postfija)
{
    PilaInt pila_num = {0};
    for (int i = 0; postfija[i] != '\0'; i++) 
    {
        char elemento = postfija[i];
        if (esNumero(elemento))
        {
            push_int(&pila_num, elemento - '0');
        } else if (esOperador(elemento))
        {
            int val2 = pop_int(&pila_num);
            int val1 = pop_int(&pila_num);
            switch (elemento) {
                case '+': push_int(&pila_num, val1 + val2); break;
                case '-': push_int(&pila_num, val1 - val2); break;
                case '*': push_int(&pila_num, val1 * val2); break;
                case '/': push_int(&pila_num, val1 / val2); break;
            }
        }
    }
    return pop_int(&pila_num);
}

/*Función para convertir la cadena ingresada por el usuario a postfijo*/
char* convertirPostfijo(char * infija){
	char elemento,operador;
	char  *postfija;
	postfija=malloc(sizeof(char)*100);	
	int j=0;
	int i=0;
	Pila *pila=crear();
	int longitud= strlen(infija);
	while (i<longitud){
		elemento= infija[i];
		i++;		
		if(esNumero(elemento)){
			postfija[j]=elemento;
			j++;
		}else if (esOperador(elemento)){
			if(!vacio(*pila)){
				int continuar;
				do{				
					operador=pop(pila);
				    if(prioridad(operador, elemento)){	
						postfija[j]=operador;
						j++;						
						continuar=1;
					}else{
						continuar=0;
						push(pila,operador);
					}					
				}while(!vacio(*pila) && continuar);				
			}
			push(pila,elemento);			
		}else if (elemento == '('){
			push(pila,elemento);
		}else if (elemento == ')'){			
			operador=pop(pila);
			while(!vacio(*pila) && operador!='(') {
				postfija[j]=operador;
				j++;
				operador=pop(pila);
			}
		}		
	}
	while(!vacio(*pila)) {
		operador=pop(pila);
		postfija[j]=operador;
		j++;			
	}
	postfija[j]='\0';
    return postfija;	
}

/*Función para convertir la operación aritmética postfija a Lenguaje Ensamblador*/
char* convertirEnsamblador(char * postfija)
{
    char elemento;
    char *ensamblador;
    ensamblador=malloc(sizeof(char)*100);
    int j=0;
    int i=0;
    Pila *pila=crear();
    int longitud= strlen(postfija);
    while (i<longitud)
    {
        elemento= postfija[i];
        i++;
        if(esNumero(elemento))
        {
            postfija[j]=elemento;
            j++;
            printf("mov ax, %c\n", elemento);
            printf("push ax \n");
            
        }
        else if (esOperador(elemento))
        {
            printf("pop bx \n");
            printf("pop ax \n");
            switch(elemento)
            {
                case '+': printf("add ax, bx \n");
                          printf("push ax \n");
                          break;
                case '-': printf("sub ax, bx \n");
                          printf("push ax \n");
                          break;
                case '*': printf("imul bx \n");
                          printf("push ax \n");
                          break;
                case '/': printf("div bx \n");
                          printf("push ax \n");
                          break;
            }
            push(pila,elemento);
        }
    }
    while(!vacio(*pila))
    {
        elemento=pop(pila);
        ensamblador[j]=elemento;
        j++;
    }
    printf("pop ax \n");
    ensamblador[j]='\0';
    return ensamblador;
}