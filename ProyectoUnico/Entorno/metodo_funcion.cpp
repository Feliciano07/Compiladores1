#include "metodo_funcion.h"

Metodo_Funcion::Metodo_Funcion()
{
    this->nombre="";
    this->tipo_F="";
    this->visivilidad="";
    this->sobre="";
    this->tipo=-1;
    this->C_A=-1;
    this->Clase="";
    this->Dimension=-1;
    this->tipo_Vis=-1;

}

void Metodo_Funcion::addParametro(QString id, Simbolos *s){
    this->parametros.insert(id,*s);
    this->ListaPara.append(*s);
}

bool Metodo_Funcion::VerificarParametro(QString id){
    if(parametros.contains(id)){
        return true;

    }
    return false;
}

void Metodo_Funcion::RetornoObjeto(QString clase, int Clase){

    this->Clase=clase;
    this->C_A=Clase;
}

void Metodo_Funcion::RetornoArreglo(int arra, int tipo, int Dimen){
    this->C_A=arra;
    this->tipo=tipo;
    this->Dimension=Dimen;
}
