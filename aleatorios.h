#ifndef ALEATORIOS_H_INCLUDED
#define ALEATORIOS_H_INCLUDED

#include "cliente.h"
#include "consumo.h"

/// ARCHIVO DE CLIENTES
void generarArchivoClientesAleatorio(char nomArch[],int n);
stCliente getClienteRandom();
void getApellido(char apellido[]);
void getNombre(char nombre[]);
void getDNI(char dni[]);
void getEMail(char email[],stCliente cliente);
void getDomicilio(char domicilio[]);
void getMovil(char movil[]);

/// ARCHIVO DE CONSUMOS
void generarArchConsumosAleatorios(char nomArchConsumos[],char nomArchClientes[]);
int getArrConsumosAleatorios(stConsumo arr[],int idCliente,int nuevoIdConsumos);

#endif // ALEATORIOS_H_INCLUDED
