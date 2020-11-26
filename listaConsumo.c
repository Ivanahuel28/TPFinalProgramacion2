#include "listaConsumo.h"


/**************************************************************************
* \brief Inicializa una lista
* \return nodoLista inicial
**************************************************************************/
nodoLista * inicLista()
{
   return NULL;
}

/**************************************************************************
* \brief Crea un nodo lista a partr de un consumo
* \return nodoLista nodo creado
**************************************************************************/
nodoLista * crearNodo(stConsumo dato)
{
    nodoLista * nuevo = (nodoLista*) malloc(sizeof(nodoLista));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}


/**************************************************************************
* \brief Agrega un nodo al principio
* \return nodoLista inicial
**************************************************************************/
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

/**************************************************************************
* \brief Da de baja una lista de consumos en la lista y en el archivo
* \return nodoLista inicial
**************************************************************************/
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
* \brief Funci�n que muestra las estad�sticas por N�mero de Cliente
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
* \brief Funci�n que retorna la suma de gastos totales por N�mero de Cliente
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
* \brief Funci�n que retorna el gasto m�nimo por N�mero de Cliente
* \param nodoArbol arbol de clientes
* \param int n�mero de clientes
* \return min - gasto m�nimo
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
* \brief Funci�n que retorna el gasto m�ximo por N�mero de Cliente
* \param nodoArbol arbol de clientes
* \param int n�mero de clientes
* \return max - gasto m�ximo
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
* \brief Funci�n que muestra los consumos de un cliente
* \param nodoArbol arbol de clientes
* \param int n�mero de cliente
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


/**************************************************************************
* \brief Funci�n que muestra los consumos de un cliente
* \param nodoArbol arbol de clientes
* \param int n�mero de cliente
**************************************************************************/
void muestraConsumosFiltrado(nodoLista * consumos, int nroCliente, stFiltroConsumos filtro){

    while(consumos){
        if(!filtro.activado){
            mostrarUnConsumo(consumos->dato, nroCliente);
        } else {
            char stringNroCliente[30];
            itoa(nroCliente,stringNroCliente,10);

            if(
                ( consumos->dato.dia == filtro.dia || filtro.dia == -1 ) &&
                ( consumos->dato.mes == filtro.mes || filtro.mes == -1 ) &&
                ( consumos->dato.anio == filtro.anio || filtro.anio == -1 ) &&
                ( consumos->dato.baja == filtro.baja || filtro.baja == -1 ) &&
                ( consumos->dato.datosConsumidos >= filtro.datosConsumidosMin || filtro.datosConsumidosMin == -1 ) &&
                ( consumos->dato.datosConsumidos <= filtro.datosConsumidosMax || filtro.datosConsumidosMax == -1 ) &&
                 strncmp(stringNroCliente,filtro.nroCliente,strlen(filtro.nroCliente)) == 0 )
               {
                mostrarUnConsumo(consumos->dato, nroCliente);
             }

        }
        consumos = consumos->siguiente;
    }

}




void mostrarFooterDeConsumo() {
    printf("%s%s--------------------------------------------------------\n", TAB, TAB);
}

void mostrarHeaderConsumos() {
    printf("%s%s--------------------------------------------------------\n", TAB, TAB);
    printf("%s%s| NRO CLIENTE |     FECHA     |     MB     |    BAJA   |\n", TAB, TAB);
    printf("%s%s--------------------------------------------------------\n", TAB, TAB);
}


void encabezadoEstadisticas(){
    printf("\n\t\t-----------------------------------------------------------------------------------------");
    printf("\n\t\t|                                                                                       |");
    printf("\n\t\t|(1) VER TODO  | (2) FILTRAR | (3) LIQUIDAR MES | (4) MODIFICAR CONSUMO | (ESC) SALIR   |");
    printf("\n\t\t|                                                                                       |");
    printf("\n\t\t-----------------------------------------------------------------------------------------\n");
}

/*************************************************************//**
*
* \brief Limpia el filtro que se pasa por referencia
* \param filtro * puntero al filtro
*
*****************************************************************/
void limpiarFiltroConsumos(stFiltroConsumos * filtro)
{
    strcpy(filtro->nroCliente,"");
    filtro->dia = -1;
    filtro->mes = -1;
    filtro->anio = -1;
    filtro->datosConsumidosMin = -1;
    filtro->datosConsumidosMax = -1;
    filtro->baja = -1;
    filtro->activado = 0;
}


/**
* \brief Función que retorna la suma de consumos de un mes
* \param nodoArbol arbol de clientes
* \param int número de clientes
* \param int mes
* \return suma - suma de los consumos por mes
**/
int sumaConsumosXMes(nodoLista* consumos, int mes){
    int suma = 0;

    while(consumos){
        if(consumos->dato.mes == mes && !consumos->dato.baja){
            suma = suma + consumos->dato.datosConsumidos;
        }
        consumos = consumos->siguiente;
    }
    return suma;
}
int ingresarMes(){
    int mes = 0;

    printf("\n\t(1) ENERO");
    printf("\n\t(2) FEBRERO");
    printf("\n\t(3) MARZO");
    printf("\n\t(4) ABRIL");
    printf("\n\t(5) MAYO");
    printf("\n\t(6) JUNIO");
    printf("\n\t(7) JULIO");
    printf("\n\t(8) AGOSTO");
    printf("\n\t(9) SEPTIEMBRE");
    printf("\n\t(10) OCTUBRE");
    printf("\n\t(11) NOVIEMBRE");
    printf("\n\t(12) DICIEMBRE");

    printf("\n\n\tIngrese el mes a liquidar: ");

    fflush(stdin);
    scanf("%d", &mes);
    system("cls");
    return mes;
}

void liquidacionMes(nodoLista* consumos){
    int mes = ingresarMes();
    int liquidacion = 0;
    int costo = 0;

    printf("\n\tIngrese el valor por MB: ");
    scanf("%d", &costo);
    system("cls");
    liquidacion = sumaConsumosXMes(consumos, mes) * costo; ///completar costo

    printf("\n\n\tLa liquidacion correspondiente al mes %d es de: $%d\n\n\n", mes, liquidacion);
}


/*****************************************************
* \brief Funcion que controla los filtros de consumos
* \param stFiltroConsumos filtro
******************************************************/
void controlarFiltrosConsumo(stFiltroConsumos * filtro){

    char opcion;

    mostrarFiltrosConsumos();
    fflush(stdin);
    opcion = getch();
    switch (opcion)
    {
    case 49:
        printf("\n\t Ingrese Nro de Cliente : ");
        fflush(stdin);
        gets(filtro->nroCliente);
        break;

    case 50:
        printf("\n\t Ingrese Dia : ");
        scanf("%d", &filtro->dia);
        break;

    case 51:
        printf("\n\t Ingrese Mes : ");
        scanf("%d", &filtro->mes);
        break;

    case 52:
        printf("\n\t Ingrese Anio : ");
        scanf("%d", &filtro->anio);
        break;

    case 53:
        printf("\n\t Ingrese Datos Consumidos Minimo : ");
        scanf("%d", &filtro->datosConsumidosMin);
        break;

    case 54:
        printf("\n\t Ingrese Datos Consumidos Maximo : ");
        scanf("%d", &filtro->datosConsumidosMax);
        break;


    case 55:
        printf("\n\t Ingrese baja ( 1 - SI | 0 - NO) : ");
        scanf("%d", &filtro->baja);
        break;
    }

    if ( opcion != ESC )
    {
        filtro->activado = 1;
    }
}
