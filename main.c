#include <stdio.h>
#include <stdlib.h>

#include "fechas.h"
#include "arbolCliente.h"
#include "aleatorios.h"


nodoArbol * menuClientes(nodoArbol * arbolClientes);

int main()
{
    srand(time(NULL));
    nodoArbol* arbolClientes = inicArbol();

    generarArchivoClientesAleatorio(AR_CLIENTES, 50);
    generarArchConsumosAleatorios(AR_CONSUMOS,AR_CLIENTES);

    arbolClientes = cargarArbolArchivos(AR_CLIENTES, AR_CONSUMOS, arbolClientes);

    menuPrincipal(arbolClientes);

    return 0;
}


//////////// FUNCIONES DE VISUALIZACION ///////////////

/**************************************************************************
* \brief Imprime en pantalla las opciones del menu principal
**************************************************************************/
void mostrarMenuPrincipal(){
    printf("\n SISTEMA DE CONTROL \n\n");
    printf("\n 1) Clientes ");
    printf("\n 2) Consumos ");
    printf("\n\n\n (ESC) Salir");
}

/**************************************************************************
* \brief Imprime en pantalla las opciones del menu de clientes
**************************************************************************/
void mostrarMenuClientes(){
    printf("\n CLIENTES \n\n");
    printf("\n 1) Agregar clientes ");
    printf("\n 2) Visualizar clientes ");
    printf("\n 3) Modificar un cliente ");
    printf("\n 4) Dar de baja un cliente ");
    printf("\n\n\n (ESC) Volver ");
}

/**************************************************************************
* \brief Imprime en pantalla las opciones del menu de consumos
**************************************************************************/
void mostrarMenuConsumos(){
    printf("\n CONSUMOS \n\n");
    printf("\n 1) Agregar consumos ");
    printf("\n 2) Visualizar consumos ");
    printf("\n 3) Modificar un consumo / Dar de baja ");
    printf("\n\n\n (ESC) Volver ");
}

//////////// FUNCIONES DE CONTROL ///////////////

/**************************************************************************
* \brief Maneja el menu principal, redirije a submenus
**************************************************************************/
void menuPrincipal(nodoArbol * arbolClientes){
    char opcion;
    do{
        system("cls");
        mostrarMenuPrincipal();
        opcion = getch();
        system("cls");
        switch(opcion){
            case 49:
                arbolClientes = menuClientes(arbolClientes);
                break;
            case 50:
                menuConsumos(arbolClientes);
                break;
        }
    }while(opcion != ESC);
}

/**************************************************************************
* \brief Maneja el menu de consumos, llama las funciones principales de consumos
**************************************************************************/
void menuConsumos(nodoArbol * arbolClientes){
    char opcion;
    do{
        system("cls");
        mostrarMenuConsumos();
        opcion = getch();
        system("cls");
        switch(opcion){
            case 49:
                controlarCargaManual(arbolClientes);
                break;
            case 50:
                mostrarArbolConsumosMenu(arbolClientes);
                break;
            case 51:
                controlarModificacionConsumo(arbolClientes);
                break;
        }
    }while(opcion != ESC);
}

/**************************************************************************
* \brief Maneja el menu de clientes, llama las funciones principales de clientes
**************************************************************************/
nodoArbol * menuClientes(nodoArbol * arbolClientes){
    char opcion;
    do{
        system("cls");
        mostrarMenuClientes();
        opcion = getch();
        system("cls");
        switch(opcion){
            case 49:
                arbolClientes = cargarClientesManual(arbolClientes);
                break;
            case 50:
                mostrarArbolClientesNuevo(arbolClientes);
                break;
            case 51:
                arbolClientes = controlarModificacionCliente(arbolClientes);
                break;
            case Cuatro:
                controlarBajaCliente(arbolClientes);
                break;
        }
    }while(opcion != ESC);
    return arbolClientes;
}


