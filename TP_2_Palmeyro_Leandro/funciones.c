#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void inicializarPersonas(ePersona x[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        x[i].estado=SIN_USO;
    }
}

int obtenerEspacioLibre(ePersona x[],int tam)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(x[i].estado==SIN_USO)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

int obtenerIndice(ePersona x[],int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(x[i].estado==SIN_USO)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void agregarPersona(ePersona x[],int i)
{
    ePersona eAux;
    char aux[500];

    system("cls");
    printf("---- Agregar Persona ----");
    printf("\n\nIngrese Nombre: ");
    fflush(stdin);
    gets(aux);

    while(validarNombreyApellido(aux)==0 || strlen(aux)>49)
    {
        printf("\nError Nombre Invalido. Reingrese: ");
        fflush(stdin);
        gets(aux);
    }
    strupr(aux);
    strcpy(eAux.nombre,aux);


    printf("\n\nIngrese Edad: ");
    scanf("%d",&eAux.edad);
    while(eAux.edad<0||eAux.edad>100)
    {
        printf("\nError Edad Invalida. Reingrese: ");
        fflush(stdin);
        scanf("%d",&eAux.edad);
    }

    printf("\n\nIngrese DNI: ");
    fflush(stdin);
    gets(aux);
    while(esNumerico(aux)==0 || strlen(aux)!=8)
    {
        printf("\nError DNI Invalido. Reingrese: ");
        fflush(stdin);
        gets(aux);
    }
    eAux.dni=atoi(aux);
    eAux.estado=EN_USO;

    if(buscarPorDni(x,eAux.dni,TAM_MAX)==0)
    {
        x[i]=eAux;

    }
    else
    {
        printf("\n\nEl DNI ya fue ingresado, Los datos se borraron.");
        getche();
    }
}

int validarNombreyApellido(char texto[])
{
    int i=0;
    int retorno=1;
    while(texto[i] != '\0')
    {
        if((texto[i] != ' ') && (texto[i] < 'a' || texto[i] > 'z') && (texto[i] < 'A' || texto[i] > 'Z'))
            retorno=0;
        i++;
    }
    return retorno;
}



int buscarPorDni(ePersona x[], int dni,int tam)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(x[i].dni==dni)
        {
            retorno=1;
            break;
        }
    }
    return retorno;

}

int obtenerIndiceDNI(ePersona x[],int dni,int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(x[i].dni==dni )
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void borrarPersona(ePersona x[],int tam)
{
    int aux;
    char auxC;
    int indice;
    system("cls");
    printf("---- Borrar Persona ----\n\n");
    printf("Ingrese DNI: ");
    fflush(stdin);
    scanf("%d",&aux);

    if(buscarPorDni(x,aux,tam)==0)
    {
        printf("\nDNI incorrecto.");
        getche();
    }
    else
    {
        printf("\nDNI encontrado, Desea eliminar? (s=si) : ");
        fflush(stdin);
        scanf("%c",&auxC);
        if(auxC=='s'||auxC=='S')
        {

            indice=obtenerIndiceDNI(x,aux,tam);

            x[indice].estado=SIN_USO;
            x[indice].dni=-1;
        }
    }
}

void imprimirLista(ePersona x[],int tam)
{
    int i;
    system("cls");
    printf("---- Imprimir Lista ----\n\n");
    ordenarLista(x,tam);
    for(i=0; i<TAM_MAX; i++)
    {
        if(x[i].estado==EN_USO)
        {
            printf("\nNombre: %s\n",x[i].nombre);
            printf("Edad: %d\n",x[i].edad);
            printf("DNI: %d\n",x[i].dni);
        }
    }
    getche();
}

void ordenarLista(ePersona x[],int tam)
{
    ePersona aux;
    int i,j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
            else
            {
                if(strcmp(x[i].nombre,x[j].nombre)==0&&x[i].dni>x[j].dni)
                {
                    aux=x[i];
                    x[i]=x[j];
                    x[j]=aux;
                }
            }
        }
    }
}


void grafico(ePersona x[],int tam)
{
    int i;
    int Menor18=0, de19a35=0, Mayor35=0;

    for(i=0; i<tam; i++)
    {
        if(x[i].estado == EN_USO)
        {
            if(x[i].edad<18)
            {
                Menor18++;
            }
            else if(x[i].edad>35)
            {
                Mayor35++;
            }
            else
            {
                de19a35++;
            }
        }
    }
    system("cls");
    printf("   Imprimir grafico por edades:\n");
    printf(" +-------------------------------------------------+\n");

    for(i=tam; i>0; i--)
    {
        printf(" |           %s", Menor18>=i?GRAFICO:" ");
        printf("             %s", de19a35>=i?GRAFICO:" ");
        printf("              %s        |\n", Mayor35>=i?GRAFICO:" ");
    }
    printf(" +-------------------------------------------------+\n");
    printf("   Edad: Menor de 18 / Entre 19 y 35 / Mayor de 35\n");
    getche();

}


int esNumerico(char str[])
{
    int i=0,retorno=1;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            retorno= 0;
        i++;

    }
    return retorno;
}
