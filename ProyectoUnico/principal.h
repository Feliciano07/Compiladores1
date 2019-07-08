#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <qdebug.h>
#include "Analizadores\parser.h"
#include "Analizadores\scanner.h"
#include <QMessageBox>
#include "PrimerRecorrido/primerrecorrido.h"
#include "PrimerRecorrido/segundorecorrido.h"
#include "Expresiones/archivosder.h"
namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

    void ListaSemanticos(QList<Errores> err);

    void CrearArchivos(QList<ArchivosDer*> entrada);

    QString Texto(QHash<QString,QString> var,int tipo);


    void ReporteSemanticos(QList<Errores> seman,QList<Errores> lex);

    void InciarTabla();

    /*----------------- Corrida del ala primera parte---------------*/
    PrimerRecorrido *pasada1;


    /*---------------- Pasadas del compilador----------------*/
    void PasadasN(QList<Extensiones> ext);

    /*------------------ pasada para comprobar las clases----------*/






    QString TextoC(QList<Conjuntos> var);
    QString TextoR(QList<Regex> var);
    QString TextoE(QList<Entradas> var);

    void Prueba();


private slots:
    void on_actionAbrir_triggered();

    void on_actionAnalizar_triggered();

    void on_actionGuardar_triggered();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
