#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listaConsumo.h"

typedef struct {
    int idCliente; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    int movil;
    int baja; /// 0 si está activo - 1 si está eliminado
} stCliente;

typedef struct nodoArbol{
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
nodoArbol* insertarConsumoXIdCliente(nodoArbol * arbol, stConsumo consumo);

/*MUESTRA / RECORRIDO*/
void mostrarArbolClientes(nodoArbol * arbol);

/*BUSQUEDA*/
nodoArbol * buscarXNroCliente(nodoArbol * arbol,int nroCliente);
nodoArbol * buscarXNroClienteDiferido(nodoArbol * arbol,int nroCliente);

/*CONTADORES*/
int contarElementos(nodoArbol * arbol);
int contarTerminales(nodoArbol * arbol);
int contarNiveles(nodoArbol * arbol);

/*BORRAR*/
nodoArbol * borrarXNroCliente(nodoArbol * arbol,int nroCliente);
nodoArbol * NMD(nodoArbol * arbol);
nodoArbol * NMI(nodoArbol * arbol);

/*PASAJES*/
nodoArbol * arr2treeXNroCliente(nodoArbol * arbol,stCliente arr[],int base,int tope);

#endif // ARBOLCLIENTE_H_INCLUDED
