#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


#include "definiciones.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idCliente; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[15];
    char email[30];
    char domicilio[45];
    char movil[15];
    int baja; /// 0 si est� activo - 1 si est� de baja
} stCliente;

///////////////// FUNCIONES DE ALTA /////////////////

void agregarUnCliente(stCliente c);
int validaEmail(char email[]);
void mostrarFiltros();
void encabezado();
void footerDeCliente();
void headerDeCliente();

void formatearCeldaEntero(int valor, char formateado[], int tamanoMaximo);
void formatearCeldaString(char valor[],char formateado[], int tamanoMaximo);
///////////////// FUNCIONES DE MODIFICACION /////////////////
int obtenerInt();
void mostrarModificacion(stCliente c);
void modificarClienteArchivo(stCliente c);

///////////////// FUNCIONES DE BUSQUEDA /////////////////
int ultimoIdCliente();
int posPorIdCliente(int id);

#endif // CLIENTE_H_INCLUDED
