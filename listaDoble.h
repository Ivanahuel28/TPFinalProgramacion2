#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _dato{
    int id;
}Dato;

typedef struct _nodoDoble{
    Dato dato;
    struct _nodoDoble *anterior;
    struct _nodoDoble *siguiente;
}nodoDoble;

nodoDoble* inicLista2();
nodoDoble* crearNodoDoble(Dato dato);
nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
void muestrNodoDoble(nodoDoble* lista);
void muestraListaDoble(nodoDoble* lista);
Dato verPrimeroDoble(nodoDoble* lista);
nodoDoble* borrarPrimeroDoble(nodoDoble* lista);
#endif // LISTADOBLE_H_INCLUDED
