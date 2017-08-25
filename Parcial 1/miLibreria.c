#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "miLibreria.h"

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


/** \brief Inicializa el array en estado sin uso
 *
 * \param Estructura a cambiar estado
 * \param tamaño de la estructura
 */
void inicializarUsuarios(eProgramador programador[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        programador[i].estado=LIBRE;
        programador[i].idCategoria=-1;
    }
}


/** \brief Inicializa el array en estado sin uso
 *
 * \param Estructura a cambiar estado
 * \param tamaño de la estructura
 */
void inicializarProyectos(eProyecto proyecto[])
{
    int i;
    int id[5]= {100,101,102,103,104};
    char nombre[5][20]= {"Proyecto 1","Proyecto 2","Proyecto 3","Proyecto 4","Proyecto 5"};
    for(i=0; i<5; i++)
    {
        proyecto[i].estado=ALTA;
        proyecto[i].contProg=0;
        proyecto[i].idProyecto=id[i];
        strcpy(proyecto[i].nombre,nombre[i]);
    }
}

/** \brief Inicializa el array en estado sin uso
 *
 * \param Estructura a cambiar estado
 * \param tamaño de la estructura
 */
void inicializarProgProyec(eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int i;
    for(i=0; i<tamProgProyec; i++)
    {
        progProyec[i].estado=LIBRE;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return retorna 0 si no encuentra espacio libre, 1 si lo encontro
 */
int obtenerEspacioLibre(eProgramador programador[],int tam)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(programador[i].estado==LIBRE)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

/** \brief Obtiene el Indice que esta libre para ser usado
 *
 * \param estructura a buscar indice libre
 * \param tamaño para recorrer
 * \return retorna el indice libre
 *
 */
int obtenerIndice(eProgramador programador[],int tam)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(programador[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


/** \brief Busca espacio libre y consigue el Indice donde se tiene que guardar el dato a cargar
 *
 * \param  Estructura de programador
 * \param  Tamaño a recorrer
 */

void altaProgramador(eProgramador programador[],int tam)
{
    int i;
    if(obtenerEspacioLibre(programador,tam)==1)
    {
        i=obtenerIndice(programador,tam);
        cargarProgramador(programador,tam,i);

    }
    else
    {
        printf("\n\nCapacidad Agotada!!!!");
        getche();
    }
}

/** \brief Da de alta un programador en el Indice que se le indica
 *
 * \param estructura a guardar lo ingresado
 * \param tamaño de la estructura
 * \param indice a guardar los datos
 *
 */
void cargarProgramador(eProgramador programador[],int tam,int indice)
{
    eProgramador eAux;
    char auxC[200];
    int auxI;
    system("cls");
    printf("===== ALTA PROGRAMADOR =====");

    printf("\n\nIngrese ID programador: ");
    fflush(stdin);
    gets(auxC);

    while(esNumerico(auxC)==0)
    {
        printf("\nError Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxC);

    }
    auxI=atoi(auxC);
    if(buscarID(programador,tam,auxI)==1)
    {
        printf("\nEl id ya fue ingresado.");
        getche();
    }
    else
    {
        eAux.idCategoria=auxI;


        printf("\n\nIngrese Nombre: ");
        fflush(stdin);
        gets(auxC);
        while(esSoloLetras(auxC)==0 || strlen(auxC)>19)
        {
            printf("\nError Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxC);
        }
        strcpy(eAux.nombre,auxC);

        printf("\n\nIngrese Apellido: ");
        fflush(stdin);
        gets(auxC);
        while(esSoloLetras(auxC)==0 || strlen(auxC)>19)
        {
            printf("\nError Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxC);
        }
        strcpy(eAux.apellido,auxC);

        printf("\n\nSeleccione categoria del Programador:\n\n1) Junior\n2) Semi Junior\n3) Senior\n\nIngrese Opcion:");
        fflush(stdin);
        scanf("%d",&auxI);
        switch(auxI)
        {
        case 1:
            eAux.descripcion=JUNIOR;
            break;
        case 2:
            eAux.descripcion=SEMI_JUNIOR;
            break;
        case 3:
            eAux.descripcion=SENIOR;
            break;
        }
        eAux.pagoXhora=0;
        eAux.estado=ALTA;
        programador[indice]=eAux;
    }
}


/** \brief Pide el ID a buscar y verifica si esta cargado
 *
 * \param Estructura a modificar
 * \param tamaño de la estructura
 *
 */
void modificarProgramador(eProgramador programador[],int tam)
{
    int aux,i;
    system("cls");
    printf("===== MODIFICAR PROGRAMADOR =====");
    printf("\n\nIngrese ID: ");
    scanf("%d",&aux);

    if(buscarID(programador,tam,aux)==1)
    {
        i=buscarIDIndice(programador,tam,aux);
        modificar(programador,i);
    }
    else
    {
        printf("\n\nID no encontrada.");
        getche();
    }
}

/** \brief Modifica los datos por los que se ingresan Nuevamente, y los guarda en el indice que se le indica
 *
 * \param estructura a guardar datos
 * \param indice a guardar datos
 *
 */
void modificar(eProgramador programador[],int i)
{
    char auxC,aux[200];
    int auxI;
    printf("\n\nUsuario encontrado. Desea modificar? (s=si) : ");
    fflush(stdin);
    scanf("%c",&auxC);
    if(auxC=='s'||auxC=='S')
    {

        printf("\n\nIngrese Nombre: ");
        fflush(stdin);
        gets(aux);
        while(esSoloLetras(aux)==0 || strlen(aux)>19)
        {
            printf("\nError Ingrese nuevamente: ");
            fflush(stdin);
            gets(aux);
        }
        strcpy(programador[i].nombre,aux);

        printf("\n\nIngrese Apellido: ");
        fflush(stdin);
        gets(aux);
        while(esSoloLetras(aux)==0 || strlen(aux)>19)
        {
            printf("\nError Ingrese nuevamente: ");
            fflush(stdin);
            gets(aux);
        }
        strcpy(programador[i].apellido,aux);

        printf("\n\nSeleccione categoria del Programador:\n\n1) Junior\n2) Semi Junior\n3) Senior\n\nIngrese Opcion:");
        fflush(stdin);
        scanf("%d",&auxI);
        switch(auxI)
        {
        case 1:
            programador[i].descripcion=JUNIOR;
            programador[i].pagoXhora=100;
            break;
        case 2:
            programador[i].descripcion=SEMI_JUNIOR;
            programador[i].pagoXhora=200;
            break;
        case 3:
            programador[i].descripcion=SENIOR;
            programador[i].pagoXhora=300;
            break;
        }
    }
}


/** \brief Busca si la Id ingresada esta ya cargada en sistema
 *
 * \param estructura a recorrer
 * \param tamaño a recorrer
 * \param id a buscar
 * \return retorna 0 si no esta duplicado, 1 si lo esta
 *
 */
int buscarID(eProgramador programador[],int tamU, int id)
{
    int i;
    int retorno=0;
    for(i=0; i<tamU; i++)
    {
        if(programador[i].idCategoria==id)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

/** \brief Busca si el id que ingresa esta cargado, da de baja y reinicia el Id
 *
 * \param estructura a recorrer
 * \param tamaño de la estructura a recorrer
 *
 */
void bajaUsuario(eProgramador programador[],int tam)
{
    int aux,i;
    system("cls");
    printf("===== BAJA PROGRAMADOR =====");
    printf("\n\nIngrese ID: ");
    fflush(stdin);
    scanf("%d",&aux);

    if(buscarID(programador,tam,aux)==1)
    {
        i=buscarIDIndice(programador,tam,aux);
        programador[i].estado=BAJA;
        programador[i].idCategoria=-1;
        printf("\n%20s %20s",programador[i].nombre,programador[i].apellido);
        printf("\n\nProgramador dado de Baja Correctamente!");
        getche();
    }
    else
    {
        printf("\n\nID no encontrada.");
        getche();
    }
}

/** \brief Da de baja un usuario si esta cargado en un proyecto
 *
 * \param estructura donde esta cargado el programador a dar de baja
 * \param tamaño de la estructura donde esta cargado el programador
 * \param estructura de proyecto donde se da de baja un programador
 * \param tamaño estructura proyecto
 * \param estructura a buscar los proyectos en los que trabaja el programador
 * \param tamaño de estructura que en los que trabajan programadores
 *
 */
void bajaUsuarioProyecto(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int i,j,k;

    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].estado==BAJA)
        {
            for(j=0; j<tamProgProyec; j++)
            {
                if(programador[i].idCategoria==progProyec[j].idCategoria)
                {
                    for(k=0; k<tamProgProyec; k++)
                    {
                        if(progProyec[j].idProyecto==proyecto[k].idProyecto)
                        {
                            programador[i].estado=LIBRE;
                            progProyec[j].estado=LIBRE;
                            proyecto[k].contProg--;
                        }
                    }
                }
            }
        }
    }

}

/** \brief Busca un ID y devuelve el Indice donde esta cargado
 *
 * \param estructura donde se busca el ID
 * \param tamaño de la estructura a recorrer
 * \param id que se busca
 * \return devuelve el indice donde se encuentra coincidencia
 *
 */
int buscarIDIndice(eProgramador programador[],int tam, int id)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(programador[i].idCategoria==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/** \brief Asigna un Programador a un proyecto
 *
 * \param estructura programador a cargar en un proyecto
 * \param tamaño estructura programador
 * \param estructura proyecto donde se va a cargar un programador
 * \param tamaño estructura proyecto
 * \param estructura a guardar el programador que trabaja en el proyecto
 * \param tamaño estructura programador y proyecto
 *
 */

void asignarProgramador(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int aux,i,j,k,aux2;
    system("cls");
    printf("===== ASIGNAR PROGRAMADOR =====\n\n");
    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].estado==ALTA && programador[i].descripcion==JUNIOR)
        {
            printf("%3d %20s %20s %15s\n",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"JUNIOR");
        }
        else if(programador[i].estado==ALTA && programador[i].descripcion==SEMI_JUNIOR)
        {
            printf("%3d %20s %20s %15s\n",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"SEMI-JUNIOR");
        }
        else if(programador[i].estado==ALTA && programador[i].descripcion==SENIOR)
        {
            printf("%3d %20s %20s %15s\n",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"SENIOR");
        }
    }

    printf("\n\nIngrese ID: ");
    fflush(stdin);
    scanf("%d",&aux);
    while(buscarID(programador,tamProgramador,aux)==0)
    {
        printf("\n\nError ID incorrecta,Reingrese: ");
        fflush(stdin);
        scanf("%d",&aux);
    }
    printf("\n\n===== PROYECTOS =====\n");
    printf("%3s %30s\n\n","ID","PROYECTO");
    for(i=0; i<tamProyecto; i++)
    {
        if(proyecto[i].estado==ALTA)
        {
            printf("%3d %30s\n",proyecto[i].idProyecto,proyecto[i].nombre);
        }
    }
    printf("\n\nSeleccione Proyecto que desea Cargar Programador: ");
    fflush(stdin);
    scanf("%d",&aux2);

    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].idCategoria==aux)
        {
            for(j=0; j<tamProyecto; j++)
            {
                if(proyecto[j].idProyecto==aux2)
                {
                    for(k=0; k<tamProgProyec; k++)
                    {
                        if(progProyec[k].estado==LIBRE)
                        {
                            progProyec[k].idCategoria = programador[i].idCategoria;
                            progProyec[k].idProyecto = proyecto[j].idProyecto;
                            proyecto[j].contProg++;
                            printf("\n\nProgramador Cargado exitosamente!!");
                            getche();
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}

/** \brief Lista usuarios ordenados por id y muestra en los proyectos que trabaja
 *
 * \param estructura programadores cargados a mostrar
 * \param tamaño de estructura programador
 * \param estructura proyectos cargados a mostrar
 * \param tamaño de estructura proyecto
 * \param estructura donde se guardan los programadores que trabajan en proyectos
 * \param tamaño de estructura programador y Proyecto
 *
 */
void listarUsuarios(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int i,j,k;
    system("cls");
    printf("===== LISTAR PROGRAMADORES =====");
    printf("\n%3s %15s %15s %15s %15s\n\n","ID","NOMBRE","APELLIDO","CATEGORIA","PROYECTOS");

    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].estado==ALTA)
        {
            if(programador[i].descripcion==JUNIOR && programador[i].estado == ALTA)
            {
                printf("%3d %15s %15s %15s",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"JUNIOR");
            }
            else if(programador[i].descripcion==SEMI_JUNIOR && programador[i].estado == ALTA)
            {
                printf("%3d %15s %15s %15s",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"SEMI-JUNIOR");
            }
            else if(programador[i].descripcion==SENIOR && programador[i].estado == ALTA)
            {
                printf("%3d %15s %15s %15s",programador[i].idCategoria,programador[i].nombre,programador[i].apellido,"SENIOR");
            }
            for(j=0; j<tamProgProyec; j++)
            {
                if(programador[i].idCategoria==progProyec[i].idCategoria)
                {
                    for(k=0; k<tamProyecto; k++)
                    {
                        if(progProyec[j].idProyecto==proyecto[k].idProyecto && proyecto[k].estado==ALTA)
                        {
                            printf(" %15s",proyecto[k].nombre);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    getche();
}

/** \brief Mustra todos los proyectos cargados
 *
 * \param estructura programadores cargados a mostrar
 * \param tamaño de estructura programador
 * \param estructura proyectos cargados a mostrar
 * \param tamaño de estructura proyecto
 * \param estructura donde se guardan los programadores que trabajan en proyectos
 * \param tamaño de estructura programador y Proyecto
 *
 */
void listarProyectos(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int i,j,k;
    int contJunior[5]={0,0,0,0,0},contSemiJunior[5]={0,0,0,0,0},contSenior[5]={0,0,0,0,0};
    system("cls");

    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].estado==ALTA)
        {
            for(j=0; j<tamProgProyec; j++)
            {
                if(programador[i].idCategoria==progProyec[j].idCategoria)
                {
                    for(k=0; k<tamProyecto; k++)
                    {
                        if(programador[i].descripcion==JUNIOR){
                            contJunior[k]++;
                        }
                        if(programador[i].descripcion==SEMI_JUNIOR){
                            contSemiJunior[k]++;
                        }
                        else if(programador[i].descripcion==SENIOR){
                            contSenior[k]++;
                        }
                    }
                }
            }
        }
    }

    printf("===== LISTAR PROYECTOS =====");
    printf("\n%3s %15s %15s %15s %15s %15s\n\n","ID","NOMBRE","CANT DE PROGR","JUNIOR","SEMI-JUNIOR","SENIOR");

    for(i=0; i<tamProyecto; i++)
    {
        if(proyecto[i].estado==ALTA)
        {
            printf("%3d %15s %15d %15d %15d %15d\n",proyecto[i].idProyecto,proyecto[i].nombre,proyecto[i].contProg,contJunior[i],contSemiJunior[i],contSenior[i]);
        }
    }
    getche();
}

/** \brief Muestra la lista de los proyectos que participa el Programador seleccionado
 *
 * \param estructura programadores cargados a mostrar
 * \param tamaño de estructura programador
 * \param estructura proyectos cargados a mostrar
 * \param tamaño de estructura proyecto
 * \param estructura donde se guardan los programadores que trabajan en proyectos
 * \param tamaño de estructura programador y Proyecto
 *
 */
void listarProyectoProgramador(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec)
{
    int i,j,k,aux;
    system("cls");
    printf("===== LISTAR PROYECTOS PROGRAMADOR =====\n\n");
    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].estado==ALTA)
        {
            printf("%3d %15s %15s\n",programador[i].idCategoria,programador[i].nombre,programador[i].apellido);
        }
    }
    printf("\n\nSeleccione ID de Programador a buscar: ");
    fflush(stdin);
    scanf("%d",&aux);
    while(buscarID(programador,tamProgramador,aux)==0)
    {
        printf("\n\nError ID incorrecta,Reingrese: ");
        fflush(stdin);
        scanf("%d",&aux);
    }

    for(i=0; i<tamProgramador; i++)
    {
        if(programador[i].idCategoria==aux)
        {
            printf("\n\nProyectos en los que participa: \n\n");
            for(j=0; j<tamProgProyec; j++)
            {
                if(programador[i].idCategoria==progProyec[j].idCategoria)
                {
                    for(k=0; k<tamProyecto; k++)
                    {
                        printf("%20s",proyecto[j].nombre);
                    }
                }
            }
        }
    }
}
