#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#define AR_CLIENTES "clientes.dat"

#include <stdio.h>
#include <stdlib.h>
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

/*BAJA*/
void darDeBajaCliente(nodoArbol* nodoCliente);
void controlarBajaCliente(nodoArbol* arbolClientes);

/*MODIFICACION*/
nodoArbol* formularioModificacionCliente(nodoArbol* arbolClientes,stCliente cm);
nodoArbol* modificarClienteArbol(nodoArbol* arbolClientes, stCliente c);
nodoArbol* controlarModificacionCliente(nodoArbol* arbolClientes);
/*MUESTRA / RECORRIDO*/
void mostrarArbolClientes(nodoArbol * arbol);

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

#endif // ARBOLCLIENTE_H_INCLUDED
