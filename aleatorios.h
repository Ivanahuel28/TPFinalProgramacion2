#ifndef ALEATORIOS_H_INCLUDED
#define ALEATORIOS_H_INCLUDED

#include "cliente.h"

void generarArchivoClientesAleatorio(char nomArch[],int n);
stCliente getClienteRandom();
void getApellido(char apellido[]);
void getNombre(char nombre[]);
void getDNI(char dni[]);
void getEMail(char email[],stCliente cliente);
void getDomicilio(char domicilio[]);
void getMovil(char movil[]);

#endif // ALEATORIOS_H_INCLUDED
