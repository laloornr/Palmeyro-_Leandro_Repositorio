#include "ArrayList.h"

typedef struct
{
    int id_usuario;
    int popularidad;
    char nick[30];

}eUsuario;

typedef struct
{
    int id_mensaje;
    int popularidad;
    char mensaje[5000];
    int id_usuario;

}ePost;

typedef struct
{
    int id_mensaje;
    char mensaje[5000];
    int popularidad_mensaje;
    int id_usuario;
    char nick[30];
    int popularidad_usuario;

}eFeed;

eUsuario* nuevoUsuario(int id, int popularidad, char* nick;);

int cargarUsuarios(ArrayList* pList);

void printUsuario(eUsuario* p);

/** \brief
 *
 * \param
 * \param
 * \return
 */
void listarUsuarios(ArrayList* pList);

ePost* nuevoPost(int id_mensaje, int id_u,int popularidad, char mensaje[5000]);

int cargarPost(ArrayList* pList);

void printPost(ePost* p);

void listarPost(ArrayList* pList);

int comparePopularidadUsuario(void* pUsuarioA,void* pUsuarioB);

int comparePopularidadPublicacion(void* pPostA, void* pPostB);

eFeed* nuevoFeed(int id_mensaje,char* mensaje,int popularidad_mensaje,int id_usuario,char* nick,int popularidad_usuario);

int cargarFeed(ArrayList* pList, ArrayList* pList2, ArrayList* pList3);

void printFeed(FILE* f, eFeed* p);

int devolverFeed(ArrayList* pList);

void printFeeds(eFeed* p);

void listarFeed(ArrayList* pList);

/** \brief Libera el espacio en memoria
 *
 * \param
 * \param
 * \param
 * \param
 * \return void
 */
void freeArrayList(ArrayList* pList, ArrayList* pList2, ArrayList* pList3);

