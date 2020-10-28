#include "pila.h"

/*********************************************************//**
*
* \brief Inicializa la pila recibida
* \param puntero a pila
* \return void
*
***********************************************************/
void inicPila(pila * p)
{
    (*p) = inicLista();
}

/*********************************************************//**
*
* \brief Comprueba que la pila este vacia
* \param pila como copia
* \return int flag - 1 si esta vacia - 0 si tiene al menos un elemento
*
***********************************************************/
int pilaVacia(pila p)
{
    int flag = 1;

    if (p)
    {
        flag = 0;
    }

    return flag;
}

/*********************************************************//**
*
* \brief Coloca el elemento recibido al tope de la pila
* \param puntero a la pila
* \param dato a apilar
* \return void
*
***********************************************************/
void apilar(pila * p,  dato) /// falta el tipo de dato recibido
{
    agregarAlPrincipio(p,crearNodo(dato));
}

/*********************************************************//**
*
* \brief Quita el elemento superior de la pila y lo retorna
* \param puntero a la pila
* \return dato - dato que se desapilo
*
***********************************************************/
 despilar(pila * p) /// falta el tipo de dato a retornar
{
    aux; /// falta el tipo de dato del auxiliar

    aux = (*p)->dato;

    borrarPrimero(p);

    return aux;
}

/*********************************************************//**
*
* \brief Retorna el elemento superior de la pila
* \param pila como copia
* \return dato - dato superior de la pila
*
***********************************************************/
 tope(pila p) /// falta el tipo de dato a retornar
{
    return p->dato;
}

/*********************************************************//**
*
* \brief Muestra todo el contenido de la pila
* \param pila como copia
* \return void
*
***********************************************************/
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
