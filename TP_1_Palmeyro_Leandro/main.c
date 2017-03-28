#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    float oper1;
    float oper2;
    int flag1=0;
    int flag2=0;
    char seguir='s';
    float resultado;
    int opcion=0;

    do
    {
        system("cls");
        printf("------- BIENVENIDO ------- \n\n");
        if(flag1==0){
                printf("1- Ingresar 1er operando (A=x)\n");
        }
        else{
                printf("1- Ingresar 1er operando (A=%.2f)\n",oper1);
        }
        if(flag2==0){
                printf("2- Ingresar 2do operando (B=y)\n");
        }
        else{
                printf("2- Ingresar 2do operando (B=%.2f)\n",oper2);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la multiplicacion (A/B)\n");
        printf("6- Calcular la division (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\n\nIngrese Opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    oper1=validarOperando("\n\nIngrese 1er Operando: ");
                    flag1=1;
                break;

            case 2:
                    oper2=validarOperando("\n\nIngrese 2do Operando: ");
                    flag2=1;
                break;

            case 3:
                if(validarBanderas(flag1,flag2)==0){
                    printf("\n\nError, Primero debe cargar los 2 operandos.");
                    getche();
                }
                else{
                    resultado=suma(oper1,oper2);
                    printf("\n\nEl resultado de la suma de los operandos es: %.2f",resultado);
                    getche();
                }

                break;

            case 4:
                if(validarBanderas(flag1,flag2)==0){
                    printf("\n\nError, Primero debe cargar los 2 operandos.");
                    getche();
                }
                else{
                    resultado=resta(oper1,oper2);
                    printf("\n\nEl resultado de la resta de los operandos es: %.2f",resultado);
                    getche();
                }
                break;

            case 5:
                if(validarBanderas(flag1,flag2)==0){
                    printf("\n\nError, Primero debe cargar los 2 operandos.");
                    getche();
                }
                else{
                    resultado=multiplicacion(oper1,oper2);
                    printf("\n\nEl resultado de la multiplicacion de los operandos es: %.2f",resultado);
                    getche();
                }
                break;

            case 6:
                if(validarBanderas(flag1,flag2)==0){
                    printf("\n\nError, Primero debe cargar los 2 operandos.");
                    getche();
                }
                else{
                        if(oper2<=0){
                                printf("Error. El 2do operando tiene que ser Mayor a 0.");
                                getche();
                        }
                        else{
                            resultado=division(oper1,oper2);
                            printf("\n\nEl resultado de la division de los operandos es: %.2f",resultado);
                            getche();
                        }
                }
                break;

            case 7:
                if(flag1==0){
                    printf("\n\nError, Primero debe cargar el 1er operando.");
                    getche();
                }
                else{
                        resultado=factorial(oper1);
                        printf("El Factorial del 1er operando es: %.2f",resultado);
                        getche();
                }
                break;

            case 8:
                    if(validarBanderas(flag1,flag2)==0){
                    printf("\n\nError, Primero debe cargar los 2 operandos.");
                    getche();
                }
                else{
                    if(oper2<=0){
                                printf("Error. El 2do operando tiene que ser Mayor a 0.");
                                getche();
                        }
                        else{
                            resultado=suma(oper1,oper2);
                            printf("\n\nEl resultado de la suma de los operandos es: %.2f",resultado);
                            resultado=resta(oper1,oper2);
                            printf("\n\nEl resultado de la resta de los operandos es: %.2f",resultado);
                            resultado=multiplicacion(oper1,oper2);
                            printf("\n\nEl resultado de la multiplicacion de los operandos es: %.2f",resultado);
                            resultado=division(oper1,oper2);
                            printf("\n\nEl resultado de la division de los operandos es: %.2f",resultado);
                            resultado=factorial(oper1);
                            printf("\n\nEl Factorial del 1er operando es: %.2f",resultado);
                            getche();
                        }
                }
                break;

            case 9:
                seguir = 'n';
                break;

            default:
                printf("\n\nOpcion incorrecta");
                getche();
                break;
        }

    }while(seguir=='s');

    return 0;
}
