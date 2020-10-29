#include "fila.h"

/***************************************************************************
 * \brief Inicializa una fila
 * \param Fila fila que se quiere inicializar
 **************************************************************************/
void inicFila(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
}

/***************************************************************************
 * \brief Agrega un dato a la fila
 * \param Fila fila a la que se quiere agregar
 * \param Dato dato que se quiere agregar a la fila
 **************************************************************************/
void agregar(Fila* fila, Dato dato){
    nodoDoble* nuevo = crearNodoDoble(dato);

    fila->fin = agregarAlFinalDoble(fila->fin, nuevo);

    if(fila->inicio==NULL){
        fila->inicio = fila->fin;
    }

    fila->fin=nuevo;
}

/***************************************************************************
 * \brief Retorna el primer dato de la fila
 * \param Fila fila de la que se quiere ver el dato
 **************************************************************************/
Dato primero(Fila* fila){
    return verPrimeroDoble(fila->inicio);
}

/***************************************************************************
 * \brief Extrae de la fila un elemento y lo retorna
 * \param Fila Fila que se quiere trabajar
 **************************************************************************/
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

/***************************************************************************
 * \brief Verifica si una fila esta vacia 0 no 1 si
 * \param Fila fila a verificar
 **************************************************************************/
int filaVacia(Fila* fila){
    return (fila->inicio) ? 0 : 1;
}

/***************************************************************************
 * \brief Muestra una fila entera
 * \param Fila fila que se quiere mostrar
 **************************************************************************/
void muestraFila(Fila* fila){
    muestraListaDoble(fila->inicio);
}
