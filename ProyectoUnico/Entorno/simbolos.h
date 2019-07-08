#ifndef SIMBOLOS_H
#define SIMBOLOS_H
#include <QString>
#include <QHash>
#include "nodoast.h"
#include "Herramientas/arreglos.h"
#include "Cuentas/cuenta.h"
class Simbolos
{
public:
    Simbolos();


    Simbolos(QString id,QString valor,QString tipo);
    QString retorno;

    //Seter----------------------------------------
    void setId(QString id);//guarda id
    void setValor(QString id);
    void setTipo_Dato(QString id);
    void setTipo(QString id);
    void setRetonor(QString retorno);
    void setVisibilidad(QString vi);
    /*---------------------------------------------*/
    //gets------------------------------------------
    QString getId();
    QString getValor();
    QString getTipo_Dato();
    QString getTipo();
    QString getRetorno();
    QString getVisibilidad();
    /*--------------------------------------------------*/

    /*--------------parametros de un metodo---------------*/
    QList<Simbolos> parametros;//guar los parametros de un metodo
    QHash<QString,Simbolos> para;
    /*---------------------------------------------------------*/

    bool poseRetorno=false;//una variable que me indica si una funcion tiene retorno

    /*------------------ si es una tiene lista de sentencias --------------------------*/
    NodoAST ListaGeneral;
    /*----------------------------------------------------------------*/

    /*-------------------tipo de ambito-------------------------------*/
    QString ambito;

    /*----------------------------------------------------------------*/

     int tipo_;//-------------------------- tipo de ambito primitivo, sirve para indicar que tipo de funcion es tambien

     //de cuantas dimensiones es
     int dimension;
    //void addParametro(QString tipo,Simbolos *s);

    //tipo de dato
    void addTipo_(int a);


    int tipoPrimitivo;


    /*---------------- para el manejo de las clase contiene todo lo anterior, que puede ser null algunos */

    /*------------- -------------------------------------------
     * ahora un simbolo puede contener una Tabla de SImboslos para las clase
     * esto se hara despues de la primera pasada
    ----------------------------------------------------------*/
    QHash<QString,Simbolos> simbolosClase;

    Simbolos ContieneClase(QString ide);


    QString id_clase;
    Simbolos(QString id,QString id_C,QString valor,QString tipo);
    bool ClaseIniciada;

    /*------------------------cuando tenemos un arreglo--------------------*/
    Arreglos *nuevoAr;

    /*----------------------------------------------------------------------*/

    /*----------------- para las cuentas------------------------------------*/
    Cuenta cuenta;


private:
    //variable para guarda el id, del objeto,variable,funcion,etc
    QString id;

    //variable para guardar el valor
    QString valor;

    // si es primitivo,si es arreglo,clase,metodo o funcion
    QString tipo_dato;

    //guarda si es numero,decimal
    QString tipo;



    //si es una funcion de retorno


    //visibilidad
    QString visibilidad;

    //si es una funcion puede tener o no parametros

};

#endif // SIMBOLOS_H
