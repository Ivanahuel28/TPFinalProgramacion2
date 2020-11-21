#ifndef MENULISTADOCLIENTES_H_INCLUDED
#define MENULISTADOCLIENTES_H_INCLUDED

#include "arbolCliente.h"

void menuListadoClientes(nodoArbol * arbol);
void encabezado();
void menuMostrarFiltrando(nodoArbol * arbol);
void mostrarOpcionesDeFiltro();
void mostrarFiltrandoXApellido(nodoArbol * arbol,char apellido[]);
void mostrarFiltrandoXNombre(nodoArbol * arbol,char nombre[]);
void mostrarFiltrandoXEstado(nodoArbol * arbol,int estado);

#endif // MENULISTADOCLIENTES_H_INCLUDED
