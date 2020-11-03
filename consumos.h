
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <locale.h>
#include "fechas.h"

#define MAX_CONSUMOS 9999
#define MAX_DATOS 9999

typedef struct{
    int id;   /// campo unico y autoincremental
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int baja; /// 0 - 1
} stConsumo;

void mostrarUnConsumo(stConsumo c);
void mostrarFiltrosConsumos();
void mostrarModificacionConsumo(stConsumo c);

stConsumo consumoRandom(int idCliente);
stConsumo cargaManualUnConsumo();
void formularioModificacionConsumo(stConsumo c);
void bajaConsumo(stConsumo &c);