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

    printf("\n ----------------------------------------");
    //printf("\n -) ID consumo .............:  %d", c.id);
    //printf("\n -) ID Cliente .............:  %d", c.idCliente);
    //printf("\n 1) Nro Cliente .............: %d", c.nroCliente);
    printf("\n 2) Anio ....................: %d", c.anio);
    printf("\n 3) Mes .....................: %d", c.mes);
    printf("\n 4) Dia .....................: %d", c.dia);
    printf("\n 5) Datos comsumidos ........: %d MB", c.datosConsumidos);
    printf("\n 6) Baja ....................: %s", (c.baja) ? "SI" : "NO" );
    printf("\n\n\n Cancelar (ESC)   |    Confirmar (c)");

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

/**
* \brief Muestra un consumo por pantalla
* \param stConsumo Consumo a mostrar
**/
void mostrarUnConsumo(stConsumo c){
    //Esta funcion deberia trabajar sobre un arreglo, por que asi es ineficiente, es algo a laburar luego la optimizacion.
    //int nroCliente = obtenerNroClientePorID(c.idCliente);
    printf("\n ----------------------------------------");
    printf("\n ID consumo .............:  %d", c.idConsumo);
    printf("\n ID Cliente .............:  %d", c.idCliente);
    //printf("\n Nro Cliente .............: %d", c.nroCliente);
    printf("\n Fecha (dia - mes - anio) : %d-%d-%d ", c.dia, c.mes, c.anio);
    printf("\n Datos comsumidos ........: %d MB", c.datosConsumidos);
    printf("\n Baja ....................: %s", (c.baja) ? "SI" : "NO" );

}
