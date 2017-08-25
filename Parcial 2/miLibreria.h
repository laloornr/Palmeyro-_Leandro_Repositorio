#define MENU "--- MENU ---\n\n1. Cargar Lista de Tareas\n2. Particionar por Prioridad\n3. Ordenar\n4. Resolver Tareas\n5. Salir\n\nOpcion: "

typedef struct
{
    char nombre[20];
    int hora;
    int prioridad;
} eTarea;

int cargarDestinatarios(ArrayList* pList);
eTarea* tareaNueva(char* nombre, int prioridad,int hora);
void printTarea(eTarea* p);
int compareTarea(void* pTareaA,void* pTareaB);
void particionarListas(ArrayList* tr_Todos, ArrayList* tr_Urg,ArrayList* tr_Reg);
int proximaTarea(ArrayList* x);
int mostrarProximaTarea(ArrayList* tr_Urg, ArrayList* tr_Reg);
