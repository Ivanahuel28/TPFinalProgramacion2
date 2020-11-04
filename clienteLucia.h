#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "arbolCliente.h"

typedef struct{
    int  id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[15];
    char email[30];
    char domicilio[45];
    char movil[15];
    int baja; /// 0 si está activo - 1 si está eliminado
}stCliente;

void bajaCliente(char nombreArchivo[], int idCliBaja);
void modificaRegistro(char nombreArchivo[], stCliente c, int idCliente);
int buscaPos(int id, char nombreArchivo[]);
void cargaArchivoClientes(char nombreArchivo[]);
int existeCliente(char nombreArchivo[], int cliente);
void guardaUnCliente(stCliente c, char nombreArchivo[]);
int buscaUltimoIdCliente(char nombreArchivo[]);
stCliente cargaUnCliente();
int validaEmail(char email[]);
void muestraArch(char nombreArchivo[]);
void muestraUnCliente(stCliente c);

#endif // CLIENTE_H_INCLUDED
