#include "estadisticas.h"
////////////////////ESTADISTICAS/////////////////////////////
/**************************************************************************
* \brief Función que muestra las estadísticas por Número de Cliente
* \param nodoArbol arbol de clientes
**************************************************************************/
void muestraEstadisticas(nodoArbol* arbolClientes){
    int nroCliente;

    printf("\n Ingrese el número de cliente a realizar las estadísticas: ");
    fflush(stdin);
    scanf("%d", &nroCliente);

    if(!buscarXNroCliente(arbolClientes, nroCliente)){
        printf("\n El número de cliente ingresado no existe");
        system("pause");
    }

    printf("\t -------------------------------------------ESTADISTICAS------------------------------------- \n\n");
    printf("\t|  GASTOS TOTALES  |  PROMEDIO MENSUAL  |  PROMEDIO DIARIO  |  GASTO MAXIMO  |  GASTO MINIMO |\n");
    printf("\t|--------------------------------------------------------------------------------------------|\n");
    printf("\t|     %d    |     %d    |     %d    |     %d    |     %d    |\n", gastosTotales(arbolClientes, nroCliente), gastosTotales(arbolClientes, nroCliente)/12, gastosTotales(arbolClientes, nroCliente)/365, gastoMinimo(arbolClientes, nroCliente), gastoMaximo(arbolClientes, nroCliente));
    printf("\t -------------------------------------------------------------------------------------------- \n");


    system("pause");
}
/**************************************************************************
* \brief Función que retorna la suma de gastos totales por Número de Cliente
* \param nodoArbol arbol de clientes
* \param int número de clientes
* \return gastos - son los gastos totales
**************************************************************************/
int gastosTotales(nodoArbol* arbolClientes, int nroCliente){
   int gastos = 0;
   nodoLista * consumos = buscarXNroCliente(arbolClientes, nroCliente)->consumos;

   while(consumos){
        gastos = gastos + consumos->dato.datosConsumidos;
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
int gastoMinimo(nodoArbol* arbolClientes, int nroCliente){
    nodoLista* consumos = buscarXNroCliente(arbolClientes, nroCliente)->consumos;
    int min = 0;

    if ( consumos )
    {
        min = consumos->dato.datosConsumidos;
    }

    while(consumos){
        if(consumos->dato.datosConsumidos < min){
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
int gastoMaximo(nodoArbol* arbolClientes, int nroCliente){
    nodoLista* consumos = buscarXNroCliente(arbolClientes, nroCliente)->consumos;
    int max = 0;

    if ( consumos )
    {
        max =consumos->dato.datosConsumidos;
    }

    while(consumos){
        if(consumos->dato.datosConsumidos > max){
            max = consumos->dato.datosConsumidos;
        }
        consumos = consumos->siguiente;
    }

    return max;
}

////////////////////////CONSUMOS/////////////////////////
/**************************************************************************
* \brief Función que muestra los consumos de un cliente
* \param nodoArbol arbol de clientes
* \param int número de cliente
**************************************************************************/
void muestraConsumos(nodoArbol* arbolClientes, int nroClientes){
    nodoLista* consumos = buscarXNroCliente(arbolClientes, nroClientes)->consumos;

    printf("\t -----------------CONSUMOS------------ \n\n");
    printf("\t|     FECHA     |     MB     |     BAJA   |\n");
    while(consumos){
        printf("\t|  %d/%d/%d    |     %d     |     %d     |\n", consumos->dato.dia, consumos->dato.mes, consumos->dato.anio, consumos->dato.datosConsumidos, consumos->dato.baja);
        consumos = consumos->siguiente;
    }
    printf("\t ------------------------------ \n");


    system("pause");
}
/**************************************************************************
* \brief Función que retorna la suma de consumos de un mes
* \param nodoArbol arbol de clientes
* \param int número de clientes
* \param int mes
* \return suma - suma de los consumos por mes
**************************************************************************/
int sumaConsumosXMes(nodoArbol* arbolClientes, int nroCliente, int mes){
    int suma = 0;
    nodoLista* consumos = buscarXNroCliente(arbolClientes, nroCliente)->consumos;

    while(consumos){
        if(consumos->dato.mes == mes){
            suma = suma + consumos->dato.datosConsumidos;
        }
        consumos = consumos->siguiente;
    }
    return suma;
}
