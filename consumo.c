#include "consumo.h"

/**************************************************************************
* \brief Agrega un consumo al archivo
* \param stConsumo Consumo a agregar
**************************************************************************/
void agregarUnConsumo(stConsumo c){
    FILE *pArchConsumos = fopen(AR_CONSUMOS, "ab");
    if(pArchConsumos){
        fwrite(&c,sizeof(stConsumo),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}

/**************************************************************************
*
* \brief Retorna el ultimo id cargado
* \return int -1 si no hay registros o el id del ultimo registro
*
**************************************************************************/
int ultimoIdConsumos() {
    stConsumo c;
    int id = -1;
    FILE *pArchConsumos = fopen(AR_CONSUMOS, "rb");
    if(pArchConsumos){
        fseek(pArchConsumos, sizeof(stConsumo)*(-1),SEEK_END);
        if(fread(&c,sizeof(stConsumo),1,pArchConsumos) > 0){
            id = c.idConsumo;
        }
        fclose(pArchConsumos);
    }
    return id;
}


/**************************************************************************
* \brief Modifica un consumo en el archivo
* \param stConsumo consumo a modificar
**************************************************************************/
void modificarConsumo(stConsumo c) {
    int pos = 0;
    pos = buscaPosConsumos(c.idConsumo);
    FILE *pArchConsumos = fopen(AR_CONSUMOS, "r+b");
    if(pArchConsumos){
        fseek(pArchConsumos, sizeof(stConsumo)*pos, SEEK_SET);
        fwrite(&c, sizeof(stConsumo), 1, pArchConsumos);
        fclose(pArchConsumos);
    }
}

/**************************************************************************
* \brief Muestra las opciones para modificar un consumo
* \param stConsumo Consumo a modificar
**************************************************************************/
void mostrarModificacionConsumo(stConsumo c){

    printf("\n\t ----------------------------------------");
    printf("\n\t 1) Anio ....................: %d", c.anio);
    printf("\n\t 2) Mes .....................: %d", c.mes);
    printf("\n\t 3) Dia .....................: %d", c.dia);
    printf("\n\t 4) Datos comsumidos ........: %d MB", c.datosConsumidos);
    printf("\n\t 5) Baja ....................: %s", (c.baja) ? "SI" : "NO" );
    printf("\n\t Cancelar (ESC)   |    Confirmar (c)\n\n");

}


///////////////// FUNCIONES DE BUSQUEDA /////////////////

/*********************************************************************//**
*
* \brief Busca la posicion en el archivo de un determinado consumo por su id
* \param int id
* \return int posicion
*
**************************************************************************/
int buscaPosConsumos(int id){
    int pos = -1;
    stConsumo c;
    FILE *pArchConsumos = fopen(AR_CONSUMOS, "rb");
    if(pArchConsumos){
        while(pos==-1 && fread(&c, sizeof(stConsumo), 1, pArchConsumos) > 0){
            if(c.idConsumo == id){
                pos = ftell(pArchConsumos)/sizeof(stConsumo)-1;
            }
        }
        fclose(pArchConsumos);
    }

    return pos;
}

/**************************************************************************
* \brief Muestra opciones de filtros por pantalla
**************************************************************************/
void mostrarFiltrosConsumos(){
    printf("\n\n\t ----------- FILTRAR POR ---------------");
    printf("\n\t ----------------------------------------");
    printf("\n\t 1) Nro Cliente .........: ");
    printf("\n\t 2) Dia .................: ");
    printf("\n\t 3) Mes .................: ");
    printf("\n\t 4) Anio ................: ");
    printf("\n\t 5) Datos Minimos .......: ");
    printf("\n\t 6) Datos Maximos .......: ");
    printf("\n\t 7) Baja ................: ");
    printf("\n\n\n\t Cancelar (ESC)     ");

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


/******************************************
* \brief Muestra un consumo por pantalla
* \param stConsumo Consumo a mostrar
********************************************/
void mostrarUnConsumo(stConsumo c, int nroCliente){
        char fechaCompleta[30] = "";
        char anio[10] = "";
        char mes[4] = "";
        char dia[4] = "";

        itoa(c.anio, anio, 10);
        itoa(c.mes, mes, 10);
        itoa(c.dia, dia, 10);

        strcat(fechaCompleta, dia);
        strcat(fechaCompleta, "/");
        strcat(fechaCompleta, mes);
        strcat(fechaCompleta, "/");
        strcat(fechaCompleta, anio);

        char fechaCompletaF[30] = "";
        formatearCeldaString(fechaCompleta,fechaCompletaF, 16);

        char nroClienteF[30] = "";
        formatearCeldaEntero(nroCliente,nroClienteF, 14);

        char datosConsumidosF[30] = "";
        formatearCeldaEntero(c.datosConsumidos,datosConsumidosF, 13);

        char bajaF[30] = "";
        formatearCeldaString(c.baja ? "SI" : "NO", bajaF, 12);

        printf("%s%s|%s%s%s%s\n", TAB, TAB, nroClienteF, fechaCompletaF ,datosConsumidosF , bajaF);

}
