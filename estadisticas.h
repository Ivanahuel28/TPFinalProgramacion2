#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

#include "arbolCliente.h"

////////////////////ESTADISTICAS/////////////////////////////
void controlarDetalleCliente(nodoArbol* arbolClientes);
int gastosTotales(nodoLista* consumos);
int gastoMinimo(nodoLista* consumos);
int gastoMaximo(nodoLista* consumos);
void muestraEstadisticas(nodoLista * listaConsumos);

////////////////////////CONSUMOS/////////////////////////
void muestraConsumos(nodoLista * consumos);
int sumaConsumosXMes(nodoArbol* arbolClientes, int nroCliente, int mes);

#endif // ESTADISTICAS_H_INCLUDED
