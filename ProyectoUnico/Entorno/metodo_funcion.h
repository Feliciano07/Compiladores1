#ifndef METODO_FUNCION_H
#define METODO_FUNCION_H
#include <QString>
#include <QList>
#include <QHash>
#include "simbolos.h"
#include "nodoast.h"
#include "Herramientas/arreglos.h"
class Metodo_Funcion
{
public:
    Metodo_Funcion();
    QString nombre;

    QString tipo_F;
    int tipo;

    QString Clase;

    int C_A;
    int Dimension;

    QString visivilidad;
    int tipo_Vis;
    QHash<QString,Simbolos> parametros;
    QList<Simbolos> ListaPara;
    QString sobre;
    NodoAST listaGeneral;

    Arreglos *arra;//arreglo

    void addParametro(QString id,Simbolos *s);
    bool VerificarParametro(QString id);

    void RetornoObjeto(QString clase,int Clase);//nombre de la clase, es de tipo clase

    void RetornoArreglo(int arra ,int tipo,int Dimen);//es de tipo arreglo,tipo, dimension que retorna


};

#endif // METODO_FUNCION_H
