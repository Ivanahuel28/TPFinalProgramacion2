#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"

typedef struct{
    nodoDoble* inicio;
    nodoDoble* fin;
}Fila;

void inicFila(Fila* fila);
void agregar(Fila* fila, Dato dato);
Dato primero(Fila* fila);
Dato extraer(Fila* fila);
int filaVacia(Fila* fila);
int filaVaciaPro(Fila* fila);
void muestraFila(Fila* fila);


#endif // FILA_H_INCLUDED
