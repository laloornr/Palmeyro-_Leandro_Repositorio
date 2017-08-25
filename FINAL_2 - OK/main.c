#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"
#include "ArrayList.h"

int main()
{
    ArrayList* A_usuarios = al_newArrayList();
    ArrayList* A_mensajes = al_newArrayList();
    ArrayList* A_feeds = al_newArrayList();

    cargarUsuarios(A_usuarios);
  //  listarUsuarios(A_usuarios);
    cargarPost(A_mensajes);
//    listarPost(A_mensajes);
    cargarFeed(A_usuarios,A_mensajes,A_feeds);
    listarUsuarios(A_feeds);
      al_sort(A_feeds,comparePopularidadUsuario,0);
    listarFeed(A_feeds);
    devolverFeed(A_feeds);
    freeArrayList(A_usuarios,A_mensajes,A_feeds);

    return 0;
}
