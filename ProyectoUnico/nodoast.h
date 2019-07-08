#ifndef NODOAST_H
#define NODOAST_H
#include "QString"
#include "qlist.h"

class NodoAST
{
public:
    NodoAST(); // Constructor
    //guardo linea,columna,tipo(token), valor
    NodoAST(int l, int c, QString t, QString v);
    void add(NodoAST n);
    QString tipo;
    QString valor;
    int linea;
    int columna;
    int tipo_; // Este nos servirá para la ejecución, ya que aquí no hay swicht(QString); vamos a hacer un Swicht(int);

    //un nodo puede tener varios hijos
    QList<NodoAST> hijos;
    int getTipo();
};

#endif // NODOAST_H
