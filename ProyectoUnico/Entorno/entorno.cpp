#include "entorno.h"

Entorno::Entorno()
{
    principal=nullptr;
    anterior=nullptr;
}



Entorno::Entorno(Entorno *ante,QString ti)
{
    this->anterior=ante;
    this->tipo_entorno=ti;
    principal=nullptr;

}

Simbolos Entorno::BuscarVariable(QString id,Entorno *actual){
    Entorno *aux=actual;
    while(aux!=nullptr){
        Simbolos  auxS=aux->tablaSimbolos.value(id);
        if(QString::compare(auxS.getId(),"")==0){

        }else{
            return auxS;
        }
        aux=aux->anterior;
    }
    Simbolos sm=Simbolos();
    return sm;
}

void Entorno::SetearValor(QString id,Operacion op,QString am,Entorno *ac){

    //Simbolos  aux=BuscarVariable(id,ac);
    Simbolos *sim=new Simbolos(id,op.valor,"variable");
    sim->addTipo_(op.tipo);
    sim->setVisibilidad("");
    sim->ambito=am;

    setearS(sim,ac);

    //addSimbolo(sim);
}

void Entorno::setearS(Simbolos *s,Entorno *a){
    Entorno *ax=ExisteSimb(s->getId(),a);
    if(ax!=nullptr){
        ax->addSimbolo(s);
    }
}



//metodo que agregar simbolos
QString Entorno::addSimbolo(Simbolos *sim){

    tablaSimbolos.insert(sim->getId(),*sim);

    return "Insertado";
}
//metodo que verifica si existe el simbolo
bool Entorno::ExisteSimbolo(Simbolos *sim,Entorno *actu){
    Entorno *aux=actu;
    while (aux!=nullptr) {
        if(aux->tablaSimbolos.contains(sim->getId()) ){
            Simbolos s=aux->BuscarVariable(sim->getId(),actu);
            if(QString::compare(s.ambito,"global",Qt::CaseInsensitive)==0){
                return false;
            }else{
                return true;
            }

        }
         aux=aux->anterior;
    }
    return false;


}

bool Entorno::ExisteSimbolo(QString id,Entorno *actu){

    Entorno *aux=actu;
    while(aux!=nullptr){

        if(aux->tablaSimbolos.contains(id)){

            return true;

        }
        aux=aux->anterior;
    }
    return false;

}
Entorno* Entorno::ExisteSimb(QString id, Entorno *a){

    Entorno *aux=a;
    while(aux!=nullptr){

        if(aux->tablaSimbolos.contains(id)){

            return aux;
        }
        aux=aux->anterior;
    }
   return aux;

}
void Entorno::addFuncion(Metodo_Funcion *s,QString na){

    Simbolos *si =new Simbolos(s->nombre,"","funcion");



    si->parametros=s->ListaPara;
    si->ambito=na;
    si->ListaGeneral=s->listaGeneral;


    si->setVisibilidad(s->visivilidad);


    /*
    entero=14,
    DOBLE=15,
    cadena=16,
    caracter=17,
    boolean=18,

    cha=40,
    str=41,
    decimal=42,
    numero=43,
    verdadero=44,
    falso=45
    QString tipo;
    voide=57,
    int tipo_;
     */
    if(QString::compare(s->tipo_F,"entero")==0){ //retorno y valor tendran el valor a retornar
        si->addTipo_(14);
        si->poseRetorno=true;
        si->setRetonor("");
    }else if(QString::compare(s->tipo_F,"doble")==0){
        si->addTipo_(15);
        si->poseRetorno=true;
        si->setRetonor("");
    }else if(QString::compare(s->tipo_F,"cadena")==0){
        si->addTipo_(16);
        si->poseRetorno=true;
        si->setRetonor("");
    }else if(QString::compare(s->tipo_F,"caracter")==0){
        si->addTipo_(17);
        si->poseRetorno=true;
        si->setRetonor("");
    }else if(QString::compare(s->tipo_F,"boolean")==0){
        si->addTipo_(18);
        si->poseRetorno=true;
        si->setRetonor("");
        //hhace falta agregar para los arreglos para la segunda fase
    }else if(QString::compare(s->tipo_F,"void")==0){
         si->addTipo_(57);



    }else if(QString::compare(s->tipo_F,"clase")==0){
       si->id_clase=s->Clase;
       si->addTipo_(48);
       si->poseRetorno=true;
    }else if(QString::compare(s->tipo_F,"arreglo")==0){
        si->nuevoAr=s->arra;
        si->addTipo_(50);
        si->dimension=s->Dimension;
        si->nuevoAr=s->arra;
        si->poseRetorno=true;

    }
    addSimbolo(si);
}

 QList<Simbolos> Entorno::getParametros(Simbolos *entrada){
    QList<Simbolos> salida;

    salida=entrada->parametros;
    return salida;
}

 Entorno* Entorno::RetornarUltimo(Entorno *aux){

     Entorno *auxE=aux;

     while(auxE!=nullptr){
         if(auxE->anterior==nullptr){
             return auxE;
         }
         auxE=auxE->anterior;

     }


 }
void Entorno::SetearGeneral(Entorno *aux,Entorno *entrada){

    Entorno *auxE=aux;

    while(auxE!=nullptr){
        if(auxE->anterior==nullptr){
            auxE=entrada;
        }
        auxE=auxE->anterior;

    }
}

 bool Entorno::DentroFuncion(Entorno *aux){

     Entorno *au=aux;
     while(au!=nullptr){

         if(au->tipo_entorno=="funcion"){
             return true;
         }
         au=au->anterior;

     }
     return false;
 }


 void Entorno ::SetearObjeto(Simbolos sem,Entorno *en){
     Simbolos *nuevo=new Simbolos(sem.getId(),sem.id_clase,sem.getValor(),sem.getTipo_Dato());
     nuevo->setVisibilidad(sem.getVisibilidad());
     nuevo->ClaseIniciada=sem.ClaseIniciada;
     nuevo->addTipo_(48);
     nuevo->ambito=sem.ambito;
     nuevo->simbolosClase=sem.simbolosClase;
     setearS(nuevo,en);

 }

 Simbolos * Entorno::BuscarArreglo(QString id, Entorno *actual){
     Simbolos *temporal;
     Entorno *aux=actual;
     while(aux!=nullptr){
         Simbolos  auxS=aux->tablaSimbolos.value(id);
         if(QString::compare(auxS.getId(),"")==0){

         }else{
             temporal=&auxS;
             return temporal;
         }
         aux=aux->anterior;
     }

     return  temporal;
 }

 void Entorno::SeterArreglo(Simbolos sem, Entorno *en){
     Simbolos *nuevo=new Simbolos(sem.getId(),sem.getValor(),sem.getTipo());
     nuevo->setVisibilidad(sem.getVisibilidad());
     nuevo->addTipo_(sem.tipo_);
     nuevo->ambito=sem.ambito;
     nuevo->nuevoAr=sem.nuevoAr;
     nuevo->dimension=sem.dimension;
     setearS(nuevo,en);
 }

 void Entorno::AgregarCuenta(QString nam, QString arch,QString exp){

     Simbolos *nuevo=new Simbolos(nam,"","cuenta");
     Cuenta nueva= Cuenta(arch,exp);
     nuevo->cuenta=nueva;
     nuevo->addTipo_(109);
     addSimbolo(nuevo);
 }
 void Entorno::SetearCuenta(Simbolos sem, Entorno *en){
     Simbolos *nuevo=new Simbolos(sem.getId(),"","cuenta");
     nuevo->cuenta=sem.cuenta;
     setearS(nuevo,en);
 }

