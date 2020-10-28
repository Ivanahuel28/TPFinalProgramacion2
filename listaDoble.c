#include "listaDoble.h"

nodoDoble* inicListaDoble(){
    return NULL;
}

nodoDoble* crearnodoDoble(Dato dato){
    nodoDoble* nuevo = (nodoDoble*) malloc(sizeof(nodoDoble));

    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior=nuevo;
    }

    return nuevo;
}

nodoDoble* agregarPpio(nodoDoble* lista, nodoDoble* nuevo){
    if(lista == NULL){
        lista = nuevo;
    } else {
        lista->anterior = nuevo;
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodoDoble* buscarUltimoDoble(nodoDoble* lista){
    nodoDoble* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

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

void muestraNodoDoble(nodoDoble* lista){
    printf("\n nodo: %p - nodo->anterior: %p - nodo->siguiente: %p",  lista, lista->anterior, lista->siguiente);
    muestraUnCliente(lista->dato);
}

void muestraListaDoble(nodoDoble* lista){
    nodoDoble* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodoDoble(seg);
        seg = seg->siguiente;
    }
}

Dato verPrimeroDoble(nodoDoble* lista){
    return lista->dato;
}

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

