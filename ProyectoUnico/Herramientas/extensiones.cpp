#include "extensiones.h"

Extensiones::Extensiones()
{

}


Extensiones::Extensiones(QString id)
{
    this->path=id;
    this->TextoArchivo=LeerArchivo(id);
}


QString Extensiones::LeerArchivo(QString path){

    QString salida="";
    QString nombreArchivo = path;
       QFile archivo(nombreArchivo);

       if (archivo.open(QIODevice::ReadOnly|QIODevice::Text)) {
           salida=(QString::fromUtf8(archivo.readAll()));
       }

       return salida;
}
