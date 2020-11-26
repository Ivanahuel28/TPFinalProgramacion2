#include "cliente.h"

///////////////// FUNCIONES DE ALTA /////////////////


/**************************************************************************
* \brief Funcion que agrega un cliente al archivo de clientes
* \param stCliente cliente a agregar
**************************************************************************/
void agregarUnCliente(stCliente c){
    FILE *pArchClientes = fopen(AR_CLIENTES, "ab");
    if(pArchClientes){
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief Valida si existe una @ en un string
* \param char email[]
* \return int 0 si no existe - 1 si existe
*
**************************************************************************/
int validaEmail(char email[]){
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0){
        if(email[i]==64){ /// =='@'
            flag=1;
        }
        i++;
    }
    return flag;
}

///////////////// FUNCIONES DE MODIFICACION /////////////////

/**************************************************************************
* \brief Funcion que obtiene un valor entero cualquiera manualmente
* \return int valor obtenido
**************************************************************************/
int obtenerInt(){
    int valor;
    printf("\n\t Ingrese nuevo valor : ");
    scanf("%d", &valor);
    return valor;
}

/**************************************************************************
* \brief Funcion que muestra las opciones para modificar un cliente
* \param stCliente cliente a modificar
**************************************************************************/
void mostrarModificacion(stCliente c) {

    printf("\n\n\t ----------------------------------------");
    printf("\n\t 1) Nro Cliente ......: %d", c.nroCliente);
    printf("\n\t 2) Nombre ...........: %s", c.nombre);
    printf("\n\t 3) Apellido .........: %s", c.apellido);
    printf("\n\t 4) DNI ..............: %s", c.dni);
    printf("\n\t 5) Email ............: %s", c.email);
    printf("\n\t 6) Domicilio ........: %s", c.domicilio);
    printf("\n\t 7) Movil ............: %s", c.movil);
    printf("\n\t 8) Baja .............: %s", (c.baja) ? "SI" : "NO" );
    printf("\n\n\n\t Cancelar (ESC)   |    Confirmar (c)");
}


/**************************************************************************
* \brief Sobreescribe un cliente en un archivo de clientes
* \param stCliente c el cliente modificado
**************************************************************************/
void modificarClienteArchivo(stCliente c) {
    int pos = 0;
    pos = posPorIdCliente(c.idCliente);
    FILE *pArchClientes = fopen(AR_CLIENTES, "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        fwrite(&c, sizeof(stCliente), 1, pArchClientes);
        fclose(pArchClientes);
    }
}

///////////////// FUNCIONES DE BUSQUEDA /////////////////

/*************************************************************************
*
* \brief Busca la posicion en el archivo de un determinado cliente por su id
* \param int id
* \return int posicion
*
**************************************************************************/
int posPorIdCliente(int id){
    int pos = -1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(pos == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0){
            if(c.idCliente == id){
                pos = ftell(pArchClientes)/sizeof(stCliente) -1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}

/**************************************************************************
*
* \brief Retorna el ultimo id cargado
* \return int -1 si no hay registros o el id del ultimo registro
*
**************************************************************************/
int ultimoIdCliente() {
    stCliente c;
    int id = -1;
    FILE *pArchCliente = fopen(AR_CLIENTES, "rb");
    if(pArchCliente){
        fseek(pArchCliente, sizeof(stCliente)*(-1),SEEK_END);
        if(fread(&c,sizeof(stCliente),1,pArchCliente) > 0){
            id = c.idCliente;
        }
        fclose(pArchCliente);
    }
    return id;
}


void cartelInformacionCliente(){
    printf("\n%s%s                                     INFORMACION DEL CLIENTE                                  ", TAB, TAB);
}


/*************************************************************//**
*
* \brief Muestra las opciones de visualizacion como encabezado
*
*****************************************************************/
void encabezado()
{
    printf("\n%s%s--------------------------------------------------------------------------------------", TAB, TAB);
    printf("\n%s%s|                                                                                    |", TAB, TAB);
    printf("\n%s%s|(1) FILTRAR  | (2) VER TODO | (3) MODIFICAR CLIENTE | (4) VER DETALLE | (ESC) SALIR |", TAB, TAB);
    printf("\n%s%s|                                                                                    |", TAB, TAB);
    printf("\n%s%s--------------------------------------------------------------------------------------\n", TAB, TAB);
}

/*************************************************************//**
*
* \brief Muestra una barra a modo de footer de lista de clientes
*
*****************************************************************/
void footerDeCliente()
{
    printf("%s---------------------------------------------------------------------------------------------------------------------------------\n", TAB);
}

/*************************************************************//**
*
* \brief Muestra las propiedades de los clientes como encabezado de la lista de clientes
*
*****************************************************************/
void headerDeCliente()
{
    printf("\n%s---------------------------------------------------------------------------------------------------------------------------------", TAB);
    printf("\n%s|             |                |                  |          |                         |                     |           |      |", TAB);
    printf("\n%s| Nro Cliente |     Nombre     |     Apellido     |    DNI   |          Email          |      Domicilio      |   Movil   | Baja |", TAB);
    printf("\n%s|             |                |                  |          |                         |                     |           |      |", TAB);
    printf("\n%s---------------------------------------------------------------------------------------------------------------------------------\n", TAB);

}

/**********************************************************************
* \brief Funcion que muestra las opciones de los filtros de clientes
********************************************************************/
void mostrarFiltros() {

    printf("\n\n\t ----------- FILTRAR POR ---------------");
    printf("\n\t ----------------------------------------");
    printf("\n\t 1) Nro Cliente ......: ");
    printf("\n\t 2) Nombre ...........: ");
    printf("\n\t 3) Apellido .........: ");
    printf("\n\t 4) DNI ..............: ");
    printf("\n\t 5) Email ............: ");
    printf("\n\t 6) Domicilio ........: ");
    printf("\n\t 7) Movil ............: ");
    printf("\n\t 8) Baja .............: ");
    printf("\n\n\n\t Cancelar (ESC)     \n\n\n");

}

/*************************************************************//**
*
* \brief Muestra un cliente formateado correctamente
* \param stCliente cliente que mostrar
*
*****************************************************************/
void mostrarUnCliente(stCliente c){
    char nroClienteF[30] = "";
    formatearCeldaEntero(c.nroCliente,nroClienteF, 14);

    char nombreF[30] = "";
    formatearCeldaString(c.nombre,nombreF, 17);

    char apellidoF[30] = "";
    formatearCeldaString(c.apellido,apellidoF, 19);

    char dniF[30] = "";
    formatearCeldaString(c.dni,dniF, 11);

    char emailF[30] = "";
    formatearCeldaString(c.email,emailF, 26);

    char domicilioF[30] = "";
    formatearCeldaString(c.domicilio,domicilioF, 22);

    char movilF[30] = "";
    formatearCeldaString(c.movil,movilF, 12);

    char bajaF[30] = "";
    formatearCeldaString(c.baja ? "SI" : "NO" ,bajaF, 7);

    printf("%s|%s%s%s%s%s%s%s%s\n",TAB ,nroClienteF , nombreF, apellidoF, dniF, emailF, domicilioF, movilF,bajaF );
}

/*************************************************************//**
*
* \brief Formatea un entero para que entre dentro de un tamaño especifico y le pone un separador
* \param int valor entero a formatear
* \param char string al que pasar el valor formateado
* \param int tamaño al que formatear el valor
*
*****************************************************************/
void formatearCeldaEntero(int valor, char formateado[], int tamanoMaximo) {
    char aux[100];
    itoa(valor, aux, 10);
    int length = strlen(aux);

    if( length < tamanoMaximo - 1) {
            int espacioVacio = tamanoMaximo - 1 - length;
            int mitad = espacioVacio / 2;

            for(int i = 0; i < mitad; i++){
                formateado[i] = ' ';
            }

            strcat(formateado, aux);

            for(int i = length + mitad; i < tamanoMaximo; i++){
                formateado[i] = ' ';
            }

            formateado[tamanoMaximo - 1] = '|';

    } else {

        for(int i = 0; i < tamanoMaximo; i++){
            formateado[i] = aux[i];
        }
        formateado[tamanoMaximo - 1] = '|';

    }

}


/*************************************************************//**
*
* \brief Formatea un entero para que entre dentro de un tamaño especifico y le pone un separador
* \param char string a formatear
* \param char string al que pasar el valor formateado
* \param int tamaño al que formatear el valor
*
*****************************************************************/
void formatearCeldaString(char valor[], char formateado[] ,int tamanoMaximo) {

    int length = strlen(valor);

    if( length < tamanoMaximo - 1) {

        int espacioVacio = tamanoMaximo - 1 - length;
        int mitad = espacioVacio / 2;

        for(int i = 0; i < mitad; i++){
            formateado[i] = ' ';
        }

        strcat(formateado, valor);

        for(int i = length + mitad; i < tamanoMaximo; i++){
            formateado[i] = ' ';
        }

        formateado[tamanoMaximo - 1] = '|';

    } else {
        for(int i = 0; i < tamanoMaximo; i++){
            formateado[i] = valor[i];
        }
        formateado[tamanoMaximo - 1] = '|';
    }

}
