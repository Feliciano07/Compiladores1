#include "cuenta.h"

Cuenta::Cuenta()
{

}

Cuenta::Cuenta(QString nombre,QString expr)
{
    this->nombreArchivo=nombre;
    this->expresionRegular=expr;
    this->dineroTotal=0;
}

void Cuenta::Sumar(QString monto){

    double parcial=monto.toDouble();
    dineroTotal+=parcial;

    QString mov="DEPOSITAR::"+monto+"; ";
    movimientos+=mov;
}

bool Cuenta::Restar(QString monto){

    double parcial=monto.toDouble();
    dineroTotal-=parcial;

    if(dineroTotal<0){
        dineroTotal+=parcial;
        return false;
    }else{
        QString mov="RESTAR::"+monto+"; ";
          movimientos+=mov;
        return true;
    }
}

QString Cuenta::RetonarMovimiento(){
    return this->movimientos;
}

double Cuenta::ConsultarSaldo(){
    return this->dineroTotal;
}




