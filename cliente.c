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
    printf("\n Ingrese nuevo valor : ");
    scanf("%d", &valor);
    return valor;
}

/**************************************************************************
* \brief Funcion que muestra las opciones para modificar un cliente
* \param stCliente cliente a modificar
**************************************************************************/
void mostrarModificacion(stCliente c) {

    printf("\n ----------------------------------------");
    printf("\n 1) Nro Cliente ......: %d", c.nroCliente);
    printf("\n 2) Nombre ...........: %s", c.nombre);
    printf("\n 3) Apellido .........: %s", c.apellido);
    printf("\n 4) DNI ..............: %s", c.dni);
    printf("\n 5) Email ............: %s", c.email);
    printf("\n 6) Domicilio ........: %s", c.domicilio);
    printf("\n 7) Movil ............: %s", c.movil);
    printf("\n 8) Baja .............: %s", (c.baja) ? "SI" : "NO" );
    printf("\n\n\n Cancelar (ESC)   |    Confirmar (c)");
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
