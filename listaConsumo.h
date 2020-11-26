#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED
#define AR_CONSUMOS "consumos.dat"
#define TAB "\t\t"
#define ESC 27

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
nodoLista * eliminarPrimerNodo(nodoLista * lista);
stConsumo verPrimero(nodoLista * lista);
void encabezadoEstadisticas();

int gastosTotales(nodoLista* consumos);
int gastoMinimo(nodoLista* consumos);
int gastoMaximo(nodoLista* consumos);
void muestraEstadisticas(nodoLista * listaConsumos);
void muestraConsumos(nodoLista * consumos);

typedef struct
{
    char nroCliente[30];
    int dia;
    int mes;
    int anio;
    int datosConsumidosMin;
    int datosConsumidosMax;
    int baja;

    int activado;
}stFiltroConsumos;
void limpiarFiltroConsumos(stFiltroConsumos * filtro);


#endif // LISTACONSUMO_H_INCLUDED
