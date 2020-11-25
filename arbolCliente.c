#include "arbolCliente.h"

///////////////// FUNCIONES BASICAS /////////////////

/*************************************************************//**
*
* \brief Inicializa el arbol
* \return nodoArbol * NULL
*
*****************************************************************/
nodoArbol * inicArbol() {
    return NULL;
}

/*************************************************************//**
*
* \brief genera un nodo y retorna su puntero
* \param stCliente con el/los cuales generar el nodo del arbol
* \return nodoArbol * puntero al nodo
*
*****************************************************************/
nodoArbol * crearNodoArbol(stCliente dato)
{
    nodoArbol * aux = (nodoArbol * ) malloc(sizeof( nodoArbol ) );
    aux->dato=dato;
    aux->consumos = NULL;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}



///////////////// FUNCIONES DE ALTA /////////////////

/**************************************************************************
* \brief Funcion que maneja la carga de clientes manuales
* \param nodoArbol arbol de clientes al que se debe cargar el cliente
* \return nodoArbol arbol de clientes con el cliente cargado
**************************************************************************/
nodoArbol* cargarClientesManual(nodoArbol* arbolClientes){
    char opcion;
    do{
        stCliente c;
        system("cls");
        c = cargaManualUnCliente(arbolClientes);
        agregarUnCliente(c);
        arbolClientes = insertarXNroCliente(arbolClientes, c);
        system("cls");
        printf("\n\n\n (ESC) Terminar");
        opcion = getch();
    }while(opcion != ESC);
    return arbolClientes;
}


/**************************************************************************
* \brief Funcion de formulario para un nuevo cliente validando los datos
* \return stCliente cliente cargado
**************************************************************************/
stCliente cargaManualUnCliente(nodoArbol* arbolClientes) {
    stCliente c;

    do{
        printf("\n Ingrese el nro de Cliente......: ");
        scanf("%d", &c.nroCliente);
    }while(c.nroCliente < 0 || buscarXNroCliente(arbolClientes,c.nroCliente));

    printf("\n Ingrese el DNI.................: ");
    fflush(stdin);
    gets(c.dni);

    printf(" Ingrese el Nombre................: ");
    fflush(stdin);
    gets(c.nombre);

    printf(" Ingrese el Apellido..............: ");
    fflush(stdin);
    gets(c.apellido);

    do{
        printf(" Ingrese el Email.................: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));

    printf(" Ingrese el Domicilio.............: ");
    fflush(stdin);
    gets(c.domicilio);

    printf(" Ingrese el Numero de telefono....: ");
    fflush(stdin);
    gets(c.movil);

    c.idCliente = ultimoIdCliente() + 1;
    c.baja = 0;

    return c;
}



/**************************************************************************
* \brief Funcion que ingresa un consumo de forma manual y lo retorna
* \return stConsumo El consumo ingresado
**************************************************************************/
stConsumo cargaManualUnConsumo(nodoArbol * arbolClientes) {
    stConsumo c;
    nodoArbol * arbolCliente = inicArbol();

    int nroCliente = -1;
    do{
        printf("\n Ingrese el nro de Cliente......: ");
        scanf("%d", &nroCliente);
        arbolCliente = buscarXNroCliente(arbolClientes, nroCliente);
    }while(nroCliente < 0 || !arbolCliente);
    do{
        printf("\n Ingrese el Anio................: ");
        scanf("%d", &c.anio);
    }while(c.anio < 0 || c.anio > 2999);
    do{
        printf("\n Ingrese el Mes.................: ");
        scanf("%d", &c.mes);
    }while(c.mes < Enero || c.mes > Diciembre);
    do{
        printf("\n Ingrese el Dia.................: ");
        scanf("%d", &c.dia);
    }while(!esFechaValida(c.anio, c.mes, c.dia));


    printf("\n Ingrese los Datos Consumidos...: ");
    scanf("%d", &c.datosConsumidos);

    c.idCliente = arbolCliente->dato.idCliente;
    c.idConsumo = ultimoIdConsumos() + 1;
    c.baja = 0;
    return c;
}

/**************************************************************************
* \brief Funcion que carga un consumo completo al archivo
**************************************************************************/
void controlarCargaManual(nodoArbol * arbolClientes){

    stConsumo c = cargaManualUnConsumo(arbolClientes);
    sumarONuevo(arbolClientes, c);
}



void sumarONuevo(nodoArbol * arbolClientes,stConsumo c) {

    nodoArbol * cliente = buscarXidClienteDiferido(arbolClientes, c.idCliente);

    if (cliente) {
        nodoLista * consumo = buscarConsumoXFecha(cliente->consumos, c.anio, c.mes, c.dia);
        if(consumo){

            consumo->dato.datosConsumidos += c.datosConsumidos;
            modificarConsumo(consumo->dato);


        } else {

            cliente->consumos = agregarEnOrden(cliente->consumos, crearNodo(c));
            agregarUnConsumo(c);

        }
    }

}



///////////////// FUNCIONES DE MODIFICACION /////////////////

/**************************************************************************
* \brief Funcion formulario para la modificacion de un cliente con validacion de datos
* \param nodoArbol Arbol de clientes del que modificar el cliente
* \param stCliente cliente a modificar
* \return nodoArbol Arbol de clientes modificado
**************************************************************************/
nodoArbol* formularioModificacionCliente(nodoArbol* arbolClientes, stCliente cm){
    char opcion;
    do{
        mostrarModificacion(cm);
        fflush(stdin);
        opcion = getch();
        switch (opcion){
            case Uno:{
                int valor;
                valor = obtenerInt();
                if(!buscarXNroCliente(arbolClientes, valor)){
                    cm.nroCliente = valor;
                } else {
                    printf("\n\n Ya existe un cliente con ese Nro Cliente! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Dos:{
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &cm.nombre );
                break;
            }
            case Tres:{
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &cm.apellido);
                break;
            }
            case Cuatro:{
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &cm.dni);
                break;
            }
            case Cinco:{
                char valor[MAX_MAIL];
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &valor);
                if(validaEmail(valor)){
                    strcpy(&cm.email, valor);
                } else {
                    printf("\n\n Correo invalido! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Seis:{
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &cm.domicilio);
                break;
            }
            case 55:{
                printf("\n Ingrese nuevo valor : ");
                scanf("%s", &cm.movil);
                break;
            }
            case 56:{
                int valor;
                valor = obtenerInt();
                if(valor == 0 || valor == 1) {
                    cm.baja = valor;
                } else {
                    printf("\n\n Valor incorrecto, solo: ( 0 / 1 )! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
        }
    }while (opcion != ESC && opcion != 'c');
    if(opcion == 'c'){
        modificarClienteArchivo(cm);
        arbolClientes = modificarClienteArbol(arbolClientes, cm);
    }
    return arbolClientes;
}

/**************************************************************************
* \brief Modifica un nodo cliente en el arbol de clientes
* \param nodoArbol Arbol de clientes del que modificar el cliente
* \param stCliente cliente a modificar
* \return nodoArbol Arbol de clientes modificado
**************************************************************************/
nodoArbol* modificarClienteArbol(nodoArbol* arbolClientes, stCliente c){

    nodoArbol* aModificar = buscarXidClienteDiferido(arbolClientes, c.idCliente);
    nodoArbol* modificado = crearNodoArbol(c);
    modificado->consumos = aModificar->consumos;
    arbolClientes = borrarXNroCliente(arbolClientes, aModificar->dato.nroCliente);
    arbolClientes = agregarNodoArbol(arbolClientes, modificado);

    return arbolClientes;
}


/**************************************************************************
* \brief Funcion que controla la modificacion de un cliente
* \param nodoArbol Arbol de clientes del que modificar el cliente
**************************************************************************/
nodoArbol* controlarModificacionCliente(nodoArbol* arbolClientes){
    nodoArbol* nodoCliente;
    int nroCliente = -1;
    printf("Ingrese el Nro Cliente a modificar : ");
    scanf("%d", &nroCliente);
    nodoCliente = buscarXNroCliente(arbolClientes, nroCliente);
    if(nodoCliente){
       arbolClientes = formularioModificacionCliente(arbolClientes, nodoCliente->dato);
    } else {
        printf("El Nro Cliente ingresado no existe en el registro");
        system("pause");
    }

    return arbolClientes;
}


/**************************************************************************
* \brief Funcion que controla la modificacion de un consumo
**************************************************************************/
void controlarModificacionConsumo(nodoArbol* arbolClientes){
    nodoArbol* nodoCliente;
    int nroCliente = -1;
    printf("Ingrese el Nro Cliente del consumo a modificar : ");
    scanf("%d", &nroCliente);
    nodoCliente = buscarXNroCliente(arbolClientes, nroCliente);

    if (nodoCliente){

        int anio = 0, mes = 0, dia = 0;
        printf("\n Ingrese anio: --/--/----");
        scanf("%d", &anio);
        printf("\n Ingrese mes : --/--/%d", anio);
        scanf("%d", &mes);
        printf("\n Ingrese dia : --/%d/%d", mes, anio);
        scanf("%d", &dia);

        nodoLista * consumo = buscarConsumoXFecha(nodoCliente->consumos, anio, mes, dia);
        if (consumo) {
            formularioModificacionConsumo(arbolClientes, nodoCliente->consumos, consumo);
            //modificamos en archivo
        } else {
            printf("El consumo ingresado no existe en el registro");
            system("pause");
        }

    } else {
        printf("El Nro Cliente ingresado no existe en el registro");
        system("pause");
    }

}


/**************************************************************************
* \brief Obtiene y valida los datos para la modificacion de un consumo
* \param stConsumo consumo a modificar
**************************************************************************/
nodoLista * formularioModificacionConsumo(nodoArbol * arbolClientes ,nodoLista * listaConsumos ,nodoLista * consumo){
    stConsumo cm = consumo->dato;
    char opcion;
    do{
        mostrarModificacionConsumo(cm);
        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case Uno:{
                int valor;
                valor = obtenerInt();
                if(valor > 0 && valor < 2999){
                    cm.anio = valor;
                } else {
                    printf("\n\n A�o incorrecto! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Dos:{
                int valor;
                valor = obtenerInt();
                if(valor > 0 && valor < 13){
                    cm.mes = valor;
                } else {
                    printf("\n\n Mes incorrecto! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Tres:{
                int valor;
                valor = obtenerInt();
                if(esFechaValida(cm.anio, cm.mes, valor)){
                    cm.dia = valor;
                } else {
                    printf("\n\n Dia incorrecto! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Cuatro:{
                int valor;
                valor = obtenerInt();
                cm.datosConsumidos = valor;
                break;
            }
            case Cinco:{
                int valor;
                valor = obtenerInt();
                if(valor == 0 || valor == 1) {
                    cm.baja = valor;
                } else {
                    printf("\n\n Valor incorrecto, solo: ( 0 / 1 )! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
        }

    }while(opcion != ESC && opcion != 'c');

    if(opcion == 'c'){
        //volver a checkear fecha por si modifico mes/a�o despues del dia
        if(esFechaValida(cm.anio, cm.mes, cm.dia)){
            //esta todo ok, lo borro y lo doy de alta
            listaConsumos = borrarNodo(listaConsumos, consumo);
            sumarONuevo(arbolClientes, cm);
        } else {
            printf("\n\n Error, fecha erronea! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
            system("pause");
        }
    }

    return listaConsumos;
}





///////////////// FUNCIONES DE BAJA /////////////////

/**************************************************************************
* \brief Funcion que controla la baja de un consumo del arbol de clientes y del archivo
* \param nodoArbol arbol de clientes del que dar de baja el consumo
**************************************************************************/
void controlarBajaConsumo(nodoArbol * arbolClientes) {

    nodoArbol* nodoCliente;
    int nroCliente = -1;
    printf("Ingrese el Nro Cliente del consumo a dar de baja : ");
    scanf("%d", &nroCliente);
    nodoCliente = buscarXNroCliente(arbolClientes, nroCliente);

    if (nodoCliente){

        int anio = 0, mes = 0, dia = 0;
        printf("\n Ingrese anio: --/--/----");
        scanf("%d", &anio);
        printf("\n Ingrese mes : --/--/%d", anio);
        scanf("%d", &mes);
        printf("\n Ingrese dia : --/%d/%d", mes, anio);
        scanf("%d", &dia);

        nodoLista * consumo = buscarConsumoXFecha(nodoCliente->consumos, anio, mes, dia);
        if (consumo) {
            consumo->dato.baja = true;
            modificarConsumo(consumo->dato);
        } else {
            printf("El consumo ingresado no existe en el registro");
            system("pause");
        }
    } else {
        printf("El Nro Cliente ingresado no existe en el registro");
        system("pause");
    }
}


/**************************************************************************
* \brief Da de baja un cliente y sus consumos
* \param nodoArbol Nodo cliente al que dar de baja
**************************************************************************/
void darDeBajaCliente(nodoArbol* nodoCliente) {

    nodoCliente->dato.baja = true;
    modificarClienteArchivo(nodoCliente->dato);
    darDeBajaListaConsumos(nodoCliente->consumos);

}

/**************************************************************************
* \brief Da de baja un cliente y sus consumos
* \param nodoArbol Arbol de clientes del que dar de baja un cliente
**************************************************************************/
void controlarBajaCliente(nodoArbol* arbolClientes) {

    nodoArbol* nodoCliente;
    int nroCliente = -1;
    printf("Ingrese el Nro Cliente a dar de baja : ");
    scanf("%d", &nroCliente);
    nodoCliente = buscarXNroCliente(arbolClientes, nroCliente);
    if(nodoCliente){
        darDeBajaCliente(nodoCliente);
    } else {
        printf("El Nro Cliente ingresado no existe en el registro");
        system("pause");
    }

}


///////////////// FUNCIONES DE INSERCION /////////////////


/*************************************************************//**
*
* \brief inserta el dato recibido en el arbol
* \param nodoArbol * puntero a la raiz del arbol
* \param stCliente dato dato a insertar en el arbol
* \return nodoArbol* nodo del arbol
*
*****************************************************************/
nodoArbol * insertarXNroCliente(nodoArbol * arbol, stCliente dato) {
    if( arbol )
    {
        if( dato.nroCliente > arbol->dato.nroCliente )
        {
            arbol->der = insertarXNroCliente(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertarXNroCliente(arbol->izq, dato);
        }
    }
    else
    {
        arbol = crearNodoArbol(dato);
    }

    return arbol;
}


/**************************************************************************
* \brief Pasa del archivo de clientes a un arbol de clientes orden nro cliente
* \param char[] Nombre del archivo
* \param nodoArbol arbol de clientes al que pasar
* \return nodoArbol Arbol de clientes con los datos
**************************************************************************/
nodoArbol* archivoCliente2arbol(char nombreArchivo[], nodoArbol* arbol){
    stCliente c;

    FILE *pArchCliente = fopen(nombreArchivo,"rb");

    if(pArchCliente)
    {
        while(fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            arbol = insertarXNroCliente(arbol, c);
        }
        fclose(pArchCliente);
    }

    return arbol;
}

/**************************************************************************
* \brief Pasa del archivo de consumos a un arbol de clientes
* \param char[] Nombre del archivo
* \param nodoArbol arbol de clientes al que pasar
* \return nodoArbol Arbol de clientes con los datos
**************************************************************************/
nodoArbol* archivoConsumo2arbol(char nombreArchivo[], nodoArbol* arbol){
    stConsumo c;

    FILE *pArchConsumos = fopen(nombreArchivo,"rb");

    if(pArchConsumos)
    {
        while(fread(&c,sizeof(stConsumo),1,pArchConsumos) > 0)
        {
            insertarConsumoXIdCliente(arbol, c);
        }
        fclose(pArchConsumos);
    }

    return arbol;
}


/**************************************************************************
* \brief Carga un arbol con sus respectivos consumos y clientes a partir de los archivos
* \param char[] Nombre del archivo clientes
* \param char[] Nombre del archivo consumos
* \param nodoArbol arbol de clientes al que pasar
* \return nodoArbol Arbol de clientes con los datos
**************************************************************************/
nodoArbol* cargarArbolArchivos(char nombreArchivoCliente[], char nombreArchivoConsumo[] ,nodoArbol* arbol){
    arbol = archivoCliente2arbol(nombreArchivoCliente, arbol);
    arbol = archivoConsumo2arbol(nombreArchivoConsumo, arbol);
    return arbol;
}


/*************************************************************//**
* \brief Inserta un consumo a base del idCliente
* \param nodoArbol arbol al que insertar el consumo
* \param stConsumo consumo que insertar
*****************************************************************/
void insertarConsumoXIdCliente(nodoArbol * arbol, stConsumo consumo)
{
    if (arbol)
    {
        if (arbol->dato.idCliente == consumo.idCliente)
        {
            nodoLista* lista = inicLista();
            lista = crearNodo(consumo);
            arbol->consumos = agregarEnOrden(arbol->consumos, lista);
        }
        else
        {
            insertarConsumoXIdCliente(arbol->izq,consumo);
            insertarConsumoXIdCliente(arbol->der,consumo);
        }
    }
}


/*************************************************************//**
*
* \brief Agrega un nodo al arbol
* \param nodoArbol* puntero a la raiz del arbol
* \param nodoArbol* puntero al nodo a agregar
* \return nodoArbol* nodo del arbol
*
*****************************************************************/
nodoArbol* agregarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol = nuevo;
    }else{
        if(nuevo->dato.nroCliente > arbol->dato.nroCliente){
            arbol->der = agregarNodoArbol(arbol->der, nuevo);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, nuevo);
        }
    }
    return arbol;
}


///////////////// FUNCIONES DE VISUALIZACION ////////////////


/*************************************************************//**
*
* \brief Controla las distintas funciones para visualizar un arbol de clientes
* \param nodoArbol arbol de clientes
*
*****************************************************************/
void mostrarArbolClientesNuevo(nodoArbol * arbol)
{
    char op;
    stFiltro filtro;

    limpiarFiltro(&filtro);

    do
    {
        system("cls");
        encabezado();
        headerDeCliente();
        mostrarArbolClientesFiltrado(arbol,filtro);
        footerDeCliente();

        fflush(stdin);
        op = getch();

        system("cls");

        switch ( op )
        {
            case Uno:
                controlarFiltros(&filtro);
                break;

            case Dos:
                limpiarFiltro(&filtro);
                break;

            case Tres:

                arbol = controlarModificacionCliente(arbol);
                break;

            case Cuatro:
                controlarDetalleCliente(arbol);
                break;

            default:
                break;
        }


        system("cls");

    } while ( op != ESC );
}


/*************************************************************//**
*
* \brief muestra el contenido del arbol de cliente
* \param nodoArbol * puntero a la raiz del arbol
* \return void
*
*****************************************************************/
void mostrarArbolClientes(nodoArbol * arbol)
{
    if (arbol)
    {
        mostrarArbolClientes(arbol->izq);
        mostrarUnCliente(arbol->dato);
        mostrarArbolClientes(arbol->der);
    }
}

///////////////// FUNCIONES DE BUSQUEDA /////////////////

/*************************************************************//**
*
* \brief busca un nodo por Nro de Cliente
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param int nroCliente -  Nro de Cliente a buscar
* \return nodoArbol * rta puntero al nodo buscado
*
*****************************************************************/
nodoArbol * buscarXNroCliente(nodoArbol * arbol,int nroCliente)
{
    nodoArbol * rta = NULL;

    if(arbol)
    {
        if(arbol->dato.nroCliente == nroCliente)
        {
            rta = arbol;
        }
        else
        {
            if(arbol->dato.nroCliente < nroCliente)
            {
                rta = buscarXNroCliente(arbol->der,nroCliente);
            }
            else
            {
                rta = buscarXNroCliente(arbol->izq,nroCliente);
            }
        }
    }

    return rta;
}


/*************************************************************//**
*
* \brief busca un nodo por Id de Cliente cuando no fue cargado bajo este parametro
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param int idCliente -  id de Cliente a buscar
* \return nodoArbol * rta puntero al nodo buscado
*
*****************************************************************/
nodoArbol * buscarXidClienteDiferido(nodoArbol * arbol,int idCliente)
{
    nodoArbol * retorno = NULL;

    if (arbol)
    {
        if (arbol->dato.idCliente == idCliente)
        {
            retorno = arbol;
        }
        else
        {
            retorno = buscarXidClienteDiferido(arbol->izq,idCliente);
            if ( !retorno )
            {
                retorno = buscarXidClienteDiferido(arbol->der,idCliente);
            }
        }
    }

    return retorno;
}
///////////////// FUNCIONES DE CALCULO /////////////////

/*************************************************************//**
*
* \brief cuenta la cantidad de elementos
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

///////////////// FUNCIONES DE ELIMINACION /////////////////

/*************************************************************//**
*
* \brief busca un nodo y lo borra ( por numero de cliente)
* \param nodoArbol * arbol - puntero a la raiz del arbol
* \param int nroCliente - numero de cliente a borrar
* \return nodoArbol * nuevo nodo raiz del arbol
*
*****************************************************************/
nodoArbol * borrarXNroCliente(nodoArbol * arbol,int nroCliente)
{
    if ( arbol )
    {
        if ( arbol->dato.nroCliente == nroCliente )
        {
            if ( arbol->izq )
            {
                nodoArbol * masDer = NMD(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarXNroCliente(arbol->izq,masDer->dato.nroCliente);
            }
            else
            {
                if ( arbol->der )
                {
                    nodoArbol * masIzq = NMI(arbol->der);
                    arbol->dato = masIzq->dato;
                    arbol->der = borrarXNroCliente(arbol->der,masIzq->dato.nroCliente);
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
            if ( arbol->dato.nroCliente < nroCliente)
            {
                arbol->der = borrarXNroCliente(arbol->der,nroCliente);
            }
            else
            {
                arbol->izq = borrarXNroCliente(arbol->izq,nroCliente);
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



////////////////////// DETALLE DE CLIENTE /////////////////////

/*************************************************************//**
*
* \brief Funcion que controla la visualizacion del detallede un cliente
* \param nodoArbol* puntero a la raiz del arbol
*
*****************************************************************/
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


//////////////////////FILTROS/////////////////////

/*************************************************************//**
*
* \brief Limpia el filtro que se pasa por referencia
* \param filtro * puntero al filtro
*
*****************************************************************/
void limpiarFiltro(stFiltro * filtro)
{
    strcpy(filtro->nroCliente,"");
    strcpy(filtro->nombre,"");
    strcpy(filtro->apellido,"");
    strcpy(filtro->dni,"");
    strcpy(filtro->email,"");
    strcpy(filtro->domicilio,"");
    strcpy(filtro->movil,"");

    filtro->baja = -1;

    filtro->activado = 0;
}


/*************************************************************//**
*
* \brief Mustra el arbol de clientes usando un filtro
* \param nodoArbol* puntero a la raiz del arbol a mostrar
* \param stFiltro* filtro a usar
*
*****************************************************************/
void mostrarArbolClientesFiltrado(nodoArbol * arbol,stFiltro filtro)
{
    if (arbol)
    {
        if ( !filtro.activado )
        {
            mostrarUnCliente(arbol->dato);
        }
        else
        {
            char stringNroCliente[30];

            itoa(arbol->dato.nroCliente,stringNroCliente,10);

            if ( strncmp(arbol->dato.apellido,filtro.apellido,strlen(filtro.apellido)) == 0 &&
                 strncmp(arbol->dato.nombre,filtro.nombre,strlen(filtro.nombre)) == 0 &&
                 strncmp(arbol->dato.dni,filtro.dni,strlen(filtro.dni)) == 0 &&
                 strncmp(arbol->dato.domicilio,filtro.domicilio,strlen(filtro.domicilio)) == 0 &&
                 strncmp(arbol->dato.email,filtro.email,strlen(filtro.email)) == 0 &&
                 strncmp(arbol->dato.movil,filtro.movil,strlen(filtro.movil)) == 0  &&
                 ( arbol->dato.baja == filtro.baja || filtro.baja == -1 ) &&
                 strncmp(stringNroCliente,filtro.nroCliente,strlen(filtro.nroCliente)) == 0 )
            {
                mostrarUnCliente(arbol->dato);
            }
        }

        mostrarArbolClientesFiltrado(arbol->izq,filtro);
        mostrarArbolClientesFiltrado(arbol->der,filtro);
    }
}


/*****************************************************
* \brief Funcion que controla los filtros de clientes
* \param stCliente arreglo de clientes
* \return int validos del arreglo
******************************************************/
void controlarFiltros(stFiltro * filtro){

    char opcion;

    mostrarFiltros();
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
        printf("\n\t Ingrese nombre : ");
        fflush(stdin);
        gets(filtro->nombre);
        break;

    case 51:
        printf("\n\t Ingrese Apellido : ");
        fflush(stdin);
        gets(filtro->apellido);
        break;

    case 52:
        printf("\n\t Ingrese Dni : ");
        fflush(stdin);
        gets(filtro->dni);
        break;

    case 53:
        printf("\n\t Ingrese Email : ");
        fflush(stdin);
        gets(filtro->email);
        break;

    case 54:
        printf("\n\t Ingrese Domicilio : ");
        fflush(stdin);
        gets(filtro->domicilio);
        break;

    case 55:
        printf("\n\t Ingrese Movil : ");
        fflush(stdin);
        gets(filtro->movil);
        break;

    case 56:
        printf("\n\t Ingrese baja ( 1 - SI | 0 - NO) : ");
        fflush(stdin);
        scanf("%d",&filtro->baja);
        break;
    }

    if ( opcion != ESC )
    {
        filtro->activado = 1;
    }
}

