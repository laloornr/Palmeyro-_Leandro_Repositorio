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


int obtenerEspacioLibre(ePersona x[],int tam);
int obtenerIndice(ePersona x[],int tam);
int buscarPorDni(ePersona x[], int dni,int tam);
void inicializarPersonas(ePersona x[],int tam);
void agregarPersona(ePersona x[],int i);
int validarNombreyApellido(char texto[]);
int obtenerIndiceDNI(ePersona x[],int dni,int tam);
void borrarPersona(ePersona x[],int tam);
void imprimirLista(ePersona x[],int tam);
void ordenarLista(ePersona x[],int tam);
void grafico(ePersona x[],int tam);
int esNumerico(char str[]);

#endif // FUNCIONES_H_INCLUDED
