#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#define AR_CLIENTES "clientes.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "listaConsumo.h"
#include "definiciones.h"


typedef struct{
    stCliente dato;
    nodoLista* consumos;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

/*BASICAS*/
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(stCliente dato);

/*INSERCION*/
nodoArbol * insertarXNroCliente(nodoArbol * arbol, stCliente dato);
void insertarConsumoXIdCliente(nodoArbol * arbol, stConsumo consumo);
nodoArbol* cargarClientesManual(nodoArbol* arbolClientes);
stCliente cargaManualUnCliente(nodoArbol* arbolClientes);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo);

/*MUESTRA / RECORRIDO*/
void mostrarArbolClientes(nodoArbol * arbol);

/*BAJA*/
void darDeBajaCliente(nodoArbol* nodoCliente);
void controlarBajaCliente(nodoArbol* arbolClientes);

/*MODIFICACION*/
nodoArbol* modificarClienteArbol(nodoArbol* arbolClientes, stCliente c);
nodoArbol* formularioModificacionCliente(nodoArbol* arbolClientes,stCliente cm);
nodoArbol* controlarModificacionCliente(nodoArbol* arbolClientes);
nodoLista * formularioModificacionConsumo(nodoArbol * arbolClientes ,nodoLista * listaConsumos ,nodoLista * consumo);

/*BUSQUEDA*/
nodoArbol * buscarXNroCliente(nodoArbol * arbol,int nroCliente);
nodoArbol * buscarXidClienteDiferido(nodoArbol * arbol,int idCliente);

/*CONTADORES*/
int contarElementos(nodoArbol * arbol);
int contarTerminales(nodoArbol * arbol);
int contarNiveles(nodoArbol * arbol);

/*BORRAR*/
nodoArbol * borrarXNroCliente(nodoArbol * arbol,int nroCliente);
nodoArbol * NMD(nodoArbol * arbol);
nodoArbol * NMI(nodoArbol * arbol);


/*MENU LISTADO CLIENTES*/
void menuListadoClientes(nodoArbol * arbol);
void encabezado();
void menuMostrarFiltrando(nodoArbol * arbol);
void mostrarOpcionesDeFiltro();
void mostrarFiltrandoXApellido(nodoArbol * arbol,char apellido[]);
void mostrarFiltrandoXNombre(nodoArbol * arbol,char nombre[]);
void mostrarFiltrandoXEstado(nodoArbol * arbol,int estado);


typedef struct
{
    char nroCliente[30];
    char nombre[30];
    char apellido[30];
    char dni[15];
    char email[30];
    char domicilio[45];
    char movil[15];
    int baja;

    int activado;
}stFiltro;

void limpiarFiltro(stFiltro * filtro);
void mostrarArbolClientesNuevo(nodoArbol * arbol);
void mostrarArbolClientesFiltrado(nodoArbol * arbol,stFiltro filtro);
void controlarFiltros(stFiltro * filtro);

#endif // ARBOLCLIENTE_H_INCLUDED
