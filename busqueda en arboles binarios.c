#include <stdio.h>
#include <stdlib.h>

//estructura nodo
typedef struct nodo {
    int dato;
    struct nodo *hijo_izquierdo;
    struct nodo *hijo_derecho;
    struct nodo *padre;
} NODO;

//prototipos
void menu(NODO **raiz);
void agregar_dato(NODO **raiz);
void buscar_dato(NODO *raiz);
void recorrer_arbol(NODO *raiz);
NODO *crear_nodo(int dato, NODO *hoja);
NODO *buscar(int dato, NODO *hoja);
void acomodar(int dato, NODO **hoja);
void orden(NODO *hoja);

//main
int main() {
    NODO *raiz = NULL;
    menu(&raiz);
    
    return 0;
}

//menu
void menu(NODO **raiz){
    int opc;
    do{
        printf("\t\t ****Menu de busqueda de arboles binarios****\n\n");
        printf("\n1.-Insertar elemento en el arbol");
        printf("\n2.-Realizar busqueda de un elemento");
        printf("\n3.-Recorrer el arbol");
        printf("\n4.-Salir\n");
        printf("Selecione la opcion deseada: ");
        scanf("%i", &opc);
        
        switch(opc){
            case 1:{
                agregar_dato(raiz);
                break;
            }
            case 2:{
                buscar_dato(*raiz);
                break;
            }
            case 3:{
                recorrer_arbol(*raiz);
                break;
            }
        }
    }while(opc!=4);
    if(opc==4){
        printf("\n\nVuelva pronto ;)");
    }
}

// Agregar elemento
void agregar_dato(NODO **raiz){
    int dato;
    printf("Dime el numero que deseas agregar al arbol: ");
    scanf("%i", &dato);
    acomodar(dato, raiz);
}

// Buscar elemento
void buscar_dato(NODO *raiz){
    int dato;
    printf("Digita el numero que deseas encontrar: ");
    scanf("%i", &dato);
    NODO *resultado = buscar(dato, raiz);
    if(resultado != NULL){
        printf("Tu dato se encontro en la direccion %p\n", resultado);
    } else {
        printf("Ese dato no se encuentra en el arbol\n");
    }
}



// Recorrer arbol
void recorrer_arbol(NODO *raiz){
    printf("Recorrido en orden\n");
    orden(raiz);
    printf("\n");
}

NODO *crear_nodo(int dato, NODO *hoja){
    NODO *nuevo = malloc(sizeof(NODO));
    nuevo->dato = dato;
    nuevo->hijo_derecho = nuevo->hijo_izquierdo = NULL;
    nuevo->padre = hoja;
    return nuevo;
}

// Buscar datos
NODO *buscar(int dato, NODO *hoja){
    while (hoja != NULL) {
        if (dato > hoja->dato) {
            hoja = hoja->hijo_derecho;
        } else if (dato < hoja->dato) {
            hoja = hoja->hijo_izquierdo;
        } else {
            return hoja;
        }
    }
    return NULL;
}


// Acomodar datos
void acomodar(int dato, NODO **hoja){
    if (*hoja == NULL) {
        *hoja = crear_nodo(dato, NULL);
    } else if (dato > (*hoja)->dato) {
        acomodar(dato, &((*hoja)->hijo_derecho));
    } else if (dato < (*hoja)->dato) {
        acomodar(dato, &((*hoja)->hijo_izquierdo));
    } else {
        printf("Valor duplicado, no se agregara al arbol\n");
    }
}
//ordenar
void orden(NODO *hoja){
    if(hoja!=NULL){
        orden(hoja->hijo_izquierdo);
        printf("%i ", hoja->dato);
        orden(hoja->hijo_derecho);
    }
}
	
	
	
	

