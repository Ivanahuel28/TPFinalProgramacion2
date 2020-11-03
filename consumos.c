#include "consumos.h"

//////////// FUNCIONES DE VISUALIZACION ///////////////

/**************************************************************************
* \brief Muestra un consumo por pantalla
* \param stConsumo Consumo a mostrar
**************************************************************************/
void mostrarUnConsumo(stConsumo c){
    int nroCliente = obtenerNroClientePorID(c.idCliente);
    printf("\n ----------------------------------------");
    //printf("\n ID consumo .............:  %d", c.id);
    //printf("\n ID Cliente .............:  %d", c.idCliente);
    printf("\n Nro Cliente .............: %d", nroCliente);
    printf("\n Fecha (dia - mes - anio) : %d-%d-%d ", c.dia, c.mes, c.anio);
    printf("\n Datos comsumidos ........: %d MB", c.datosConsumidos);
    printf("\n Baja ....................: %s", (c.baja) ? "SI" : "NO" );
}

/**************************************************************************
* \brief Muestra opciones de filtros por pantalla
**************************************************************************/
void mostrarFiltrosConsumos(){
    printf("\n ----------- FILTRAR POR ---------------");
    printf("\n ----------------------------------------");
    printf("\n 1) Nro Cliente .........: ");
    printf("\n 2) Anio ................: ");
    printf("\n 3) Mes .................: ");
    printf("\n 4) Dia .................: ");
    printf("\n 5) Fecha Completa ......: ");
    printf("\n 6) Baja ................: ");
    printf("\n 7) Rango de Datos en MB.: ");
    printf("\n\n\n Cancelar (ESC)     ");
}

/**************************************************************************
* \brief Muestra las opciones para modificar un consumo
* \param stConsumo Consumo a modificar
**************************************************************************/
void mostrarModificacionConsumo(stConsumo c){

    int nroCliente = obtenerNroClientePorID(c.idCliente);
    printf("\n ----------------------------------------");
    //printf("\n -) ID consumo .............:  %d", c.id);
    //printf("\n -) ID Cliente .............:  %d", c.idCliente);
    printf("\n 1) Nro Cliente .............: %d", nroCliente);
    printf("\n 2) Anio ....................: %d", c.anio);
    printf("\n 3) Mes .....................: %d", c.mes);
    printf("\n 4) Dia .....................: %d", c.dia);
    printf("\n 5) Datos comsumidos ........: %d MB", c.datosConsumidos);
    printf("\n 6) Baja ....................: %s", (c.baja) ? "SI" : "NO" );
    printf("\n\n\n Cancelar (ESC)   |    Confirmar (c)");
}

///////////////// FUNCIONES DE CARGA AUTOMATICA /////////////////


/**************************************************************************
* \brief Crea un consumo con datos aleatorios
* \return stConsumo Consumo aleatorio
**************************************************************************/
stConsumo consumoRandom(int idCliente){
    stConsumo c;
    c.idCliente = idCliente;
    fechaRandom(&c.anio, &c.mes, &c.dia);
    c.datosConsumidos = rand() % MAX_DATOS;
    c.baja = 0;
}


///////////////// FUNCIONES DE CARGA /////////////////

/**************************************************************************
* \brief Funcion que ingresa un consumo de forma manual y lo retorna
* \return stConsumo El consumo ingresado
**************************************************************************/
stConsumo cargaManualUnConsumo() {
    stConsumo c;
    int nroCliente = -1;
    do{
        printf("\n Ingrese el nro de Cliente......: ");
        scanf("%d", &nroCliente);
    }while(nroCliente < 0 || !existeNroCliente(nroCliente));
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

    c.idCliente = obtenerIdClientePorNro(nroCliente);
    c.baja = 0;
    return c;
}

///////////////// FUNCIONES DE MODIFICACION /////////////////

/**************************************************************************
* \brief Obtiene y valida los datos para la modificacion de un consumo
* \param stConsumo consumo a modificar
**************************************************************************/
void formularioModificacionConsumo(stConsumo c){
    stConsumo cm = c;
    char opcion;
    do{
        mostrarModificacionConsumo(cm);
        fflush(stdin);
        opcion = getch();
        switch(opcion){
            case Uno:{
                int valor;
                valor = obtenerInt();
                if(existeNroCliente(valor)){
                    int idCliente = obtenerIdClientePorNro(valor);
                    cm.idCliente = idCliente;
                } else {
                    printf("\n\n NO existe un cliente con ese Nro Cliente! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Dos:{
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
            case Tres:{
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
            case Cuatro:{
                int valor;
                valor = obtenerInt();
                if(esFechaValida(c.anio, c.mes, valor)){
                    cm.dia = valor;
                } else {
                    printf("\n\n Dia incorrecto! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
                break;
            }
            case Cinco:{
                int valor;
                valor = obtenerInt();
                cm.datosConsumidos = valor;
                break;
            }
            case Seis:{
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
                //verifico si no existe o si es el propio.
                int idConsumo = idConsumoPorDatos(cm.idCliente, cm.anio, cm.mes, cm.dia);
                if( idConsumo == -1 || idConsumo == cm.id) {
                    modificar(cm); //ESTO HAY QUE MEJORAR
                } else {
                    printf("\n\n Error, ese consumo ya existe! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                    system("pause");
                }
            } else {
                printf("\n\n Error, fecha erronea! ..........(OK) \n\n\n\n\n\n\n\n\n\n");
                system("pause");

            }
        }
    }

///////////////// FUNCIONES DE BAJA /////////////////


/**************************************************************************
* \brief Da de baja un consumo
* \param stConsumo consumo a dar de baja
**************************************************************************/
void bajaConsumo(stConsumo &c) {
    c.baja = 1;
}