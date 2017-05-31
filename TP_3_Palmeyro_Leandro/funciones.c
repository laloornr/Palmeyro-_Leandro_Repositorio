#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

/** \brief Valida la cadena de caracteres a ingresar(solo letras).
 *
 * \param buffer, Array de caracteres a validar
 * \param maxCadena, Entero
 * \return entero indicando 1 si fue correcto el ingreso o 0 si no lo fue.
 *
 */
int esCadena(char* buffer, int maxCadena)
{
    int cadValida = 1;
    if( strlen(buffer)> maxCadena || atoi(buffer)< 0 || atoi(buffer)>0)
    {
        cadValida =0;
    }
    return cadValida;
}

/** \brief Nos indica si la cadena ingresada es numerica.
 *
 * \param numero, Array de caracteres a validar.
 * \return 1 si lo que se ingreso fueron numeros o 0 si no lo fue
 *
 */
int esNumeroPositivo(char* numero)
{
    int i;
    int retorno=1;

    for(i=0; i< strlen(numero); i++)
    {
        if(!isdigit(numero[i]) || atoi(numero)<0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Nos captura la cadena a validar
 *
 * \param buffer, Array de caracteres a validar
 * \param textoError, Texto que se muestra si lo que se ingreso no es correcto
 * \param tamDeseado, Entero que representa el tamaño que se desea validar
 *
 */
void capturarCadena(char* buffer, char* textoError, int tamDeseado)
{
    fflush(stdin);
    gets(buffer);
    while(!esCadena(buffer, 50))
    {
        printf("%s",textoError);
        fflush(stdin);
        gets(buffer);
    }
}

/** \brief Carga los valores del Array de estructuras en VACIO (0)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 *
 */
void peliculas_inicializar(EMovie* movies, int tamMovies)
{
    int i;
    for(i=0; i<tamMovies; i++)
    {
        movies[i].estado = VACIO;
        movies[i].idMovie=-1;
    }
}

/** \brief Se encarga de leer los datos del archivo binario y agregarlos a la estructura vacia.
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 *
 */
void peliculas_carga(EMovie* movies, int tamMovies)
{
    int i=0;
    FILE* pArchivo;

    pArchivo = fopen("Movies.dat","rb");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            fread(&movies[i],sizeof(EMovie),tamMovies,pArchivo);
            i++;
        }
    }
    fclose(pArchivo);
}

/** \brief Busca en el campo estado del Array de estructuras peliculas el valor 0 (VACIO)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return Un Entero, indicando el indice encontrado o -1 si no lo encontro.
 *
 */
int buscarLugarVacio(EMovie* movies, int tam)
{
    int i;
    int indice=-1;

    for(i=0; i<tam; i++)
    {
        if(movies[i].estado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/**
 *  \brief Agrega una pelicula al archivo binario
 *  \param movies Array de estructuras a ser agregada al archivo
 *  \param tamaño del array
 */
void peliculas_agregar(EMovie* movies, int tam)
{
    FILE* pArchivo;

    char buffer[5000];
    int indice,aux;

    int cantidad;

    pArchivo = fopen("Movies.dat","ab");
    indice = buscarLugarVacio(movies,tam);
    if(pArchivo != NULL)
    {
        if(indice!=-1)
        {
            system("cls");
            printf("----- ALTA PELICULAS -----\n\n");

            printf("\nIngrese ID: ");
            fflush(stdin);
            gets(buffer);
            while(!esNumeroPositivo(buffer))
            {
                printf("\nError. Ingrese ID valido: ");
                fflush(stdin);
                gets(buffer);
            }
            aux=atoi(buffer);
            if(buscarID(movies,tam,aux)==0)
            {
                movies[indice].idMovie=aux;

                printf("\nIngrese titulo: ");
                capturarCadena(buffer,"\nError. Ingrese titulo valido: ",50);
                strcpy(movies[indice].titulo,buffer);

                printf("\nIngrese genero: ");
                capturarCadena(buffer,"\nError. Ingrese genero valido: ",50);
                strcpy(movies[indice].genero,buffer);

                printf("\nIngresar duracion: ");
                fflush(stdin);
                gets(buffer);
                while(!esNumeroPositivo(buffer))
                {
                    printf("\nError. Ingrese duracion valido: ");
                    fflush(stdin);
                    gets(buffer);
                }
                movies[indice].duracion = atoi(buffer);

                printf("\nIngrese descripcion: ");
                capturarCadena(buffer,"\nError. Ingrese descripcion valida: ",250);
                strcpy(movies[indice].descripcion,buffer);

                printf("\nIngresar puntaje: ");
                fflush(stdin);
                gets(buffer);
                while(!esNumeroPositivo(buffer))
                {
                    printf("\nError. Ingrese puntaje valido: ");
                    fflush(stdin);
                    gets(buffer);
                }
                movies[indice].puntaje =atoi(buffer);

                printf("\nIngrese link de la Imagen: ");
                fflush(stdin);
                gets(buffer);
                strcpy(movies[indice].linkImagen,buffer);
                movies[indice].estado = ALTA;
                cantidad = fwrite(&movies[indice],sizeof(EMovie),1,pArchivo);

                if(cantidad<1)
                {
                    printf("Ha ocurrido un error al cargar los datos");
                    exit(1);
                }
            }
            else
            {
                printf("\n\nID en uso.");
                getche();
            }

        }
        else
        {
            printf("\nNo hay espacio para agregar otra pelicula.\n");
        }
    }
    fclose(pArchivo);
}



/** \brief Muestra el Array de peliculas que estan HABILITADAS (1)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 *
 */
void peliculas_mostrar(EMovie* movies,int tamMovies)
{
    int i;

    for(i=0; i<tamMovies; i++)
    {
        if(movies[i].estado==ALTA)
        {
            printf("->Titulo : %s \n",movies[i].titulo);
            printf("->Genero : %s \n",movies[i].genero);
            printf("->Duracion : %d \n",movies[i].duracion);
            printf("->Descripcion : %s \n",movies[i].descripcion);
            printf("->Puntaje : %d \n",movies[i].puntaje);
            printf("->Link imagen : %s \n",movies[i].linkImagen);
            printf("->Id: %d\n\n",movies[i].idMovie);
        }
    }
}


/**
 *  \brief Borra una pelicula del archivo binario
 *  \param movie la estructura a ser eliminada al archivo
 *  \param TAmaño del array
 */
void peliculas_borrar(EMovie* movies, int tamMovies)
{
    int id;
    int indice;
    system("cls");
    printf("----- BAJA DE PELICULAS -----\n\n");

    peliculas_mostrar(movies,tamMovies);
    printf("\n\nIngrese ID: ");
    fflush(stdin);
    scanf("%d", &id);
    indice = buscarIDindice(movies,TAM_PELICULAS,id);

    if(indice!=-1)
    {
        movies[indice].estado=VACIO;
        movies[indice].idMovie=-1;
        printf("\nPelicula Dada de Baja con exito.");
        getche();
    }
    else
    {
        printf("\nID incorrecto\n");
        getche();
    }
}



/** \brief Se encarga de buscar el Id solicitado en el Array de estructura, peliculas
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \param  id, Entero que representa el id a buscar.
 * \return Un Entero, distinto de -1 si lo encontro o -1 si no lo encontro.
 *
 */
int buscarIDindice(EMovie* movies, int tamMovies, int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<tamMovies; i++)
    {
        if(movies[i].idMovie == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/** \brief Busca si el indice ingresado ya fue usado
 *
 * \param array de estructura de peliculas
 * \param tamaño del array de peliculas
 * \param id a buscar
 * \return retorna 0 si el id no se encontro, 1 si se encontro igualdad
 *
 */
int buscarID(EMovie* movies,int tamMovies, int id)
{
    int i;
    int retorno=0;
    for(i=0; i<tamMovies; i++)
    {
        if(movies[i].idMovie == id)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}


/** \brief Se encarga de modificar algun campo del Array de estructuras, peliculas.
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 *
 */
void peliculas_editar(EMovie* movies, int tamMovies)
{
    int idMovie;
    int indice;
    char buffer[300];

    system("cls");
    printf("----- MODIFICAR PELICULAS -----\n");

    peliculas_mostrar(movies,tamMovies);
    printf("\nIngrese id de pelicula a modificar: ");
    fflush(stdin);
    scanf("%d",&idMovie);

    indice = buscarIDindice(movies,TAM_PELICULAS,idMovie);
    if(indice!=-1 && movies[indice].estado==ALTA)
    {
        printf("\nIngrese titulo: ");
        capturarCadena(buffer,"\nError. Ingrese titulo valido: ",50);
        strcpy(movies[indice].titulo,buffer);

        printf("\nIngrese genero: ");
        capturarCadena(buffer,"\nError. Ingrese genero valido: ",50);
        strcpy(movies[indice].genero,buffer);

        printf("\nIngresar duracion: ");
        fflush(stdin);
        gets(buffer);
        while(!esNumeroPositivo(buffer))
        {
            printf("\nError. Ingrese duracion valido: ");
            fflush(stdin);
            gets(buffer);
        }
        movies[indice].duracion = atoi(buffer);

        printf("\nIngrese descripcion: ");
        capturarCadena(buffer,"\nError. Ingrese descripcion valida: ",250);
        strcpy(movies[indice].descripcion,buffer);

        printf("\nIngresar puntaje: ");
        fflush(stdin);
        gets(buffer);
        while(!esNumeroPositivo(buffer))
        {
            printf("\nError. Ingrese puntaje valido: ");
            fflush(stdin);
            gets(buffer);
        }
        movies[indice].puntaje =atoi(buffer);

        printf("\nIngrese link de la Imagen: ");
        fflush(stdin);
        gets(buffer);
        strcpy(movies[indice].linkImagen,buffer);
        movies[indice].estado = ALTA;
    }
    else
    {
        printf("\nNo se encontro pelicula con ese Id\n");
    }
}


/**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param lista la lista de peliculas a ser agregadas en el archivo.
 *  \param nombre el nombre para el archivo.
 *  \param Tamaño de array de peliculas
 */
void peliculas_generarWeb(EMovie* movies, char* nombre, int tamMovies)
{
    FILE* pArchivo;
    int i;

    pArchivo = fopen(nombre,"w");

    for(i=0; i<tamMovies; i++)
    {
        if(movies[i].estado == ALTA)
        {
            fprintf(pArchivo, "<article class='col-md-4 article-intro'> \n <a href='#'> \n");
            fprintf(pArchivo, "<img class='img-responsive img-rounded' src='%s' alt=''> \n",movies[i].linkImagen);
            fprintf(pArchivo, "</a> \n <h3> \n <a href='#'> %s </a> \n ",movies[i].titulo);
            fprintf(pArchivo," </h3> \n <ul> \n <li>Género: %s </li> \n ",movies[i].genero);
            fprintf(pArchivo,"<li>Puntaje: %d </li> \n ",movies[i].puntaje);
            fprintf(pArchivo,"<li>Duración: %d </li> \n </ul> \n",movies[i].duracion);
            fprintf(pArchivo, "<p> %s </p></article> \n",movies[i].descripcion);
        }
    }
    printf("\n\nPagina web Generada con exito!!\n\n");
    fclose(pArchivo);
    getche();
}
