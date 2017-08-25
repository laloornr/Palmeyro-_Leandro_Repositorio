#define MENU "Menu de Opciones\n\n 1) ALTA PROGRAMADOR \n 2) MODIFICAR DATOS DEL PROGRAMADOR \n 3) BAJA DEL PROGRAMADOR \n 4) ASIGNAR PROGRAMADOR A UN PROYECTO \n 5) LISTADO DE PROGRAMADORES\n 6) LISTADO DE TODOS LOS PROYECTOS\n 7) LISTAR PROYECTOS DE PROGRAMADOR\n 8) PROYECTO DEMANDANTE \n 9) SALIR\n\nOpcion: "

#define PROGRAMADORES 50
#define PROYECTOS 1000


#define LIBRE 0
#define ALTA 1
#define BAJA 2

#define JUNIOR 0
#define SEMI_JUNIOR 1
#define SENIOR 2

typedef struct
{
    int idCategoria;
    int descripcion;
    int pagoXhora;
    char nombre[20];
    char apellido[20];
    int estado;
} eProgramador;

typedef struct
{
    int idProyecto;
    char nombre[30];
    int contProg;
    int estado;
} eProyecto;

typedef struct{
int idCategoria;
int idProyecto;
int estado;
}eProgramadorProyecto;


int esNumerico(char str[]) ;
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

void inicializarUsuarios(eProgramador programador[],int tam);
void inicializarProyectos(eProyecto proyecto[]);
void inicializarProgProyec(eProgramadorProyecto progProyec[],int tamProgProyec);

int obtenerEspacioLibre(eProgramador programador[],int tam);
int obtenerIndice(eProgramador programador[],int tam);


void altaProgramador(eProgramador programador[],int tam);

void cargarProgramador(eProgramador programador[],int tam,int indice);
void modificarProgramador(eProgramador programador[],int tam);
void modificar(eProgramador programador[],int i);
int buscarID(eProgramador programador[],int tam, int id);
void bajaUsuario(eProgramador programador[],int tam);
int buscarIDIndice(eProgramador programador[],int tam, int id);
void asignarProgramador(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec);
void bajaUsuarioProyecto(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec);
void listarUsuarios(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec);
void listarProyectos(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec);
void listarProyectoProgramador(eProgramador programador[],int tamProgramador,eProyecto proyecto[],int tamProyecto,eProgramadorProyecto progProyec[],int tamProgProyec);



