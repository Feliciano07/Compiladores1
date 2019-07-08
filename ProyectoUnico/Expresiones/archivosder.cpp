#include "archivosder.h"

ArchivosDer::ArchivosDer()
{

}


ArchivosDer::ArchivosDer(QString name,QString d)
{
    this->nombre=name;
    this->id=d;
    this->guardado=false;
}

void ArchivosDer::Add_Conjunto(QString id, QString conjunto){
 Conjuntos *nuevo=new Conjuntos(id,conjunto);
    this->conjuntos.append(*nuevo);

}
void ArchivosDer::add_Expresion(QString id, QString exp){
    Regex *nuevo=new Regex(id,exp);
    this->expresiones.append(*nuevo);
}
void ArchivosDer::add_Entrada(QString id, QString entra){
    Entradas *nuevo=new Entradas(id,entra);
    this->entradas.append(*nuevo);
}



