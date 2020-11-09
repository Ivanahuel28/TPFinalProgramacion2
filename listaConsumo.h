#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id; /// campo �nico y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a � dependiendo del mes
    int datosConsumidos; /// expresados en mb.
    int baja; /// 0 si est� activo - 1 si est� eliminado
}stConsumo;


typedef struct{
    stConsumo dato;
    struct nodoLista * siguiente;
}nodoLista;

nodoLista * inicLista();
nodoLista * crearNodo(stConsumo dato);
nodoLista * agregarPpio (nodoLista * lista, nodoLista * nuevoNodo);
nodoLista * buscarUltimo(nodoLista * lista);
nodoLista * buscarConsumoXFecha(nodoLista * lista,int anio,int mes,int dia);
nodoLista * agregarFinal(nodoLista * lista,nodoLista * nuevoNodo);
nodoLista * borrarNodo(nodoLista* lista,nodoLista * nodo);
nodoLista * agregarEnOrden(nodoLista * lista, nodoLista * nuevoNodo);
nodoLista * borrarTodaLaLista(nodoLista * lista);
void muestraLista(nodoLista * lista);
void muestraNodo(nodoLista * nodo);
nodoLista * eliminarPrimerNodo(nodoLista * lista);
stConsumo verPrimero(nodoLista * lista);


#endif // LISTACONSUMO_H_INCLUDED
