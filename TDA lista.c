nodo* inicLista(){
   return NULL;
}

nodo* crearNodo (dato){ ///AGREGAR DATO
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarPpio (nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* buscarNodo(dato, nodo* lista){ ///AGREGAR DATO
    nodo* seg;
    seg = lista;
    while ((seg) && ( dato == seg->dato){ ///AGREGAR DATO
      seg=seg->siguiente;
   }
   return seg;
}

nodo* agregarFinal(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo* borrarNodo(nodo* lista, dato){ ///AGREGAR DATO
    nodo* seg;
    nodo* ante;
    if((lista) && (dato == lista->dato)){///AGREGAR DATO
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while((seg) && (dato == lista->dato )){///AGREGAR DATO
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        if(nuevoNodo->dato < lista->dato){
            lista = agregarPpio(lista, nuevoNodo);
        }else{
            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while((seg) &&(nuevoNodo->dato > lista->dato){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;
}

nodo* borrarTodaLaLista(nodo* lista){
    nodo* proximo;
    nodo* seg = lista;
    while(seg) {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

void muestraNodo(nodo *nodo){
    printf("\n nodo: %p - nodo siguiente: %p ----------------------------------------------", nodo, nodo->siguiente);
    ///AGREGAR FUNCIÓN MUESTRA DATO
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}

nodo* eliminarPrimerNodo(nodo* lista){
    nodo* aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

stPersona verPrimero(nodo* lista){
    return lista->dato;
}

