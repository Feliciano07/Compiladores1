#include "primerrecorrido.h"



 enum Estados{
    INICIO=0,
    LISTA_INCLU=1,
    incluir=2,
    CLASES=3,
    CLASE=4,
    //cosas que pueden venir en la estructura de una clase
    LISTA_SENTENCIA=5,
    VARIABLE=6,
    OBJETO=7,
    ARREGLO=8,
    METODO_FUNCION=9,
    PRINCIPAL=10,

    //visibilidad de las cosas
    publico=11,
    privado=12,
    protegido=13,

    //tipo de datos primitivos

    entero=14,
    DOBLE=15,
    cadena=16,
    caracter=17,
    boolean=18,
    //idetificador variables, arreglos

    DEC_ID=19,

    Id=20,

    //asignar valor, var, arreglos
    ASIGNACION=21,
    final=22,
    operacion=23,

    //operaciones aritmeticas y logicas
    suma=24,
    resta=25,
    multiplicacion=26,
    division=27,
    potencia=28,
    Or=29,
    And=30,
    Nand=31,
    Nor=32,
    comparar=33,
    diferencia=34,
    menorQ=35,
    menorIgual=36,
    mayorQ=37,
    mayorIgual=38,
    Not=39,

    //valores como tal, de los primitivos
    cha=40,
    str=41,
    decimal=42,
    numero=43,
    verdadero=44,
    falso=45,

    //Manipulaciond de metodos y funciones
    sobrescribir=46,
    TIPO_F=47,
    clase=48,
    PRIMITIVO=49,
    arreglo=50,
    //en otro caso es void
    voide=57,
    //tipos de parametros
    SIN_PARAMETRO=51,
    LISTA_PARAMETROS=52,
    variable=51,
    objeto=52,


    //lista genenral para funciones,codiciones,ciclos,casos
    LISTA_GENERAL=53,
    LLAMADA_FUNCION=54,
    POR_ARREGLO=55,
    ERROR=56,
     //siguiente numero 58

     //manejar lo que esta dentro de los metodos
     SENTENCIA_GENERAL=58,
     SENTENCIA_ARCHIVOS=59,
     VAR_GLOBALES =60,
     DECLARAR_OBJEC=61,
     NUEVO_OBJEC=62,
     REASIGNAR_ARREGLO=64,
     ASIGNAR_VAR=65,
     actualizar=66,
     START_SI=67,
     START_HACER=68,
     START_MIENTRAS=69,
     START_PARA=70,
     START_REPETIR=71,
     imprimir=72,
     RETORNO=73,
     romper=74,
     continuar=75,
     OTRO_SI=76,

     sino=77,
     FIN_SI=78,
     SinoSi=79,
     LISTA_SI=80,

     /*arcivos*/
     archivo=81,
     nuevo_conjunto=82,
     nuevo_regex=83,
    nueva_entrada=84,
     guarda_arch=85,

     Local_F_V=86,
     Local_F_S=87,
     negativo=88,
     nuevo_objeto=89,
     No_Inicial=90,

     DIMENSION1=91,
     DIMENSION2=92,
     DIMENSION3=93,
     LISTA_NORMAL=94,
     LISTA2=95,
     LISTA3=96,

     Externa_F_V=97,
     Externa_F_S=98,
     Externa_Var=99,
     Externa_Var_A=100,
     Externa_Ar_A=101,
     Externa_Ar=102,
     START_COMPROBAR=103,
     LISTA_CASO=104,
     caso=105,
     defecto=106,

     /*---las cuentas*/

     SENTENCIA_CUENTA=108,

     cuenta=109,
     verCuenta=110,
     depCuenta=111,
     resCuenta=112,
     imprimirCuenta=113,
     conCuenta=114,
     transferir=115

};


PrimerRecorrido::PrimerRecorrido()
{
    this->termina=-1;
    this->rompe=-1;
    this->continua=-1;
}

void PrimerRecorrido::ComprobarClases(){
    QHash<QString, Entorno>::iterator i;

    bool Encontrado=false;
    for ( (i = clases.begin()); i != clases.end(); ++i){
            //QHash<QString,Simbolos> tableSim=i.value().tablaSimbolos;

            QHash<QString, Simbolos>::iterator j;

            for ( (j = i.value().tablaSimbolos.begin()); j != i.value().tablaSimbolos.end(); ++j){
                   Simbolos sem=j.value();
                   if(sem.tipo_==48 && sem.getTipo_Dato()!="funcion"){

                       QHash<QString, Entorno>::iterator k;

                       for ( (k = clases.begin()); k != clases.end(); ++k){
                           if(QString::compare(sem.id_clase,k.key(),Qt::CaseInsensitive)==0){

                               QHash<QString,Simbolos> nuevo=k.value().tablaSimbolos;
                               j.value().simbolosClase=nuevo;

                               Encontrado=true;
                           }

                       }
                       if(Encontrado==false){

                       }
                   }

            }

    }

}

void PrimerRecorrido::CreandoTabla(Entorno *aux){
    QHash<QString,Simbolos> tabla=aux->tablaSimbolos;

     QHash<QString, Simbolos>::iterator i;

     for ( (i = tabla.begin()); i != tabla.end(); ++i){

         tablaS->insertRow(tablaS->rowCount());

         tablaS->setItem(tablaS->rowCount()-1,0,new QTableWidgetItem(i.value().getVisibilidad()));
         tablaS->setItem(tablaS->rowCount()-1,1,new QTableWidgetItem(i.key()));
         tablaS->setItem(tablaS->rowCount()-1,2,new QTableWidgetItem(i.value().getValor()));
         tablaS->setItem(tablaS->rowCount()-1,3,new QTableWidgetItem(i.value().getTipo()));
         tablaS->setItem(tablaS->rowCount()-1,4,new QTableWidgetItem(i.value().getTipo_Dato()));
         tablaS->setItem(tablaS->rowCount()-1,5,new QTableWidgetItem(i.value().getRetorno()));
         tablaS->setItem(tablaS->rowCount()-1,6,new QTableWidgetItem(i.value().ambito));
     }

}

void PrimerRecorrido::Recorrer(NodoAST *raiz){

    for (int x= 0; x< raiz->hijos.size(); x++){
        int ti=raiz->hijos.at(x).tipo_;

        switch (ti) {
        case CLASES:
            {
                //acciones de clase
                NodoAST lista_clases=raiz->hijos.at(x);

                for(int y= 0; y< lista_clases.hijos.size(); y++){

                    NodoAST nodo=lista_clases.hijos.at(y);
                    QString nombre=nodo.valor;//nombre de la clase
                    Entorno *nuevo=new Entorno();//entorno nuevo clase

                    nuevo->id_Entorno=nombre;
                    nuevo->tipo_entorno=clase;

                    NodoAST ex=nodo.hijos.at(0);
                    Extender(&ex); //metodo de extender

                    NodoAST sentencia=nodo.hijos.at(1);
                    SacarClases(&sentencia,nuevo,nombre);//metodo para sacar,variables,arreglos,etc

                    //QHash con las clases declaradas
                    clases.insert(nombre,*nuevo);
                }

            }

            break;
        case LISTA_INCLU:
            {
                NodoAST incl=raiz->hijos.at(x);
                GuardarIncluir(&incl);

            }
            break;

        }

    }


}
/*---------------------------- MANEJO DE EXTENER---------------------------*/
void PrimerRecorrido::GuardarIncluir(NodoAST *Lista){
    QList<NodoAST> lis=Lista->hijos;

    for (int x =0;x<lis.size();x++) {

        QString valor=lis.at(x).valor;
        Extensiones *nuevo=new Extensiones(valor);
        ArchivosExternos.append(*nuevo);
        //recorro todos los incluir del archivo original

    }



}
void PrimerRecorrido::IngresarIncluir(){

}

//-----------------------METODO DE LOS EXTENDER-------------------------------
void PrimerRecorrido::Extender(NodoAST *raiz){

    //algo para sacar los extender

}

//-----------------------------METODO QUE SACA,varriable,arreglos,metodos,funciones

void PrimerRecorrido::SacarClases(NodoAST *raiz,Entorno *en,QString nombe){

    //empiezo a recorrer la lista de sentencias
    for (int y=0;y<raiz->hijos.size();y++) {
        int tipo=raiz->hijos.at(y).tipo_;
        switch (tipo) {
                case VARIABLE:
                    {
                            //los hijos de variable globales siempre seran dos
                            NodoAST variable=raiz->hijos.at(y);

                            QString visi=variable.hijos.at(0).valor;//visibilidad

                            QList<NodoAST> datos=variable.hijos.at(1).hijos;

                            QString tipoDato=datos.at(0).valor;//entero,doble,cadena,etc

                            int te=datos.at(0).tipo_;//tipo de dato en int

                            Operacion op=Operacion();
                            QList<QString> ids;//--->lista de que guarda el id o id's

                            for (int a=0;a<datos.size();a++) {
                                switch (datos.at(a).tipo_) {
                                    case DEC_ID://lista de id
                                    {
                                        NodoAST listaId=datos.at(a);

                                        ids=IDE(&listaId);//obtengo los ids


                                    }break;
                                    case operacion://se le asigna valor a las variables
                                    {
                                        NodoAST operacion=datos.at(a).hijos.at(0);

                                        op=Asignacion(&operacion,en);
                                    }break;
                                    case final://no se asgina valor
                                    {
                                        NodoAST fin=datos.at(a);

                                    }break;
                                }
                            }
                        //llamada a la funcion para comprobar los datos
                         CASTEO(en,ids,te,visi,op,"global",false);

                    } break;
                    case PRINCIPAL:{
                        NodoAST aux=raiz->hijos.at(y);
                        NodoAST *pri=new NodoAST();
                        *pri=aux.hijos.at(0);
                        en->principal=pri;

                    }break;
                case OBJETO :
                    {
                        NodoAST obe=raiz->hijos.at(y);
                        ExtraerObjetos(&obe,en,"global",0);
                    }break;
                case ARREGLO:
                    {
                        NodoAST hijosA=raiz->hijos.at(y);
                        ExtraerArreglo(&hijosA,en,0);

                    }break;
                case METODO_FUNCION:
                    {
                        NodoAST aux=raiz->hijos.at(y);
                        Metodo_Funcion *mefA=new Metodo_Funcion();
                        Metodos_Funciones(&aux,mefA);
                        en->addFuncion(mefA,nombe);
                       // delete mefA;
                    }break;
        }

    }

}
/*----------------------- METODO PARA GUARDAR LOS OBJETOS ----------------------*/
void PrimerRecorrido::ExtraerObjetos(NodoAST *raiz, Entorno *actua,QString am,int ambito){

    QList<NodoAST> hijos=raiz->hijos;
    QList<NodoAST> nombres;
    QString visibi="";
    bool Inicial=false;
    QString obj;QString cl;
    for(NodoAST ast: hijos){
        int tipo_=ast.tipo_;

        if(tipo_==nuevo_objeto){
            nombres=ast.hijos;
            Inicial=true;
        }else if(tipo_==No_Inicial){
            nombres=ast.hijos;
        }else{
            visibi=ast.valor;
        }


    }
    bool YaEntro=false;
    for(NodoAST ast:nombres){
        int tipo_=ast.tipo_;
        if(tipo_==Id){
            if(YaEntro==false){
                cl=ast.valor;
                YaEntro=true;
            }else{
                obj=ast.valor;
            }

        }
    }
    Simbolos *nuevo=new Simbolos(obj,cl,"","clase");
    nuevo->setVisibilidad(visibi);
    nuevo->ClaseIniciada=Inicial;
    nuevo->addTipo_(48);
    nuevo->ambito=am;
    if(ambito==0){

        if(actua->ExisteSimbolo(obj,actua)){
            Errores *er =new Errores(obj,"semantico","Ya existe un simbolo con el mismo nombre",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{
             actua->addSimbolo(nuevo);
        }

    }else{
        if(actua->ExisteSimbolo(nuevo,actua)){
            Errores *er =new Errores(obj,"semantico","Ya existe un simbolo con el mismo nombre",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{
            bool encontrado=false;
            QHash<QString, Entorno>::iterator i;

            for ( (i = clases.begin()); i != clases.end(); ++i){
                QString id=i.key();
                if(QString::compare(cl,id,Qt::CaseInsensitive)==0){
                    encontrado=true;
                    nuevo->simbolosClase=i.value().tablaSimbolos;
                }

            }
            if(encontrado==true){
                actua->addSimbolo(nuevo);
            }else{
                Errores *er=new Errores(obj,"semanticos","La clase no se ha encontrado",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }

        }
    }

}


/*--------------------- METODO PARA GUARDAR LOS ARREGLOS--------------------------*/
void PrimerRecorrido::ExtraerArreglo(NodoAST *raiz, Entorno *actual,int ambito){
    QList<NodoAST> hijos=raiz->hijos;// recibo visibilidad o arreglo
    QString visi="";
    QList<QString> ids;
    NodoAST ids_dato;
    NodoAST dimension;
    int te=0;
    for(NodoAST ast: hijos){
        if(ast.tipo_==arreglo){
            ids_dato=ast.hijos.at(0);
            dimension=ast.hijos.at(1);
        }else{
            visi=ast.valor;//la visivilidad
        }

    }

    /*--------sacar los id y el tipo*/

    for(NodoAST ast: ids_dato.hijos){
        switch (ast.tipo_) {
        case DEC_ID:{
            NodoAST dec=ast;
            ids=IDE(&dec);
        }break;
        default:{
            te=ast.tipo_;
        }break;
        }
    }

    //int TipoDimension;

    Arreglos *nuevos;

    switch (dimension.tipo_) {
    case DIMENSION1:{
        NodoAST ast1=dimension.hijos.at(0);
        Operacion op1=Asignacion(&ast1,actual);
        nuevos=new Arreglos(op1.valor.toInt());
        nuevos->tipo_=te;
        NodoAST unico=dimension.hijos.at(1);
        if(unico.tipo_==final){

            CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION1);
        }else{
            ArregloIniciado(&unico,nuevos,actual,-1,-1,0);
            CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION1);
        }

    }break;
    case DIMENSION2:{
             NodoAST ast1=dimension.hijos.at(0);
              NodoAST ast2=dimension.hijos.at(1);
              Operacion op1=Asignacion(&ast1,actual);
              Operacion op2=Asignacion(&ast2,actual);
              nuevos=new Arreglos(op1.valor.toInt(),op2.valor.toInt());
              nuevos->tipo_=te;
              NodoAST unico=dimension.hijos.at(2);
              if(unico.tipo_==final){
                  CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION2);
              }else{
                  ArregloIniciado(&unico,nuevos,actual,-1,0,0);
                  CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION2);

              }

    }break;
    case DIMENSION3:{
         NodoAST ast1=dimension.hijos.at(0);
          NodoAST ast2=dimension.hijos.at(1);
           NodoAST ast3=dimension.hijos.at(2);
           Operacion op1=Asignacion(&ast1,actual);
           Operacion op2=Asignacion(&ast2,actual);
           Operacion op3=Asignacion(&ast3,actual);
           nuevos=new Arreglos(op1.valor.toInt(),op2.valor.toInt(),op3.valor.toInt());
           nuevos->tipo_=te;
           NodoAST unico=dimension.hijos.at(3);
           if(unico.tipo_==final){
               CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION3);
           }else{
              ArregloIniciado(&unico,nuevos,actual,0,0,0);
              CrearArreglo(ids,actual,nuevos,visi,te,ambito,DIMENSION3);
           }
    }break;

    }

}

void PrimerRecorrido::ArregloIniciado(NodoAST *lis, Arreglos *auxiliar, Entorno *entor,int f,int c,int n){
    NodoAST *aux=lis;

    switch (aux->tipo_) {
    case LISTA_NORMAL:{
        QList<NodoAST> hijos=aux->hijos;

        for(int x=0;x<hijos.size();x++){
            NodoAST oper=hijos.at(x);
            Operacion op=Asignacion(&oper,entor);
            Objeto nuevo=Objeto(op.valor,op.tipo,"");
            QString mensaje;
            if(f==-1 && c==-1){
                mensaje=auxiliar->setDato1(nuevo,x,op.tipo);
                for(int a=0;a<auxiliar->F;a++){

                        qDebug()<<auxiliar->array[a].dato;


                }

            }else if(f==-1 && c!=-1){
                mensaje=auxiliar->setDato2(nuevo,c,x,op.tipo);
            }else if(f!=-1 && c!=-1){
                mensaje=auxiliar->setDato3(nuevo,f,c,x,op.tipo);
            }

            if(QString::compare(mensaje,"")!=0){
                Errores *er =new Errores("Arreglos","semantico",mensaje,oper.linea,oper.columna);
                semanticos.append(*er);
            }
        }


    }break;
    case LISTA2:{
        QList<NodoAST> hijos=aux->hijos;
        for(int y=0;y<hijos.size();y++){
            NodoAST entra=hijos.at(y);
            if(f==-1){
                ArregloIniciado(&entra,auxiliar,entor,-1,y,0);
            }else{
                ArregloIniciado(&entra,auxiliar,entor,f,y,0);
            }

        }

    }break;

    case LISTA3:{
        QList<NodoAST> hijos=aux->hijos;
        for(int a=0;a<hijos.size();a++){
            NodoAST entra=hijos.at(a);
            ArregloIniciado(&entra,auxiliar,entor,a,0,0);
        }

    }break;

    }



}

/*-------------------------- METODO PARA CREAR LOS ARREGLOS COMO TAL-------------------------------------------------------*/
void PrimerRecorrido::CrearArreglo(QList<QString> ide, Entorno *actu, Arreglos *nuevo, QString visi, int tipo,int ambito,int dime){

    for(QString iden: ide){

        if(ambito==0){//entorno global
            Simbolos *nueSimbolo=new Simbolos(iden,"","arreglo");
            if(actu->ExisteSimbolo(iden,actu)){
                Errores *er=new Errores(iden,"semantico","Nombre de la variable ya utilizada",0,0);
                semanticos.append(*er);
            }else{
                nueSimbolo->addTipo_(50);
                nueSimbolo->ambito="global";
                nueSimbolo->setVisibilidad(visi);
                nueSimbolo->dimension=dime;
                nuevo->tipo_=tipo;

                nueSimbolo->nuevoAr=nuevo;
                actu->addSimbolo(nueSimbolo);
            }
        }else {
            Simbolos *nueSimbolo=new Simbolos(iden,"","arreglo");
            if(actu->ExisteSimbolo(nueSimbolo,actu)){
                Errores *er=new Errores(iden,"semantico","Nombre de la variable ya utilizada",0,0);
                semanticos.append(*er);
            }else{
                nueSimbolo->addTipo_(50);
                nueSimbolo->ambito="local";
                nueSimbolo->setVisibilidad(visi);
                nueSimbolo->dimension=dime;
                nuevo->tipo_=tipo;
                nueSimbolo->nuevoAr=nuevo;
                actu->addSimbolo(nueSimbolo);
            }

        }
    }


}


/*----------------------METODO PARA SACAR LISTA DE IDS-----------------------------*/

QList<QString> PrimerRecorrido::IDE(NodoAST *raiz){
    QList<QString> listaId;

    for(int b=0;b<raiz->hijos.size();b++){
            listaId.append(raiz->hijos.at(b).valor);//lista de ids
    }

    return listaId;
}

/*-----------------------METODO PARA CREAR LA TABLA DE SIMBOLOS PARA LA PRIMERA CLASE--------------------*/

void PrimerRecorrido::CASTEO(Entorno *en, QList<QString> id, int tipo, QString vis, Operacion op,QString ambito,int te){



        if(tipo==entero){
            if(op.tipo==numero){
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==str){
                Errores *err=new Errores("Castep","semantico","No se puede castear cadena a entero",op.linea,op.columna);
                semanticos.append(*err);
            }else if(op.tipo==cha){
                int aux=ConverInt(op.valor);
                op.tipo=numero;
                op.valor=QString::number(aux);
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==verdadero){
                op.tipo=numero;
                op.valor="1";
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==falso){
                op.tipo=numero;
                op.valor="0";
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==decimal){
                    int aux=op.valor.toInt();
                    op.tipo=numero;
                    op.valor=QString::number(aux);
                    AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==ERROR){

            }else if(op.tipo==-1){
                op.tipo=numero;
                AsignarVariable(en,id,"",op,ambito,te);
            }

        }else if(tipo==cadena){
            if(op.tipo==str){
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==-1){
                op.tipo=str;
                AsignarVariable(en,id,"",op,ambito,te);

            }else{
                Errores *err=new Errores("Casteo","semantico","No se puede castear este tipo a cadena",op.linea,op.columna);
                semanticos.append(*err);
            }


        }else if(tipo==caracter){
            if(op.tipo==numero){
                QString aux=ConverChar(op.valor);
                op.tipo=cha;
                op.valor=aux;
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==cha){
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==-1){
                op.tipo=cha;
                AsignarVariable(en,id,"",op,ambito,te);
            }else{
                Errores *err=new Errores("Casteo","semantico","No se puede castear este tipo a caracter",op.linea,op.columna);
                semanticos.append(*err);
            }

        }else if(tipo==boolean){
            if(op.tipo==verdadero || op.tipo==falso){
                AsignarVariable(en,id,vis,op,ambito,te);
            }else if(op.tipo==-1){
                op.tipo=falso;
                AsignarVariable(en,id,"",op,ambito,te);
            }else{
                Errores *err=new Errores("Casteo","semantico","No se puede castear este tipo a cadena",op.linea,op.columna);
                semanticos.append(*err);
            }

        }else if(tipo==DOBLE){
            if(op.tipo==entero){
                op.tipo=decimal;
                double in=op.valor.toDouble();
                op.valor=QString::number(in);
                AsignarVariable(en,id,vis,op,ambito,te);

            }else if(op.tipo==str){
                Errores *err=new Errores("Casteo","semantico","No se puede castear este cadena a doble",op.linea,op.columna);
                semanticos.append(*err);
            }else if(op.tipo==cha){
                int aux=ConverInt(op.valor);
                op.tipo=decimal;
                op.valor=QString::number(aux);
            }else if(op.tipo==verdadero){
                Errores *err=new Errores("Casteo","semantico","No se puede castear este booleano a doble",op.linea,op.columna);
                semanticos.append(*err);

            }else if(op.tipo==falso){
                Errores *err=new Errores("Casteo","semantico","No se puede castear este booleano a doble",op.linea,op.columna);
                semanticos.append(*err);
            }else if(op.tipo==decimal){
                AsignarVariable(en,id,vis,op,ambito,te);

            }else if(op.tipo==-1){
                op.tipo=decimal;
                AsignarVariable(en,id,"",op,ambito,te);
            }else if(op.tipo==ERROR){

            }

        }else if(tipo==ERROR){

        }




}

void PrimerRecorrido::AsignarVariable(Entorno *en, QList<QString> id, QString vis,Operacion op,QString am,int t){
    for (int a=0;a<id.size();a++) {

        Simbolos *sm=new Simbolos(id.at(a),op.valor,"variable");
        sm->addTipo_(op.tipo);
        sm->setVisibilidad(vis);
        sm->ambito=am;
        if(t==false){//0
            if(en->ExisteSimbolo(sm,en)==true){
                Errores *err=new Errores(id.at(a),"semantico","Variable ya existente",op.linea,op.columna);
                semanticos.append(*err);
            }else{
                en->addSimbolo(sm);
            }
        }else if(t==true){//1
            en->SetearValor(id.at(a),op,am,en);
        }else {
            QStringList lis=id.at(a).split(";");
            QString obje=lis.at(0);
            QString simb=lis.at(1);

            Simbolos objeto=en->BuscarVariable(obje,en);
            Simbolos sem=objeto.simbolosClase.value(simb);
            //copia los valores y creo nueva var
            Simbolos sim= Simbolos(sem.getId(),op.valor,"variable");
            sim.addTipo_(op.tipo);
            sim.setVisibilidad(sem.getVisibilidad());
            sim.ambito=am;
            // sustituyo el valor anterior por el nuevo
            objeto.simbolosClase.insert(sim.getId(),sim);
            //vuelve a setear el objeto
            en->SetearObjeto(objeto,en);

        }




    }
}





/*------------------------METODO PARA OPERACIONES LOGICAS--------------------------------*/

double PrimerRecorrido::Potencia(int base,int potecia){
    double potencia=0;

    potencia=base^potecia;

    return potencia;

}

QString PrimerRecorrido::ConverChar(QString caracter){//convertir int a char
    int cha=caracter.toInt();
    char ca=char(cha);
    QString salida;
    salida.append(ca);
    return salida;

}

int PrimerRecorrido::ConverInt(QString caracter){//convertir char a int
    std::string cas=caracter.toStdString();
    char c=cas[0];
    try {
        return int(c);
    } catch (...) {
        return -1;
    }

}

bool PrimerRecorrido::Comparar(QString a, QString b){
    int x = QString::compare(a, b, Qt::CaseInsensitive);

    if(x==0){
        return true;
    }else{
        return false;
    }

}
//--------------metodo para menor que numeros-----

bool PrimerRecorrido::MenorQEntero(QString a, QString v){
    double primer=a.toDouble();
    double ultimo=v.toDouble();

    if(primer<ultimo){
        return true;
    }else {
        return false;
    }
}

bool PrimerRecorrido::menorIgualE(QString a, QString v){
    double primer=a.toDouble();
    double ultimo=v.toDouble();

    if(primer<=ultimo){
        return true;
    }else {
        return false;
    }
}
bool PrimerRecorrido::MayorQEntero(QString a, QString v){
    double primer=a.toDouble();
    double ultimo=v.toDouble();

    if(primer>ultimo){
        return true;
    }else {
        return false;
    }
}
bool PrimerRecorrido::MayorIgualE(QString a, QString v){
    double primer=a.toDouble();
    double ultimo=v.toDouble();

    if(primer>=ultimo){
        return true;
    }else {
        return false;
    }
}

int PrimerRecorrido::MenorQCadena(QString a, QString v){
    int salida=QString::compare(a,v,Qt::CaseInsensitive);

    return salida;
}

/*--------------------------METODO QUE EXTRAE LOS DATOS DE UNA FUNCION--------------------*/

void PrimerRecorrido::Metodos_Funciones(NodoAST *raiz,Metodo_Funcion *mef){



    switch (raiz->tipo_) {
    case sobrescribir:{
            mef->sobre=raiz->valor;
    }break;
    case publico:{
            mef->visivilidad=raiz->valor;//visibilidad
            mef->tipo_Vis=raiz->tipo_;//tipo visiblidad
    }break;
    case privado:{
        mef->visivilidad=raiz->valor;
        mef->tipo_Vis=raiz->tipo_;
    }break;
    case protegido:{
        mef->visivilidad=raiz->valor;
        mef->tipo_Vis=raiz->tipo_;
    }break;
    case entero:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case DOBLE:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case cadena:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case caracter:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case boolean:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case arreglo:{
        /*-------------------------------- ACA VA A IR EL CODIGO DE CUANDO TENGO QUE RETORNAR UN TIP ARREGLO-----*/
        mef->tipo_F="arreglo";
        mef->tipo=raiz->hijos.at(0).tipo_;
        NodoAST dimen=raiz->hijos.at(1);
        Arreglos *nuevo=new Arreglos();

        switch (dimen.tipo_) {

        case DIMENSION1:{
            NodoAST astOp1=dimen.hijos.at(0);

             nuevo=new Arreglos(astOp1.valor.toInt());
             nuevo->tipo_=raiz->hijos.at(0).tipo_;
             mef->Dimension=DIMENSION1;

        }break;

        case  DIMENSION2:{
            NodoAST astOp1=dimen.hijos.at(0);

            NodoAST astOp2=dimen.hijos.at(1);

            nuevo=new Arreglos(astOp1.valor.toInt(),astOp2.valor.toInt());
            nuevo->tipo_=raiz->hijos.at(0).tipo_;
            mef->Dimension=DIMENSION2;
        }break;

        case DIMENSION3:{
            NodoAST astOp1=dimen.hijos.at(0);

            NodoAST astOp2=dimen.hijos.at(1);

            NodoAST astOp3=dimen.hijos.at(2);

            nuevo=new Arreglos(astOp1.valor.toInt(),astOp2.valor.toInt(),astOp3.valor.toInt());
            nuevo->tipo_=raiz->hijos.at(0).tipo_;
            mef->Dimension=DIMENSION3;
        }break;

        }
        mef->arra=nuevo;


    }break;
    case clase:{
        /*---------------------- ACA VA A IR EL CODIGO DE CUANDO TENGA QUE RETORNAR UN TIPO DE CLAS--------------*/
        mef->Clase=raiz->valor;
        mef->tipo_F="clase";

    }break;
    case voide:{
        mef->tipo_F=raiz->valor;
        mef->tipo=raiz->tipo_;
    }break;
    case Id:{
        mef->nombre=raiz->valor;
        break;
    }
    case SIN_PARAMETRO:{

    }break;
    case LISTA_GENERAL:{
        NodoAST nuevo=*raiz;

        mef->listaGeneral=nuevo;
    }break;
    case LISTA_PARAMETROS:{
            //aca voy a tener a tener una lista
        for (int b=0;b<raiz->hijos.size();b++) {
            NodoAST aux=raiz->hijos.at(b);
            Lista_Para(&aux,mef);
        }


    }break;
    case METODO_FUNCION:{
        for(int a=0;a<raiz->hijos.size();a++){
            NodoAST aux=raiz->hijos.at(a);
            Metodos_Funciones(&aux,mef);
        }
        //aca va a terminar

    }break;

    }


}
/*------------------------------funcion que me guarda una lista de parametros de Metodo_Funcion-----------------------*/
void PrimerRecorrido::Lista_Para(NodoAST *raiz,Metodo_Funcion *mef){
    switch (raiz->tipo_) {
    case variable:{
        int tip_=-1;
        QString tipo;
        NodoAST aux=raiz->hijos.at(0);
        QString id=raiz->hijos.at(1).valor;
        if(aux.tipo_==entero){
            tipo=aux.valor;
            tip_=numero;
        }else if(aux.tipo_==DOBLE){
            tipo=aux.valor;
            tip_=decimal;
        }else if(aux.tipo_==cadena){
            tipo=aux.valor;
            tip_=str;
        }else if(aux.tipo_==caracter){
            tipo=aux.valor;
            tip_=cha;
        }else if(aux.tipo_==boolean){
            tipo=aux.valor;
            tip_=falso;

        }
        if(mef->VerificarParametro(id)){
            Errores *er=new Errores(id,"semantico","FUncion con parametros con el mismo nombre",raiz->hijos.at(1).linea,raiz->hijos.at(1).columna);
            semanticos.append(*er);
        }else{
            Simbolos *s=new Simbolos(id,"","variable");
            s->addTipo_(tip_);

            mef->addParametro(id,s);
        }

    }break;
    case objeto:{
        /*------------------- CUANDO UNA FUNCION RECIBA PARAMETROS DE OBJETO-------------------*/
        QString cla=raiz->hijos.at(0).valor;
        QString obe=raiz->hijos.at(1).valor;

        if(mef->VerificarParametro(obe)){
            Errores *er=new Errores(obe,"semantico","FUncion con parametros con el mismo nombre",raiz->hijos.at(1).linea,raiz->hijos.at(1).columna);
            semanticos.append(*er);
        }else{
            Simbolos *nuevo=new Simbolos(obe,cla,"","clase");
            nuevo->setVisibilidad("");
            nuevo->ClaseIniciada=true;
            nuevo->addTipo_(48);
            nuevo->ambito="";
            mef->addParametro(obe,nuevo);
        }


    }break;
    case arreglo:{
            /*------------------- CUANDO UNA FUNCION RECIBA PARAMETROS DE ARREGLO-------------------*/
            QString iden=raiz->valor;
            NodoAST te=raiz->hijos.at(0);
            NodoAST dimen=raiz->hijos.at(1);

            int dim=dimen.tipo_;
            Arreglos *nuevo=new Arreglos();

            switch (dimen.tipo_) {

            case DIMENSION1:{
                NodoAST astOp1=dimen.hijos.at(0);

                 nuevo=new Arreglos(astOp1.valor.toInt());
                 nuevo->tipo_=te.tipo_;


            }break;

            case  DIMENSION2:{
                NodoAST astOp1=dimen.hijos.at(0);

                NodoAST astOp2=dimen.hijos.at(1);

                nuevo=new Arreglos(astOp1.valor.toInt(),astOp2.valor.toInt());
               nuevo->tipo_=te.tipo_;

            }break;

            case DIMENSION3:{
                NodoAST astOp1=dimen.hijos.at(0);

                NodoAST astOp2=dimen.hijos.at(1);

                NodoAST astOp3=dimen.hijos.at(2);

                nuevo=new Arreglos(astOp1.valor.toInt(),astOp2.valor.toInt(),astOp3.valor.toInt());
                nuevo->tipo_=te.tipo_;

            }break;

            }
            if(mef->VerificarParametro(iden)){
                Errores *er=new Errores(iden,"semantico","FUncion con parametros con el mismo nombre",raiz->hijos.at(1).linea,raiz->hijos.at(1).columna);
                semanticos.append(*er);
            }else{
                Simbolos *nueSimbolo=new Simbolos(iden,"","arreglo");
                nueSimbolo->addTipo_(50);
                nueSimbolo->ambito="local";
                nueSimbolo->setVisibilidad("");
                nueSimbolo->dimension=dim;
                nuevo->tipo_=te.tipo_;
                nueSimbolo->nuevoAr=nuevo;
                mef->addParametro(iden,nueSimbolo);
            }
    }break;
    }

}

/*--------------------- METODO QUE EXTRAE UN VALOR PARA VARIABLE--------------------------*/

Operacion PrimerRecorrido::Asignacion(NodoAST *raiz,Entorno *clas){

    Operacion op=Operacion();
    op.linea=raiz->linea;
    op.columna=raiz->columna;

    switch (raiz->tipo_)
    {

        case numero://cuando viene solo un numero
        {
            op.tipo=numero;
            op.valor=raiz->valor;

        }
        break;
        case str:
        {

           op.tipo=str;
           op.valor=raiz->valor;
        }
        break;
        case cha://viene una caracter
        {
            op.tipo=cha;
            op.valor=raiz->valor;
        }
        break;
        case decimal:
        {
            op.tipo=decimal;
            op.valor=raiz->valor;
        }
        break;

        case verdadero:
        {
            op.tipo=verdadero;
            op.valor=raiz->valor;
        }
        break;
        case falso:
        {
            op.tipo=falso;
            op.valor=raiz->valor;

        }break;
        case verCuenta:
        {

            QString ide=raiz->valor;

            Simbolos aux=clas->BuscarVariable(ide,clas);

            if(QString::compare(aux.getId(),"")!=0){
                bool salida=ValidarCuenta(aux.cuenta.nombreArchivo,aux.cuenta.expresionRegular);
                if(salida==true){
                    op.valor="verdadero";
                    op.tipo=verdadero;
                }else{
                    op.valor="falso";
                    op.tipo=falso;
                }
            }else{
                Errores *er =new Errores(ide,"semantico","la variable cuenta no existe",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }

        }break;
        case imprimirCuenta:
        {
            QString ide=raiz->valor;

            Simbolos aux=clas->BuscarVariable(ide,clas);

            if(QString::compare(aux.getId(),"")!=0){
                op.valor=aux.cuenta.RetonarMovimiento();
                op.tipo=str;
            }else{
                Errores *er =new Errores(ide,"semantico","la variable cuenta no existe",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }

        }
        break;
        case conCuenta:
        {
            QString ide=raiz->valor;

            Simbolos aux=clas->BuscarVariable(ide,clas);

            if(QString::compare(aux.getId(),"")!=0){
                op.valor=QString::number(aux.cuenta.ConsultarSaldo());
                op.tipo=decimal;
            }else{
                Errores *er =new Errores(ide,"semantico","la variable cuenta no existe",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }

        }break;
        case LLAMADA_FUNCION:
        {
            NodoAST tipoLlamada=raiz->hijos.at(0);

            switch (tipoLlamada.tipo_) {
                case Local_F_S:{
                /*FUNCION LOCAL SIN PARAMETROS*/
                    QString id=tipoLlamada.valor;
                    VerificarFuncion(id,nullptr,clas,1);

                    Simbolos sem=clas->BuscarVariable(id,clas);
                    if(QString::compare(sem.getId(),"")!=0){

                        if(sem.poseRetorno==true){

                            if(sem.tipo_==48){
                                op.objec=sem;
                                op.tipo=48;
                            }else if(sem.tipo_==50){
                                op.array=*sem.nuevoAr;
                                op.tipo=50;
                            }else{
                                op.valor=sem.retorno;
                                op.tipo=sem.tipo_;
                            }
                        }
                    }


                }break;

                case Local_F_V:{
                /*FUNCION LOCAN CON PARAMETROS*/
                    QString id =tipoLlamada.valor;
                    NodoAST par=tipoLlamada.hijos.at(0);//nodo con los valores
                    VerificarFuncion(id,&par,clas,0);

                    Simbolos sem=clas->BuscarVariable(id,clas);
                    if(QString::compare(sem.getId(),"")!=0){

                        if(sem.poseRetorno==true){

                            if(sem.tipo_==48){
                                op.objec=sem;
                                op.tipo=48;
                            }else if(sem.tipo_==50){
                                op.array=*sem.nuevoAr;
                                op.tipo=50;
                            }else{
                                op.valor=sem.retorno;
                                op.tipo=sem.tipo_;
                            }
                        }
                    }

                }break;

                case Externa_F_V:{
                    /*funcion externa co parametros tipo pueden traer parametro 2*/
                    QString id=tipoLlamada.valor;
                    QString simbolo=tipoLlamada.hijos.at(0).valor;
                    NodoAST para=tipoLlamada.hijos.at(1);
                    QString valor=id+";"+simbolo;
                    VerificarFuncion(valor,&para,clas,2);

                    Simbolos objeto=clas->BuscarVariable(id,clas);

                    if(QString::compare(objeto.getId(),"")!=0){

                        Simbolos sem=objeto.simbolosClase.value(simbolo);
                        if(sem.poseRetorno==true){

                            if(sem.tipo_==48){
                                op.objec=sem;
                                op.tipo=48;
                            }else if(sem.tipo_==50){
                                op.array=*sem.nuevoAr;
                                op.tipo=50;
                            }else{
                                op.valor=sem.retorno;
                                op.tipo=sem.tipo_;
                            }
                        }
                    }



                }break;

                case Externa_F_S:{
                    /*funcion externa sin parametros tipo 3 */
                    QString id=tipoLlamada.valor;
                    QString simbolo=tipoLlamada.hijos.at(0).valor;

                    QString valor=id+";"+simbolo;
                    VerificarFuncion(valor,nullptr,clas,3);


                    Simbolos objeto=clas->BuscarVariable(id,clas);

                    if(QString::compare(objeto.getId(),"")!=0){

                        Simbolos sem=objeto.simbolosClase.value(simbolo);
                        if(sem.poseRetorno==true){

                            if(sem.tipo_==48){
                                op.objec=sem;
                                op.tipo=48;
                            }else if(sem.tipo_==50){
                                op.array=*sem.nuevoAr;
                                op.tipo=50;
                            }else{
                                op.valor=sem.retorno;
                                op.tipo=sem.tipo_;
                            }
                        }
                    }

                }break;

                case Externa_Var:{
                     QString id=tipoLlamada.valor;
                     QString simbolo=tipoLlamada.hijos.at(0).valor;

                     Simbolos objeto=clas->BuscarVariable(id,clas);

                     if(QString::compare(objeto.getId(),"")!=0){

                         Simbolos sem=objeto.simbolosClase.value(simbolo);


                             if(QString::compare(sem.getTipo_Dato(),"clase")==0){
                                 op.objec=sem;
                                 op.tipo=48;
                             }else if(QString::compare(sem.getTipo_Dato(),"objeto")==0){
                                 op.array=*sem.nuevoAr;
                                 op.tipo=50;
                             }else{
                                 op.valor=sem.getValor();
                                 op.tipo=sem.tipo_;
                             }

                     }

                }break;

                case Externa_Ar:{
                    QString id=tipoLlamada.valor;

                    NodoAST izq=tipoLlamada.hijos.at(0);

                    Simbolos aux=clas->BuscarVariable(id,clas);

                    QString ide;
                    switch (izq.tipo_) {

                    case DIMENSION1:{
                        NodoAST ast1=izq.hijos.at(0);
                        Operacion op1=Asignacion(&ast1,clas);

                        ide=izq.hijos.at(1).valor;
                        Simbolos arr=aux.simbolosClase.value(ide);
                        if(QString::compare(arr.getId(),"")!=0){

                            Objeto obe=arr.nuevoAr->getDato1(op1.valor.toInt());
                            op.valor=obe.dato;
                            op.tipo=obe.tipo_;

                        }else{
                            Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                            semanticos.append(*er);
                        }

                    }break;
                    case DIMENSION2:{
                        NodoAST ast1=izq.hijos.at(0);
                        Operacion op1=Asignacion(&ast1,clas);
                        NodoAST ast2=izq.hijos.at(1);
                        Operacion op2=Asignacion(&ast2,clas);

                        ide=izq.hijos.at(2).valor;

                        Simbolos arr=aux.simbolosClase.value(ide);
                        if(QString::compare(arr.getId(),"")!=0){

                            Objeto obe=arr.nuevoAr->getDato2(op1.valor.toInt(),op2.valor.toInt());
                            op.valor=obe.dato;
                            op.tipo=obe.tipo_;


                        }else{
                            Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                            semanticos.append(*er);
                        }

                    }break;
                    case DIMENSION3:{
                        NodoAST ast1=izq.hijos.at(0);
                        Operacion op1=Asignacion(&ast1,clas);
                        NodoAST ast2=izq.hijos.at(1);
                        Operacion op2=Asignacion(&ast2,clas);
                        NodoAST ast3=izq.hijos.at(2);
                        Operacion op3=Asignacion(&ast3,clas);

                        ide=izq.hijos.at(3).valor;
                        Simbolos arr=aux.simbolosClase.value(ide);

                        if(QString::compare(arr.getId(),"")!=0){

                            Objeto obe=arr.nuevoAr->getDato3(op1.valor.toInt(),op2.valor.toInt(),op3.valor.toInt());
                            op.valor=obe.dato;
                            op.tipo=obe.tipo_;

                        }else{
                            Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                            semanticos.append(*er);
                        }

                    }break;

                    }



                }break;


            }


        }
        break;
        case POR_ARREGLO:
        {
        /*------------------- ARREGLO LOCAl----------------------*/
            NodoAST izq=raiz->hijos.at(0);

            QString ide;

            switch (izq.tipo_) {

            case DIMENSION1:{
                NodoAST ast1=izq.hijos.at(0);
                Operacion op1=Asignacion(&ast1,clas);

                ide=izq.hijos.at(1).valor;
                if(clas->ExisteSimbolo(ide,clas)){
                    Simbolos auxS=clas->BuscarVariable(ide,clas);
                    Objeto obe=auxS.nuevoAr->getDato1(op1.valor.toInt());
                    op.valor=obe.dato;
                    op.tipo=obe.tipo_;

                }else{
                    Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                    semanticos.append(*er);
                }

            }break;
            case DIMENSION2:{
                NodoAST ast1=izq.hijos.at(0);
                Operacion op1=Asignacion(&ast1,clas);
                NodoAST ast2=izq.hijos.at(1);
                Operacion op2=Asignacion(&ast2,clas);
                ide=izq.hijos.at(2).valor;

                if(clas->ExisteSimbolo(ide,clas)){
                    Simbolos auxS=clas->BuscarVariable(ide,clas);
                    Objeto obe=auxS.nuevoAr->getDato2(op1.valor.toInt(),op2.valor.toInt());
                    op.valor=obe.dato;
                    op.tipo=obe.tipo_;


                }else{
                    Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                    semanticos.append(*er);
                }

            }break;
            case DIMENSION3:{
                NodoAST ast1=izq.hijos.at(0);
                Operacion op1=Asignacion(&ast1,clas);
                NodoAST ast2=izq.hijos.at(1);
                Operacion op2=Asignacion(&ast2,clas);
                NodoAST ast3=izq.hijos.at(2);
                Operacion op3=Asignacion(&ast3,clas);

                ide=izq.hijos.at(3).valor;

                if(clas->ExisteSimbolo(ide,clas)){
                    Simbolos auxS=clas->BuscarVariable(ide,clas);
                    Objeto obe=auxS.nuevoAr->getDato3(op1.valor.toInt(),op2.valor.toInt(),op3.valor.toInt());
                    op.valor=obe.dato;
                    op.tipo=obe.tipo_;

                }else{
                    Errores *er =new Errores(ide,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                    semanticos.append(*er);
                }

            }break;

            }



        }
        break;

        case Id:{
            QString id=raiz->valor;
            if(clas->ExisteSimbolo(id,clas)){
                Simbolos auxS=clas->BuscarVariable(id,clas);

                if(QString::compare(auxS.getTipo_Dato(),"variable")==0){
                    op.tipo=auxS.tipo_;
                    op.valor=auxS.getValor();
                }else if(QString::compare(auxS.getTipo_Dato(),"clase")==0){
                    op.objec=auxS;
                    op.tipo=auxS.tipo_;
                }else if(QString::compare(auxS.getTipo_Dato(),"arreglo")==0){
                    op.array=*auxS.nuevoAr;
                    op.tipo=auxS.tipo_;
                }



            }else{
                Errores *er =new Errores(id,"semantico","La variable aun no ha sido declarada",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }


        }break;


        case negativo:{
            NodoAST izq=raiz->hijos.at(0);
            Operacion op1=Asignacion(&izq,clas);
            switch (op1.tipo) {
                case numero:{
                    op.tipo=numero;
                    op.valor="-"+op1.valor;
                }break;
                case decimal:{
                    op.tipo=decimal;
                    op.valor="-"+op1.valor;
                }break;
                default:{
                    Errores *er=new Errores("Negativo","semantico","Solo se permite numeros y decimales negativos",izq.linea,raiz->columna);
                    semanticos.append(*er);
                }break;

            }

        }break;
        case suma:/*-------------------------SUMA ---------------------------------*/
        {
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha

            switch (op1.tipo) {
                case numero:{
                    switch (op2.tipo) {
                        case numero:{
                            op.tipo=numero;
                            int resultado=op1.valor.toInt()+op2.valor.toInt();
                            op.valor=QString::number(resultado);
                            break;
                        }
                        case str:{
                            op.tipo=str;
                            op.valor=op1.valor+op2.valor;
                            break;
                        }
                        case decimal:{
                                op.tipo=decimal;
                                double result=op1.valor.toDouble()+op2.valor.toDouble();
                                op.valor=QString::number(result);
                            break;

                        }
                        case cha:{
                             op.tipo=numero;
                             std::string as=op2.valor.toStdString();
                             char c=as[0];
                             int ass=c;
                             int result=op1.valor.toInt()+ass;
                             op.valor=QString::number(result);
                             break;
                        }
                        case verdadero:{
                            op.tipo=numero;
                            int result=op1.valor.toInt()+1;
                            op.valor=QString::number(result);
                            break;
                        }
                        case falso:{
                            op.tipo=numero;
                            int result =op1.valor.toInt()+0;
                            op.valor=QString::number(result);
                            break;
                    }default:{
                        Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;

                        break;
                    }

                    }
                    break;
                }
                case str:{
                    switch (op2.tipo) {
                        case numero:{
                            op.tipo=str;
                            op.valor=op1.valor+op2.valor;
                            break;
                        }
                        case str:{
                            op.tipo=str;
                            op.valor=op1.valor+op2.valor;
                            break;
                        }
                        case decimal:{
                                op.tipo=str;
                                op.valor=op1.valor+op2.valor;
                            break;

                        }
                        case cha:{
                             op.tipo=str;
                             op.valor=op1.valor+op2.valor;

                             break;
                        }
                        default:{
                        Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }

                }
                    break;

                }case decimal:{
                    switch (op2.tipo) {
                        case numero:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()+op2.valor.toDouble();
                            op.valor=QString::number(result);
                            break;
                        }
                        case str:{
                            op.tipo=str;
                            op.valor=op1.valor+op2.valor;
                            break;
                        }
                        case decimal:{
                                op.tipo=decimal;
                                double result=op1.valor.toDouble()+op2.valor.toDouble();
                                op.valor=QString::number(result);
                            break;

                        }
                        case cha:{
                             op.tipo=decimal;
                             std::string as=op2.valor.toStdString();
                             char c=as[0];
                             int ass=c;
                             double result=  op1.valor.toDouble()+ass;
                             op.valor=QString::number(result);
                             break;
                        }
                        case verdadero:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()+1;
                            op.valor=QString::number(result);
                            break;
                        }
                        case falso:{
                            op.tipo=decimal;
                            double result =op1.valor.toDouble()+0;
                            op.valor=QString::number(result);
                            break;
                    }default:{
                        Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }

                    }
                    break;
                }case cha:{
                    switch (op2.tipo) {
                        case numero:{
                            op.tipo=numero;
                            std::string as=op1.valor.toStdString();
                            char c=as[0];
                            int ass=c;
                            int result=ass+op2.valor.toInt();
                            op.valor=QString::number(result);
                            break;
                        }
                        case str:{
                            op.tipo=str;
                            op.valor=op1.valor+op2.valor;
                            break;
                        }
                        case decimal:{
                                op.tipo=decimal;

                                std::string as=op1.valor.toStdString();
                                char c=as[0];
                                int ass=c;
                                double result=ass +op2.valor.toDouble();
                                op.valor=QString::number(result);

                            break;

                        }
                        case cha:{
                             op.tipo=numero;
                             std::string as1=op1.valor.toStdString();
                             char c1=as1[0];
                             int ass1=c1;

                             std::string as2=op2.valor.toStdString();
                             char c2=as2[0];
                             int ass2=c2;
                             int result=ass1+ass2;
                             op.valor=QString::number(result);

                             break;
                        }
                        case verdadero:{
                            op.tipo=numero;
                            std::string as1=op1.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;

                            int result=ass1+1;
                            op.valor=QString::number(result);
                            break;
                        }
                        case falso:{
                            op.tipo=numero;
                            std::string as1=op1.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            int result =ass1+0;
                            op.valor=QString::number(result);
                            break;
                    }default:{
                        Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }

                    }

                }break;
                case verdadero:{
                    switch (op2.tipo) {
                        case numero:{
                            op.tipo=numero;
                            int result=1+op2.valor.toInt();
                            op.valor=QString::number(result);
                            break;
                        }
                        case decimal:{
                            op.tipo=decimal;
                            double result=1+op2.valor.toDouble();
                            op.valor=QString::number(result);
                            break;
                        }
                        case cha:{
                                op.tipo=numero;
                                std::string as1=op2.valor.toStdString();
                                char c1=as1[0];
                                int ass1=c1;
                                int result=1+ass1;
                                op.valor=QString::number(result);
                            break;

                        }
                        case verdadero:{
                             op.tipo=numero;
                             int result =1+1;
                             op.valor=QString::number(result);

                             break;
                        }
                        case falso:{
                             op.tipo=str;
                             int result =1+0;
                             op.valor=QString::number(result);

                             break;
                        }
                        default:{
                        Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }

                }

                }break;

            case falso:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int result=0+op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                        op.tipo=decimal;
                        double result=0+op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }
                    case cha:{
                            op.tipo=numero;
                            std::string as1=op2.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            int result=0+ass1;
                            op.valor=QString::number(result);
                        break;

                    }
                    case verdadero:{
                         op.tipo=numero;
                         int result =0+1;
                         op.valor=QString::number(result);

                         break;
                    }
                    case falso:{
                         op.tipo=str;
                         int result =0+0;
                         op.valor=QString::number(result);

                         break;
                    }
                    default:{
                    Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

            }

            }break;
            default:{
                Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op1.linea,op1.columna);
                semanticos.append(*er);
                op.tipo=ERROR;
                break;
            }

            }


        }
        break;
        case resta:{/*--------------------------------RESTA-----------------------------------*/
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha

            switch (op1.tipo) {
            case numero: {
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int resultado=op1.valor.toInt()-op2.valor.toInt();
                        op.valor=QString::number(resultado);
                        break;
                    }

                    case decimal:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()-op2.valor.toDouble();
                            op.valor=QString::number(result);
                        break;

                    }
                    case cha:{
                         op.tipo=numero;
                         std::string as=op2.valor.toStdString();
                         char c=as[0];
                         int ass=c;
                         int result=op1.valor.toInt()-ass;
                         op.valor=QString::number(result);
                         break;
                    }
                    case verdadero:{
                        op.tipo=numero;
                        int result=op1.valor.toInt()-1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        op.tipo=numero;
                        int result =op1.valor.toInt()-0;
                        op.valor=QString::number(result);
                        break;
                }default:{
                    Errores *er=new Errores("resta","Semantico","No se puede hacer la resta de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

                }

            }break;

            case str:{
                switch (op2.tipo) {

                    default:{
                    Errores *er=new Errores("resta","Semantico","No se puede hacer la resta de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

            }


            }break;

            case decimal:{//---------- RESTA DE UNA DECIMAL CON OTRO TIPO

                switch (op2.tipo) {
                    case numero:{
                        op.tipo=decimal;
                        double result=op1.valor.toDouble()-op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }

                    case decimal:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()-op2.valor.toDouble();
                            op.valor=QString::number(result);
                        break;

                    }
                    case cha:{
                         op.tipo=decimal;
                         std::string as=op2.valor.toStdString();
                         char c=as[0];
                         int ass=c;
                         double result=op1.valor.toDouble()-ass;
                         op.valor=QString::number(result);
                         break;
                    }
                    case verdadero:{
                        op.tipo=decimal;
                        double result=op1.valor.toDouble()-1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        op.tipo=decimal;
                        double result =op1.valor.toDouble()-0;
                        op.valor=QString::number(result);
                        break;
                }default:{
                    Errores *er=new Errores("Suma","Semantico","No se puede hacer la suma de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

                }


            }break;
            case cha:{//---------------RESTA DE UN CHAR CON UN TIPO
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        std::string as=op1.valor.toStdString();
                        char c=as[0];
                        int ass=c;
                        int result=ass-op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                            op.tipo=decimal;

                            std::string as=op1.valor.toStdString();
                            char c=as[0];
                            int ass=c;
                            double result=ass-op2.valor.toDouble();
                            op.valor=QString::number(result);

                        break;

                    }
                    case cha:{
                         op.tipo=numero;
                         std::string as1=op1.valor.toStdString();
                         char c1=as1[0];
                         int ass1=c1;

                         std::string as2=op2.valor.toStdString();
                         char c2=as2[0];
                         int ass2=c2;
                         int result=ass1-ass2;
                         op.valor=QString::number(result);

                         break;
                    }

                    default:{
                    Errores *er=new Errores("Resta","Semantico","No se puede hacer la resta de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }

                }

            }break;
            case verdadero:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int result=1-op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                        op.tipo=decimal;
                        double result=1-op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }

                    default:{
                    Errores *er=new Errores("resta","Semantico","No se puede hacer la resta de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }

            }
            }break;

            case falso:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int result=0-op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                        op.tipo=decimal;
                        double result=0-op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }

                    default:{
                    Errores *er=new Errores("resta","Semantico","No se puede hacer la resta de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }

            }
            }break;
            default:{
                Errores *er=new Errores("resta","Semantico","No se puede hacer la resta de este tipo",op1.linea,op1.columna);
                semanticos.append(*er);
                op.tipo=ERROR;

            }break;


            }
        }
        break;


        case multiplicacion:{/*---------------------MULTIPLICACION DE TIPOS DE DATOS-------------*/
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {
            case numero:{//----------------------CUANDO VIENE UN NUMERO----------------------------
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int resultado=op1.valor.toInt()*op2.valor.toInt();
                        op.valor=QString::number(resultado);
                        break;
                    }

                    case decimal:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()*op2.valor.toDouble();
                            op.valor=QString::number(result);
                        break;

                    }
                    case cha:{
                         op.tipo=numero;
                         std::string as=op2.valor.toStdString();
                         char c=as[0];
                         int ass=c;
                         int result=op1.valor.toInt()*ass;
                         op.valor=QString::number(result);
                         break;
                    }
                    case verdadero:{
                        op.tipo=numero;
                        int result=op1.valor.toInt()*1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        op.tipo=numero;
                        int result =op1.valor.toInt()*0;
                        op.valor=QString::number(result);
                        break;
                }default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

                }
            }break;
            case str:{//-------------cadena multiplicada con cuqluer tipo
                switch (op2.tipo) {

                    default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }
                }

            }break;
            case decimal:{//-------------decimal multiplicada con cualquier tipo
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=decimal;
                        double result=op1.valor.toDouble()*op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }

                    case decimal:{
                            op.tipo=decimal;
                            double result=op1.valor.toDouble()*op2.valor.toDouble();
                            op.valor=QString::number(result);
                        break;

                    }
                    case cha:{
                         op.tipo=decimal;
                         std::string as=op2.valor.toStdString();
                         char c=as[0];
                         int ass=c;
                         double result=op1.valor.toDouble()*ass;
                         op.valor=QString::number(result);
                         break;
                    }
                    case verdadero:{
                        op.tipo=decimal;
                        double result=op1.valor.toDouble()*1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        op.tipo=decimal;
                        double result =op1.valor.toDouble()*0;
                        op.valor=QString::number(result);
                        break;
                }default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

                }

            }break;
            case cha:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        std::string as=op1.valor.toStdString();
                        char c=as[0];
                        int ass=c;
                        int result=ass*op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                            op.tipo=decimal;

                            std::string as=op1.valor.toStdString();
                            char c=as[0];
                            int ass=c;
                            double result=ass*op2.valor.toDouble();
                            op.valor=QString::number(result);

                        break;

                    }
                    case cha:{
                         op.tipo=numero;
                         std::string as1=op1.valor.toStdString();
                         char c1=as1[0];
                         int ass1=c1;

                         std::string as2=op2.valor.toStdString();
                         char c2=as2[0];
                         int ass2=c2;
                         int result=ass1*ass2;
                         op.valor=QString::number(result);

                         break;
                    }
                    case verdadero:{
                        op.tipo=numero;
                        std::string as1=op1.valor.toStdString();
                        char c1=as1[0];
                        int ass1=c1;
                        int result=ass1*1;
                        op.valor=QString::number(result);

                    }break;
                    case falso:{
                        op.tipo=numero;
                        std::string as1=op1.valor.toStdString();
                        char c1=as1[0];
                        int ass1=c1;
                        int result=ass1*0;
                        op.valor=QString::number(result);

                    }break;

                    default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }

                }

            }break;
            case verdadero:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int result=1*op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                        op.tipo=decimal;
                        double result=1*op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }
                    case cha:{
                            op.tipo=numero;
                            std::string as1=op2.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            int result=1*ass1;
                            op.valor=QString::number(result);
                        break;

                    }
                    case verdadero:{
                         op.tipo=verdadero;

                         op.valor="verdadero";

                         break;
                    }
                    case falso:{
                         op.tipo=falso;

                         op.valor="falso";

                         break;
                    }
                    default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

            }

            }break;
            case falso:{
                switch (op2.tipo) {
                    case numero:{
                        op.tipo=numero;
                        int result=0*op2.valor.toInt();
                        op.valor=QString::number(result);
                        break;
                    }
                    case decimal:{
                        op.tipo=decimal;
                        double result=0*op2.valor.toDouble();
                        op.valor=QString::number(result);
                        break;
                    }
                    case cha:{
                            op.tipo=numero;
                            std::string as1=op2.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            int result=0*ass1;
                            op.valor=QString::number(result);
                        break;

                    }
                    case verdadero:{
                         op.tipo=falso;
                         //int result =0*1;
                         op.valor="falso";

                         break;
                    }
                    case falso:{
                         op.tipo=falso;
                         //int result =0*0;
                         op.valor="falso";

                         break;
                    }
                    default:{
                    Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

            }

            }break;
            default:{
                Errores *er=new Errores("multiplicacion","Semantico","No se puede hacer la multiplicacion de este tipo",op1.linea,op1.columna);
                semanticos.append(*er);
                op.tipo=ERROR;
            }break;

            }


        } break;

        case division: {/*-----------------------------DIVION DE NUMEROS--------------------------*/
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha

            switch (op1.tipo) {

            case numero:{
                switch (op2.tipo) {
                    case numero:{
                        int divisor=op1.valor.toInt();
                        int dividiendo=op2.valor.toInt();
                        if(dividiendo!=0){
                            op.tipo=decimal;
                            op.valor=QString::number(divisor/dividiendo);

                        }else{
                            Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                    }break;

                    case decimal:{
                        int divisor=op1.valor.toInt();
                        double dividiendo=op2.valor.toDouble();
                        if(dividiendo>0.0000){
                            op.tipo=decimal;
                            op.valor=QString::number(divisor/dividiendo);

                        }else{
                            Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }


                    }break;
                    case cha:{

                         std::string as=op2.valor.toStdString();
                         char c=as[0];

                         int divisor=op1.valor.toInt();
                         int dividiendo=c;
                         if(dividiendo>0.0000){
                             op.tipo=decimal;
                             op.valor=QString::number(divisor/dividiendo);

                         }else{
                             Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                             semanticos.append(*er);
                             op.tipo=ERROR;
                         }
                         break;
                    }
                    case verdadero:{
                        op.tipo=numero;
                        int result=op1.valor.toInt()/1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }default:{
                    Errores *er=new Errores("division","Semantico","No se puede hacer la division de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

                }

            }break;
            case decimal:{//---------DIVISION DE DECIMAL------------
                switch (op2.tipo) {
                    case numero:{
                        double divisor=op1.valor.toDouble();
                        int dividiendo=op2.valor.toInt();
                        if(dividiendo!=0){
                            op.tipo=decimal;
                            op.valor=QString::number(divisor/dividiendo);

                        }else{
                            Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                    }break;

                    case decimal:{
                        double divisor=op1.valor.toDouble();
                        double dividiendo=op2.valor.toDouble();
                        if(dividiendo>0.0000){
                            op.tipo=decimal;
                            op.valor=QString::number(divisor/dividiendo);

                        }else{
                            Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }

                        break;

                    }
                    case cha:{
                        std::string as=op2.valor.toStdString();
                        char c=as[0];

                        double divisor=op1.valor.toDouble();
                        int dividiendo=c;
                        if(dividiendo>0){
                            op.tipo=decimal;
                            op.valor=QString::number(divisor/dividiendo);

                        }else{
                            Errores *er=new Errores("Division","semantico","No se puede dividir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }

                         break;
                    }
                    case verdadero:{
                        op.tipo=decimal;
                        double result=op1.valor.toDouble()/1;
                        op.valor=QString::number(result);
                        break;
                    }
                    case falso:{
                        Errores *er=new Errores("division","semantico","no se puede dividiri entre 0",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                        break;
                    }default:{
                        Errores *er=new Errores("division","Semantico","No se puede hacer la division de este tipo",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    break;
                    }

                }
            } break;
            case cha:{
                switch (op2.tipo) {
                    case numero:{

                        std::string as=op1.valor.toStdString();
                        char c=as[0];
                        int ass=c;
                        int divisor=op2.valor.toInt();
                        if(divisor!=0){
                            op.tipo=decimal;
                            op.valor=QString::number(ass/divisor);
                        }else{
                            Errores *er=new Errores("division","semantico","no se puede diviri entre 0",op2.linea,op.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                        break;
                    }
                    case decimal:{
                            std::string as=op1.valor.toStdString();
                            char c=as[0];
                            int ass=c;
                            double divisor=op2.valor.toDouble();
                            if(divisor>0.0000){
                                op.tipo=decimal;
                                op.valor=QString::number(ass/divisor);
                            }else{
                                Errores *er=new Errores("division","semantico","no se puede diviri entre 0",op2.linea,op.columna);
                                semanticos.append(*er);
                                op.tipo=ERROR;
                            }

                        break;

                    }
                    case cha:{

                         std::string as1=op1.valor.toStdString();
                         char c1=as1[0];
                         int dividiendo=c1;

                         std::string as2=op2.valor.toStdString();
                         char c2=as2[0];
                         int divisor=c2;
                         if(divisor>0){
                             op.tipo=decimal;
                             op.valor=QString::number(dividiendo/divisor);
                         }else{
                             Errores *er=new Errores("division","semantico","no se puede diviri entre 0",op2.linea,op.columna);
                             semanticos.append(*er);
                             op.tipo=ERROR;
                         }


                         break;
                    }
                    case verdadero:{
                        op.tipo=numero;
                        std::string as1=op1.valor.toStdString();
                        char c1=as1[0];
                        int ass1=c1;
                        int result=ass1/1;
                        op.valor=QString::number(result);

                    }break;
                    case falso:{
                      Errores *er=new Errores("division","semantico","No se puede dividiri entre 0",op2.linea,op2.columna);
                      semanticos.append(*er);
                      op.tipo=ERROR;

                    }break;

                    default:{
                    Errores *er=new Errores("division","Semantico","No se puede hacer la multiplicacion de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                    }

                }




            }break;
            case verdadero:{
                switch (op2.tipo) {
                    case numero:{
                        if(op2.valor.toInt()>0){
                            op.tipo=decimal;
                            op.valor=QString::number(1/op2.valor.toInt());
                        }else{
                            Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }

                    } break;
                    case decimal:{
                        if(op2.valor.toDouble()>0.000){
                            op.tipo=decimal;
                            op.valor=QString::number(1/op2.valor.toInt());
                        }else{
                            Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                        break;
                    }
                    case cha:{
                            op.tipo=numero;
                            std::string as1=op2.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            if(ass1>0){
                                op.tipo=decimal;
                                op.valor=QString::number(1/ass1);
                            }else{
                                Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                                semanticos.append(*er);
                                op.tipo=ERROR;
                            }
                        break;

                    }

                    default:{
                    Errores *er=new Errores("divisoin","Semantico","No se puede hacer la division de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }

            }

            }break;
            case falso:{

                switch (op2.tipo) {
                    case numero:{
                        if(op2.valor.toInt()>0){
                            op.tipo=decimal;
                            op.valor=QString::number(0/op2.valor.toInt());
                        }else{
                            Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }

                    } break;
                    case decimal:{
                        if(op2.valor.toDouble()>0.000){
                            op.tipo=decimal;
                            op.valor=QString::number(0/op2.valor.toInt());
                        }else{
                            Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                        break;
                    }
                    case cha:{
                            op.tipo=numero;
                            std::string as1=op2.valor.toStdString();
                            char c1=as1[0];
                            int ass1=c1;
                            if(ass1>0){
                                op.tipo=decimal;
                                op.valor=QString::number(0/ass1);
                            }else{
                                Errores *er =new Errores("division","semantico","no se puede divirir entre 0",op2.linea,op2.columna);
                                semanticos.append(*er);
                                op.tipo=ERROR;
                            }
                        break;

                    }

                    default:{
                    Errores *er=new Errores("division","Semantico","No se puede hacer la division de este tipo",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                    break;
                }
            }

            }break;
            default:{
                Errores *er=new Errores("division","semantico","no se puede hacer a division de este tipo",op2.linea,op2.columna);
                semanticos.append(*er);
                op.tipo=ERROR;

            }break;

            }

        }
        break;
        case potencia:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {
                case numero:{
                    if(op2.tipo==numero){
                        op.tipo=numero;
                        op.valor=QString::number(pow(op1.valor.toInt(),op2.valor.toInt()));

                    }else if(op2.tipo==decimal){
                        op.tipo=decimal;
                        op.valor=QString::number(pow(op1.valor.toInt(),op2.valor.toDouble()));

                    }else if(op2.tipo==cha){
                        op.tipo=numero;
                        int caracter=ConverInt(op2.valor);
                        if(caracter>=0){
                            op.valor=QString::number(pow(op1.valor.toInt(),caracter));
                        }else{
                            Errores *er=new Errores("pontencia","Semantico","no se puede hacer la conversion de char a int",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }

                    }else if(op2.tipo==verdadero){
                        op.tipo=numero;
                        op.valor=QString::number(pow(op1.valor.toInt(),1));
                    }else if(op2.tipo==falso){
                        op.tipo=numero;
                        op.valor=QString::number(pow(op1.valor.toInt(),0));
                    }else{
                        Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    }
                }break;
            case str:{
                Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                semanticos.append(*er);
                op.tipo=ERROR;

            }break;
            case decimal:{
                if(op2.tipo==numero){
                    op.tipo=decimal;
                    op.valor=QString::number(pow(op1.valor.toDouble(),op2.valor.toDouble()));

                }else if(op2.tipo==decimal){
                    op.tipo=decimal;
                    op.valor=QString::number(pow(op1.valor.toDouble(),op2.valor.toDouble()));
                }else if(op2.tipo==cha){
                    int ca=ConverInt(op2.valor);
                    if(ca>=0){
                        op.tipo=decimal;
                        op.valor=QString::number(pow(op1.valor.toDouble(),ca));

                    }else{
                        Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    }
                }else if(op2.tipo==verdadero){
                    op.tipo=numero;
                    op.valor=QString::number(pow(op1.valor.toDouble(),1));
                }else if(op2.tipo==false){
                    op.tipo=numero;
                    op.valor=QString::number(pow(op1.valor.toDouble(),0));
                }else{
                    Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                }

            }break;
            case cha:{
                int ca=ConverInt(op1.valor);
                if(ca>=0){
                    if(op2.tipo==numero){
                        op.tipo=numero;
                        op.valor=QString::number(pow(ca,op2.valor.toInt()));

                    }else if(op2.tipo==decimal){
                        op.tipo=decimal;
                        op.valor=QString::number(pow(ca,op2.valor.toDouble()));

                    }else if(op2.tipo==cha){
                        int c=ConverInt(op2.valor);
                        if(c>=0){
                            op.tipo=numero;
                            op.valor=QString::number(pow(ca,c));
                        }else{
                            Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                            semanticos.append(*er);
                            op.tipo=ERROR;
                        }
                    }else if(op2.tipo==verdadero){
                        op.tipo=entero;
                        op.valor=QString::number(pow(ca,1));
                    }else if(op2.tipo==falso){
                        op.tipo=entero;
                        op.valor=QString::number(pow(ca,0));
                    }else {
                        Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    }
                }else{
                    Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op1.linea,op1.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                }


            }break;
            case verdadero:{
                if(op2.tipo==numero){
                    op.tipo=numero;
                    op.valor=QString::number(pow(1,op2.valor.toInt()));

                }else if(op2.tipo==decimal){
                    op.tipo=decimal;
                    op.valor=QString::number(pow(1,op2.valor.toDouble()));

                }else if(op2.tipo==cha){
                    int ca=ConverInt(op2.valor);
                    if(ca>=0){
                        op.tipo=entero;
                        op.valor=QString::number(pow(1,ca));
                    }else{
                        Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    }
                }else if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                }

            }break;
            case falso:{
                if(op2.tipo==numero){
                    op.tipo=numero;
                    op.valor=QString::number(pow(0,op2.valor.toInt()));

                }else if(op2.tipo==decimal){
                    op.tipo=decimal;
                    op.valor=QString::number(pow(0,op2.valor.toDouble()));

                }else if(op2.tipo==cha){
                    int ca=ConverInt(op2.valor);
                    if(ca>=0){
                        op.tipo=entero;
                        op.valor=QString::number(pow(0,ca));
                    }else{
                        Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia",op2.linea,op2.columna);
                        semanticos.append(*er);
                        op.tipo=ERROR;
                    }
                }else if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else{
                    Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia 0^0",op2.linea,op2.columna);
                    semanticos.append(*er);
                    op.tipo=ERROR;
                }

            }break;
            default:{
                Errores *er=new Errores("pontencia","Semantico","no se puede hacer la operacion potencia 0^0",op2.linea,op2.columna);
                semanticos.append(*er);
                op.tipo=ERROR;
            }break;

            }

        }break;
        case comparar:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {
            case numero:{
                if(op2.tipo==numero){
                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }

                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                  op.tipo=falso;
                  op.valor="falso";
                }

            }break;
            case str:{
                if(op2.tipo==str){
                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";

                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case decimal:{
                if(op2.tipo==decimal){
                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case cha:{
                if(op2.tipo==cha){
                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case verdadero:{
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case falso:{
                if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
                else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            default:{
                op.tipo=ERROR;
                Errores *er=new Errores("error","semantico","el tipo no es valido",op1.linea,op1.columna);
                semanticos.append(*er);
                break;
            }

            }

        }break;
        case diferencia:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {

            case numero:{
                if(op2.tipo==numero){

                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=falso;
                        op.valor="falso";
                    }else{
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }



                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }break;
            case str:{
                if(op2.tipo==str){

                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=falso;
                        op.valor="falso";
                    }else{
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }



                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }break;
            case decimal:{

                if(op2.tipo==decimal){

                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=falso;
                        op.valor="falso";
                    }else{
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }

                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }break;
            case cha:{
                if(op2.tipo==cha){

                    if(Comparar(op1.valor,op2.valor)){
                        op.tipo=falso;
                        op.valor="falso";
                    }else{
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }



                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }break;
            case verdadero:{

                if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }
            }break;
            case falso:{
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("error","semantico","el tipo no es valido",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }
            }break;
            default:{
                Errores *er=new Errores("error","semantico","el tipo no es valido",op1.linea,op1.columna);
                semanticos.append(*er);
                op.tipo=ERROR;
                break;
            }

            }
        }break;
        case menorQ:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {

            case numero:{
                if(op2.tipo==numero){
                    if(MenorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(MenorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case str:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case decimal:{
                if(op2.tipo==numero){
                    if(MenorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(MenorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case cha:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            default:{
                op.tipo=ERROR;
                Errores *er=new Errores("MenorQue","semantico","no se pudo hacer la comparacion de tipos",op1.linea,op1.columna);
                semanticos.append(*er);
            }break;

            }

        }break;
        case menorIgual:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            switch (op1.tipo) {
                case numero:{
                if(op2.tipo==numero){
                    if(menorIgualE(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(menorIgualE(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

                }break;
                case decimal:{
                if(op2.tipo==numero){
                    if(menorIgualE(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(menorIgualE(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

                }break;
                case str:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)<=0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)<=0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

                }break;
                case cha:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)<=0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)<=0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

                }break;
                default:{
                    op.tipo=ERROR;
                    Errores *er=new Errores("MenorIgual","semantico","no se pudo hacer la comparacion de tipos",op1.linea,op1.columna);
                    semanticos.append(*er);
                    break;
                }
            }

        }break;
        case mayorQ:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha

            switch (op1.tipo) {

            case numero:{
                if(op2.tipo==numero){
                    if(MayorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(MayorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MayorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case str:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)>0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)>0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MayorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case decimal:{
                if(op2.tipo==numero){
                    if(MayorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==decimal){
                    if(MayorQEntero(op1.valor,op2.valor)){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MayorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);

                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            case cha:{
                if(op2.tipo==str){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==cha){
                    if(MenorQCadena(op1.valor,op2.valor)<0){
                        op.tipo=verdadero;
                        op.valor="verdadero";
                    }else{
                        op.tipo=falso;
                        op.valor="falso";
                    }
                }else if(op2.tipo==ERROR){
                    op.tipo=ERROR;
                    Errores *er=new Errores("MayorQue","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                    semanticos.append(*er);
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }

            }break;
            default:{
                op.tipo=ERROR;
                Errores *er=new Errores("MayorQue","semantico","no se pudo hacer la comparacion de tipos",op1.linea,op1.columna);
                semanticos.append(*er);
            }break;


            }

        }break;
        case mayorIgual:{
        NodoAST izq=raiz->hijos.at(0);
        NodoAST der=raiz->hijos.at(1);
        Operacion op1=Asignacion(&izq,clas);//izquierda
        Operacion op2=Asignacion(&der,clas);//derecha
        switch (op1.tipo) {
            case numero:{
            if(op2.tipo==numero){
                if(MayorIgualE(op1.valor,op2.valor)){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==decimal){
                if(MayorIgualE(op1.valor,op2.valor)){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==ERROR){
                op.tipo=ERROR;
                Errores *er=new Errores("MayorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                semanticos.append(*er);

            }else{
                op.tipo=falso;
                op.valor="falso";
            }

            }break;
            case decimal:{
            if(op2.tipo==numero){
                if(MayorIgualE(op1.valor,op2.valor)){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==decimal){
                if(MayorIgualE(op1.valor,op2.valor)){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==ERROR){
                op.tipo=ERROR;
                Errores *er=new Errores("MayorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                semanticos.append(*er);

            }else{
                op.tipo=falso;
                op.valor="falso";
            }

            }break;
            case str:{
            if(op2.tipo==str){
                if(MenorQCadena(op1.valor,op2.valor)>=0){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==cha){
                if(MenorQCadena(op1.valor,op2.valor)>=0){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==ERROR){
                op.tipo=ERROR;
                Errores *er=new Errores("MayorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                semanticos.append(*er);
            }else{
                op.tipo=falso;
                op.valor="falso";
            }

            }break;
            case cha:{
            if(op2.tipo==str){
                if(MenorQCadena(op1.valor,op2.valor)>=0){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==cha){
                if(MenorQCadena(op1.valor,op2.valor)>=0){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=falso;
                    op.valor="falso";
                }
            }else if(op2.tipo==ERROR){
                op.tipo=ERROR;
                Errores *er=new Errores("MayorIgual","semantico","no se pudo hacer la comparacion de tipos",op2.linea,op2.columna);
                semanticos.append(*er);
            }else{
                op.tipo=falso;
                op.valor="falso";
            }

            }break;
            default:{
                op.tipo=ERROR;
                Errores *er=new Errores("MayorIgual","semantico","no se pudo hacer la comparacion de tipos",op1.linea,op1.columna);
                semanticos.append(*er);
                break;
            }
        }

        }break;
        case Or:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            if(op1.tipo==verdadero){
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("Or","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }

            }else if(op1.tipo==falso){
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=falso;
                    op.valor="falso";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("Or","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
            }else{
                op.tipo=ERROR;
                Errores *er=new Errores("Or","semantico","no se puede hacer la operacion Logica",op1.linea,op1.columna);
                semanticos.append(*er);
            }

        }break;
        case And:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            if(op1.tipo==verdadero){
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=falso;
                    op.valor="falso";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("ANd","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }

            }else if(op1.tipo==falso){
                if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==falso){
                    op.tipo=falso;
                    op.valor="falso";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("And","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
            }else{
                op.tipo=ERROR;
                Errores *er=new Errores("And","semantico","no se puede hacer la operacion Logica",op1.linea,op1.columna);
                semanticos.append(*er);
            }

        }break;
        case Nor:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            if(op1.tipo==verdadero){
                if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==falso){
                    op.tipo=falso;
                    op.valor="falso";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("NOr","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }

            }else if(op1.tipo==falso){
                if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("NOr","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
            }else{
                op.tipo=ERROR;
                Errores *er=new Errores("NOr","semantico","no se puede hacer la operacion Logica",op1.linea,op1.columna);
                semanticos.append(*er);
            }
        }break;
        case Nand:{
            NodoAST izq=raiz->hijos.at(0);
            NodoAST der=raiz->hijos.at(1);
            Operacion op1=Asignacion(&izq,clas);//izquierda
            Operacion op2=Asignacion(&der,clas);//derecha
            if(op1.tipo==verdadero){
                if(op2.tipo==verdadero){
                    op.tipo=falso;
                    op.valor="falso";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("NANd","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }

            }else if(op1.tipo==falso){
                if(op2.tipo==verdadero){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else if(op2.tipo==falso){
                    op.tipo=verdadero;
                    op.valor="verdadero";
                }else{
                    op.tipo=ERROR;
                    Errores *er=new Errores("NAnd","semantico","no se puede hacer la operacion Logica",op2.linea,op2.columna);
                    semanticos.append(*er);
                }
            }else{
                op.tipo=ERROR;
                Errores *er=new Errores("NAnd","semantico","no se puede hacer la operacion Logica",op1.linea,op1.columna);
                semanticos.append(*er);
            }

        }break;
        case Not:{
                  NodoAST izq=raiz->hijos.at(0);
                  Operacion op1=Asignacion(&izq,clas);//izquierda
                  if(op1.tipo==verdadero){
                      op.tipo=falso;
                      op.valor="falso";
                  }else if(op1.tipo==falso){
                      op.tipo=verdadero;
                      op.valor="verdadero";
                  }else{
                      op.tipo=ERROR;
                      Errores *er=new Errores("Not","semantico","no se puede hacer la operacion Logica",op1.linea,op1.columna);
                      semanticos.append(*er);
                  }

        }break;

    }

    return op;
}

/*---------------------------------METODO QUE HACE LA SEGUNDA PASADA DEL COMPILADOR-----------------------------*/
Entorno * PrimerRecorrido::EncontrarPrincipal(){
    QHash<QString, Entorno>::iterator i;

    for ( (i = clases.begin()); i != clases.end(); ++i){
            NodoAST *aux=i.value().principal;
            if(aux!=nullptr){
                //Entorno en=i.value();
                return &i.value();
            }
    }

    return nullptr;
}

Entorno* PrimerRecorrido::EncontrarClase(QString id){
    QHash<QString, Entorno>::iterator i;

    for ( (i = clases.begin()); i != clases.end(); ++i){
        if(QString::compare(id,i.key())==0){
            return &i.value();

        }
    }
    return nullptr;

}

void PrimerRecorrido::SegundaPasada(){
    Entorno *salida=new Entorno();
    salida=EncontrarPrincipal();
   if(salida!=nullptr){
        NodoAST *raiz=salida->principal;
        Entorno *nuevo=new Entorno(salida,"principal");
        nuevo->id_Entorno="principal";
        nuevo->tipo_entorno="principal";
        //CopiarDatos(nuevo,nuevo->anterior);
        SegundaPasada(raiz,nuevo);
        CreandoTabla(nuevo->anterior);

    }else{
        Errores *er=new Errores("Principal","Semantico","No se encontro el metodo principal",0,0);
        semanticos.append(*er);
    }

}

/*void PrimerRecorrido::CopiarDatos(Entorno *&nuevo, Entorno *&anterior){
    nuevo->tablaSimbolos=anterior->tablaSimbolos;

}*/

Entorno * PrimerRecorrido::CrearNuevoEntorno(Entorno *actual,QString ti){
    Entorno *nuevo =new Entorno(actual,ti);
    //CopiarDatos(nuevo,actual);
    return nuevo;
}

/*------------------------------ METODO QUE GUARDA VARIABLE DENTRO DE METODO_FUNCION-------------------------*/
void PrimerRecorrido::GuardarVariable(NodoAST *raiz,Entorno *&entor,QString am){
    QList<QString> ids;
    QString tipo;
    int tipo_=0;
    Operacion op=Operacion();
    for (int a=0;a<raiz->hijos.size();a++) {
        switch (raiz->hijos.at(a).tipo_) {
        case DEC_ID:{
            NodoAST lista=raiz->hijos.at(a);//contiene
            ids=IDE(&lista);
        }break;
        case operacion:{
            NodoAST ope=raiz->hijos.at(a).hijos.at(0);
            op=Asignacion(&ope,entor);
        }break;
        case final:{
            //no asignar valor
        }break;
        default:{
            tipo=raiz->hijos.at(a).valor;
            tipo_=raiz->hijos.at(a).tipo_;
        }break;
        }
    }
    CASTEO(entor,ids,tipo_,"",op,am,false);

}

/*---------------- metodo que permite asignar valores directamente a otra variable
    Variable1= E
    objeto= E
    arreglo= E
*/
void PrimerRecorrido::VariableExistente(NodoAST *raiz, Entorno *&en,QString am){

    bool yapaso=false;
    QString ids;
    Operacion op=Operacion();
    for(int a=0;a<raiz->hijos.size();a++){
        switch (raiz->hijos.at(a).tipo_) {
        case Id:{
            if(yapaso==true){
                NodoAST ope=raiz->hijos.at(a);
                op=Asignacion(&ope,en);
            }else{
                ids=raiz->hijos.at(a).valor;
                yapaso=true;
            }

        }break;
        default:{
            NodoAST ope=raiz->hijos.at(a);
            op=Asignacion(&ope,en);

        }break;
        }
    }
/*
 * OPeracion puede traer, valor, arreglo o un objeto
*/

    /*-----------Mando a buscar la variable */
    Simbolos sim=en->BuscarVariable(ids,en);
    if(QString::compare(sim.getId(),"")==0){
        Errores *er=new Errores(ids,"semantico","La variable no existe ",raiz->linea,raiz->columna);
        semanticos.append(*er);
    }else{
        /*-----cuando el simbol es de tipo variable se asigno el valor como tal--------*/
        if(QString::compare(sim.getTipo_Dato(),"variable",Qt::CaseInsensitive)==0){
            QList<QString>id;
            id.append(ids);
            CASTEO(en,id,sim.tipoPrimitivo,"",op,am,true);
            /*---- cuando el simbolo es de tipo clase(objeto) se asigno los simbolos de lo que traigo */
        }else if(QString::compare(sim.getTipo_Dato(),"clase",Qt::CaseInsensitive)==0){ //clase
            if(QString::compare(sim.id_clase,op.objec.id_clase,Qt::CaseInsensitive)==0){
                sim.simbolosClase=op.objec.simbolosClase;
                sim.ClaseIniciada=true;
                en->SetearObjeto(sim,en);
            }
            /*------ cuando el simbolo es de tipo arreglo le asigno el arreglo del simbolo a la variable */
        }else if(QString::compare(sim.getTipo_Dato(),"arreglo",Qt::CaseInsensitive)==0){
            sim.nuevoAr->array=op.array.array;
            en->SeterArreglo(sim,en);

        }

    }
}

void PrimerRecorrido::SegundaPasada(NodoAST *raiz,Entorno *actual){
    //se crea el entorno principal


    for (int a=0;a<raiz->hijos.size();a++) {
        NodoAST aux=raiz->hijos.at(a);

        switch (aux.tipo_) {

        case VAR_GLOBALES:{//---------------  aca es cuando tengo se escribe una nueva variable
                NodoAST variable=aux.hijos.at(0);
                GuardarVariable(&variable,actual,"local"+actual->tipo_entorno);

        }break;

        case ASIGNAR_VAR:{//--------variable declarada previamente---------------- mando nodo operacion*/
               // NodoAST aux=raiz->hijos.at(a);
                NodoAST asi=aux.hijos.at(0);
                VariableExistente(&asi,actual,"local"+actual->tipo_entorno);

        }break;

        case OBJETO :
        {
                NodoAST obe=aux;

                ExtraerObjetos(&obe,actual,"local"+actual->tipo_entorno,1);


        }break;
        case NUEVO_OBJEC:{
                NodoAST ob=aux;
                DeclararOBJ(&ob,actual);

        }break;
        case ARREGLO:{
                NodoAST entra=aux;
                ExtraerArreglo(&entra,actual,1);

        }break;
        case REASIGNAR_ARREGLO:{
            NodoAST arra=aux;
            ReArreglo(&arra,actual);

        }break;

        case actualizar:{/*------------------------------- CUANDO SE TIENE ALGO COMO variable1++,variable--  -----------------*/
                NodoAST *ac=&(aux);
                ActuVar(ac,actual);

        }break;

        case START_SI:{/*-------------------------cuando viene una sentecia si------------------------------*/
                    NodoAST si=raiz->hijos.at(a);
                    SI(&si,actual,"Si");

        }break;

        case START_HACER:{/*---------- cuando viene un sentencia hacer(<condicion>){sentencias}*/
                    NodoAST hacer=raiz->hijos.at(a);
                    Hacer(&hacer,actual);

        }break;

        case START_MIENTRAS:{/*----------- SENTENCIA MIENTRAS mientras(<condicon>){ sentencias}*/
                    NodoAST mientras=raiz->hijos.at(a);
                    Mientras(&mientras,actual);

        }break;

        case START_REPETIR:{/*----------- SENTENCIA REPETIR, CIERTO NUMERO DE VECES */
                    NodoAST repetir=raiz->hijos.at(a);
                    Repetir(&repetir,actual);


        }break;

        case START_PARA:{/*------ sentencia para(<var>$ condicion$ actualizacion)*/
                NodoAST para=raiz->hijos.at(a);
                Para(&para,actual);

        }break;
        case START_COMPROBAR:{/*------ sentencia para(<var>$ condicion$ actualizacion)*/
               NodoAST value=aux.hijos.at(0);
               Operacion op=Asignacion(&value,actual);
               NodoAST cas=aux.hijos.at(1);
               Casos(&cas,actual,op);

        }break;

        case SENTENCIA_ARCHIVOS:{/*-------- captura cualquier sentecia para los archivos--------------*/
                NodoAST arch=raiz->hijos.at(a).hijos.at(0);
                SentenciaArch(&arch,actual);


        }break;
        case SENTENCIA_CUENTA:{/*-------- captura cualquier sentecia para los archivos--------------*/
                NodoAST cuen=raiz->hijos.at(a).hijos.at(0);//acaso saco de una vez
                SentenciaCuenta(&cuen,actual);


        }break;

        case LLAMADA_FUNCION:{/*-------- captura de las llamaadas funciones,variables y arreglos--------------*/
                NodoAST call=raiz->hijos.at(a).hijos.at(0);
                LlamarFunciones(&call,actual);



        }break;

        case imprimir:{
            NodoAST imprime=raiz->hijos.at(a).hijos.at(0);//obtengo el nodo de lo que quier imprimir
            Operacion op=Operacion();
            op=Asignacion(&imprime,actual);
            if(op.tipo!=-1 & op.tipo!=56){
                consola->appendPlainText(op.valor);
            }



        }break;

        case RETORNO:{// para metodos con retorno
                    NodoAST oper=aux.hijos.at(0);
                    setRetorno(&oper,actual);
                    this->termina=1;

        }break;

        case romper:{// ciclos
            this->rompe=1;

        }break;

        case continuar:{//ciclos

            this->continua=1;
        }break;



        }
        if(this->termina==1){
            break;
        }else if(this->rompe==1){
            break;
        }else if(this->continua==1){
            break;
        }
    }
    CreandoTabla(actual);


}

/*-------------------------METODO PARA MANEJAR LAS SENTENCIS DE CUENTA---------------*/

void PrimerRecorrido::SentenciaCuenta(NodoAST *raiz, Entorno *&en){

    int tipo_=raiz->tipo_;

    switch (tipo_) {
    case cuenta:{
        QString ide=raiz->valor;
        NodoAST arc=raiz->hijos.at(0);
        NodoAST exp=raiz->hijos.at(1);
        Operacion op1=Asignacion(&arc,en);
        Operacion op2=Asignacion(&exp,en);
        en->AgregarCuenta(ide,op1.valor,op2.valor);
    }break;
    case verCuenta:{


    }break;
    case depCuenta:{
        QString ide=raiz->valor;
        NodoAST ope=raiz->hijos.at(0);
        Operacion monto=Asignacion(&ope,en);

        Simbolos sem=en->BuscarVariable(ide,en);
        if(QString::compare(sem.getId(),"")!=0){
            sem.cuenta.Sumar(monto.valor);

            en->SetearCuenta(sem,en);
        }else{
            Errores *er=new Errores(ide,"semantico","variable de cuenta no existe",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }

    }break;

    case resCuenta:{
        QString ide=raiz->valor;
        NodoAST ope=raiz->hijos.at(0);
        Operacion monto=Asignacion(&ope,en);

        Simbolos sem=en->BuscarVariable(ide,en);
        if(QString::compare(sem.getId(),"")!=0){
            sem.cuenta.Restar(monto.valor);

            en->SetearCuenta(sem,en);
        }else{
            Errores *er=new Errores(ide,"semantico","variable de cuenta no existe",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }

    }break;
    case imprimirCuenta:{

    }break;

    case conCuenta:{

    }break;
    case transferir:{
            QString cuenta1=raiz->hijos.at(0).valor;
            QString cuenta2=raiz->hijos.at(1).valor;
            NodoAST operacion=raiz->hijos.at(2);

            Operacion op=Asignacion(&operacion,en);

            Simbolos c1=en->BuscarVariable(cuenta1,en);
            if(QString::compare(c1.getId(),"")!=0){
                Simbolos c2=en->BuscarVariable(cuenta2,en);
                if(QString::compare(c2.getId(),"")!=0){

                    if(c2.cuenta.dineroTotal>=op.valor.toInt()){

                        c2.cuenta.Restar(op.valor);
                        c1.cuenta.Sumar(op.valor);

                        en->SetearCuenta(c1,en);
                        en->SetearCuenta(c2,en);
                    }else{
                        //errror de cuenta
                    }

                }else{
                    Errores *er=new Errores(cuenta1,"semantico","variable de cuenta no existe",raiz->linea,raiz->columna);
                    semanticos.append(*er);
                }

            }else{
                Errores *er=new Errores(cuenta1,"semantico","variable de cuenta no existe",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }
    }break;
    }



}

/*------------------------ METODO PARA MANEJAR LA SENTECIA DE COMPROBAR---------------*/

void PrimerRecorrido::Casos(NodoAST *raiz, Entorno *&en,Operacion Value){

   bool Ejecutar=false;

    for(NodoAST ast: raiz->hijos){

        switch (ast.tipo_) {

        case caso:{
            NodoAST valor=ast.hijos.at(0);
            NodoAST sentencias=ast.hijos.at(1);

            Operacion op=Asignacion(&valor,en);
            if(Value.valor==op.valor){
                Ejecutar=true;
                SegundaPasada(&sentencias,en);
            }


        }break;
        case defecto:{
            NodoAST senten=ast.hijos.at(0);

            if(Ejecutar==false){
                SegundaPasada(&senten,en);
            }


        }break;

        }
        if(Ejecutar==true){
            break;
        }
    }



}


/*----------------------- METODO PARA VER LA ONDA DE LOS SI, SINO-SI Y SINO--------------------------*/

bool PrimerRecorrido::SI(NodoAST *raiz, Entorno *&en,QString a){
   bool cumplido=false;
    Operacion op=Operacion();
    for (int x=0;x<raiz->hijos.size();x++) {
            int tipo_=raiz->hijos.at(x).tipo_;

            switch (tipo_) {

            case LISTA_SI:{//cuando viene un si, sino-si,sino-si y al final puede o no venir el sino
                if(cumplido==false){
                    NodoAST ListSinoSi=raiz->hijos.at(x);//capturo lista SinoSI
                    SI(&ListSinoSi,en,"SinoSi");//mando la lista SinoSI
                }
            }break;
            case LISTA_GENERAL:{//lista de sentencias a ejecutar,aca valido la condicion anterior
                if(op.tipo==verdadero){//si da verdadero entro

                    NodoAST Lista=raiz->hijos.at(x);
                    Entorno *nuevo=new Entorno(en,a);
                    SegundaPasada(&Lista,nuevo);
                    cumplido=true;

                }else if(op.tipo==falso){//cuando la condicion no se cumple
                    cumplido=false;
                }else{//si da otro tipo de dato error semantico
                    Errores *er=new Errores("Si","Semantico","La condicion no es valida",raiz->hijos.at(x).linea,raiz->hijos.at(x).columna);
                    semanticos.append(*er);
                    cumplido=true;

                }

            }break;

            case sino:{//cuando viene un SI y SINO,
                if(cumplido==false){

                    NodoAST Lista=raiz->hijos.at(x).hijos.at(0);
                    Entorno *nuevo=new Entorno(en,"SiNO");
                    SegundaPasada(&Lista,nuevo);
                    cumplido=true;
                }


            }break;
            case SinoSi:{
                NodoAST SiNOsi=raiz->hijos.at(x);
                if(SI(&SiNOsi,en,"SinoSi")){//recibo el nodo de SinoSI, este va tener condicion y luego LISTA_GENERAL,Si recibo true es porque ya se cumplio
                    cumplido=true;
                }

            }break;

            case FIN_SI:{//cuando solo viene un si y nada mas

            }break;

            default:{//aca se optiene la condicion
                NodoAST ope=raiz->hijos.at(x);
                op=Asignacion(&ope,en);
            }

            }
            if(cumplido==true){
                break;
            }

    }
    if(cumplido==true){
        return true;
    }
    return false;

}


/*------------------METODO QUE HACER LA PARSE DE "HACER"-----------------------------------*/
void PrimerRecorrido::Hacer(NodoAST *raiz, Entorno *&en){
    //bool primera=false;
    QList<NodoAST> aux=raiz->hijos;
    Operacion op=Operacion();
    do{
        Entorno *nuevo=new Entorno();
        nuevo=CrearNuevoEntorno(en,"Hacer");


        for (int y=0;y<aux.size(); y++) {
            int tipo_=aux.at(y).tipo_;

            switch (tipo_) {
            case LISTA_GENERAL:{
                NodoAST list=aux.at(y);
                SegundaPasada(&list,nuevo);


            }break;
            default:{
                NodoAST ope=aux.at(y);
                op=Asignacion(&ope,nuevo);

            }
            }
            if(op.tipo==ERROR){
                Errores *er =new Errores("hacer","semantico","La condicion no es valida",aux.at(y).linea,aux.at(y).columna);
                semanticos.append(*er);
            }
        }
        if(this->rompe==1 && this->continua==-1){
            this->rompe=-1;
            break;
        }else if(this->continua==1 && this->rompe==-1){
            this->continua=-1;
        }

    }while (op.tipo==verdadero );

}


/*---------------------METODO PARA LA SENTENCIA MIENTRAS--------------*/

void PrimerRecorrido::Mientras(NodoAST *raiz, Entorno *&en){
    QList<NodoAST> hijos=raiz->hijos;

     Operacion op=Operacion();
    do{

    Entorno *nuevo=new Entorno();
    nuevo=CrearNuevoEntorno(en,"Mientras");

    for (int x=0;x<hijos.size();x++) {
        int tipo_=hijos.at(x).tipo_;

        switch (tipo_) {

        case LISTA_GENERAL:{
            if(op.tipo==verdadero){
                NodoAST listM=hijos.at(x);
                SegundaPasada(&listM,nuevo);


            }else if(op.tipo==ERROR){
                Errores *er =new Errores("Mientras","semantico","La condicion no es valida",hijos.at(x).linea,hijos.at(x).columna);
                semanticos.append(*er);
            }

        }break;
        default:{
            NodoAST oper=hijos.at(x);
            op=Asignacion(&oper,en);

        }break;
        }
    }
    if(this->rompe==1 && this->continua==-1){
        this->rompe=-1;
        break;
    }else if(this->continua==1 && this->rompe==-1){
        this->continua=-1;
    }

    }while(op.tipo==verdadero);

}


/*-------------------- METODO PARA LA SENTENCIA REPETIR-------------------*/

void PrimerRecorrido::Repetir(NodoAST *raiz, Entorno *&en){
    QList<NodoAST> hijos=raiz->hijos;

    NodoAST No=hijos.at(0);//numero de veces
    NodoAST LiGeneral=hijos.at(1);//lista de sentecias
    Operacion op=Operacion();
    op=Asignacion(&No,en);

    if(op.tipo==numero){

        int veces =0;
        while(veces<=op.valor.toInt()){
            Entorno *nuevo=new Entorno();
            nuevo=CrearNuevoEntorno(en,"Repetir");
            NodoAST entra=hijos.at(1);
            SegundaPasada(&entra,nuevo);
            if(this->rompe==1 && this->continua==-1){
                this->rompe=-1;
                break;
            }else if(this->continua==1 && this->rompe==-1){
                this->continua=-1;
            }
            veces++;
        }

    }else{
        Errores *er=new Errores("repetir","Semantico","Se esperaba un numero en la condicion",No.linea,No.columna);
        semanticos.append(*er);
    }


}


/*---------------------- METODO PARA LA SENTENCIA PARA---------------------*/


void PrimerRecorrido::Para(NodoAST *raiz, Entorno *&en){
    QList<NodoAST> lista=raiz->hijos;
    Simbolos sim=Simbolos();
    Entorno *nuevo=new Entorno(en,"para");
     //nuevo=CrearNuevoEntorno(en,"Para");

    for (int y=0;y<lista.size();y++) {
        int tipo_=lista.at(y).tipo_;

        switch (tipo_) {
        case VAR_GLOBALES:{
            NodoAST var=lista.at(y).hijos.at(0);
            GuardarVariable(&var,nuevo,"local"+nuevo->tipo_entorno);


        }break;

        case ASIGNAR_VAR:{
            NodoAST var=lista.at(y).hijos.at(0);
            VariableExistente(&var,nuevo,"local"+nuevo->tipo_entorno);

        }break;


        }
    }
    //verificar las veces
    NodoAST con=lista.at(1);
    Operacion op=Operacion();
    op=Asignacion(&con,nuevo);

    if(op.tipo==verdadero){
        do{


            NodoAST general=lista.at(3);
            SegundaPasada(&general,nuevo);
            //actualizar
            NodoAST actu=lista.at(2);
            sim=ActuVar(&actu,nuevo);



            Simbolos *nue=new Simbolos();
            nue->setId(sim.getId());
            nue->setTipo(sim.getTipo());
            nue->setValor(sim.getValor());
            nue->setRetonor(sim.getRetorno());
            nue->setTipo_Dato(sim.getTipo_Dato());
            nue->setVisibilidad(sim.getVisibilidad());
            nue->tipo_=sim.tipo_;
            nue->tipoPrimitivo=sim.tipoPrimitivo;

            nuevo->tablaSimbolos.clear();
            nuevo->addSimbolo(nue);

            op=Asignacion(&con,nuevo);
        }while(op.tipo==verdadero);
    }else if(op.tipo==ERROR){

    }

}
/*---------------------------- METODO PARA ACTUALIZAR------------------*/
Simbolos PrimerRecorrido::ActuVar(NodoAST *raiz, Entorno *&en){

    if(QString::compare(raiz->valor,"-")==0){
        QString id=raiz->hijos.at(0).valor;
        Simbolos sim=en->BuscarVariable(id,en);
        if(QString::compare(sim.getId(),"")==0){
            Errores *er=new Errores("Asigcion","semantico","La variable no existe ",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{
            QString valor=sim.getValor();
            int val=valor.toInt();
            val=val-1;
            Operacion op=Operacion();
            op.valor=QString::number(val);
            op.tipo=sim.tipo_;
            en->SetearValor(sim.getId(),op,sim.ambito,en);
            Simbolos sim=en->BuscarVariable(id,en);
            return sim;
        }
    }else{
        QString id=raiz->hijos.at(0).valor;
        Simbolos sim=en->BuscarVariable(id,en);
        if(QString::compare(sim.getId(),"")==0 && sim.tipo_!=56){
            Errores *er=new Errores("Asigcion","semantico","La variable no existe ",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{



            QString valor=sim.getValor();
            int val=valor.toInt();
            val=val+1;

            Operacion op=Operacion();
            op.valor=QString::number(val);
            op.tipo=sim.tipo_;
            en->SetearValor(sim.getId(),op,sim.ambito,en);
            Simbolos sim=en->BuscarVariable(id,en);
            return sim;
        }
    }

}


ArchivosDer * PrimerRecorrido::BuscarArchivo(QString id){
    for (int y=0;y<ListArch.size();y++) {
        if(QString::compare(id,ListArch.at(y)->id,Qt::CaseInsensitive)==0){
                return ListArch.at(y);
        }
    }
    return nullptr;

}
Operacion PrimerRecorrido::ExtraerAtributo(NodoAST *raiz, Entorno *&actual){
    Operacion op=Operacion();
    op=Asignacion(raiz,actual);
    return op;
}

/*------------------------------METODO PARA MANEJAR LOS ARCHIVOS-----------------------*/


void PrimerRecorrido::SentenciaArch(NodoAST *raiz, Entorno *&en){
    //recibo el nodo como tal

    int tipo_=raiz->tipo_;

    switch (tipo_) {
    case archivo:{
                QString id=raiz->valor;
                NodoAST hijo=raiz->hijos.at(0);
                Operacion op=ExtraerAtributo(&hijo,en);
                if(op.tipo!=-1 && op.tipo!=56){
                    ArchivosDer *nuevo=new ArchivosDer(op.valor,id);
                    ListArch.append(nuevo);
                }


    }break;

    case nuevo_conjunto: {
            QString id=raiz->valor;
            ArchivosDer *aux=BuscarArchivo(id);
            if(aux!=nullptr){
                NodoAST con=raiz->hijos.at(0);
                NodoAST si=raiz->hijos.at(1);
                Operacion opC=Asignacion(&con,en);Operacion opS=Asignacion(&si,en);
                if(opC.tipo!=56 && opC.tipo!=-1 && opS.tipo!=56 && opS.tipo!=-1){
                    aux->Add_Conjunto(opC.valor,opS.valor);
                }
            }

    }break;

    case nuevo_regex:{
        QString id=raiz->valor;
        ArchivosDer *aux=BuscarArchivo(id);
        if(aux!=nullptr){
            NodoAST con=raiz->hijos.at(0);
            NodoAST si=raiz->hijos.at(1);
            Operacion opC=Asignacion(&con,en);Operacion opS=Asignacion(&si,en);
            if(opC.tipo!=56 && opC.tipo!=-1 && opS.tipo!=56 && opS.tipo!=-1){
                aux->add_Expresion(opC.valor,opS.valor);
            }
        }

    }break;

    case nueva_entrada: {
        QString id=raiz->valor;
        ArchivosDer *aux=BuscarArchivo(id);
        if(aux!=nullptr){
            NodoAST con=raiz->hijos.at(0);
            NodoAST si=raiz->hijos.at(1);
            Operacion opC=Asignacion(&con,en);Operacion opS=Asignacion(&si,en);
            if(opC.tipo!=56 && opC.tipo!=-1 && opS.tipo!=56 && opS.tipo!=-1){
                aux->add_Entrada(opC.valor,opS.valor);
            }
        }

    }break;

    case guarda_arch:{
        QString id=raiz->valor;
        ArchivosDer *aux=BuscarArchivo(id);
        if(aux!=nullptr){
           aux->guardado=true;
        }

    }break;

    }



}



/*--------------------- METODO PARA LAS LLAMADAS DE FUNCIONES----------------------------*/

void PrimerRecorrido::LlamarFunciones(NodoAST *raiz, Entorno *&actual){

    switch (raiz->tipo_) {
        case Local_F_S:{
        /*FUNCION LOCAL SIN PARAMETROS*/
            QString id=raiz->valor;
            VerificarFuncion(id,nullptr,actual,1);

        }break;

        case Local_F_V:{
        /*FUNCION LOCAN CON PARAMETROS*/
            QString id =raiz->valor;
            NodoAST par=raiz->hijos.at(0);//nodo con los valores
            VerificarFuncion(id,&par,actual,0);

        }break;

        case Externa_F_V:{
            /*funcion externa co parametros tipo pueden traer parametro 2*/
            QString id=raiz->valor;
            QString simbolo=raiz->hijos.at(0).valor;

            NodoAST para=raiz->hijos.at(1);
            QString valor=id+";"+simbolo;
            VerificarFuncion(valor,&para,actual,2);

        }break;

        case Externa_F_S:{
            /*funcion externa sin parametros tipo 3 */
            QString id=raiz->valor;
            QString simbolo=raiz->hijos.at(0).valor;

            QString valor=id+";"+simbolo;
            VerificarFuncion(valor,nullptr,actual,3);
        }break;

        case Externa_Var:{
            /*llamada a funcion externa tipo 4*/
        }break;

        case Externa_Var_A:{
            /*llamada a variable externa que se le asigna algo*/
            setExternaVariable(raiz,actual);

        }break;
        case Externa_Ar:{
            /*llamada a arreglo sin asignacion */
        }break;
        case Externa_Ar_A:{

            setExterArray(raiz,actual);
        }break;

    }

}



void PrimerRecorrido::VerificarFuncion(QString id,NodoAST *raiz, Entorno *&actual, int tipo){


    if(tipo==0){// tipo =0 es una funcion con parametros
        Simbolos aux=actual->BuscarVariable(id,actual);
        if(QString::compare(aux.getId(),"",Qt::CaseInsensitive)==0){
            Errores *er =new Errores("LLamada_Funcion","Semantico","la funcion no ha sido declarada",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{
            Simbolos *funcion=new Simbolos();
            funcion=&aux;
             QList<Simbolos>salida=actual->getParametros(funcion);//obtengo los parametros

             Entorno *auxiliar=new  Entorno();

             if(actual->DentroFuncion(actual)){
                 auxiliar->anterior=actual;

             }else if(actual->tipo_entorno=="principal"){
                 auxiliar->anterior=actual;
             }
             else{
                 auxiliar->anterior=actual->RetornarUltimo(actual);
             }


             //mando a llamar una funcion para verficar los tipo de datos
             bool val=ExtraerParametros(raiz,auxiliar,salida);
             if(val==true){
                 auxiliar->id_Entorno=aux.getId()+";"+"0";
                 auxiliar->tipo_entorno="funcion";

                 /*nuevo entorno es el para una funcion no tiene que estar ligado al anterior*/

                    auxiliar->anterior=actual->RetornarUltimo(actual);
                    NodoAST au=aux.ListaGeneral;
                    //aca se manda a correr la funcion, con las variable iniciasda de entorno etc
                   SegundaPasada(&au,auxiliar);

                    /*-----------verificar el retorno-------- */
                   if(aux.poseRetorno==true){
                       if(opeGeneral.tipo==50){
                           aux.nuevoAr->array=opeGeneral.array.array;


                       }else if(opeGeneral.tipo==48){
                           aux.simbolosClase=opeGeneral.objec.simbolosClase;
                       }else{
                           aux.retorno=opeGeneral.valor;
                           aux.tipo_=opeGeneral.tipo;
                       }
                       actual->setearS(&aux,actual);
                       opeGeneral.tipo=-1;
                       this->termina=-1;

                   }
             }


        }

    }else if(tipo==1){//funcion sin parametros
        Simbolos aux=actual->BuscarVariable(id,actual);
        if(QString::compare(aux.getId(),"",Qt::CaseInsensitive)==0){
            Errores *er =new Errores("LLamada_Funcion","Semantico","la funcion no ha sido declarada",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }else{
            Entorno *nuevo=new Entorno();
            if(actual->DentroFuncion(actual)){
                nuevo->anterior=actual;
            }else if(actual->tipo_entorno=="principal"){
                nuevo->anterior=actual;
            }
            else{
                 nuevo->anterior=actual->RetornarUltimo(actual);
            }


            //nuevo=CrearNuevoEntorno(actual,aux.getId());
            nuevo->id_Entorno=aux.getId()+";"+"0";
            nuevo->tipo_entorno="funcion";

            nuevo->anterior=actual->RetornarUltimo(actual);

            //inicial la segunda pasada
            NodoAST au=aux.ListaGeneral;

            SegundaPasada(&au,nuevo);

            if(aux.poseRetorno==true){
                if(opeGeneral.tipo==50){
                    aux.nuevoAr->array=opeGeneral.array.array;


                }else if(opeGeneral.tipo==48){
                    aux.simbolosClase=opeGeneral.objec.simbolosClase;
                }else{
                    aux.retorno=opeGeneral.valor;
                    aux.tipo_=opeGeneral.tipo;
                }
                opeGeneral.tipo=-1;
                actual->setearS(&aux,actual);
                this->termina=-1;

            }



        }
    }else if(tipo==2){
        QStringList var=id.split(";");
        QString obje=var.at(0);
        QString func=var.at(1);

        Simbolos objeto=actual->BuscarVariable(obje,actual);

        if(QString::compare(objeto.getId(),"",Qt::CaseInsensitive)!=0){

            Simbolos funtion=objeto.simbolosClase.value(func);
            if(QString::compare(funtion.getId(),"",Qt::CaseInsensitive)==0){
                Errores *er =new Errores(func,"Semantico","la funcion no ha sido declarada",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }else{
                Simbolos *funcion=new Simbolos();
                funcion=&funtion;
                 QList<Simbolos>salida=actual->getParametros(funcion);//obtengo los parametros

                 Entorno *auxiliar=new  Entorno();

                 if(actual->DentroFuncion(actual)){
                     auxiliar->anterior=actual;

                 }else if(actual->tipo_entorno=="principal"){
                     auxiliar->anterior=actual;
                 }
                 else{
                     auxiliar->anterior=actual->RetornarUltimo(actual);
                 }


                 //mando a llamar una funcion para verficar los tipo de datos
                 bool val=ExtraerParametros(raiz,auxiliar,salida);
                 if(val==true){
                     auxiliar->id_Entorno=id+";"+"1";//lleva el id del entorno y id del afuncion
                     auxiliar->tipo_entorno="funcion";

                     /*nuevo entorno es el para una funcion no tiene que estar ligado al anterior*/
                        Entorno *cla=new Entorno();
                        cla->id_Entorno=objeto.id_clase;
                        cla->tablaSimbolos=objeto.simbolosClase;
                        auxiliar->anterior=cla;


                        NodoAST au=funtion.ListaGeneral;
                     //aca se manda a correr la funcion, con las variable iniciasda de entorno etc
                     SegundaPasada(&au,auxiliar);

                     if(funtion.poseRetorno==true){
                         if(opeGeneral.tipo==50){
                             funtion.nuevoAr->array=opeGeneral.array.array;
                         }else if(opeGeneral.tipo==48){
                             funtion.simbolosClase=opeGeneral.objec.simbolosClase;
                         }else{
                             funtion.retorno=opeGeneral.valor;
                             funtion.tipo_=opeGeneral.tipo;
                         }

                         objeto.simbolosClase.insert(funtion.getId(),funtion);
                         actual->SetearObjeto(objeto,actual);
                         opeGeneral.tipo=-1;
                         this->termina=-1;
                     }
                 }


            }
        }else{
            Errores *er =new Errores(obje,"Semantico","El Objeto No existe",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }

    }else if(tipo==3){
        QStringList var=id.split(";");
        QString obje=var.at(0);
        QString func=var.at(1);
        Simbolos objeto=actual->BuscarVariable(obje,actual);
        if(QString::compare(objeto.getId(),"",Qt::CaseInsensitive)!=0){

            Simbolos aux=objeto.simbolosClase.value(func);
            if(QString::compare(aux.getId(),"",Qt::CaseInsensitive)==0){
                Errores *er =new Errores(func,"Semantico","la funcion no ha sido declarada",raiz->linea,raiz->columna);
                semanticos.append(*er);
            }else{
                Entorno *nuevo=new Entorno();
                if(actual->DentroFuncion(actual)){
                    nuevo->anterior=actual;
                }else if(actual->tipo_entorno=="principal"){
                    nuevo->anterior=actual;
                }
                else{
                     nuevo->anterior=actual->RetornarUltimo(actual);
                }



                nuevo->id_Entorno=id+";"+"1";// mando el entorno con el objeto y la funcion
                nuevo->tipo_entorno="funcion";

                Entorno *cla=new Entorno();
                cla->id_Entorno=objeto.id_clase;
                cla->tablaSimbolos=objeto.simbolosClase;
                nuevo->anterior=cla;



                //inicial la segunda pasada
                NodoAST au=aux.ListaGeneral;

                SegundaPasada(&au,nuevo);

                if(aux.poseRetorno==true){
                    if(opeGeneral.tipo==50){
                        aux.nuevoAr->array=opeGeneral.array.array;
                    }else if(opeGeneral.tipo==48){
                        aux.simbolosClase=opeGeneral.objec.simbolosClase;
                    }else{
                        aux.retorno=opeGeneral.valor;
                        aux.tipo_=opeGeneral.tipo;
                    }

                    objeto.simbolosClase.insert(aux.getId(),aux);
                    actual->SetearObjeto(objeto,actual);
                    opeGeneral.tipo=-1;
                    this->termina=-1;
                }
        }

        }else{
            Errores *er =new Errores(obje,"Semantico","El objeto no existe",raiz->linea,raiz->columna);
            semanticos.append(*er);
        }

    }
}



bool PrimerRecorrido::ExtraerParametros(NodoAST *raiz,Entorno *ac, QList<Simbolos> entrada){

    QList<NodoAST > operaciones=raiz->hijos;
    QList<Operacion> ope;
    for(int x=0;x<operaciones.size();x++){

        Operacion op=Operacion();
        NodoAST aux=operaciones.at(x);
        op=Asignacion(&aux,ac);
        ope.append(op);
    }

    bool correcto=false;
    if(entrada.size()==ope.size()){
        for(int a=0;a<entrada.size();a++){
            if(entrada.at(a).tipo_==ope.at(a).tipo){


                correcto=true;
            }else if((entrada.at(a).tipo_==falso) && ope.at(a).tipo==verdadero ){

                correcto=true;
            }else if(entrada.at(a).tipo_==falso && ope.at(a).tipo==falso){

                correcto=true;
            }else {
                correcto=false;
            }
        }
    }else{
        Errores *er=new Errores("funcion","semantico","hacen falta parametros",raiz->linea,raiz->columna);
        semanticos.append(*er);
    }

    if(correcto==true){
        for(int a=0;a<entrada.size();a++){
            if(entrada.at(a).tipo_==48){
                Simbolos auxS=entrada.at(a);
                auxS.simbolosClase=ope.at(a).objec.simbolosClase;
                Simbolos *aux=new Simbolos(auxS.getId(),auxS.id_clase,"","clase");
                aux->setVisibilidad(auxS.getVisibilidad());
                aux->ClaseIniciada=auxS.ClaseIniciada;
                aux->addTipo_(48);
                aux->ambito=auxS.ambito;
                aux->simbolosClase=auxS.simbolosClase;
                ac->addSimbolo(aux);
            }else if(entrada.at(a).tipo_==50){
                Simbolos sem=entrada.at(a);
                sem.nuevoAr->array=ope.at(a).array.array;
                Simbolos *nuevo=new Simbolos(sem.getId(),sem.getValor(),sem.getTipo());
                nuevo->setVisibilidad(sem.getVisibilidad());
                nuevo->addTipo_(sem.tipo_);
                nuevo->ambito=sem.ambito;
                nuevo->nuevoAr=sem.nuevoAr;
                nuevo->dimension=sem.dimension;
                ac->addSimbolo(nuevo);

            }
            else if(entrada.at(a).tipo_==ope.at(a).tipo){
                Simbolos auxS=entrada.at(a);
                auxS.setValor(ope.at(a).valor);
                Simbolos *aux=new Simbolos();
                aux=&auxS;
                QString id=auxS.getId();
                ac->addSimbolo(aux);
            }else if(entrada.at(a).tipo_==falso && ope.at(a).tipo==verdadero){
                Simbolos auxS=entrada.at(a);
                auxS.setValor(ope.at(a).valor);
                Simbolos *aux=new Simbolos();
                aux=&auxS;
                aux->tipo_=verdadero;
                QString id=auxS.getId();
                ac->addSimbolo(aux);
            }else if(entrada.at(a).tipo_==falso && ope.at(a).tipo==falso){
                Simbolos auxS=entrada.at(a);
                auxS.setValor(ope.at(a).valor);
                Simbolos *aux=new Simbolos();
                aux=&auxS;
                aux->tipo_=falso;
                QString id=auxS.getId();
                ac->addSimbolo(aux);
            }
        }
        return correcto;
    }

    return false;
}


/*----------------------------------- METODO PARA INICIAR UN OBJETO,DECLARADO----------------*/
void PrimerRecorrido::DeclararOBJ(NodoAST *raiz, Entorno *actual){
    bool yapaso=false;
    QList<NodoAST> hijos=raiz->hijos;
    QString id;
    for(NodoAST ast:hijos){

        if(ast.tipo_==Id){
            if(yapaso==false){
               id=ast.valor;
               yapaso=true;
            }
        }
    }

    Simbolos sim=actual->BuscarVariable(id,actual);

    if(sim.getId()==""){
        Errores *er=new Errores(id,"Semantico","Variable no existe",raiz->linea,raiz->columna);
        semanticos.append(*er);
    }else{
       sim.ClaseIniciada=true;
       actual->SetearObjeto(sim,actual);

    }

}

/*------------------------------- METODO PARA REASIGNAR UN ARREGLO----------------------------*/

void PrimerRecorrido::ReArreglo(NodoAST *ax, Entorno *ac){

    NodoAST porArra=ax->hijos.at(0);
    NodoAST valor=ax->hijos.at(1);
    Operacion genOP=Asignacion(&valor,ac);
    Objeto nue=Objeto();
    nue.dato=genOP.valor;
    nue.tipo_=genOP.tipo;

    switch (porArra.tipo_) {
    case DIMENSION1:{
        NodoAST astOp1=porArra.hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
        QString id=porArra.hijos.at(1).valor;

        Simbolos sem=ac->BuscarVariable(id,ac);
        if(QString::compare(sem.getId(),"")==0){
            Errores *er=new Errores(id,"semantico","Arreglo no Existe",astOp1.linea,astOp1.columna);
            semanticos.append(*er);
        }else{
            QString salida=sem.nuevoAr->setDato1(nue,op1.valor.toInt(),genOP.tipo);
            if(QString::compare(salida,"")!=0){
                Errores *er=new Errores(id,"semantico",salida,astOp1.linea,astOp1.columna);
                semanticos.append(*er);
            }else{
                ac->SeterArreglo(sem,ac);
            }
        }




    }break;

    case DIMENSION2:{
        NodoAST astOp1=porArra.hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
        NodoAST astOp2=porArra.hijos.at(1);
        Operacion op2=Asignacion(&astOp2,ac);

        QString id=porArra.hijos.at(2).valor;
        Simbolos sem=ac->BuscarVariable(id,ac);
        if(QString::compare(sem.getId(),"")==0){
            Errores *er=new Errores(id,"semantico","Arreglo no Existe",astOp1.linea,astOp1.columna);
            semanticos.append(*er);
        }else{
            QString salida=sem.nuevoAr->setDato2(nue,op1.valor.toInt(),op2.valor.toInt(),genOP.tipo);
            if(QString::compare(salida,"")!=0){
                Errores *er=new Errores(id,"semantico",salida,astOp1.linea,astOp1.columna);
                semanticos.append(*er);
            }else{
                ac->SeterArreglo(sem,ac);
            }
        }



    }break;

    case DIMENSION3:{
        NodoAST astOp1=porArra.hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
        NodoAST astOp2=porArra.hijos.at(1);
        Operacion op2=Asignacion(&astOp2,ac);
        NodoAST astOp3=porArra.hijos.at(2);
        Operacion op3=Asignacion(&astOp3,ac);

        QString id=porArra.hijos.at(3).valor;
        Simbolos sem=ac->BuscarVariable(id,ac);

        if(QString::compare(sem.getId(),"")==0){
            Errores *er=new Errores(id,"semantico","Arreglo no Existe",astOp1.linea,astOp1.columna);
            semanticos.append(*er);
        }else{
            QString salida=sem.nuevoAr->setDato3(nue,op1.valor.toInt(),op2.valor.toInt(),op3.valor.toInt(),genOP.tipo);
            if(QString::compare(salida,"")!=0){
                Errores *er=new Errores(id,"semantico",salida,astOp1.linea,astOp1.columna);
                semanticos.append(*er);
            }else{
                ac->SeterArreglo(sem,ac);
            }
        }



    }break;

    }
}


Arreglos* PrimerRecorrido::ExtraerDimensiones(NodoAST *aux, Entorno *ac){

    Arreglos *nuevo;

    switch (aux->tipo_) {

    case DIMENSION1:{
        NodoAST astOp1=aux->hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
         nuevo=new Arreglos(op1.valor.toInt());
         return nuevo;
    }

    case  DIMENSION2:{
        NodoAST astOp1=aux->hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
        NodoAST astOp2=aux->hijos.at(1);
        Operacion op2=Asignacion(&astOp2,ac);
        nuevo=new Arreglos(op1.valor.toInt(),op2.valor.toInt());
        return nuevo;
    }

    case DIMENSION3:{
        NodoAST astOp1=aux->hijos.at(0);
        Operacion op1=Asignacion(&astOp1,ac);
        NodoAST astOp2=aux->hijos.at(1);
        Operacion op2=Asignacion(&astOp2,ac);
        NodoAST astOp3=aux->hijos.at(2);
        Operacion op3=Asignacion(&astOp3,ac);
        nuevo=new Arreglos(op1.valor.toInt(),op2.valor.toInt(),op3.valor.toInt());
        return  nuevo;
    }

    }

}


void PrimerRecorrido::setRetorno(NodoAST *reto, Entorno *ac){

    opeGeneral=Operacion();
    opeGeneral=Asignacion(reto,ac);
}

void PrimerRecorrido::setExternaVariable(NodoAST *raiz, Entorno *actual){

    QString obj=raiz->valor;
    QString var=raiz->hijos.at(0).valor;
    NodoAST ope=raiz->hijos.at(1);
    QList<QString> identi;
    /*mando a hacer la operacion*/
    Operacion op=Asignacion(&ope,actual);

    /*-----mando a buscar el objeto que llaman -----*/
    Simbolos objeto=actual->BuscarVariable(obj,actual);

    if(QString::compare(objeto.getId(),"")!=0){

        /*----mando a buscar en los simbolos del objeto, la variable a que se le quiere asignar algo------*/

        Simbolos sem=objeto.simbolosClase.value(var);
        QString conca=objeto.getId()+";"+sem.getId();

        if(QString::compare(sem.getTipo_Dato(),"variable",Qt::CaseInsensitive)==0){
            identi.append(conca);
            CASTEO(actual,identi,sem.tipoPrimitivo,sem.getVisibilidad(),op,sem.ambito,2);

        }else if(QString::compare(sem.getTipo_Dato(),"clase",Qt::CaseInsensitive)==0){
            sem.simbolosClase=op.objec.simbolosClase;
            objeto.simbolosClase.insert(sem.getId(),sem);
            //actual->SetearObjeto(objeto,actual);

        }else if(QString::compare(sem.getTipo_Dato(),"arreglo",Qt::CaseInsensitive)==0){
            sem.nuevoAr->array=op.array.array;
            objeto.simbolosClase.insert(sem.getId(),sem);
           // actual->SeterArreglo(objeto,actual);
        }


    }else{
        Errores *er =new Errores("LLamada_Objeto"+obj,"Semantico","El objeto no ha sido declarado",raiz->linea,raiz->columna);
        semanticos.append(*er);
    }

}

void PrimerRecorrido::setExterArray(NodoAST *raiz, Entorno *actual){

    QString obj=raiz->valor;
    NodoAST dimen=raiz->hijos.at(0);
    NodoAST ope=raiz->hijos.at(1);

    Simbolos objeto=actual->BuscarVariable(obj,actual);
    if(QString::compare(objeto.getId(),"")!=0){


        switch (dimen.tipo_) {
            case DIMENSION1:{
                NodoAST astOp1=dimen.hijos.at(0);
                Operacion op1=Asignacion(&astOp1,actual);

                Simbolos arra=objeto.simbolosClase.value(dimen.hijos.at(1).valor);

                //cuando hago esto espero recibir en operacion un tipo primitivo
                Operacion op=Asignacion(&ope,actual);


                    Objeto ob=Objeto(op.valor,op.tipo,"");
                    int i=op1.valor.toInt();
                    QString salida=arra.nuevoAr->setDato1(ob,i,ob.tipo_);

                    if(QString::compare(salida,"")!=0){
                        objeto.simbolosClase.insert(arra.getId(),arra);


                    }else {
                        Errores *er =new Errores(objeto.getId(),"semantico",salida,dimen.linea,dimen.columna);
                        semanticos.append(*er);
                    }



            }break;
            case DIMENSION2:{
            NodoAST astOp1=dimen.hijos.at(0);
            Operacion op1=Asignacion(&astOp1,actual);
            NodoAST astOp2=dimen.hijos.at(1);
            Operacion op2=Asignacion(&astOp2,actual);

             Simbolos arra=objeto.simbolosClase.value(dimen.hijos.at(2).valor);

             Operacion op=Asignacion(&ope,actual);


                    Objeto ob=Objeto(op.valor,op.tipo,"");
                    int i=op1.valor.toInt();
                    int j=op2.valor.toInt();

                    QString salida=arra.nuevoAr->setDato2(ob,i,j,ob.tipo_);
                    if(QString::compare(salida,"")==0){
                        objeto.simbolosClase.insert(arra.getId(),arra);

                    }else{
                        Errores *er =new Errores(objeto.getId(),"semantico",salida,dimen.linea,dimen.columna);
                        semanticos.append(*er);
                    }



            }break;
            case DIMENSION3:{
            NodoAST astOp1=dimen.hijos.at(0);
            Operacion op1=Asignacion(&astOp1,actual);
            NodoAST astOp2=dimen.hijos.at(1);
            Operacion op2=Asignacion(&astOp2,actual);
            NodoAST astOp3=dimen.hijos.at(2);
            Operacion op3=Asignacion(&astOp3,actual);


             Simbolos arra=objeto.simbolosClase.value(dimen.hijos.at(3).valor);

             Operacion op=Asignacion(&ope,actual);

             if(op.tipo==50){//puedo sacarel el valor
                  arra.nuevoAr=&op.array;
             }else{
                Objeto ob=Objeto(op.valor,op.tipo,"");
                int i=op1.valor.toInt();
                int j=op2.valor.toInt();
                int k=op3.valor.toInt();


                QString salida=arra.nuevoAr->setDato3(ob,i,j,k,ob.tipo_);
                if(QString::compare(salida,"")!=0){
                    objeto.simbolosClase.insert(arra.getId(),arra);



                }else{
                    Errores *er =new Errores(objeto.getId(),"semantico",salida,dimen.linea,dimen.columna);
                    semanticos.append(*er);
                }

             }

            }break;

        }

    }else{
        Errores *er =new Errores(obj,"semantico","Objeto no encontrado",raiz->linea,raiz->columna);
        semanticos.append(*er);
    }


}

bool PrimerRecorrido::ValidarCuenta(QString arch, QString nombre){

    //QString arch="C:\\Users\\CORE i7 64BITS\\Desktop\\PrubaXML.txt";

    QFile archivo(arch);
    QString contenido;



    if (archivo.open(QIODevice::ReadOnly|QIODevice::Text)) {
        contenido=QString::fromUtf8(archivo.readAll());
    }

     QRegExp exp("(\n|\r)");

     contenido.replace(exp,"");
     contenido.replace(" ","");


    nombre.replace(" ","");

    int actual=0;
    for(int x=0;x<contenido.size();x++){


        actual=contenido.indexOf(nombre,actual);

        if(actual==-1){
            return false;
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
            return  true;

        }else{
            x=ultimo;
        }


    }
    return false;
}
