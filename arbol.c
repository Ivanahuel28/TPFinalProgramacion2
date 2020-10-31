#include "arbol.h"

/*************************************************************//**
*
* \brief Inicializa el arbol
* \return nodoArbol * NULL
*
*****************************************************************/
nodoArbol * inicArbol()
{
    return NULL;
}

/*************************************************************//**
*
* \brief genera un nodo y retorna su puntero
* \param dato con el/los cuales generar el nodo del arbol
* \return nodoArbol * puntero al nodo
*
*****************************************************************/
nodoArbol * crearNodoArbol(stDatos dato)
{
    nodoArbol * aux = (nodoArbol * ) malloc(sizeof( nodoArbol ) );
    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

/*************************************************************//**
*
* \brief inserta el dato recibido en el arbol
* \param nodoArbol * puntero a la raiz del arbol
* \param stDatos dato dato a insertar en el arbol
* \return nodoArbol* nodo del arbol
*
*****************************************************************/
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

/*************************************************************//**
*
* \brief Muestra el contanido del arbol con recorrido preorder
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return void
*
*****************************************************************/
void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("%d ", arbol->dato.entero);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

/*************************************************************//**
*
* \brief Muestra el contanido del arbol con recorrido inorder
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return void
*
*****************************************************************/
void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        printf("%d ", arbol->dato.entero);
        inorder(arbol->der);
    }
}

/*************************************************************//**
*
* \brief Muestra el contanido del arbol con recorrido postorder
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return void
*
*****************************************************************/
void postorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%d ", arbol->dato.entero);
    }
}

/*************************************************************//**
*
* \brief busca un nodo por el mismo parametro en el que se ordenó el arbol
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param stDatos dato -  dato a buscar
* \return nodoArbol * rta puntero al nodo buscado
*
*****************************************************************/
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

/*************************************************************//**
*
* \brief busca un nodo por el mismo parametro DISTINTO al que se ordenó el arbol
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param stDatos dato -  dato a buscar
* \return nodoArbol * rta puntero al nodo buscado
*
*****************************************************************/
nodoArbol * buscarNodoDiferido(nodoArbol * arbol,stDatos dato)
{
    nodoArbol * retorno = NULL;

    if (arbol)
    {
        if (arbol->dato.letra == dato.letra)
        {
            retorno = arbol;
        }
        else
        {
            retorno = buscarNodo(arbol->izq,dato);
            if ( !retorno )
            {
                retorno = buscarNodo(arbol->der,dato);
            }
        }
    }

    return retorno;
}

/*************************************************************//**
*
* \brief copia el contenido del arreglo en el arbol ordenando por apellido
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return int contador -  cantidad de elementos del arbol
*
*****************************************************************/
int contarElementos(nodoArbol * arbol)
{
    int contador = 0;

    if (arbol)
    {
        contador += 1 + contarElementos(arbol->izq) + contarElementos(arbol->der);
    }

    return contador;
}

/*************************************************************//**
*
* \brief cuenta las terminales (u hojas del arbol)
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return int cantidad de hojas
*
*****************************************************************/
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

/*************************************************************//**
*
* \brief cuenta los niveles (o altura) del arbol
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return int cantidad de niveles
*
*****************************************************************/
int contarNiveles(nodoArbol * arbol)
{
    int nivel = 0;

    if (arbol)
    {
        if ( (arbol->izq) || (arbol->der) )
        {
            nivel += 1;
            int nivelIzq = contarNiveles(arbol->izq);
            int nivelDer = contarNiveles(arbol->der);

            if ( nivelIzq < nivelDer)
            {
                nivel += nivelDer;
            }
            else
            {
                nivel += nivelIzq;
            }
        }
    }

    return nivel;
}

/*************************************************************//**
*
* \brief busca un nodo y lo borra
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param stDatos dato -  dato a borrar
* \return nodoArbol * nuevo nodo raiz del arbol
*
*****************************************************************/
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

/*************************************************************//**
*
* \brief busca y retorna el nodo mas a la derecha del arbol
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return nodoArbol * nodo mas a la derecha
*
*****************************************************************/
nodoArbol * NMD(nodoArbol * arbol)
{
    if (arbol->der)
    {
        arbol = NMD(arbol->der);
    }

    return arbol;
}

/*************************************************************//**
*
* \brief busca y retorna el nodo mas a la izq del arbol
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \return nodoArbol * nodo mas a la izq
*
*****************************************************************/
nodoArbol * NMI(nodoArbol * arbol)
{


    if (arbol->izq)
    {
        arbol = NMI(arbol->izq);
    }

    return arbol;
}

/*************************************************************//**
*
* \brief copia el contenido del arreglo en el arbol ordenando por int
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param stDatos arr[v] - arreglo
* \param int base - subindice en que inicia el arreglo (a la llamada va 0)
* \param int base - subindice en que termina el arreglo (a la llamada va validos-1)
* \return nodoArbol * puntero al arbol cargado
*
*****************************************************************/
nodoArbol * arr2treeXApellido(nodoArbol * arbol,stDatos arr[],int base,int tope)
{
    int medio;

    if ( !(base<tope) )
    {
        medio = (base+tope)/2;
        arbol = insertar(arbol,arr[medio]);

        arbol = arr2treeXApellido(arbol,arr,base,medio-1);
        arbol = arr2treeXApellido(arbol,arr,medio+1,tope);
    }

    return arbol;
}


