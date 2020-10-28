#include "pila.h"

void inicPila(pila * p)
{
    (*p) = inicLista();
}

int pilaVacia(pila p)
{
    int flag = 1;

    if (p)
    {
        flag = 0;
    }

    return flag;
}

void apilar(pila * p,  dato) /// falta el tipo de dato recibido
{
    agregarAlPrincipio(p,crearNodo(dato));
}

 despilar(pila * p) /// falta el tipo de dato a retornar
{
    aux; /// falta el tipo de dato del auxiliar

    aux = (*p)->dato;

    borrarPrimero(p);

    return aux;
}

 tope(pila p) /// falta el tipo de dato a retornar
{
    return p->dato;
}

void mostrarPila(pila p)
{
    pila aux;

    inicPila(&aux);

    while (!pilaVacia(p))
    {
        mostrar(tope(p)); /// mostrar es de la libreria lista simple
        apilar(&aux,despilar(&p));
    }
}
