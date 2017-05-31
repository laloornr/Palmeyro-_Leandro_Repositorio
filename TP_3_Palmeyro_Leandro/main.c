#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    EMovie movies[TAM_PELICULAS];

    peliculas_inicializar(movies, TAM_PELICULAS);
    peliculas_carga(movies,TAM_PELICULAS);

    do
    {
        system("cls");
        printf(MENU);
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                peliculas_agregar(movies,TAM_PELICULAS);
                break;
            case 2:
                peliculas_borrar(movies,TAM_PELICULAS);
                break;
            case 3:
                peliculas_editar(movies, TAM_PELICULAS);
               break;
            case 4:
                peliculas_generarWeb(movies,"Movies.html",TAM_PELICULAS);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\n\nOpcion Incorrecta");
                break;
        }
    }while(seguir=='s');
    return 0;
}
