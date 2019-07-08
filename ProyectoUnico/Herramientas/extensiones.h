#ifndef EXTENSIONES_H
#define EXTENSIONES_H
#include <QString>
#include <QFile>
class Extensiones
{
public:
    Extensiones();
    Extensiones(QString id);
    QString path;
    QString TextoArchivo;

    QString LeerArchivo(QString path);
};

#endif // EXTENSIONES_H
