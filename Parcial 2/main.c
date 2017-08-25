#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Arraylist.h"
#include "miLibreria.h"

int main()
{
    ArrayList* tr_Urg=al_newArrayList();
    ArrayList* tr_Reg=al_newArrayList();
    ArrayList* tr_Todos=al_newArrayList();

    int opcion,flag=0,flag2=0;
    char seguir='s';

    do
    {
        system("cls");
        printf(MENU);
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            if(cargarDestinatarios(tr_Todos)==0)
            {
                printf("\n\n Lista Cargada Exitosamente!");
                getche();
            }
            break;
        case 2:
            if(!al_isEmpty(tr_Todos))
            {
                particionarListas(tr_Todos,tr_Urg,tr_Reg);
                al_clear(tr_Todos);
                flag=1;
                printf("\n\n La lista fue Particionada Correctamente.");
                getche();
            }
            else
            {
                if(flag==1)
                {
                    printf("\n\n Error, La Lista Ya fue Particionada");
                    getche();
                }
                else
                {
                    printf("\n\n Error, Debe cargar la Lista Primero.");
                    getche();
                }
            }
            break;
        case 3:
            if(!al_isEmpty(tr_Urg) && !al_isEmpty(tr_Reg))
            {
                al_sort(tr_Urg,compareTarea,0);
                al_sort(tr_Reg,compareTarea,0);
                printf("\n\n Listas Ordenadas!");
                getche();
            }
            else
            {
                printf("\n\n Error, Debe particionar las Listas Primero.");
                getche();
            }

            break;
        case 4:
            if(!al_isEmpty(tr_Urg) && !al_isEmpty(tr_Reg))
            {
                printf("%10s %10s %10s\n","Nombre","Prioridad","Horas");
                printf("---------------------------------------------\n");
                mostrarProximaTarea(tr_Urg,tr_Reg);
                flag2=1;
                getche();
            }
            else
            {
                if(flag2==1)
                {
                    printf("\n\n Error, Las Tareas Fueron Realizadas");
                    getche();
                }
                else
                {
                    printf("\n\n Error, Debe particionar las Listas Primero.");
                    getche();
                }
            }
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("\nOpcion Incorrecta");
            getche();
            break;
        }
    }
    while(seguir=='s');
    al_deleteArrayList(tr_Todos);
    al_deleteArrayList(tr_Urg);
    al_deleteArrayList(tr_Reg);
    return 0;
}
