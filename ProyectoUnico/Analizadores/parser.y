%{
#include "scanner.h"
//header del arbol
#include "nodoast.h"
#include "qdebug.h"
#include <iostream>

extern int yylineno; //linea actual donde se encuentra el parse (analisis lexico) lo maneja bison
extern int columna;//columna actual donde se encuentra el parse(analisi lexico) lo maneja bison
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON

//NODO RAIZ DEL AST
extern NodoAST *raiz;

//extern QList <Errores> *listaSintac=new QList<Errores>();

int yyerror(const char* mens)
{

    std::cout << mens <<" "<<yytext<< std::endl;
    return 0;
}


%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *node;
}

//TERMINALES DE TIPO TEXT SON STRING
%token<TEXT> str;
%token<TEXT> cha;
%token<TEXT> cadena;
%token<TEXT> entero;
%token<TEXT> decimal;
%token<TEXT> numero;
%token<TEXT> caracter;
%token<TEXT> boolean;
%token<TEXT> doble;
%token<TEXT> Id;
%token<TEXT> comparar;
%token<TEXT> diferencia;
%token<TEXT> menorQ;
%token<TEXT> menorIgual;
%token<TEXT> mayorQ;
%token<TEXT> mayorIgual;

%token<TEXT> Or;
%token<TEXT> And;
%token<TEXT> Nand;
%token<TEXT> Nor;
%token<TEXT> Not;
%token<TEXT> notificar;

%token<TEXT> caso;
%token<TEXT> suma;
%token<TEXT> resta;
%token<TEXT> multiplicacion;
%token<TEXT> division;
%token<TEXT> potencia;
%token<TEXT> parA;
%token<TEXT> parC;

%token<TEXT> final;
%token<TEXT> llaveA;
%token<TEXT> llaveC;

%token<TEXT> igual;
%token<TEXT> coma;
%token<TEXT> puntoComa;

%token<TEXT> arreglo;
%token<TEXT> corA;
%token<TEXT> corC;

%token<TEXT> si;
%token<TEXT> SinoSi;
%token<TEXT> sino;
%token<TEXT> comprobar;
%token<TEXT> salir;
%token<TEXT> defecto;
%token<TEXT> dosPunto;


%token<TEXT> para;
%token<TEXT> mientras;
%token<TEXT> repetir;
%token<TEXT> hacer;

%token<TEXT> romper;
%token<TEXT> continuar;
%token<TEXT> incluir;
%token<TEXT> imprimir;

%token<TEXT> archivo;
%token<TEXT> crearDer;
%token<TEXT> crearConjunto;
%token<TEXT> crearRegex;
%token<TEXT> crearEntrada;
%token<TEXT> guardarA

%token<TEXT> cuenta;
%token<TEXT> crearC;
%token<TEXT> verCuenta;
%token<TEXT> depCuenta;
%token<TEXT> resCuenta
%token<TEXT> imprimirCuenta;
%token<TEXT> conCuenta;
%token<TEXT> transferir;

%token<TEXT> clase;
%token<TEXT> extender;
%token<TEXT> principal;
%token<TEXT> sobrescribir;
%token<TEXT> funcion;

%token<TEXT> publico;
%token<TEXT> privado;
%token<TEXT> protegido;
%token<TEXT> voide;
%token<TEXT> Retornar;
%token<TEXT> falso;
%token<TEXT> verdadero;
%token<TEXT> punto;
%token<TEXT> nuevo;



/*----------NO TERMINALES ------*/

%type<node> INICIO;
%type<node> CLASES;
%type<node> RETORNO;
%type<node> CLASE;
%type<node> EXTENDER;
%type<node> HERENCIA;
%type<node> LISTA_SENTENCIA;
%type<node> CUERPO_CLASE;
%type<node> VISIBILIDAD;
%type<node> VAR_GLOBALES;
%type<node> TIPO_DATO;
%type<node> DEC_ID;
%type<node> ASIGNACION;
%type<node> ASIGNAR_VAR;
%type<node> E;
%type<node> IN_BOOL;
%type<node> DECLARAR_OBJEC;
%type<node> DECLAR_ARREGLO;
%type<node> DIMENSION;
%type<node> TERMI1;
%type<node> ARRAY1;
%type<node> LISTA_NORMAL;
%type<node> TERMI2;
%type<node> LISTA2;
%type<node> TERMI3;
%type<node> LISTA3;
%type<node> POR_ARREGLO;
%type<node> REASIGNAR_ARREGLO;
%type<node> START_SI;
%type<node> OTRO_SI;
%type<node> SINO_SI;
%type<node> SINO;
%type<node> START_PARA;
%type<node> INICIAR;

%type<node> CUERPO_PARA;
%type<node>START_REPETIR;
%type<node> START_MIENTRAS;
%type<node> START_HACER;

%type<node> START_COMPROBAR;
%type<node> CUERPO_COMPRO;
%type<node> LISTA_CASO;
%type<node> DEFAU;

%type<node> START_INCLUIR;
%type<node> START_IMPRIMIR;
%type<node> ARCH;
%type<node> NUEVO_CONJUNTO;
%type<node> NUEVO_REGEX;
%type<node> NUEVA_ENTRADA;
%type<node> GUARDAR;
%type<node> LISTA_GENERAL;
%type<node> SENTENCIA_GENERAL;
%type<node> NUEVO_OBJEC;

%type<node> METODO_FUNCION;

%type<node> CUERPO_MF;
%type<node> FUNCION_PARAMETRO;

%type<node> DIMENSION_N;

%type<node> ACTUALIZAR;

%type<node> PARAMETROS;
%type<node> LISTA_PARAMETROS;

%type<node> TIPO_F;
%type<node> PRIMITIVO;

%type<node> LLAMADA;
%type<node> LISTA_VALORES;
%type<node> PRINCIPAL;
%type<node> SENTENCIA_ARCHIVOS;



%type<node> DIMENSION1;
%type<node> DIMENSION2;
%type<node> DIMENSION3;

%type<node> SENTENCIA_CUENTA ;
%type<node> CREAR_CUENTA;
%type<node> VERIFICAR_CUENTA;
%type<node> DEP_CUENTA;
%type<node> RESTA_CUENTA;
%type<node> IMPRI_CUENTA;
%type<node> CONSUL_CUENTA;
%type<node> TRANFERIR;



%type<node> LISTA_INCLU;

//------> PRECEDENCIA

%left Or Nor
%left And Nand
%right Not
%left comparar diferencia menorQ menorIgual mayorQ mayorIgual
%left suma resta
%left  division multiplicacion
%left nonassoc potencia


%start INICIO

%%

//---------------REGLAS GRAMATICALES----

INICIO: LISTA_INCLU CLASES{
        $$=new NodoAST(@1.first_line,@1.first_column,"INICIO","INICIO");
        raiz=$$;
        raiz->add(*$1);
        raiz->add(*$2);

        }|CLASES{
        $$=new NodoAST(@1.first_line,@1.first_column,"INICIO","INICIO");
        raiz=$$;
        raiz->add(*$1);
        };

LISTA_INCLU:LISTA_INCLU START_INCLUIR{
            $$=$1;
            $$->add(*$2);
            }
            |START_INCLUIR{
            $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_INCLU","LISTA_INCLU");
            $$->add(*$1);
            };

CLASES: CLASES CLASE{
        $$=$1;
        //NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
        //nodo->add(*$2);
        $$->add(*$2);
}
        |CLASE{
        $$=new NodoAST(@1.first_line, @1.first_column,"CLASES","CLASES");
       // NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
        //nodo->add(*$1);
        $$->add(*$1);
};


CLASE: clase Id EXTENDER  LISTA_SENTENCIA llaveC{
        $$=new NodoAST(@1.first_line, @1.first_column,"clase",$2);
        //AUN NO SE COMO MANEJAR LOS EXTENDER


        $$->add(*$3);// HERENCIA O sin_herencia

        $$->add(*$4);//le asigno la lista sentencias

        };


EXTENDER: extender HERENCIA llaveA{
            $$=$2;
          }
          |llaveA{
          $$=new NodoAST(@1.first_line,@1.first_column,"sin_herencia","sin_herencia");
          };

HERENCIA: HERENCIA coma Id{
            $$=$1;
            NodoAST *ide=new NodoAST(@1.first_line,@1.first_column,"Id",$3);
            $$->add(*ide);
          }
          |Id{
            $$=new NodoAST(@1.first_line,@1.first_column,"HERENCIA","HERENCIA");
            NodoAST *ide=new NodoAST(@1.first_line,@1.first_column,"Id",$1);
            $$->add(*ide);
          };



LISTA_SENTENCIA: LISTA_SENTENCIA CUERPO_CLASE{
                 $$=$1;
                 $$->add(*$2);
                 }
                 |CUERPO_CLASE{
                  $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_SENTENCIA","LISTA_SENTENCIA");
                  $$->add(*$1);
                  };

CUERPO_CLASE:  VAR_GLOBALES{
                $$=new NodoAST(@1.first_line, @1.first_column,"VARIABLE","VARIABLE");
                NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"publico","publico");
               // nodo->add(*$1);
                $$->add(*nodo);
                $$->add(*$1);

              }
              |METODO_FUNCION{

              $$=$1;
              }

              |VISIBILIDAD VAR_GLOBALES{
              $$=new NodoAST(@1.first_line, @1.first_column,"VARIABLE","VARIABLE");
              $$->add(*$1);
              $$->add(*$2);
              }
              |DECLARAR_OBJEC{
              $$=new NodoAST(@1.first_line, @1.first_column,"OBJETO","OBJETO");
              NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"publico","publico");
              $$->add(*nodo);
              $$->add(*$1);

              }
              |VISIBILIDAD DECLARAR_OBJEC{
              $$=new NodoAST(@1.first_line, @1.first_column,"OBJETO","OBJETO");
              $$->add(*$1);
              $$->add(*$2);
              }
              |DECLAR_ARREGLO{
              $$=new NodoAST(@1.first_line, @1.first_column,"ARREGLO","ARREGLO");
              NodoAST *nodo =new NodoAST(@1.first_line, @1.first_column,"publico","publico");
              $$->add(*nodo);
              $$->add(*$1);
              }
              |VISIBILIDAD DECLAR_ARREGLO{
              $$=new NodoAST(@1.first_line, @1.first_column,"ARREGLO","ARREGLO");
              $1->add(*$1);//visibilidad
              $$->add(*$2);//datos
              }
              |PRINCIPAL{

                $$=$1;
              };





VISIBILIDAD: publico{
             $$=new NodoAST(@1.first_line, @1.first_column,"publico","publico");
             }
             |privado{
             $$=new NodoAST(@1.first_line, @1.first_column,"privado","privado");
             }
             |protegido{
             $$=new NodoAST(@1.first_line, @1.first_column,"protegido","protegido");
              };

/*----------PARTE DE LA DECLARION DE VARIABLES GLOBLES------------*/
VAR_GLOBALES: TIPO_DATO  ASIGNACION{
               $$=$1;
               //NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"ASIGNACION","ASIGNACION");
               //node->add(*$2);
               $$->add(*$2);
            } ;



TIPO_DATO:  PRIMITIVO DEC_ID{
            $$=new NodoAST(@1.first_line, @1.first_column,"TIPO_DATO","TIPO_DATO");
            $$->add(*$1);
            $$->add(*$2);
            };

DEC_ID: DEC_ID coma Id{
        //DEC_ID ES UNA LISTA DE IDS
        $$=$1;
        NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Id",$3);
        $$->add(*nodo);
        }
        |Id{
        $$=new NodoAST(@1.first_line, @1.first_column,"DEC_ID","DEC_ID");
        NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Id",$1);
        $$->add(*nodo);
        };


ASIGNACION: igual E final{
            $$=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");

            $$->add(*$2);
            }
            |final{
            $$=new NodoAST(@1.first_line, @1.first_column,"final",$1);
            };



ASIGNAR_VAR: Id igual E final{
               $$=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
               NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Id",$1);
               $$->add(*nodo);
               $$->add(*$3);//guarda

            };




/*------OPERACION,INCLUYE RETURN FUNCION,BOOLEANO,ASCII
HACER COMPROBACIONES DE TIPO, errores semanticos
-------*/
E:     E suma E{
            NodoAST *nodo =new NodoAST(@1.first_line, @1.first_column,"suma",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
       }
       |E resta E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"resta",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
       }
       |E multiplicacion E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"multiplicacion",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
       }
       |E division E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"division",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
       }
       |E potencia E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"potencia",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
       |E Or E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Or",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;

        }
       |E And E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"And",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
       }
        |E Nand E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Nand",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;

        }
        |E Nor  E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Nor",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E comparar E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"comparar",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E diferencia E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"diferencia",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E menorQ E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"menorQ",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E menorIgual E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"menorIgual",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E mayorQ  E{
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"mayorQ",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;
        }
        |E mayorIgual E  {
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"mayorIgual",$2);
            nodo->add(*$1);
            nodo->add(*$3);
            $$=nodo;

       }
       |VERIFICAR_CUENTA{
          $$=$1;
       }
       |IMPRI_CUENTA{
            $$=$1;
       }
       |CONSUL_CUENTA{
            $$=$1;
       }
       |Id{
           $$=new NodoAST(@1.first_line, @1.first_column,"Id",$1);

       }
       | POR_ARREGLO{
            NodoAST *node=new NodoAST(@1.first_line, @1.first_column,"POR_ARREGLO","POR_ARREGLO");
            node->add(*$1);   
            $$=node;
        }
       |LLAMADA{//va a devolver externa_F_v, Local_F_V, etc
            NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"LLAMADA_FUNCION","LLAMADA_FUNCION");
            node->add(*$1);
            $$=node;
       }
       |Not E{
             NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Not",$1);
             nodo->add(*$2);
             $$=nodo;
        }
       |IN_BOOL{
        $$=$1;
       }
       |cha{
            $$=new NodoAST(@1.first_line, @1.first_column,"cha",$1);
       }
       |str{
            $$=new NodoAST(@1.first_line, @1.first_column,"str",$1);
       }
       |decimal{
            $$=new NodoAST(@1.first_line, @1.first_column,"decimal",$1);
       }
       |numero{
            $$=new NodoAST(@1.first_line, @1.first_column,"numero",$1);
       }
       |resta E{
          NodoAST *nega=new NodoAST(@1.first_line, @1.first_column,"negativo",$1);
          nega->add(*$2);
          $$=nega;
       }
       |parA E parC{
            $$=$2;
        };


IN_BOOL: verdadero{
            $$=new NodoAST(@1.first_line, @1.first_column,"verdadero",$1);
         }
         |falso{
            $$=new NodoAST(@1.first_line, @1.first_column,"falso",$1);
         };

/*--------------------------------------------------------------------------*/

/*--------------------------------OBJETOS -----------------------------------*/
DECLARAR_OBJEC : Id Id igual nuevo Id parA parC final {
                  $$=new NodoAST(@1.first_line,@1.first_column,"nuevo_objeto","nuevo_objeto");

                    NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Id",$1);//clase
                    NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$2);//objeto
                    //NodoAST *nodo2=new NodoAST(@1.first_line, @1.first_column,"clase",$5);
                    $$->add(*nodo);
                    $$->add(*nodo1);


                }
                |Id Id final{
                  $$=new NodoAST(@1.first_line,@1.first_column,"No_Inicial","No_Inicial");
                  NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"Id",$1);//clase
                  NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$2);//objeto
                  $$->add(*nodo);
                  $$->add(*nodo1);
                };



/*----------------------------------------------------------------------------*/

/*--------------------------------- ARREGLOS ---------------------------------*/

DECLAR_ARREGLO: arreglo TIPO_DATO  DIMENSION{
                $$=new NodoAST(@1.first_line, @1.first_column,"arreglo","arreglo");
                $$->add(*$2);//primitivo y ids
                $$->add(*$3);//dimensiones y se inicia

                };


DIMENSION: DIMENSION1 TERMI1{
                $$=$1;
                $$->add(*$2);
            }
            |DIMENSION2 TERMI2{
                $$=$1;
                $$->add(*$2);

            }
            |DIMENSION3 TERMI3{
                $$=$1;
                $$->add(*$2);
            };




DIMENSION1: corA E corC{
                    $$=new NodoAST(@1.first_line, @1.first_column,"DIMENSION1","DIMENSION1");
            $$->add(*$2);
                   };

DIMENSION2 :corA E corC corA E corC{
                  $$=new NodoAST(@1.first_line, @1.first_column,"DIMENSION2","DIMENSION2");
            $$->add(*$2);
            $$->add(*$5);
                   };

DIMENSION3:corA E corC corA E corC corA E corC{
                        $$=new NodoAST(@1.first_line, @1.first_column,"DIMENSION3","DIMENSION3");
                $$->add(*$2);
                $$->add(*$5);
                $$->add(*$8);
                      };


TERMI1: final{
         $$=new NodoAST(@1.first_line, @1.first_column,"final","final");
        }
        |igual ARRAY1 final{
            $$=$2;//lista normal
        };

ARRAY1: llaveA LISTA_NORMAL llaveC{
        $$=$2;
        };

LISTA_NORMAL: LISTA_NORMAL coma E{
        $$=$1;
        $$->add(*$3);
        }
        |E{
        $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_NORMAL","LISTA_NORMAL");
        $$->add(*$1);
        };




TERMI2 : final{
         $$=new NodoAST(@1.first_line, @1.first_column,"final","final");
         }
         |igual llaveA LISTA2 llaveC final{
            $$=$3;//Lista 2
         };



LISTA2: LISTA2 coma ARRAY1{
        $$=$1;//Lista 2
        $$->add(*$3);//ingreso objeto de lista 2
        }
        |ARRAY1{
         $$=new NodoAST(@1.first_line, @1.first_column,"LISTA2","LISTA2");
         $$->add(*$1); //devuelve objeto lista normal
        };




TERMI3 : final{
         $$=new NodoAST(@1.first_line, @1.first_column,"final","final");
         }
         |igual llaveA   LISTA3 llaveC final{
            $$=$3;
         };


LISTA3 : LISTA3 coma llaveA LISTA2 llaveC{
         $$=$1;
         $$->add(*$4);//devuelve objeto de lista 2
         }
         | llaveA LISTA2 llaveC{
            $$=new NodoAST(@1.first_line, @1.first_column,"LISTA3","LISTA3");
            $$->add(*$2);//devuelve objeto de lista 2
        };



//-----> SACAR VALOR DE UN ARREGLO

POR_ARREGLO : Id DIMENSION1{
                $$=$2;
                NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"Id",$1);
                $$->add(*node);
               // $$->add(*$2);//si es dimen1,dimen2 o dimen3

              }
              |Id DIMENSION2{
                $$=$2;
                NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"Id",$1);
                $$->add(*node);
                //$$->add(*$2);

              }
              |Id DIMENSION3{
                $$=$2;
                NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"Id",$1);
                $$->add(*node);
                //$$->add(*$2);
              };



/*-------------------------- agregar valor arreglo--------------------------*/

REASIGNAR_ARREGLO: POR_ARREGLO igual E final{
                        $$=new NodoAST(@1.first_line, @1.first_column,"REASIGNAR_ARREGLO","REASIGNAR_ARREGLO");
                        $$->add(*$1);
                        $$->add(*$3);
                    };

/*----------------------------------------------------------------------------*/



/*---------------------- INSTRUCCION SI, SINO, SINO SI------------------------*/

START_SI: si parA E parC  llaveA LISTA_GENERAL OTRO_SI{
            //OTRO_SI PUEDE ESTAR VACIO O PUEDE TENER OTRO SI Y A LA VEZ SINO
            $$=new NodoAST(@1.first_line, @1.first_column,"START_SI","START_SI");
            $$->add(*$3);//enlazo con la condicion
            $$->add(*$6);//enlazo con las sentencias
            $$->add(*$7);//enalzo con ListaSI,
          };


OTRO_SI: llaveC SINO_SI{
            $$=$2;
           //recibo padre como Lista_SI
        }
         |llaveC SINO_SI SINO{
            $$=$2;//recibo como Padre Lista_Si
            $$->add(*$3);//enlace con sino
         }
         |llaveC SINO{

            $$=$2;//enlazo con la sino

         }
         |llaveC{
            $$=new NodoAST(@1.first_line, @1.first_column,"FIN_SI","FIN_SI");//solo viene un si

         };

SINO_SI : SINO_SI SinoSi parA E parC llaveA LISTA_GENERAL llaveC{
            $$=$1;//recibo Lista_si

            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"SinoSi",$2);//creacion de sinosi

            nodo->add(*$4);
            nodo->add(*$7);
            $$->add(*nodo);

         }
         |SinoSi parA E parC  llaveA LISTA_GENERAL llaveC{
            $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_SI","LISTA_SI");//creacion de la lista si
            NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"SinoSi",$1);//creacion de sinoSI

            nodo->add(*$3);//condicion
            nodo->add(*$6);//Lista sentencia
            $$->add(*nodo);//enlazo Lista_SI a sinosi
         };


SINO : sino llaveA LISTA_GENERAL llaveC{
            $$=new NodoAST(@1.first_line, @1.first_column,"sino","sino");//sino,
            $$->add(*$3);//enlazo sino con la ->condicion
       };

/*--------------------------------- INSTRUCCION PARA-------------------------- */

START_PARA: para parA INICIAR E final ACTUALIZAR parC CUERPO_PARA{
                $$=new NodoAST(@1.first_line, @1.first_column,"START_PARA","START_PARA");
                $$->add(*$3);
                //NodoAST *no=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                $$->add(*$4);
                //$$->add(*no);
                $$->add(*$6);
                $$->add(*$8);

            };

ACTUALIZAR: Id suma suma {
            $$=new NodoAST(@1.first_line,@1.first_column,"actualizar",$2);
            NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"Id",$1);
            $$->add(*node);


            }
           |Id resta resta{
            $$=new NodoAST(@1.first_line,@1.first_column,"actualizar",$2);
            NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"Id",$1);

            $$->add(*node);


           };

INICIAR: VAR_GLOBALES{
            $$=new NodoAST(@1.first_line, @1.first_column,"VAR_GLOBALES","VAR_GLOBALES");
            $$->add(*$1);
         }
         |ASIGNAR_VAR {
               $$=new NodoAST(@1.first_line, @1.first_column,"ASIGNAR_VAR","ASIGNAR_VAR");
            $$->add(*$1);
          };



CUERPO_PARA: llaveA LISTA_GENERAL llaveC{
                 //  $$=new NodoAST(@1.first_line, @1.first_column,"CUERPO_PARA","CUERPO_PARA");
                   $$=$2;

            };


/*--------------------------------INSTRUCCION REPETIR -------------------------*/

START_REPETIR: repetir parA E parC llaveA LISTA_GENERAL llaveC{
                $$=new NodoAST(@1.first_line, @1.first_column,"START_REPETIR","START_REPETIR");

                $$->add(*$3);
                $$->add(*$6);
               };

/*-------------------------------- CICLO MIENTRAS------------------------------*/

START_MIENTRAS: mientras parA E parC llaveA LISTA_GENERAL llaveC{
                $$=new NodoAST(@1.first_line, @1.first_column,"START_MIENTRAS","START_MIENTRAS");
               // NodoAST *node=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
               // node->add(*$3);

                //NodoAST *nod1=new NodoAST(@1.first_line, @1.first_column,"LISTA_GENERAL","LISTA_GENERAL");
                //nod1->add(*$6);

                $$->add(*$3);//condicion
                $$->add(*$6);//listaGeneral
                };

/*------------------------------ CICLO HACER MIENTRAS------------------------------*/

START_HACER: hacer llaveA LISTA_GENERAL llaveC mientras parA E parC final{
               $$=new NodoAST(@1.first_line, @1.first_column,"START_HACER","START_HACER");

               //NodoAST *nod=new NodoAST(@1.first_line, @1.first_column,"LISTA_GENERAL","LISTA_GENERAL");
               //nod->add(*$3);

               //NodoAST *nod1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
               //nod1->add(*$7);
               $$->add(*$3);
               $$->add(*$7);

            };



/*-------------------------- SENTENCIA DE COMPROBAR-------------------------------------*/

START_COMPROBAR: comprobar parA E parC llaveA CUERPO_COMPRO llaveC{
                  $$=new NodoAST(@1.first_line, @1.first_column,"START_COMPROBAR","START_COMPROBAR");
                  $$->add(*$3);
                  $$->add(*$6);
                };


CUERPO_COMPRO: LISTA_CASO DEFAU{
                $$=$1;//recibo una lista de casos
                $$->add(*$2);//ingreso el defau

              }
              |LISTA_CASO{
              $$=$1;//recibo una lista de casos
              }
              |DEFAU{
              $$=$1;//ingreso solo el dafau
              }

DEFAU: defecto dosPunto LISTA_GENERAL salir final{
        $$=new NodoAST(@1.first_line, @1.first_column,"defecto","defecto");
        $$->add(*$3);
      }

LISTA_CASO: LISTA_CASO caso E dosPunto LISTA_GENERAL salir final{
            $$=$1;
            NodoAST *no1=new NodoAST(@1.first_line, @1.first_column,"caso","caso");
            no1->add(*$3);
            no1->add(*$5);
          
            $$->add(*no1);

            }
            |caso E dosPunto LISTA_GENERAL salir final{

            $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_CASO","LISTA_CASO");
            NodoAST *no1=new NodoAST(@1.first_line, @1.first_column,"caso","caso");
            no1->add(*$2);
            no1->add(*$4);
          
            $$->add(*no1);
            };



/*-------------------------SENTENCIA INCLUIR, IMPRIMIR----------------------------*/

START_INCLUIR : incluir parA str parC final{
                $$=new NodoAST(@1.first_line, @1.first_column,"incluir",$3);
                };


START_IMPRIMIR: imprimir parA E parC final {
                    $$=new NodoAST(@1.first_line, @1.first_column,"imprimir",$1);
                    //NodoAST *no=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                    //no->add(*$3);
                    $$->add(*$3);

                };


/*------------------------- SENTENCIA PARA ARCHIVOS DER---------------------------*/

SENTENCIA_ARCHIVOS: ARCH{
                        //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        $$=$1;
                    }
                    |NUEVO_CONJUNTO{
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        $$=$1;
                    }
                    |NUEVO_REGEX{
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        $$=$1;
                     }
                    |NUEVA_ENTRADA{
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        $$=$1;
                    }
                    |GUARDAR{
                        //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        $$=$1;
                    };

ARCH: archivo Id igual crearDer parA E parC final{
            $$=new NodoAST(@1.first_line, @1.first_column,"archivo",$2);
            //NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
            $$->add(*$6);

            };



NUEVO_CONJUNTO: Id punto crearConjunto parA E coma E parC final{
                 $$=new NodoAST(@1.first_line, @1.first_column,"nuevo_conjunto",$1);
                // NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                 $$->add(*$5);
                 $$->add(*$7);

                };

NUEVO_REGEX: Id punto crearRegex parA E coma E parC final{
                $$=new NodoAST(@1.first_line, @1.first_column,"nuevo_regex",$1);

                //NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                $$->add(*$5);
                $$->add(*$7);
                //$$->add(*n1);

            };

NUEVA_ENTRADA: 	Id punto crearEntrada parA E coma E parC final{
                    $$=new NodoAST(@1.first_line, @1.first_column,"nueva_entrada",$1);

                   // NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                    $$->add(*$5);
                    $$->add(*$7);
                    //$$->add(*n1);
                } ;

GUARDAR : Id punto guardarA  parA parC final{
            $$=new NodoAST(@1.first_line, @1.first_column,"guarda_arch",$1);
        };


/*------------------------------- SENTENCIAS DE CUENTAS----------------------------------------------*/

SENTENCIA_CUENTA : CREAR_CUENTA{
                    $$=$1;
                  }
                  |VERIFICAR_CUENTA{
                  $$=$1;
                  }
                  |DEP_CUENTA{
                  $$=$1;
                  }
                  |RESTA_CUENTA{
                  $$=$1;
                  }
                  |IMPRI_CUENTA{
                  $$=$1;
                  }
                  |CONSUL_CUENTA{
                  $$=$1;
                  }
                  |TRANFERIR{
                  $$=$1;
                  };

CREAR_CUENTA: cuenta Id igual crearC parA E coma E parC final{
              $$=new NodoAST(@1.first_line,@1.first_column,"cuenta",$2);
              $$->add(*$6);
              $$->add(*$8);
              };

VERIFICAR_CUENTA: Id punto verCuenta parA parC final{
                  $$=new NodoAST(@1.first_line,@1.first_column,"verCuenta",$1);
                  };

DEP_CUENTA: Id punto depCuenta parA E parC final{
              $$=new NodoAST(@1.first_line,@1.first_column,"depCuenta",$1);
              $$->add(*$5);
              } ;

RESTA_CUENTA: Id punto resCuenta parA E parC final{
                $$=new NodoAST(@1.first_line,@1.first_column,"resCuenta",$1);
                $$->add(*$5);
              };



IMPRI_CUENTA: Id punto imprimirCuenta parA parC final{
              $$=new NodoAST(@1.first_line,@1.first_column,"imprimirCuenta",$1);
              };

CONSUL_CUENTA: Id punto conCuenta parA parC final{
                $$=new NodoAST(@1.first_line,@1.first_column,"conCuenta",$1);
                } ;

TRANFERIR: transferir parA Id coma Id coma E parC final{
            $$=new NodoAST(@1.first_line,@1.first_column,"transferir","transferir");
            NodoAST *ide1=new NodoAST(@1.first_line,@1.first_column,"Id",$3);
            $$->add(*ide1);//cuenta 1
            NodoAST *de2=new NodoAST(@1.first_line,@1.first_column,"Id",$5);
            $$->add(*de2);//cuenta 2
            $$->add(*$7);// monto
            };





//------------------------------ SENTENCIAS QUE VAN DENTRO DE UN METODO-----------------*/

LISTA_GENERAL: LISTA_GENERAL SENTENCIA_GENERAL{
               $$=$1;
               $$->add(*$2);
               }
               |SENTENCIA_GENERAL{
               $$=new NodoAST(@1.first_line,@1.first_column,"LISTA_GENERAL","LISTA_GENERAL");
               $$->add(*$1);
                         };

SENTENCIA_GENERAL: VAR_GLOBALES{
                    $$=new NodoAST(@1.first_line, @1.first_column,"VAR_GLOBALES","VAR_GLOBALES");
                    $$->add(*$1);
                    }
                    |DECLARAR_OBJEC{
                    $$=new NodoAST(@1.first_line, @1.first_column,"OBJETO","OBJETO");

                    $$->add(*$1);
                    }
                    |NUEVO_OBJEC{
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |DECLAR_ARREGLO{
                    $$=new NodoAST(@1.first_line, @1.first_column,"ARREGLO","ARREGLO");
                    $$->add(*$1);
                    }
                    |REASIGNAR_ARREGLO{
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |ASIGNAR_VAR{
                    $$=new NodoAST(@1.first_line, @1.first_column,"ASIGNAR_VAR","ASIGNAR_VAR");
                    $$->add(*$1);
                    }
                    |ACTUALIZAR final{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_SI{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_HACER{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_MIENTRAS{
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_PARA{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_REPETIR{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_COMPROBAR{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |START_IMPRIMIR{
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=$1;
                    }
                    |SENTENCIA_ARCHIVOS{
                    $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                    $$->add(*$1);
                    }
                    |SENTENCIA_CUENTA{
                    $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_CUENTA","SENTENCIA_CUENTA");
                    $$->add(*$1);
                    }
                    |RETORNO final{
                    
                    $$=$1;
                    }
                    |LLAMADA {
                    $$=new NodoAST(@1.first_line, @1.first_column,"LLAMADA_FUNCION","LLAMADA_FUNCION");
                    $$->add(*$1);
                    }
                    |romper final{
                    NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"romper",$1);
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=node;
                    }
                    |continuar final{
                    NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"continuar",$1);
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    $$=node;
                    };

NUEVO_OBJEC: Id igual nuevo Id parA parC final{ 
                //ca=nuevo Clase1()
                $$=new NodoAST(@1.first_line,@1.first_column,"NUEVO_OBJEC","NUEVO_OBJEC");
                NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"Id",$1);//id obje
                NodoAST *node1=new NodoAST(@1.first_line,@1.first_column,"Id",$4);//id clase
                $$->add(*node);
                $$->add(*node1);
            } ;


RETORNO:Retornar E{
        $$=new NodoAST(@1.first_line,@1.first_column,"RETORNO","RETORNO");
        $$->add(*$2);
        };

/*---------------------------- METODOS SIN RETORNO-------------------------*/

METODO_FUNCION: funcion sobrescribir VISIBILIDAD TIPO_F Id PARAMETROS CUERPO_MF{
                $$=new NodoAST(@1.first_line,@1.first_column,"METODO_FUNCION","METODO_FUNCION");
                NodoAST *node1=new NodoAST(@1.first_line,@1.first_column,"sobrescribir",$2);
                $$->add(*node1);//sobreescribir
                $$->add(*$3);//visibilidad

                //funcion o metodo,tipo de retorno
                $$->add(*$4);

                NodoAST *nod=new NodoAST(@1.first_line,@1.first_column,"Id",$5);
                $$->add(*nod);

                $$->add(*$6);//parametros

                $$->add(*$7);//cuerpo

                }
               |funcion VISIBILIDAD TIPO_F Id PARAMETROS CUERPO_MF{
                    $$=new NodoAST(@1.first_line,@1.first_column,"METODO_FUNCION","METODO_FUNCION");
                    $$->add(*$2);//visibilidad
                    //funcion o metodo,tipo de retorno
                    $$->add(*$3);
                    NodoAST *no=new NodoAST(@1.first_line,@1.first_column,"Id",$4);

                    $$->add(*no);//id
                    $$->add(*$5);//parametros
                    $$->add(*$6);//cuerpo

                }
               |funcion sobrescribir TIPO_F Id PARAMETROS CUERPO_MF{
                    $$=new NodoAST(@1.first_line,@1.first_column,"METODO_FUNCION","METODO_FUNCION");
                    NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"sobrescribir",$2);
                    NodoAST *n1=new NodoAST(@1.first_line,@1.first_column,"publico","publico");
                    $$->add(*node);//sobre
                    $$->add(*n1);//visibilidad
                    //funcion o metodo,tipo de retorno
                    $$->add(*$3);
                    NodoAST *ide=new NodoAST(@1.first_line,@1.first_column,"Id",$4);
                    $$->add(*ide);//id
                    $$->add(*$5);//parametros
                    $$->add(*$6);//cuerpo
               }
               |funcion TIPO_F Id PARAMETROS CUERPO_MF{
                    $$=new NodoAST(@1.first_line,@1.first_column,"METODO_FUNCION","METODO_FUNCION");
                    NodoAST *visi=new NodoAST(@1.first_line,@1.first_column,"publico","publico");
                    $$->add(*visi);//visibilidad
                    //funcion o metodo
                    $$->add(*$2);
                    NodoAST *ide=new NodoAST(@1.first_line,@1.first_column,"Id",$3);

                    $$->add(*ide);//id
                    $$->add(*$4);//parametros
                    $$->add(*$5);//metodo

                };


CUERPO_MF: llaveA LISTA_GENERAL llaveC{
            $$=$2;

            };


FUNCION_PARAMETRO: PRIMITIVO Id{//variable
                    $$=new NodoAST(@1.first_line,@1.first_column,"variable","variable");
                    $$->add(*$1);
                    NodoAST *node =new NodoAST(@1.first_line,@1.first_column,"Id",$2);
                    $$->add(*node);

                    }
                    |arreglo PRIMITIVO Id DIMENSION_N{//arreglo
                    $$=new NodoAST(@1.first_line,@1.first_column,"arreglo",$3);
                    $$->add(*$2);//dato primitivo
                    $$->add(*$4);

                    }
                    |Id Id{//objeto
                    $$=new NodoAST(@1.first_line,@1.first_column,"objeto","objeto");
                    NodoAST *no1=new NodoAST(@1.first_line,@1.first_column,"Id",$1);//clase
                    NodoAST *no2=new NodoAST(@1.first_line,@1.first_column,"Id",$2);//objec
                    $$->add(*no1);
                    $$->add(*no2);
                    };

PARAMETROS: parA LISTA_PARAMETROS parC{
            $$=$2;
            }
            |parA parC{
                $$=new NodoAST(@1.first_line,@1.first_column,"SIN_PARAMETRO","SIN_PARAMETRO");

            };


LISTA_PARAMETROS: LISTA_PARAMETROS coma FUNCION_PARAMETRO{
                        $$=$1;
                        $$->add(*$3);
                    }
                   |FUNCION_PARAMETRO{
                        $$=new NodoAST(@1.first_line,@1.first_column,"LISTA_PARAMETROS","LISTA_PARAMETROS");
                        $$->add(*$1);
                    };



DIMENSION_N:      DIMENSION1{
                    $$=$1;
                  }
                  |DIMENSION2{
                    $$=$1;
                  }
                  |DIMENSION3{
                      $$=$1;
                  };




TIPO_F: PRIMITIVO{

           $$=$1;
        }
        |arreglo PRIMITIVO DIMENSION_N{

            $$=new NodoAST(@1.first_line, @1.first_column,"arreglo","arreglo");

            $$->add(*$2);//primitivo
            $$->add(*$3);//dimensiones[][][]

        }
        |Id{

            $$=new NodoAST(@1.first_line, @1.first_column,"clase",$1);//nombre de la clase
        }
        |voide{

             $$ =new NodoAST(@1.first_line, @1.first_column,"void",$1);

        };



/*-------------------------FUNCION CON RETORNO ---------------------------*/



PRIMITIVO: entero{
            $$=new NodoAST(@1.first_line, @1.first_column,"entero","entero");
           }
           |doble{
           $$=new NodoAST(@1.first_line, @1.first_column,"doble","doble");
           }
           |cadena{
           $$=new NodoAST(@1.first_line, @1.first_column,"cadena","cadena");
           }
           |caracter{
           $$=new NodoAST(@1.first_line, @1.first_column,"caracter","caracter");
           }
           |boolean{
            $$=new NodoAST(@1.first_line, @1.first_column,"boolean","boolean");
            };




/*------------------------- LLAMADA A FUNCIONES -------------------------*/

LLAMADA: Id punto Id parA LISTA_VALORES parC final{
            //----llamada de una funcion de otra clase

            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_F_V",$1);//contiene el id del objeto

            NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$3);//id de la funcion
           
            $$->add(*nodo1);//funcion
            $$->add(*$5);//valores de parametro


        }|Id punto Id parA parC final{ //llamada de una funcion externa sin valores

            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_F_S",$1);//contiene el id del objeto

            
            NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$3);//funcion como tal
           
            $$->add(*nodo1);//funcion


        }|Id parA LISTA_VALORES parC final{//----> este ya funciona
            $$=new NodoAST(@1.first_line, @1.first_column,"Local_F_V",$1);
            $$->add(*$3);



        }|Id parA parC final{//este ya funciona 
                $$=new NodoAST(@1.first_line, @1.first_column,"Local_F_S",$1);


        }|Id punto Id{//llamada de variable extena 
            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_Var",$1);//contiene el id del objeto
            NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$3);//id de la variable
            $$->add(*nodo1);

         }
         |Id punto Id igual E final{//llamada de variable extena 
            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_Var_A",$1);//contiene el id del objeto
            NodoAST *nodo1=new NodoAST(@1.first_line, @1.first_column,"Id",$3);//id de la variable
            $$->add(*nodo1);
            $$->add(*$5);

         }|Id punto POR_ARREGLO igual E final{//llamada arreglo externo
            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_Ar_A",$1);//contiene el id del objeto
            $$->add(*$3);//trae id y dimension
            $$->add(*$5);//trae el valor a asignar
         };

         |Id punto POR_ARREGLO{//llamada arreglo externo
            $$=new NodoAST(@1.first_line, @1.first_column,"Externa_Ar",$1);//contiene el id del objeto
            $$->add(*$3);
         };

LISTA_VALORES : LISTA_VALORES coma E{
                $$=$1;
                //NodoAST *node=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                //node->add(*$3);
                $$->add(*$3);
                }
                |E{
                $$=new NodoAST(@1.first_line, @1.first_column,"LISTA_VALORES","LISTA_VALORES");
                //NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                //node->add(*$1);
                $$->add(*$1);
                };
/*-----------------------------------METODO PRINCIPAL----------------------*/

PRINCIPAL: principal parA parC CUERPO_MF{
            $$=new NodoAST(@1.first_line,@1.first_column,"PRINCIPAL","PRINCIPAL");
            $$->add(*$4);

            };

%%










