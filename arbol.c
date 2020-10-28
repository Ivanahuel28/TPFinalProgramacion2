#include "arbol.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(stDatos dato)
{
    nodoArbol * aux = (nodoArbol * ) malloc(sizeof( nodoArbol ) );
    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, stDatos dato)
{
    if( arbol )
    {
        if( dato > arbol->dato )
        {
            arbol->der = insertar(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, dato);
        }
    }
    else
    {
        arbol = crearNodoArbol(dato);
    }

    return arbol;
}

void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("%d ", arbol->dato.entero);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        printf("%d ", arbol->dato.entero);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%d ", arbol->dato.entero);
    }
}

nodoArbol * buscar(nodoArbol * arbol,stDatos dato)
{
    nodoArbol * rta=NULL;

    if(arbol)
    {
        if(dato.entero == arbol->dato.entero)
        {
            rta = arbol;
        }
        else
        {
            if(dato.entero > arbol->dato.entero)
            {
                rta = buscar(arbol->der, dato);
            }
            else
            {
                rta = buscar(arbol->izq, dato);
            }
        }
    }

    return rta;
}

int contarTerminales(nodoArbol * arbol)
{
    int retorno = 0;

    if (arbol)
    {
        if ( !(arbol->izq) && !(arbol->der) )
        {
            retorno += 1;
        }
        else
        {
            retorno += contarTerminales(arbol->izq);
            retorno += contarTerminales(arbol->der);
        }
    }

    return retorno;
}

nodoArbol * buscarNodo(nodoArbol * arbol,stDatos dato)
{
    nodoArbol * retorno = NULL;

    if (arbol)
    {
        if (arbol->dato.entero == dato.entero)
        {
            retorno = arbol;
        }
        else
        {
            retorno = buscarNodo(arbol->izq,numero);
            if ( !retorno )
            {
                retorno = buscarNodo(arbol->der,numero);
            }
        }
    }

    return retorno;
}

nodoArbol * arr2tree(nodoArbol * arbol,int v,stDatos arr[v])
{
    int pos,temp;

    for( int i=0 ; i<v ; i++ )
    {
        pos = rand()%(v-i);

        temp = arr[pos];
        arr[pos] = arr[v-i-1];
        arr[v-i-1] = temp;

        arbol = insertar(arbol,temp);
    }

    return arbol;
}

nodoArbol * borrarNodo(nodoArbol * arbol,stDatos dato)
{
    if ( arbol )
    {
        if ( arbol->dato.entero == dato.entero )
        {
            if ( arbol->izq )
            {
                nodoArbol * masDer = NMD(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarNodo(arbol->izq,masDer->dato);
            }
            else
            {
                if ( arbol->der )
                {
                    nodoArbol * masIzq = NMI(arbol->der);
                    arbol->dato = masIzq->dato;
                    arbol->der = borrarNodo(arbol->der,masIzq->dato);
                }
                else
                {
                    free(arbol);
                    arbol = NULL;
                }
            }
        }
        else
        {
            if ( arbol->dato < dato)
            {
                arbol->der = borrarNodo(arbol->der,dato);
            }
            else
            {
                arbol->izq = borrarNodo(arbol->izq,dato);
            }
        }
    }

    return arbol;
}

nodoArbol * NMD(nodoArbol * arbol)
{
    if (arbol->der)
    {
        arbol = NMD(arbol->der);
    }

    return arbol;
}

nodoArbol * NMI(nodoArbol * arbol)
{


    if (arbol->izq)
    {
        arbol = NMI(arbol->izq);
    }

    return arbol;
}
