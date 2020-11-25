#include "listaConsumo.h"

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

void darDeBajaListaConsumos(nodoLista * lista) {

    nodoLista * aux = lista;
    while (aux) {
        aux->dato.baja = 1;
        modificarConsumo(aux->dato);
        aux = aux->siguiente;
    }

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
        if ( lista == nodo )
        {
            nodoLista * aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            lista->siguiente = borrarNodo(lista->siguiente,nodo);
        }
    }

    return lista;
}

nodoLista * agregarEnOrden(nodoLista * lista, nodoLista * nuevoNodo)
{
    if (lista)
    {
        if (
            izqMasChica(nuevoNodo->dato.anio,
                        nuevoNodo->dato.mes,
                        nuevoNodo->dato.dia,
                        lista->dato.anio,
                        lista->dato.mes,
                        lista->dato.dia) ) /// comparar a que la fecha sea mas chica
        {
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
        else
        {
            lista->siguiente = agregarEnOrden(lista->siguiente,nuevoNodo);
        }
    } else {
            lista = nuevoNodo;
    }

    return lista;
}

nodoLista * borrarTodaLaLista(nodoLista * lista)
{
    if (lista)
    {
        lista = borrarTodaLaLista(lista->siguiente);
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
        muestraLista(lista->siguiente);
    }
}

void muestraNodo(nodoLista * nodo)
{
    mostrarUnConsumo(nodo->dato);
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

/**************************************************************************
* \brief Función que muestra las estadísticas por Número de Cliente
* \param nodoArbol arbol de clientes
**************************************************************************/
void muestraEstadisticas(nodoLista * listaConsumos){

    int gastosTotalesINT = gastosTotales(listaConsumos);
    char gastosTotalesF[30] = "";
    formatearCeldaEntero(gastosTotalesINT,gastosTotalesF, 19);

    char promedioMensualF[30] = "";
    formatearCeldaEntero(gastosTotalesINT / 12, promedioMensualF, 21);

    char promedioDiarioF[30] = "";
    formatearCeldaEntero(gastosTotalesINT / 365, promedioDiarioF, 20);


    int gastoMaximoINT = gastoMaximo(listaConsumos);
    char gastoMaximoF[30] = "";
    formatearCeldaEntero(gastoMaximoINT,gastoMaximoF, 17);

    int gastoMinimoINT = gastoMinimo(listaConsumos);
    char gastoMinimoF[30] = "";
    formatearCeldaEntero(gastoMinimoINT,gastoMinimoF, 16);


    printf("\n\n%s\t\t--------------------------------------------ESTADISTICAS--------------------------------------\n",TAB);
    printf("%s\t\t|  GASTOS TOTALES  |  PROMEDIO MENSUAL  |  PROMEDIO DIARIO  |  GASTO MAXIMO  |  GASTO MINIMO |\n",TAB);
    printf("%s\t\t|--------------------------------------------------------------------------------------------|\n",TAB);
    printf("%s\t\t|%s%s%s%s%s\n",TAB, gastosTotalesF, promedioMensualF, promedioDiarioF, gastoMaximoF, gastoMinimoF );
    printf("%s\t\t---------------------------------------------------------------------------------------------- \n",TAB);

}

/**************************************************************************
* \brief Función que retorna la suma de gastos totales por Número de Cliente
* \param nodoLista lista de consumos
* \return gastos - son los gastos totales
**************************************************************************/
int gastosTotales(nodoLista* consumos){
   int gastos = 0;

   while(consumos){

        if(!consumos->dato.baja) {
            gastos = gastos + consumos->dato.datosConsumidos;
        }

        consumos = consumos->siguiente;
   }

   return gastos;
}

/**************************************************************************
* \brief Función que retorna el gasto mínimo por Número de Cliente
* \param nodoArbol arbol de clientes
* \param int número de clientes
* \return min - gasto mínimo
**************************************************************************/
int gastoMinimo(nodoLista* consumos){
    int min = 0;

    if ( consumos ) {
        min = consumos->dato.datosConsumidos;
    }

    while(consumos){
        if(consumos->dato.datosConsumidos < min && !consumos->dato.baja){
            min = consumos->dato.datosConsumidos;
        }
        consumos = consumos->siguiente;
    }

    return min;
}
/**************************************************************************
* \brief Función que retorna el gasto máximo por Número de Cliente
* \param nodoArbol arbol de clientes
* \param int número de clientes
* \return max - gasto máximo
**************************************************************************/
int gastoMaximo(nodoLista* consumos){
    int max = 0;

    if ( consumos ){
        max =consumos->dato.datosConsumidos;
    }

    while(consumos){
        if(consumos->dato.datosConsumidos > max && !consumos->dato.baja){
            max = consumos->dato.datosConsumidos;
        }
        consumos = consumos->siguiente;
    }

    return max;
}

/**************************************************************************
* \brief Función que muestra los consumos de un cliente
* \param nodoArbol arbol de clientes
* \param int número de cliente
**************************************************************************/
void muestraConsumos(nodoLista * consumos){

    printf("%s%s\t\t\t------------------CONSUMOS----------------\n", TAB, TAB);
    printf("%s%s\t\t\t|     FECHA     |     MB     |    BAJA   |\n", TAB, TAB);

    while(consumos){
        char fechaCompleta[30] = "";
        char anio[10] = "";
        char mes[4] = "";
        char dia[4] = "";

        itoa(consumos->dato.anio, anio, 10);
        itoa(consumos->dato.mes, mes, 10);
        itoa(consumos->dato.dia, dia, 10);

        strcat(fechaCompleta, dia);
        strcat(fechaCompleta, "/");
        strcat(fechaCompleta, mes);
        strcat(fechaCompleta, "/");
        strcat(fechaCompleta, anio);

        char fechaCompletaF[30] = "";
        formatearCeldaString(fechaCompleta,fechaCompletaF, 16);

        char datosConsumidosF[30] = "";
        formatearCeldaEntero(consumos->dato.datosConsumidos,datosConsumidosF, 13);

        char bajaF[30] = "";
        formatearCeldaString(consumos->dato.baja ? "SI" : "NO", bajaF, 12);

        printf("%s%s\t\t\t|%s%s%s\n", TAB, TAB,fechaCompletaF ,datosConsumidosF , bajaF);
        consumos = consumos->siguiente;
    }
    printf("%s%s\t\t\t------------------------------------------\n", TAB, TAB );

}

