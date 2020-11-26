#include <stdio.h>
#include <stdlib.h>

#include "fechas.h"
#include "arbolCliente.h"
#include "aleatorios.h"


void menuPrincipal(nodoArbol * arbolClientes);
void menuConsumos(nodoArbol * arbolClientes);
nodoArbol * menuClientes(nodoArbol * arbolClientes);

void mostrarMenuPrincipal();
void mostrarMenuClientes();
void mostrarMenuConsumos();



int main()
{
    srand(time(NULL));
    nodoArbol* arbolClientes = inicArbol();

    int opcion = -1;
    printf("\n\n\tBienvenido, desea generar datos nuevos?\n\t(1) - SI  |  (0) - NO\n\n");
    scanf("%d", &opcion);
    if(opcion == 1){
        generarArchivoClientesAleatorio(AR_CLIENTES, 50);
        generarArchConsumosAleatorios(AR_CONSUMOS,AR_CLIENTES);
    }

    arbolClientes = cargarArbolArchivos(AR_CLIENTES, AR_CONSUMOS, arbolClientes);

    menuPrincipal(arbolClientes);

    return 0;
}




//////////// FUNCIONES DE VISUALIZACION ///////////////

/**************************************************************************
* \brief Imprime en pantalla las opciones del menu principal
**************************************************************************/
void mostrarMenuPrincipal(){
    imprimirCabecera("SISTEMA DE CONTROL");
    printf("\n 1) Clientes ");
    printf("\n 2) Consumos ");
    printf("\n\n\n (ESC) Salir");
}

/**************************************************************************
* \brief Imprime en pantalla las opciones del menu de clientes
**************************************************************************/
void mostrarMenuClientes(){
    imprimirCabecera("CLIENTES");
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
    imprimirCabecera("CONSUMOS");
    printf("\n 1) Agregar consumos ");
    printf("\n 2) Visualizar consumos ");
    printf("\n 3) Modificar un consumo / Dar de baja ");
    printf("\n\n\n (ESC) Volver ");
}


/****************************************
* \brief Imprime Cabecera
***************************************/
void imprimirCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0; i<45; i++)
    {
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%29s%17c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0; i<45; i++)
    {
        printf("%c",205);
    }
    printf("%c", 188);
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


