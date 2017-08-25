#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "miLibreria.h"

int main()
{
    int opcion;
    char seguir='s';
    eProgramador programador[PROGRAMADORES];
    eProyecto proyecto[5];
    eProgramadorProyecto progProyec[PROYECTOS];

    inicializarUsuarios(programador,PROGRAMADORES);
    inicializarProyectos(proyecto);
    inicializarProgProyec(progProyec,PROYECTOS);
    do
    {
        system("cls");
        printf(MENU);
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaProgramador(programador,PROGRAMADORES);
            break;
        case 2:
            modificarProgramador(programador,PROGRAMADORES);
            break;
        case 3:
            bajaUsuario(programador,PROGRAMADORES);
            bajaUsuarioProyecto(programador,PROGRAMADORES,proyecto,5,progProyec,PROYECTOS);
            break;
        case 4:
            asignarProgramador(programador,PROGRAMADORES,proyecto,5,progProyec,PROYECTOS);
            break;
        case 5:
            listarUsuarios(programador,PROGRAMADORES,proyecto,5,progProyec,PROYECTOS);
            break;
        case 6:
            listarProyectos(programador,PROGRAMADORES,proyecto,5,progProyec,PROYECTOS);
            break;
        case 7:
            listarProyectoProgramador(programador,PROGRAMADORES,proyecto,5,progProyec,PROYECTOS);
            break;
        case 8:

            break;
        case 9:
            seguir='n';
            break;

        default:
            printf("\n\nOpcion Incorrecta.");
            getche();
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
