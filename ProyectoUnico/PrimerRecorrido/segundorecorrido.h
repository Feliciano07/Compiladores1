#ifndef SEGUNDORECORRIDO_H
#define SEGUNDORECORRIDO_H

#include "PrimerRecorrido/primerrecorrido.h"

class SegundoRecorrido
{
public:
    SegundoRecorrido();
    SegundoRecorrido(QHash<QString,Entorno> clases);
    QHash<QString,Entorno> clases;

    void Recorrer(NodoAST *raiz);

    PrimerRecorrido Tprimer=PrimerRecorrido();


};

#endif // SEGUNDORECORRIDO_H
