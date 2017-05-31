#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MENU "----- MENU DE OPCIONES -----\n\n1.- Agregar Pelicula\n2.- Borrar Pelicula\n3.- Modificar Pelicula\n4.- Generar Pagina Web\n5.- Salir\n\nIngrese Opcion: "
#define TAM_PELICULAS 10

#define VACIO 0
#define ALTA 1

typedef struct{

    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[120];
    int estado;
    int idMovie;
}EMovie;


void peliculas_agregar(EMovie* movies, int tam);
void peliculas_borrar(EMovie* movie, int tamMovies);
void peliculas_generarWeb(EMovie* lista, char* nombre, int tamMovies);
void peliculas_inicializar(EMovie* movies, int tamMovies);
void peliculas_carga(EMovie* movies, int tamMovies);
void peliculas_mostrar(EMovie* movies,int tamMovies);
int buscarIDindice(EMovie* movies, int tamMovies, int id);
int buscarID(EMovie* movies,int tamMovies, int id);
void peliculas_editar(EMovie* movies, int tamMovies);
int buscarLugarVacio(EMovie* movies, int tam);
int esCadena(char* buffer, int maxCadena);
int esNumeroPositivo(char* numero);
void capturarCadena(char* buffer, char* textoError, int tamDeseado);


#endif // FUNCIONES_H_INCLUDED
