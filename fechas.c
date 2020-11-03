#include "fechas.h"

/**************************************************************************
* \brief Trae la cantidad de dias que hay en el mes requerido
* \param y Anio del mes
* \param m Mes a ver
**************************************************************************/
int diasEnMes(int y, int m)
{
   const int dias[12] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };
   int resultado;

   resultado = dias[m-1];

   if ( m == Febrero && esAnioBisciesto( y ) )
      resultado++;

   return resultado;
}

/**************************************************************************
* \brief Retorna si una fecha es valida
* \param y Anio
* \param m Mes
* \param m Dia
**************************************************************************/
int esFechaValida( int y, int m, int d ){
   if ( d < 0 || d >= diasEnMes( y, m ) )
      return false;

   return true;
}

/**************************************************************************
* \brief Carga una fecha aleatoria
* \param y Anio
* \param m Mes
* \param m Dia
**************************************************************************/
int fechaRandom( int *y, int *m, int *d ){
    *y = ANIO_HOY;
    *m = Enero + rand() % (Diciembre);
    *d = 1 + rand() % (diasEnMes(*y,*m));
}
