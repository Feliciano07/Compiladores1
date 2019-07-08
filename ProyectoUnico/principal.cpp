#include "principal.h"
#include "ui_principal.h"
#include <QRegularExpression>

extern int yyparse();
extern NodoAST *raiz;
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

extern QString textConsola;

extern QList <Errores> *listaLexico;

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionAbrir_triggered()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this,
                                                           ("Abrir archivo"), "",
                                                           ("txt(*.txt);;All Files(*)"));
       QFile archivo(nombreArchivo);

       if (archivo.open(QIODevice::ReadOnly|QIODevice::Text)) {
           ui->entrada->setPlainText(QString::fromUtf8(archivo.readAll()));
       }


}

void Principal::on_actionAnalizar_triggered()
{
    //Prueba();

    pasada1=new PrimerRecorrido();
    QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
        if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
            QTextStream stream1( &file );
            stream1 << ui->entrada->toPlainText();
        }



        ui->salida->appendPlainText("INFO::Iniciando programa ");


        //Variable para el primer recorrido

        //SegundoRecorrido *pasada2=new SegundoRecorrido(clases);
        const char* x = "temp.txt";
        FILE* input = fopen(x, "r");
        yyrestart(input);
        if(yyparse()==0){
            ui->salida->appendPlainText("INFO::Recorriendo el arbol ");



               pasada1->consola=ui->salida;
               pasada1->tablaS=ui->tableWidget;


               pasada1->Recorrer(raiz);

               QList<Extensiones> exten=pasada1->ArchivosExternos;

               pasada1->ArchivosExternos.clear();

               if(exten.size()>0){
                   PasadasN(exten);
               }

               //------------> pasada intermdia

               pasada1->ComprobarClases();
               QMessageBox msgBox;
                  msgBox.setText("FIN DEL ANALISIS");
                  msgBox.exec();
                  InciarTabla();


               ui->salida->appendPlainText("INFO:: fin de la primera pasada");
               pasada1->SegundaPasada();
               //segunda pasada

               CrearArchivos(pasada1->ListArch);

               QList <Errores> *lista=listaLexico;
               ReporteSemanticos(pasada1->semanticos,*lista);

        }else{
            ReporteSemanticos(pasada1->semanticos,*listaLexico);
            QMessageBox msgBox;
               msgBox.setText("ERROR");
               msgBox.exec();
        }
}

void Principal::PasadasN(QList<Extensiones> ext){
    for(Extensiones exten:ext){

        QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
            if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
                QTextStream stream1( &file );
                stream1 << exten.TextoArchivo;
            }

            const char* x = "temp.txt";
            FILE* input = fopen(x, "r");
            yyrestart(input);
            if(yyparse()==0){
                pasada1->Recorrer(raiz);

                QList<Extensiones> exten=pasada1->ArchivosExternos;

                pasada1->ArchivosExternos.clear();

                if(exten.size()>0){
                    PasadasN(exten);
                }
            }

    }

}


void Principal::ListaSemanticos(QList<Errores> err){
    for (int a=0;a<err.size();a++) {
        qDebug()<<err.at(a).descripcion;
    }



}


void Principal::CrearArchivos(QList<ArchivosDer*> entrada){


    for (int num=0;num<entrada.size();num++) {
        QString dire="C:\\Users\\CORE i7 64BITS\\Documents\\LaboratoriosECYS\\Compiladores1\\Vacaciones\\Proyecto_Fases\\ProyectoUnico\\Archivos\\";
        QString file = entrada.at(num)->nombre;

        QString path=dire+file;
        QList<Conjuntos> con=entrada.at(num)->conjuntos;
        QList<Regex> exp=entrada.at(num)->expresiones;
        QList<Entradas> prueba=entrada.at(num)->entradas;


            QFile outputFile(path);
           // outputFile.open(QIODevice::WriteOnly);

            QString str = "text inside file";

            if(!outputFile.open(QFile::WriteOnly) |QFile::Text)
            {
                ui->salida->appendPlainText("error al abrir el archivo"+file);
            }


            QTextStream outStream(&outputFile);

            outStream <<"{\n";

            outStream<<TextoC(con)<<"\n";

            outStream<<TextoR(exp)<<"\n";

            outStream<<"%%%%"<<"\n";

            outStream<<TextoE(prueba)<<"\n";
            outStream<<"}";
            outputFile.flush();
            outputFile.close();
    }

}

QString Principal::TextoC(QList<Conjuntos> var){

    /* valor es:
    1----> conjunto
    2----> definicion
    3-----> entradas
    */


    QString salida="";
    QHash<QString, QString>::iterator i;

    for (Conjuntos cj: var) {
        QString encabezado ="CONJ:";
        QString aux=encabezado+" "+cj.nombre+"->"+cj.expresion+"; \n";
        salida+=aux;
    }

return salida;
}
QString Principal::TextoR(QList<Regex> var){

    /* valor es:
    1----> conjunto
    2----> definicion
    3-----> entradas
    */


    QString salida="";
    QHash<QString, QString>::iterator i;

    for (Regex rex: var) {
       // QString encabezado ="CONJ:";
        QString aux=rex.nombre+"-> "+rex.rege+"; \n";
        salida+=aux;
    }

return salida;
}

QString Principal::TextoE(QList<Entradas> var){

    /* valor es:
    1----> conjunto
    2----> definicion
    3-----> entradas
    */


    QString salida="";
    QHash<QString, QString>::iterator i;

    for (Entradas rex: var) {
       // QString encabezado ="CONJ:";
        QString aux=rex.nombre+":"+"\""+rex.entrada+"\""+"; \n";
        salida+=aux;
    }

return salida;
}


void Principal::ReporteSemanticos(QList<Errores> seman,QList<Errores> lex){
    QString file="C:\\Users\\CORE i7 64BITS\\Documents\\LaboratoriosECYS\\Compiladores1\\Vacaciones\\Proyecto_Fases\\ProyectoUnico\\Reportes\\Semanticos.html";

    QFile outputFile(file);
    outputFile.open(QIODevice::WriteOnly);

    QString str = "text inside file";

    if(!outputFile.isOpen())
    {
        ui->salida->appendPlainText("error al abrir el archivo"+file);
    }


    QTextStream write(&outputFile);

    write<<"<!DOCTYPE html>";
    write<<"<html>";
    write<<"<head>";
    write<<"<title>Tabla de Errores</title>";
    write<<"</head>";
    write<<"<body>";

    write<<"<table border=3 width=60% heught=7%>";
    write<<"<tr>" ;
    write<<"<th scope="<<'"'<< "col" << '"' << ">Lexema</th>" ;
    write<<"<th scope=" << '"' << "col" << '"' << ">Tipo</th>" ;
    write <<"<th scope=" << '"' << "col" << '"' << ">Descripcion</th>" ;

    write <<"<th scope=" << '"' << "col" << '"' << ">Fila</th>" ;
    write <<"<th scope=" << '"' << "col" << '"' << ">Columna</th>";
    write<<"</tr>";

    for(Errores Err:seman){

        write<<"<tr>";
        write<<"<td><b>"<<Err.lexema<<"</b></td>" ;
        write<<"<td><b>"<<Err.tipo<<"</b></td>" ;
         write<<"<td><b>"<<Err.descripcion<<"</b></td>" ;
        write<<"<td><b>"<<Err.linea<<"</b></td>" ;
        write<<"<td><b>"<<Err.columna<<"</b></td>" ;
        write<<"</tr>";

    }

    for(Errores erLex: lex){
        write<<"<tr>";
        write<<"<td><b>"<<erLex.lexema<<"</b></td>" ;
        write<<"<td><b>"<<erLex.tipo<<"</b></td>" ;
         write<<"<td><b>"<<erLex.descripcion<<"</b></td>" ;
        write<<"<td><b>"<<erLex.linea<<"</b></td>" ;
        write<<"<td><b>"<<erLex.columna<<"</b></td>" ;
        write<<"</tr>";
    }

    outputFile.close();
}


void Principal::InciarTabla(){


    ui->tableWidget->setColumnCount(7);

    QStringList l;
    l<<"visibilidad"<<"nombre"<<"valor"<<"Tipo"<<"Tipo Dato"<<"Retorno"<<"Ambito";

    ui->tableWidget->setHorizontalHeaderLabels(l);


}










void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         ("Guardar archivo"), "",
                                                         ("txt(*.txt);;All Files(*)"));

     if(nombreArchivo.isEmpty())
         return;

     QFile archivo(nombreArchivo);
     if (archivo.open(QIODevice::WriteOnly|QIODevice::Text))
     {
         archivo.write(ui->entrada->toPlainText().toUtf8());
     }
}

void Principal::Prueba(){

    QString arch="C:\\Users\\CORE i7 64BITS\\Desktop\\PrubaXML.txt";

    QFile archivo(arch);
    QString contenido;

    QString nombre="ExpresionReg1";

    if (archivo.open(QIODevice::ReadOnly|QIODevice::Text)) {
        contenido=QString::fromUtf8(archivo.readAll());
    }

     QRegExp exp("(\n|\r)");

     contenido.replace(exp,"");
     contenido.replace(" ","");


    nombre.replace(" ","");

    int actual=0;
    for(int x=0;x<contenido.size();x++){


        actual=contenido.lastIndexOf(nombre);

        if(actual==-1){
            break;
        }
        //si encontro coincidencia algo lo siguiente

        QString busc="<Resultado>";
        QString busca1="<Resultado/>";

        int primer=contenido.indexOf(busc,actual);

        primer+=busc.size();

        int ultimo=contenido.indexOf(busca1,actual);

        int diferencia=ultimo-primer;;


        QString ext=contenido.mid(primer,diferencia);

        QString salida=ext.toUtf8().constData();
        if(QString::compare(ext,"cadenavalida",Qt::CaseInsensitive)==0){
            //retorno algo

        }else{
            x=ultimo;
        }


    }
}
