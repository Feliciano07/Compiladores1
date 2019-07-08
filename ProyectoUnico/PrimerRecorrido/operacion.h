#ifndef OPERACION_H
#define OPERACION_H
#include <QString>
#include <Entorno/simbolos.h>
#include "Herramientas/arreglos.h"
class Operacion
{
public:
       Operacion();
       Operacion(int linea,int columna,int tipo,QString valor);

       Operacion(int linea,int columna,int tipo,Arreglos nuevo);
        Operacion(int linea,int columna,int tipo,Simbolos nuevo);
       int tipo;
       QString valor;
       int linea;
       int columna;

       Arreglos array;
       Simbolos objec;
};

#endif // OPERACION_H
