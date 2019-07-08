#include "errores.h"
#include "nodoast.h"
Errores::Errores(QString le,QString ti,QString des,int li,int col )
{
    lexema=le;
    tipo=ti;
    descripcion=des;
    linea=li;
    columna=col;



}
