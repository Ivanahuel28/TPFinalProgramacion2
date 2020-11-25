#include "estadisticas.h"
////////////////////ESTADISTICAS/////////////////////////////
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

void controlarDetalleCliente(nodoArbol* arbolClientes){
    int nroCliente;

    printf("\n Ingrese el numero de cliente a realizar las estadisticas: ");
    fflush(stdin);
    scanf("%d", &nroCliente);
    system("cls");
    nodoArbol * cliente = buscarXNroCliente(arbolClientes, nroCliente);
    if(cliente) {

        printf("\n\n\n");

        headerDeCliente();
        mostrarUnCliente(cliente->dato);
        footerDeCliente();
        printf("\n\n");
        muestraEstadisticas(cliente->consumos);
        printf("\n\n\n");
        muestraConsumos(cliente->consumos);

    } else {
        printf("\n El numero de cliente ingresado no existe");
        system("pause");

    }
    system("pause");
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

////////////////////////CONSUMOS/////////////////////////
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


    system("pause");
}
