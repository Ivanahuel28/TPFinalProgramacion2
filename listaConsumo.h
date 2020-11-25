#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED
#define AR_CONSUMOS "consumos.dat"
#define TAB "\t\t"

#include <stdio.h>
#include <stdlib.h>
#include "consumo.h"

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
void darDeBajaListaConsumos(nodoLista * lista);
void muestraLista(nodoLista * lista);
void muestraNodo(nodoLista * nodo);
nodoLista * eliminarPrimerNodo(nodoLista * lista);
stConsumo verPrimero(nodoLista * lista);

int gastosTotales(nodoLista* consumos);
int gastoMinimo(nodoLista* consumos);
int gastoMaximo(nodoLista* consumos);
void muestraEstadisticas(nodoLista * listaConsumos);
void muestraConsumos(nodoLista * consumos);


#endif // LISTACONSUMO_H_INCLUDED
