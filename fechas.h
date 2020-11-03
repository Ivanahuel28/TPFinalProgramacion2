#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>

#include "definiciones.h"

//////////// DEFINICIONES ///////////////
#define esAnioBisciesto(y)  ((((y)%400)==0)||((((y)%4)==0)&&(((y)%100)!=0)))
#define DIA_HOY 3
#define MES_HOY 11
#define ANIO_HOY 2020


int diasEnMes(int y, int m);
int esFechaValida( int y, int m, int d );
int fechaRandom( int *y, int *m, int *d );

#endif // FECHAS_H_INCLUDED
