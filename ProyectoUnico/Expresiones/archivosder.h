#ifndef ARCHIVOSDER_H
#define ARCHIVOSDER_H
#include <QString>
#include <QList>
#include "Expresiones/conjuntos.h"
#include "Expresiones/regex.h"
#include "Expresiones/entradas.h"
class ArchivosDer
{
public:
    ArchivosDer();
    ArchivosDer(QString nombre,QString ide);
    QString nombre;//guarda el nombre del archivo
    QString id;

    QList<Conjuntos> conjuntos;

    QList<Regex> expresiones;
    QList <Entradas> entradas;
    bool guardado;// is guardo el archivo

    void Add_Conjunto(QString id,QString conjunto);
    void add_Expresion(QString id,QString exp);
    void add_Entrada(QString id,QString entra);


};

#endif // ARCHIVOSDER_H
