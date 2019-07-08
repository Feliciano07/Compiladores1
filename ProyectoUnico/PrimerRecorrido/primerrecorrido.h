#ifndef PRIMERRECORRIDO_H
#define PRIMERRECORRIDO_H


#include <QHash>
#include <QList>
#include <QString>
#include <QChar>
#include <QFloat16>
#include <math.h>
#include "nodoast.h"
#include "Entorno/simbolos.h"
#include "Entorno/entorno.h"
#include <QPlainTextEdit>
#include <QTableWidget>
#include "operacion.h"
#include "errores.h"
#include<Entorno/metodo_funcion.h>
#include "Expresiones/archivosder.h"
#include "Herramientas/extensiones.h"
#include <QDebug>
#include <QStringList>

class PrimerRecorrido
{
public:
    PrimerRecorrido();
     QPlainTextEdit *consola;
     QTableWidget *tablaS;

    QList<Errores> semanticos;
     QHash<QString,Entorno> clases;

     Operacion opeGeneral;

     //variables para retorno,romper y continuar

     int termina;
     int rompe;
     int continua;


     QList<ArchivosDer*> ListArch;

     ArchivosDer * BuscarArchivo(QString id);
     Operacion ExtraerAtributo(NodoAST *raiz,Entorno *&actual);

     //Lamada Funciones

     void LlamarFunciones(NodoAST *raiz,Entorno *&actual);

     void VerificarFuncion(QString id,NodoAST *raiz, Entorno *&actual,int tipo);

     bool VerificarParametros(NodoAST *raiz, QList<Simbolos> sa);

     bool ExtraerParametros(NodoAST *raiz,Entorno *ac, QList<Simbolos> salida);

     void CreandoTabla(Entorno *aux);


    void Recorrer(NodoAST *raiz);

  // Entorno *inicial;
    void SegundaPasada();
    void SegundaPasada(NodoAST *raiz,Entorno *ini);

    void CopiarDatos(Entorno *&nuevo,Entorno *&anterior);

    Entorno * CrearNuevoEntorno(Entorno *actual,QString tipoEntorno);

    Entorno * EncontrarPrincipal();

    Entorno* EncontrarClase(QString id);

    void GuardarVariable(NodoAST *raiz,Entorno *&en,QString a);

    void VariableExistente(NodoAST *raiz,Entorno *&en,QString am);

    bool SI(NodoAST *raiz,Entorno *&en,QString am);

    void Hacer(NodoAST *raiz,Entorno *&en);

    void Mientras(NodoAST *raiz,Entorno *&en);

    void Repetir(NodoAST *raiz,Entorno *&en);
    void Para(NodoAST *raiz,Entorno *&en);
    Simbolos ActuVar(NodoAST *raiz,Entorno *&en);

    void Casos(NodoAST *razi,Entorno *&en,Operacion op);


    /*------Metodos para manejar las sentencias de archivos--------------*/
    void SentenciaArch(NodoAST *raiz,Entorno *&en);

    //id y entorno con sus variables y funciones
    void SentenciaCuenta(NodoAST *raiz, Entorno *&en);


    //sacar cosas clase
    void SacarClases(NodoAST *raiz,Entorno *e,QString nombre);
    //sacar extender

    void Extender(NodoAST *raiz);

    //sacar el valor
    Operacion Asignacion(NodoAST *raiz,Entorno *aux);

    //sacar datos de una funcion
    void Metodos_Funciones(NodoAST *raiz,Metodo_Funcion *mef);

    void Lista_Para(NodoAST *raiz,Metodo_Funcion *mef);

    //metodo que devuelve el valor de una llamada


    //sacar una lista de IDs

    QList<QString> IDE(NodoAST *raiz);

    //Lista de errores semanticos



    //------ ---para manejar los incluir--------------------------*/

      void GuardarIncluir(NodoAST *lista);
      void IngresarIncluir();
      QList<Extensiones> ArchivosExternos;


    /*------------------------------------------------------------*/

    /*---------------- manejo de objetos--------------------------*/

     void ExtraerObjetos(NodoAST *raiz, Entorno *actua,QString am,int ambito);

    void DeclararOBJ(NodoAST *raiz,Entorno *actual);

     /*-------------------------------------------------------------*/

    /*--------------- COMPROBAR LAS CLASES--------------------------*/
    void ComprobarClases();


    /*------------------ MANEJO DE LOS ARREGLOS------------------------*/
    void ExtraerArreglo(NodoAST *raiz,Entorno *actual,int ambito);
    void CrearArreglo(QList<QString> ide, Entorno *actu, Arreglos *nuevo,QString visi,int tipo,int ambito,int dim);
    void ArregloIniciado(NodoAST *lis,Arreglos *auxiliar,Entorno *entor,int f,int c,int n);

    void ReArreglo(NodoAST *ax, Entorno *ac);

    Arreglos* ExtraerDimensiones(NodoAST *aux, Entorno *ac);

    /*-------------- METODO PARA INGRESAR EL RETORNO--------------------*/

    void setRetorno(NodoAST *reto,Entorno *ac);


    void setExternaVariable(NodoAST *reto,Entorno *ac);

    void setExterArray(NodoAST *raiz,Entorno *actual);


    double Potencia(int a1,int a2);

    QString ConverChar(QString caracter);

    int ConverInt(QString caracter);

    bool Comparar(QString a,QString b);

    bool MenorQEntero(QString a,QString v);
    bool menorIgualE(QString a,QString v);

    bool MayorQEntero(QString a,QString v);
    bool MayorIgualE(QString a,QString v);

    int MenorQCadena(QString a,QString v);

    void CASTEO(Entorno *en,QList<QString> id,int tipo,QString vis,Operacion op,QString amb,int fo) ;
    void AsignarVariable(Entorno *en,QList<QString> id,QString vis,Operacion op,QString amb,int fo);


    bool ValidarCuenta(QString archivo,QString nombre);


};

#endif // PRIMERRECORRIDO_H
