#include <stdio.h>
#include <stdlib.h>

#include "fechas.h"
#include "arbolCliente.h"


int main()
{
    srand(time(NULL));
    nodoArbol* arbolClientes = inicArbol();
/*
    for(int i = 0; i < 10; i++){
        stCliente c;
        c.idCliente = i;
        c.nroCliente = i;

        FILE *pArchClientes = fopen(AR_CLIENTES, "ab");
        if(pArchClientes){
            fwrite(&c,sizeof(stCliente),1,pArchClientes);
            fclose(pArchClientes);
        }
    }

    for(int i = 0; i < 10; i++){
        stConsumo c;
        c.idCliente = i;
        c.idConsumo = i;

        FILE *pArchConsumos = fopen(AR_CONSUMOS, "ab");
        if(pArchConsumos){
            fwrite(&c,sizeof(stConsumo),1,pArchConsumos);
            fclose(pArchConsumos);
        }
    }

    arbolClientes = cargarArbolArchivos(AR_CLIENTES, AR_CONSUMOS, arbolClientes);
    mostrarArbolClientes(arbolClientes);
*/

   arbolClientes = cargarArbolArchivos(AR_CLIENTES, AR_CONSUMOS, arbolClientes);
   arbolClientes = cargarClientesManual(arbolClientes);

   arbolClientes = controlarModificacionCliente(arbolClientes);
   arbolClientes = controlarBajaCliente(arbolClientes);
   mostrarArbolClientes(arbolClientes);


   return 0;
}
