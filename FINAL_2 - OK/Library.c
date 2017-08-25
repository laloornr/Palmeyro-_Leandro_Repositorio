#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"
#include "ArrayList.h"

eUsuario* nuevoUsuario(int id, char* nick, int popularidad)
{
    eUsuario* returnAux = NULL;
    eUsuario* pUsuario = (eUsuario*)malloc(sizeof(eUsuario));

    if(pUsuario != NULL)
    {
        strcpy(pUsuario->nick,nick);
        pUsuario->id_usuario=id;
        pUsuario->popularidad=popularidad;
        returnAux = pUsuario;
    }
    return returnAux;
}

int cargarUsuarios(ArrayList* pList)
{
    char id[5], nick[20], followers[10];

    FILE* f;
    eUsuario* usuario;
    int auxReturn = -1;

    f = fopen("usuarios.csv","r");

    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^\n]\n",id,nick,followers);
            usuario = nuevoUsuario(atoi(id),nick,atoi(followers));
            al_add(pList, usuario);
        }
        al_pop(pList,0);
        fclose(f);
        auxReturn = 0;
    }

    return auxReturn;
}

void printUsuario(eUsuario* p)
{
    printf("\n%5d%15s%10d\n",p->id_usuario,p->nick,p->popularidad);
}

void listarUsuarios(ArrayList* pList)
{
    int i;
    for( i=0; i<al_len(pList); i++)
    {
        printUsuario((eUsuario*)al_get(pList,i));
    }
}

ePost* nuevoPost(int id_mensaje, int id_usuario,int popularidad, char* mensaje)
{
    ePost* returnAux = NULL;
    ePost* pPost = (ePost*)malloc(sizeof(ePost));

    if(pPost != NULL)
    {
        strcpy(pPost->mensaje,mensaje);
        pPost->id_mensaje=id_mensaje;
        pPost->id_usuario=id_usuario;
        pPost->popularidad=popularidad;
        returnAux = pPost;
    }
    return returnAux;
}

int cargarPost(ArrayList* pList)
{
    char id_mensaje[5], mensaje[5000], followers[10], id_usuario[5];

    FILE* f;
    ePost* post;
    int auxReturn = -1;

    f = fopen("mensajes.csv","r");

    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",id_mensaje,id_usuario,followers,mensaje);
            post = nuevoPost(atoi(id_mensaje),atoi(id_usuario),atoi(followers),mensaje);
            al_add(pList, post);
        }
        fclose(f);
        auxReturn = 0;
    }

    return auxReturn;
}

void printPost(ePost* p)
{
    printf("\n%5d%5d%5d%10s\n",p->id_mensaje,p->id_usuario,p->popularidad,p->mensaje);
}

void listarPost(ArrayList* pList)
{
    int i;
    for( i=0; i<al_len(pList); i++)
    {
        printPost((ePost*)al_get(pList,i));
    }
}

int comparePopularidadUsuario(void* pFeedA,void* pFeedB)
{
    int retAux;

    if(((eFeed*)pFeedA)->popularidad_usuario > ((eFeed*)pFeedB)->popularidad_usuario)
    {
        retAux = 1;
    }
    if(((eFeed*)pFeedA)->popularidad_usuario < ((eFeed*)pFeedB)->popularidad_usuario)
    {
        retAux = -1;
    }
    if(((eFeed*)pFeedA)->popularidad_usuario == ((eFeed*)pFeedB)->popularidad_usuario)
    {
        retAux =  comparePopularidadPublicacion(pFeedA,pFeedB);
    }

       return retAux;
}

int comparePopularidadPublicacion(void* pFeedA, void* pFeedB)
{

    if(((eFeed*)pFeedA)->popularidad_mensaje > ((eFeed*)pFeedB)->popularidad_mensaje)
    {
        return 1;
    }
    if(((eFeed*)pFeedA)->popularidad_mensaje < ((eFeed*)pFeedB)->popularidad_mensaje)
    {
        return -1;
    }
    return 0;
}

eFeed* nuevoFeed(int id_mensaje,char* mensaje,int popularidad_mensaje,int id_usuario,char* nick,int popularidad_usuario)
{
    eFeed* returnAux = NULL;
    eFeed* pFeed = (eFeed*)malloc(sizeof(eFeed));

    if(pFeed != NULL)
    {
        strcpy(pFeed->mensaje,mensaje);
        strcpy(pFeed->nick,nick);
        pFeed->id_mensaje=id_mensaje;
        pFeed->id_usuario=id_usuario;
        pFeed->popularidad_mensaje=popularidad_mensaje;
        pFeed->popularidad_usuario=popularidad_usuario;
        returnAux = pFeed;
    }
    return returnAux;
}

int cargarFeed(ArrayList* pList, ArrayList* pList2, ArrayList* pList3)
{
    ePost* post;
    eUsuario* usuario;
    eFeed* feed;
    int auxReturn = -1;

    for(int i=0; i<al_len(pList); i++)
    {
        usuario=(eUsuario*)al_get(pList,i);
        for(int j=0; j<al_len(pList2); j++)
        {
            post=(ePost*)al_get(pList2,j);
            if(post->id_usuario == usuario->id_usuario)
            {
                feed=nuevoFeed(post->id_mensaje,post->mensaje,post->popularidad,post->id_usuario,usuario->nick,usuario->popularidad);
                al_add(pList3,feed);
            }
        }
    }
    auxReturn = 0;
    return auxReturn;
}

void printFeed(FILE* f, eFeed* p)
{
    fprintf(f,"\n%d,%s,%d,%d,%s,%d\n",p->id_mensaje,p->mensaje,p->popularidad_mensaje,p->id_usuario,p->nick,p->popularidad_usuario);

}

int devolverFeed(ArrayList* pList)
{

    FILE* f;
    eFeed* feed;
    int auxReturn = -1;

    f = fopen("feed.csv","w");
    if(f!=NULL)
    {
        while(!al_isEmpty(pList))
        {
            feed=(eFeed*)al_pop(pList,0);
            printFeed(f,feed);
        }
    }
    fclose(f);
    auxReturn = 0;

    return auxReturn;
}

void printFeeds(eFeed* p)
{
    printf("\n%d,%d,%d,%s,%d\n",p->id_mensaje,p->popularidad_mensaje,p->id_usuario,p->nick,p->popularidad_usuario);

}

void listarFeed(ArrayList* pList)
{
    int i;
    for( i=0; i<al_len(pList); i++)
    {
        printFeeds((eFeed*)al_get(pList,i));
    }
}

void freeArrayList(ArrayList* pList, ArrayList* pList2, ArrayList* pList3)
{
    al_deleteArrayList(pList);
    al_deleteArrayList(pList2);
    al_deleteArrayList(pList3);
}
