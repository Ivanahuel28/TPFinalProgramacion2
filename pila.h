#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "lista.h" /// completar include a la libreria lista simple

#define pila nodo* /// pila es puntero a primer nodo lista simple

void inicPila(pila * p);
int pilaVacia(pila p);
void apilar(pila * p,  dato); /// falta el tipo de dato recibido
 despilar(pila * p); /// falta el tipo de dato de retorno
 tope(pila p); /// falta el tipo de dato de retorno
void mostrarPila(pila p);

#endif // PILA_H_INCLUDED
