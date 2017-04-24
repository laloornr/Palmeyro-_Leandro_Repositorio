#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,indice;
    ePersona unaPersona[TAM_MAX];

    inicializarPersonas(unaPersona,TAM_MAX);

    do
    {
        system("cls");
        printf("------ MENU ------\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\n\nIngrese Opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(unaPersona,TAM_MAX)==1){
                    indice=obtenerIndice(unaPersona,TAM_MAX);
                    agregarPersona(unaPersona,indice);
                }
                else{
                    printf("\n\nCapacidad Agotada!!!");
                }
                break;

            case 2:
                borrarPersona(unaPersona,TAM_MAX);
                break;
            case 3:
                imprimirLista(unaPersona,TAM_MAX);
                break;
            case 4:
                grafico(unaPersona,TAM_MAX);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nError opcion Incorrecta.");
                getche();
        }
    }while(seguir=='s');

    return 0;
}

