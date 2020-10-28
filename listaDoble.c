#include "listaDoble.h"

nodoDoble* inicListaDoble(){
    return NULL;
}

/***************************************************************************
 * \brief Crea un nodo doble
 * \param Dato Dato del que se quiere crear un nodo
 **************************************************************************/
nodoDoble* crearnodoDoble(Dato dato){
    nodoDoble* nuevo = (nodoDoble*) malloc(sizeof(nodoDoble));

    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

/***************************************************************************
 * \brief Agrega al principio de la lista un nodo Doble
 * \param nodoDoble Nodo lista a la que se quiere agregar
 * \param nodoDoble Nodo nuevo a agregar a la lista
 **************************************************************************/
nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior=nuevo;
    }

    return nuevo;
}


/***************************************************************************
 * \brief Busca el ultimo nodo de una lista doble
 * \param nodoDoble Nodo lista a que se quiere buscar
 **************************************************************************/
nodoDoble* buscarUltimoDoble(nodoDoble* lista){
    nodoDoble* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

/***************************************************************************
 * \brief Agrega al final de la lista un nodo Doble
 * \param nodoDoble Nodo lista a la que se quiere agregar
 * \param nodoDoble Nodo nuevo a agregar a la lista
 **************************************************************************/
nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodoDoble* ultimo = buscarUltimoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

/***************************************************************************
 * \brief Muestra un nodo doble
 * \param nodoDoble Nodo lista que se quiere mostrar
 **************************************************************************/
void muestraNodoDoble(nodoDoble* lista){
    printf("\n nodo: %p - nodo->anterior: %p - nodo->siguiente: %p",  lista, lista->anterior, lista->siguiente);
    //muestraDato(lista->dato); CAMBIAR POR METODO DE MOSTRAR SEGUN TIPO DE DATO
}

/***************************************************************************
 * \brief Muestra una lista de nodos dobles
 * \param nodoDoble Nodo lista que se quiere mostrar
 **************************************************************************/
void muestraListaDoble(nodoDoble* lista){
    nodoDoble* seg = lista;
    while(seg){  
        muestraNodoDoble(seg);
        seg = seg->siguiente;
    }
}

/***************************************************************************
 * \brief Retorna el primer nodo de una lista
 * \param nodoDoble Nodo lista que se desea ver
 * \return Dato
 **************************************************************************/
Dato verPrimeroDoble(nodoDoble* lista){
    return lista->dato;
}

/***************************************************************************
 * \brief Borra el primer nodo de una lista de nodos dobles
 * \param nodoDoble Nodo lista al que eliminar primer nodo
 * \return nodoDoble 
 **************************************************************************/
nodoDoble* borrarPrimeroDoble(nodoDoble* lista){
    if(lista!=NULL){
        nodoDoble * aborrar=lista;
        lista=lista->siguiente;
        if(lista!=NULL){
            lista->anterior=NULL;
            free(aborrar);
        }
    }
    return lista;
}

