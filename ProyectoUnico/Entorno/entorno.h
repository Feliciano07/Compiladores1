#ifndef ENTORNO_H
#define ENTORNO_H

#include <QHash>
#include <QString>
#include <QList>
#include <QTextEdit>

#include "metodo_funcion.h"

#include "PrimerRecorrido/operacion.h"

class Entorno
{
public:
    Entorno();
    QTextEdit *consola;

    QString tipo_entorno;
    QString id_Entorno;

    //Tabla has que recibe el id y el toda la informacion del simbolo
    QHash<QString,Simbolos> tablaSimbolos;

    Entorno *anterior;//enlaza al entorno anterior clase1<-metodo1<-if<-ciclo

    NodoAST *principal;//guarda la referencia al metodo principal


    Entorno(Entorno *anterio,QString ti);

    void setearS(Simbolos *s,Entorno *a);

    QString addSimbolo(Simbolos *sim);

    bool ExisteSimbolo(Simbolos *sim,Entorno *a);

    bool ExisteSimbolo(QString id,Entorno *a);

     Entorno* ExisteSimb(QString id,Entorno *a);

    void addFuncion(Metodo_Funcion *s,QString ide);

    Simbolos BuscarVariable(QString id,Entorno *actual);

    void SetearValor(QString id, Operacion o,QString am,Entorno *e);

     QList<Simbolos> getParametros(Simbolos *entrada);

     Entorno* RetornarUltimo(Entorno *aux);

     bool DentroFuncion(Entorno *aux);
     void SetearGeneral(Entorno *aux,Entorno *entrada);


     /*------------------- SETEAR OBJETO NUEVAMENTE----------------------*/
     void SetearObjeto(Simbolos sem,Entorno *en);

     /*------------------------- SETEAR ARREGLO--------------------------*/

     Simbolos *BuscarArreglo(QString id,Entorno *actual);
     void SeterArreglo(Simbolos sem,Entorno *en);

     void AgregarCuenta(QString nam,QString arch,QString exp);
     void SetearCuenta(Simbolos sem,Entorno *en);


};

#endif // ENTORNO_H
