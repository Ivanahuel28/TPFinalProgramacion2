nodoLista * inicLista()
{
   return NULL;
}

nodoLista * crearNodo(stConsumo dato)
{
    nodoLista * nuevo = (nodoLista*) malloc(sizeof(nodoLista));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoLista * agregarPpio (nodoLista * lista, nodoLista * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    return lista;
}

nodoLista * buscarUltimo(nodoLista * lista)
{
    nodoLista * seg = lista;

    while(seg->siguiente)
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodoLista * buscarConsumoXFecha(nodoLista * lista,int anio,int mes,int dia)
{
    nodoLista * seg = lista;
    int flag = 0;

    while ((seg) && (flag != 1))
    {
        if ((seg->dato.anio == anio) && (seg->dato.mes == mes) && (seg->dato.dia == dia) )
        {
            flag = 1;
        }
        else
        {
            seg=seg->siguiente;
        }
    }

    return seg;
}

nodoLista * agregarFinal(nodoLista * lista,nodoLista * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoLista * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }

    return lista;
}

nodoLista * borrarNodo(nodoLista* lista,nodoLista * nodo)
{
    if ( lista )
    {
        if ( lista == p )
        {
            nodoLista * aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            lista->sig = borrarNodoRec(lista->siguiente,p);
        }
    }

    return lista;
}

nodoLista * agregarEnOrden(nodoLista * lista, nodoLista * nuevoNodo)
{
    if (lista)
    {
        if (  ) /// comparar a que la fecha sea mas chica
        {
            nuevoNodo->sig = lista;
            lista = nuevoNodo;
        }
        else
        {
            lista->sig = agregarEnOrden(lista->sig,nuevoNodo);
        }
    }

    return lista;
}

nodolista * borrarTodaLaLista(nodoLista * lista)
{
    if (lista)
    {
        lista = borrarTodaLaLista(lista->sig);
        free(lista);
        lista = NULL;
    }

    return lista;
}

void muestraLista(nodoLista * lista)
{
    if (lista)
    {
        muestraNodo(lista);
        muestraLista(lista->sig);
    }
}

nodoLista * eliminarPrimerNodo(nodoLista * lista)
{
    nodoLista * aux = lista;
    lista=lista->siguiente;
    free(aux);

    return lista;
}

stConsumo verPrimero(nodoLista * lista)
{
    return lista->dato;
}
