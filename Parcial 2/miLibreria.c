#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Arraylist.h"
#include "miLibreria.h"

int cargarDestinatarios(ArrayList* pList)
{
    char auxNombre[30],hora[10],prioridad[10];
    FILE* f;
    eTarea* tareaAux=NULL;
    int auxReturn = -1;

    f = fopen("tar.csv","r");

    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^\n]",auxNombre,prioridad,hora);

            tareaAux = tareaNueva(auxNombre,atoi(prioridad),atoi(hora));
            al_add(pList, tareaAux);
        }
        fclose(f);
        auxReturn = 0;
    }
    return auxReturn;
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param turno int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
eTarea* tareaNueva(char* nombre, int prioridad,int hora)
{
    eTarea* returnAux = NULL;
    eTarea* pTarea = malloc(sizeof(eTarea));

    if(pTarea != NULL)
    {
        strcpy(pTarea->nombre,nombre);
        pTarea->prioridad=prioridad;
        pTarea->hora=hora;

        returnAux = pTarea;
    }
    return returnAux;
}

void particionarListas(ArrayList* tr_Todos, ArrayList* tr_Urg,ArrayList* tr_Reg)
{
    eTarea* tr_Aux=NULL;
    int i;
    if(tr_Todos != NULL && tr_Urg != NULL && tr_Reg != NULL)
    {
        for(i=0; i < al_len(tr_Todos);)
        {
            tr_Aux=al_pop(tr_Todos,0);

            if(tr_Aux->prioridad==1)
            {
                al_add(tr_Urg,tr_Aux);
            }
            else
            {
                al_add(tr_Reg,tr_Aux);
            }
        }
    }

}

int compareTarea(void* pTareaA,void* pTareaB)
{
    if(((eTarea*)pTareaA)->hora > ((eTarea*)pTareaB)->hora)
    {
        return 1;
    }
    if(((eTarea*)pTareaA)->hora < ((eTarea*)pTareaB)->hora)
    {
        return -1;
    }
    return 0;
}

void printTarea(eTarea* p)
{
    printf("%20s %10d %10d\n",p->nombre,p->prioridad,p->hora);
}


int mostrarProximaTarea(ArrayList* tr_Urg, ArrayList* tr_Reg)
{
    int retorno=-1;
    if(tr_Urg != NULL && tr_Reg != NULL)
    {
        if(!al_isEmpty(tr_Urg))
        {
            if(proximaTarea(tr_Urg))
            {
                retorno=1;
            }
        }
        else
        {
            if(proximaTarea(tr_Reg))
            {
                retorno=1;
            }
        }
        retorno=0;
    }
    return retorno;
}


int proximaTarea(ArrayList* x)
{
    int retorno = 0;
    eTarea* tarea=NULL;
    eTarea* tarea2=NULL;

    if(!al_isEmpty(x))
    {
        tarea=al_pop(x,0);
        printTarea(tarea);
        tarea2=al_get(x,0);
        while(!al_isEmpty(x) && compareTarea(tarea2,tarea)==0)
        {
            printTarea(tarea2);
            al_remove(x,0);
            tarea2=al_get(x,0);
        }
        retorno = 1;
    }
    return retorno;
}
