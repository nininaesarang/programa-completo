/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*Programa para números de un solo dígito*/
#include <stdio.h>
/*Enlaza la página que contiene las funcionalidades del código*/
#include "funciones.h"

int main()
{
    /*Declaración de variables*/
    char cadena[50] = "";
    char *ensamblador;
    /*Impresión de mensajes*/
    printf("Escriba la operación aritmética: ");
    /*Lectura de lo que ingrese el usuario*/
    scanf("%49s", cadena);
    /*Impresión de la conversión postfija*/
    char *postfija = convertirPostfijo(cadena);
    printf("Conversión a postfija: %s\n", postfija);
    /*Impresión del resultado*/
    int resultado = evaluar_postfija(postfija);
    printf("Resultado de la operación: %d\n", resultado);
    if(resultado >= 0 && resultado <= 9)
    {
        /*Conversión de la expresión aritmética*/
        printf("\nEl resultado es menor a nueve.\nEspere mientras se hace la traducción a Lenguaje Ensamblador...\n");
        printf("\n--- Código Ensamblador EMU8086 ---\n");
        printf("\n");
        ensamblador=convertirEnsamblador(postfija);
    }
    else
    {
        printf("\nNo se puede realizar la traducción: el resultado es mayor a 9.");
    }
    return 0;
}