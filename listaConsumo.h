#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
#include "consumo.h"

typedef struct{
    stConsumo dato;
    struct nodoLista * siguiente;
}nodoLista;

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
void controlarFiltrosConsumo(stFiltroConsumos * filtro);

nodoLista * inicLista();
nodoLista * crearNodo(stConsumo dato);
nodoLista * agregarEnOrden(nodoLista * lista, nodoLista * nuevoNodo);

nodoLista * buscarConsumoXFecha(nodoLista * lista,int anio,int mes,int dia);

nodoLista * borrarNodo(nodoLista* lista,nodoLista * nodo);

void darDeBajaListaConsumos(nodoLista * lista);

void muestraEstadisticas(nodoLista * listaConsumos);
void muestraConsumos(nodoLista * consumos);
void muestraConsumosFiltrado(nodoLista * consumos, int nroCliente, stFiltroConsumos filtro);

int gastosTotales(nodoLista* consumos);
int gastoMinimo(nodoLista* consumos);
int gastoMaximo(nodoLista* consumos);
void liquidacionMes(nodoLista* consumos);
int sumaConsumosXMes(nodoLista* consumos, int mes);
int ingresarMes();



#endif // LISTACONSUMO_H_INCLUDED
