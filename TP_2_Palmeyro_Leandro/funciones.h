#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_MAX 20
#define SIN_USO 0
#define EN_USO 1
#define GRAFICO "*"

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return retorna 0 si no encuentra espacio libre, 1 si lo encontro
 */
int obtenerEspacioLibre(ePersona x[],int tam);

/** \brief Obtiene el Indice que esta libre para ser usado
 *
 * \param estructura a buscar indice libre
 * \param tamaño para recorrer
 * \return retorna el indice libre
 *
 */
int obtenerIndice(ePersona x[],int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona x[], int dni,int tam);

/** \brief Inicializa el array en estado sin uso
 *
 * \param Estructura a cambiar estado
 * \param tamaño de la estructura
 */
void inicializarPersonas(ePersona x[],int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void agregarPersona(ePersona x[],int i);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int validarNombreyApellido(char texto[]);

/** \brief Obtiene el Indice que el dni esta ingresado
 *
 * \param estructura a buscar indice libre
 * \param tamaño para recorrer
 * \return retorna el indice buscado
 *
 */
int obtenerIndiceDNI(ePersona x[],int dni,int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void borrarPersona(ePersona x[],int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void imprimirLista(ePersona x[],int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ordenarLista(ePersona x[],int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void grafico(ePersona x[],int tam);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

#endif // FUNCIONES_H_INCLUDED
