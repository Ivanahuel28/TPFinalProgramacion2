#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

#include "arbolCliente.h"

////////////////////ESTADISTICAS/////////////////////////////
void muestraEstadísticas(nodoArbol* arbolClientes);
int gastosTotales(nodoArbol* arbolClientes, int nroCliente);
int gastoMinimo(nodoArbol* arbolClientes, int nroCliente);
int gastoMaximo(nodoArbol* arbolClientes, int nroCliente);

////////////////////////CONSUMOS/////////////////////////
void muestraConsumos(nodoArbol* arbolClientes, int nroClientes);
int sumaConsumosXMes(nodoArbol* arbolClientes, int nroCliente, int mes);

#endif // ESTADISTICAS_H_INCLUDED
