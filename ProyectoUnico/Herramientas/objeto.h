#ifndef OBJETO_H
#define OBJETO_H
#include <QString>

class Objeto
{
public:
    Objeto();
    Objeto(QString dato,int tipo_,QString posicion);
    QString dato;
    int tipo_;
    QString posicion;

};

#endif // OBJETO_H
