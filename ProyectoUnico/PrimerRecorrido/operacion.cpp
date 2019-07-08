#include "operacion.h"

Operacion::Operacion()
{
    this->linea=0;
    this->columna=0;
    this->tipo=-1;
    this->valor="";


}

Operacion::Operacion(int l,int c, int t,QString v){
    this->linea=l;
    this->columna=c;
    this->tipo=t;
    this->valor=v;

}

Operacion::Operacion(int linea,int columna,int tipo,Arreglos nuevo){
    this->linea=linea;
    this->columna=columna;
    this->tipo=tipo;
    this->array=nuevo;
}

Operacion::Operacion(int linea,int columna,int tipo,Simbolos nuevo){
    this->linea=linea;
    this->columna=columna;
    this->tipo=tipo;
    this->objec=nuevo;
}
