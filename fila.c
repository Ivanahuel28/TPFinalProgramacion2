#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
}

void agregar(Fila* fila, Dato dato){
    nodoDoble* nuevo = crearNodoDoble(dato);

    fila->fin = agregarAlFinalDoble(fila->fin, nuevo);

    if(fila->inicio==NULL){
        fila->inicio = fila->fin;
    }

    fila->fin=nuevo;
}

Dato primero(Fila* fila){
    return verPrimeroDoble(fila->inicio);
}

Dato extraer(Fila* fila){
    Dato dato;
    if(fila->inicio){
        dato = verPrimeroDoble(fila->inicio);
        fila->inicio = borrarPrimeroDoble(fila->inicio);
        if(!fila->inicio){
            fila->fin = inicListaDoble();
        }
    }
    return dato;
}

int filaVacia(Fila* fila){
    return (fila->inicio) ? 0 : 1;
}

void muestraFila(Fila* fila){
    muestraListaDoble(fila->inicio);
}
