#ifndef ERRORES_H
#define ERRORES_H
#include <QString>

class Errores
{
public:
    Errores(QString le,QString t,QString des,int linea,int colum);

    /*variables de la clase*/
    QString lexema;//guardar el lexema
    QString tipo;//guarda el tipo de error
    QString descripcion;
    int linea;
    int columna;



};

#endif // ERRORES_H
