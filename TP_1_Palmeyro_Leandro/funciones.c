#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

#define MAX_OPER 9999999999
#define MIN_OPER -9999999999



/**
 * \brief Solicita el operando al usuario y devuelve el numero flotante ingresado
 * \param mensaje Es para mostrar el mensaje que dice Ingrese Operando
 * \return Retorna el número ingresado por el usuario
 *
 */
float validarOperando(char mensaje[]){
    float operando;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&operando);

    while(operando < MIN_OPER || operando > MAX_OPER)
    {
        printf("\nError, ingrese opcion valida.\n");
        fflush(stdin);
        scanf("%f", &operando);
    }
    return operando;
}

/** \brief Verifica las Banderas y devuelve 1 si estan cargados los operandos, y 0 si hay error
 *
 * \param flag1 Bandera del primer operando
 * \param flag2 Bandera del 2do operando
 * \return devuelve 1 si las banderas estan cargadas, 0 si hay error
 *
 */
int validarBanderas(int flag1 , int flag2){
    int validacion=0;
    if(flag1==1&&flag2==1){
        validacion=1;
    }
    return validacion;
}

/** \brief Funcion para sumar 2 operandos
 *
 * \param oper1 Primer Operando
 * \param oper2 Segundo Operando
 * \return retorna la suma de los opernados
 *
 */
float suma(float oper1, float oper2){
    return oper1+oper2;
}

/** \brief Funcion para Restar 2 operandos
 *
 * \param oper1 Primer Operando
 * \param oper2 Segundo Operando
 * \return retorna la resta de los operandos
 *
 */
float resta(float oper1, float oper2){
    return oper1-oper2;
}

/** \brief Funcion para Multiplicar 2 Operandos
 *
 * \param oper1 Primer Operando
 * \param oper2 Segundo Operando
 * \return retorna la multiplicacion de los operandos
 *
 */
float multiplicacion(float oper1, float oper2){
    return oper1*oper2;
}

/** \brief Funcion para Dividir 2 operandos
 *
 * \param oper1 Primer Operando
 * \param oper2 Segundo Operando
 * \return retorna la division de los operandos
 *
 */
float division(float oper1, float oper2){
    return oper1/oper2;
}


/** \brief factorial, toma el valor del operando 1 y realiza la operacion
 *
 * \param float x para el operando 1
 * \return retorna el factorial del operando 1
 *
 */
float factorial(float oper1)
{
    float resultado=1;
    int i;
    if(oper1!=0)
    {
        for(i = 1; i<=oper1; i++)
        {
            resultado*=i;
        }
    }
    return resultado;
}
