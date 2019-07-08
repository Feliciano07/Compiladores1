#include "simbolos.h"

Simbolos::Simbolos()
{
    this->tipo_=56;

}


Simbolos::Simbolos(QString i,QString v,QString ti)
{
    id=i;
    valor=v;
    tipo_dato=ti;
    this->tipo_=56;

}

Simbolos::Simbolos(QString i,QString id_c,QString v,QString ti)
{
    id=i;
    id_clase=id_c;
    valor=v;
    tipo_dato=ti;
    this->tipo_=56;
    ClaseIniciada=false;

}


/*
    cha=40,
    str=41,
    decimal=42,
    numero=43,
    verdadero=44,
    falso=45
    QString tipo;
    voide=57,
    int tipo_;

    entero=14,
    DOBLE=15,
    cadena=16,
    caracter=17,
    boolean=18,
*/

void Simbolos::addTipo_(int a){
    if(a==40){
        this->tipo="cha";
        this->tipo_=40;
        this->tipoPrimitivo=17;
    }else if(a==41){
        this->tipo="str";
        this->tipo_=41;
        this->tipoPrimitivo=16;
    }else if(a==42){
        this->tipo="decimal";
        this->tipo_=42;
        this->tipoPrimitivo=15;
    }else if(a==43){
        this->tipo="numero";
        this->tipo_=43;
        this->tipoPrimitivo=14;
    }else if(a==44){
        this->tipo="verdadero";
        this->tipo_=44;
        this->tipoPrimitivo=18;
    }else if(a==45){
        this->tipo="falso";
        this->tipo_=45;
        this->tipoPrimitivo=18;
    }else if(a==57){
        this->tipo="void";
        this->tipo_=57;
        this->tipoPrimitivo=-1;
    }else if(a==14){
        this->tipo="entero";
        this->tipo_=43;
        this->tipoPrimitivo=14;
    }else if(a==15){
        this->tipo="doble";
        this->tipo_=42;
        this->tipoPrimitivo=15;
    }else if(a==16){
        this->tipo="cadena";
        this->tipo_=41;
        this->tipoPrimitivo=16;
    }else if(a==17){
        this->tipo="caracter";
        this->tipo_=40;
        this->tipoPrimitivo=17;
    }else if(a==18){
        this->tipo="boolean";
        this->tipo_=18;
        this->tipoPrimitivo=45;

    }else if(a==48){
        this->tipo_=48;
        this->tipo="clase";

    }else if(a==50){
        this->tipo_=50;
        this->tipo="arreglo";

    }else if(a==109){
        this->tipo_=109;
        this->tipo="cuenta";
    }
}

Simbolos Simbolos::ContieneClase(QString ide){

}


void Simbolos::setId(QString id){
    this->id=id;
}



void Simbolos::setValor(QString va){
    this->valor=va;
}

void Simbolos::setVisibilidad(QString vi){
    this->visibilidad=vi;
}

void Simbolos::setRetonor(QString retorno){
    this->retorno=retorno;
}

void Simbolos::setTipo_Dato(QString td){
    this->tipo_dato=td;
}
void Simbolos::setTipo(QString t){
    this->tipo=t;
}

QString Simbolos::getId(){
    return this->id;
}

QString Simbolos::getTipo(){
    return this->tipo;
}


QString Simbolos::getTipo_Dato(){
    return this->tipo_dato;
}

QString Simbolos::getValor(){
    return this->valor;
}

QString Simbolos::getRetorno(){
    return this->retorno;
}


QString Simbolos::getVisibilidad(){
    return this->visibilidad;
}

