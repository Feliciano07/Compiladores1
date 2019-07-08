#include "nodoast.h"

#include <qdebug.h> // Para imprimir en consola.
NodoAST::NodoAST()
{
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;
    hijos =  QList<NodoAST>();
}

NodoAST:: NodoAST(int l, int c, QString t, QString v)
{
    linea = l;
    columna = c;

    if(v.startsWith("\"")){
        if(v.endsWith("\"")){
            QString salida;
            for(int a=1;a<=v.size()-2;a++){
                salida.append(v[a]);
            }
            v=salida;
        }
    }

    if(v.startsWith("\'")){
        if(v.endsWith("\'")){
            QString salida;
            for(int a=1;a<=v.size()-2;a++){
                salida.append(v[a]);
            }
            v=salida;
        }
    }


    tipo = t;
    valor = v;
    tipo_ = getTipo();
    hijos = QList<NodoAST>();
}

void NodoAST::add(NodoAST nd)
{
    this->hijos.append(nd);
}

int NodoAST::getTipo()
{
   // if(QString::compare(this->tipo,"hola",Qt::CaseInsensitive)==0){}
   if(QString::compare(this->tipo,"INICIO",Qt::CaseInsensitive)==0){return 0;}
   if(this->tipo=="LISTA_INCLU"){return 1;}
   if(QString::compare(this->tipo,"incluir",Qt::CaseInsensitive)==0){return 2;}
   if(QString::compare(this->tipo,"clases",Qt::CaseInsensitive)==0){return 3;}
    if(QString::compare(this->tipo,"CLASE")==0){return 4;}
    //cosas que pueden venir en la estructura de una clase

    if(QString::compare(this->tipo,"LISTA_SENTENCIA",Qt::CaseInsensitive)==0){return 5;}
    if(this->tipo=="VARIABLE"){return 6;}
    if(this->tipo=="OBJETO"){return 7;}
    if(this->tipo=="ARREGLO"){return 8;}
    if(this->tipo=="METODO_FUNCION"){return 9;}
    if(this->tipo=="PRINCIPAL"){return 10;}

    //visibilidad de las cosas
    if(QString::compare(this->tipo,"publico",Qt::CaseInsensitive)==0){return 11;}
    if(QString::compare(this->tipo,"privado",Qt::CaseInsensitive)==0){return 12;}
    if(QString::compare(this->tipo,"protegido",Qt::CaseInsensitive)==0){return 13;}

    //tipo de datos primitivos

    if(this->tipo=="entero"){return 14;}
    if(this->tipo=="doble"){return 15;}
    if(this->tipo=="cadena"){return 16;}
    if(this->tipo=="caracter"){return 17;}
    if(this->tipo=="boolean"){return 18;}
    //idetificador variables, arreglos

    if(this->tipo=="DEC_ID"){return 19;}
    if(this->tipo=="Id"){return 20;}

    //asignar valor, var, arreglos
    if(this->tipo=="ASIGNACION"){return 21;}
    if(this->tipo=="final"){return 22;}
    if(this->tipo=="operacion"){return 23;}

    //operaciones aritmeticas y logicas
    if(this->tipo=="suma"){return 24;}
    if(this->tipo=="resta"){return 25;}
    if(this->tipo=="multiplicacion"){return 26;}
    if(this->tipo=="division"){return 27;}
    if(this->tipo=="potencia"){return 28;}
    if(this->tipo=="Or"){return 29;}
    if(this->tipo=="And"){return 30;}
    if(this->tipo=="Nand"){return 31;}
    if(this->tipo=="Nor"){return 32;}
    if(this->tipo=="comparar"){return 33;}
    if(this->tipo=="diferencia"){return 34;}
    if(this->tipo=="menorQ"){return 35;}
    if(this->tipo=="menorIgual"){return 36;}
    if(this->tipo=="mayorQ"){return 37;}
    if(this->tipo=="mayorIgual"){return 38;}
    if(this->tipo=="Not"){return 39;}

    //valores como tal, de los primitivos
    if(this->tipo=="cha"){return 40;}
    if(this->tipo=="str"){return 41;}
    if(this->tipo=="decimal"){return 42;}
    if(this->tipo=="numero"){return 43;}
    if(QString::compare(this->tipo,"verdadero",Qt::CaseInsensitive)==0){return 44;}
    if(QString::compare(this->tipo,"falso",Qt::CaseInsensitive)==0){return 45;}


    //Manipulaciond de metodos y funciones
    if(this->tipo=="sobrescribir"){return 46;}
    if(this->tipo=="TIPO_F"){return 47;}
    if(this->tipo=="clase"){return 48;}
    if(this->tipo=="PRIMITIVO"){return 49;}
    if(QString::compare(this->tipo,"arreglo",Qt::CaseInsensitive)==0){return 50;}
    //en otro caso es
    if(this->tipo=="void"){return 57;}

    //tipos de parametros
    if(this->tipo=="SIN_PARAMETRO"){return 51;}
    if(this->tipo=="LISTA_PARAMETROS"){return 52;}
    if(this->tipo=="variable"){return 51;}
    if(this->tipo=="objeto"){return 52;}


    //lista genenral para funciones,codiciones,ciclos,casos
    if(this->tipo=="LISTA_GENERAL"){return 53;}
    if(this->tipo=="LLAMADA_FUNCION"){return 54;}
    if(this->tipo=="POR_ARREGLO"){return 55;}



    if(this->tipo=="SENTENCIA_GENERAL"){return 58;}
    if(this->tipo=="SENTENCIA_ARCHIVOS"){ return 59;}
    if(this->tipo=="VAR_GLOBALES") {return 60;}
    if(this->tipo=="DECLARAR_OBJEC"){return 61;}
    if(this->tipo=="NUEVO_OBJEC"){return 62;}
    if(this->tipo=="REASIGNAR_ARREGLO"){return 64;}
    if(this->tipo=="ASIGNAR_VAR"){return 65;}
    if(this->tipo=="actualizar"){return 66;}
    if(this->tipo=="START_SI"){return 67;}
    if(this->tipo=="START_HACER"){return 68;}
   if(this->tipo=="START_MIENTRAS"){return 69;}
    if(this->tipo=="START_PARA"){return 70;}
    if(this->tipo=="START_REPETIR"){return 71;}
    if(this->tipo=="imprimir"){return 72;}
    if(this->tipo=="RETORNO"){return 73;}
    if(this->tipo=="romper"){return 74;}
    if(this->tipo=="continuar"){return 75;}
    if(this->tipo=="OTRO_SI"){return 76;}


    if(this->tipo=="sino"){return 77;}
    if(this->tipo=="FIN_SI"){return 78;}
    if(this->tipo=="SinoSi"){return 79;}
    if(this->tipo=="LISTA_SI"){return 80;}

    if(this->tipo=="archivo"){return 81;}
    if(this->tipo=="nuevo_conjunto"){return 82;}
    if(this->tipo=="nuevo_regex"){return 83;}
    if(this->tipo=="nueva_entrada"){return 84;}
     if(this->tipo=="guarda_arch"){return 85;}

     if(this->tipo=="Local_F_V"){return 86;}
     if(this->tipo=="Local_F_S"){return 87;}
     if(this->tipo=="negativo"){return  88;}

     if(this->tipo=="nuevo_objeto"){return 89;}
     if(this->tipo=="No_Inicial"){return 90;}
     if(this->tipo=="DIMENSION1"){return 91;}
     if(this->tipo=="DIMENSION2"){return 92;}
     if(this->tipo=="DIMENSION3"){return 93;}

     if(this->tipo=="LISTA_NORMAL"){return 94;}
     if(this->tipo=="LISTA2"){return 95;}
     if(this->tipo=="LISTA3"){return 96;}

     if(this->tipo=="Externa_F_V"){return 97;}
     if(this->tipo=="Externa_F_S"){return 98;}
     if(this->tipo=="Externa_Var"){return 99;}
     if(this->tipo=="Externa_Var_A"){return 100;}
     if(this->tipo=="Externa_Ar_A"){return 101;}
     if(this->tipo=="Externa_Ar"){return 102;}

     if(this->tipo=="START_COMPROBAR"){return 103;}

     if(this->tipo=="LISTA_CASO"){return 104;}
     if(this->tipo=="caso"){return 105;}
     if(this->tipo=="defecto"){return 106;}


     if(this->tipo=="SENTENCIA_CUENTA"){return 108;}
     if(this->tipo=="cuenta"){return 109;}
     if(this->tipo=="verCuenta"){return 110;}
     if(this->tipo=="depCuenta"){return 111;}
     if(this->tipo=="resCuenta"){return 112;}
     if(this->tipo=="imprimirCuenta"){return 113;}
     if(this->tipo=="conCuenta"){return 114;}
     if(this->tipo=="transferir"){return 115;}



    return 0;
   
}
