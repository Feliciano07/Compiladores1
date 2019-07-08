/*
Area 1. Deficiones
*/
%option case-insensitive
%option yylineno
%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput
%{

#include <cstdlib>
#include <string>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <errores.h>
#include "nodoast.h"
#include "qdebug.h"

#include "qlist.h"

//funcion que realiza el analizador lexico
int yylex();
//errores lexicos
void yyerror(const char *s);
 int linea=1;//para contar lineas
int columna=1;//para contar columnas
int anterior=0;
 NodoAST *raiz;

 extern QList <Errores> *listaLexico=new QList<Errores>();



//metodo para imprimir en consola
 void imprimirEnConsola(const char *mensaje, const char *tkn){

         std::cout << mensaje <<" : "<<tkn <<std::endl;

 }

%}
/*indica a flex que no distinga mayusculas o minusculas*/



/*Espresiones regulares*/

numero [0-9]+
decimal [0-9]+"."[0-9]+

letra [a-zA-ZñÑ]+

identificador {letra}({letra}|{numero}|"_")*

otros \t|\r|\f


str "\""[^"\""\n]*["\""\n]




cha [\']([^\']|[\\][^\'])?[\']

%x COM COMM STR STR1


%%



INITIAL
{
"//" {  BEGIN COM; }
"/*" { BEGIN COMM; }



{otros}     {/* ignore white space*/}


" "       {columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext);}

"\n"        {linea++; columna=0;anterior=0;}



{cha}      {imprimirEnConsola("caracter",yytext);
             std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return cha;}

{str}      {imprimirEnConsola("cadena",yytext);
             std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return str;}




{numero}        {imprimirEnConsola("numero",yytext);
                std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return numero;}

{decimal}       {imprimirEnConsola("decimal",yytext);
                 std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return decimal;}


"."             {imprimirEnConsola("punto",yytext);
                std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return punto;}


     "entero"        {imprimirEnConsola("entero",yytext);
                std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return entero;}

     "doble"         {imprimirEnConsola("doble",yytext);
                std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return doble;}

    "cadena"         {imprimirEnConsola("cadena",yytext);
               std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return cadena;}

    "caracter"         {imprimirEnConsola("caracter",yytext);
               std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return caracter;}


     "booleano"      {imprimirEnConsola("booleano",yytext);
                     std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return boolean;}

     "verdadero"      {imprimirEnConsola("verdadero",yytext);
                    std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return verdadero;}

     "falso"     {imprimirEnConsola("falso",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return falso;}


"=="            {imprimirEnConsola("comparar",yytext);
            std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return comparar;}

"!="            {imprimirEnConsola("diferencia",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return diferencia;}

"<"             {imprimirEnConsola("menorQ",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return menorQ;}

"<="             {imprimirEnConsola("menorIgual",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return menorIgual;}

">"             {imprimirEnConsola("mayorQ",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return mayorQ;}

">="            {imprimirEnConsola("mayorIgual",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return mayorIgual;}


"||"            {imprimirEnConsola("Or",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Or;}

"&&"            {imprimirEnConsola("And",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return And;}

"!&&"           {imprimirEnConsola("Nand",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Nand;}

"!"             {imprimirEnConsola("diferencia",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Not;}

"!||"           {imprimirEnConsola("Nor",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Nor;}



"+"             {imprimirEnConsola("suma",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return suma;}

     "-"             {imprimirEnConsola("resta",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return resta;}

     "*"             {imprimirEnConsola("multiplicacion",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return multiplicacion;}

     "/"             {imprimirEnConsola("division",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return division;}

     "^"             {imprimirEnConsola("potencia",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return potencia;}

     "("             {imprimirEnConsola("parentesisAbre",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return parA;}

     ")"             {imprimirEnConsola("parentesisCierrra",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return parC;}




"$"             {imprimirEnConsola("fin_Sentencia",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return final;}

"{"             {imprimirEnConsola("LLaveAbre",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return llaveA;}

"}"             {imprimirEnConsola("LLaveCierra",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return llaveC;}



"="             {imprimirEnConsola("igual",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return igual;}

","             {imprimirEnConsola("coma",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return coma;}

";"             {imprimirEnConsola("puntoComa",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return puntoComa;}



"arreglo"       {imprimirEnConsola("arreglo",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return arreglo;}

"["             {imprimirEnConsola("CorcheteAbre",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return corA;}

"]"             {imprimirEnConsola("CorcheteCierra",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return corC;}




"si"            {imprimirEnConsola("setencia_si",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return si;}

"sino si"       {imprimirEnConsola("Sentencia_SINOSI",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return SinoSi;}

"sino"          {imprimirEnConsola("Sentencia Sino",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return sino;}



"para"          {imprimirEnConsola("sentencia Para",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return para;}


"repetir"       {imprimirEnConsola("sentencia repetir",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return repetir;}


"mientras"       {imprimirEnConsola("sentencia mientras",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return mientras;}




"hacer"         {imprimirEnConsola("sentencia hacer",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return hacer;}



"comprobar"         {imprimirEnConsola("sentencia_comprobar",yytext);std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return comprobar;}

"salir"             {imprimirEnConsola("sentencia_salir",yytext);  std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return salir;}

"caso"              {imprimirEnConsola("sentencia_caso",yytext); std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return caso;}

"defecto"           {imprimirEnConsola("sentencia_defecto",yytext); std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return defecto;}

":"             {imprimirEnConsola("DosPunto",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return dosPunto;}



"romper"        {imprimirEnConsola("sentencia_romper",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return romper;}

"continuar"     {imprimirEnConsola("sentencia_continuar",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return continuar;}




"archivo"       {imprimirEnConsola("sentencia_archivo",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return archivo;}

"crearArchivoDer" {imprimirEnConsola("sentencia_crearArchivo",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return crearDer;}

"crearConjunto" {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return crearConjunto;}

"crearRegex"    {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return crearRegex;}

"crearEntrada"  {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return crearEntrada;}

"guardarArchivo"    {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return guardarA;}


"Cuenta"        {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return cuenta;}

"crearCuenta"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return crearC;}

"verificarCuenta" {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return verCuenta;}

"depositarCuenta"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return depCuenta;}

"restarCuenta"      {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return resCuenta;}

"imprimirTransaccionesCuenta"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return imprimirCuenta;}

"consultarCuenta"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return conCuenta;}

"Transferir"        {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return transferir;}




"clase"             {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return clase;}

"extender"          {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return extender;}

"principal"         {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return principal;}

"nuevo"             {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return nuevo;}

"sobrescribir"      {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return sobrescribir;}


"publico"           {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return publico;}

"privado"           {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return privado;}

"protegido"         {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return protegido;}



"void"              {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return voide;}

"retornar"          {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Retornar;}




"incluir"       {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return incluir;}

"imprimir"      {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return imprimir;}

"mostrarNotificacion"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return notificar;}

"funcion"   {imprimirEnConsola("Reconocido",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return funcion;}





{identificador} {imprimirEnConsola("identificador",yytext);
         std::cout<<yytext<<std::endl;  columna=columna+anterior;  anterior=strlen(yytext);    strcpy(yylval.TEXT,yytext); return Id;}


.           {imprimirEnConsola("ERROR",yytext);
                Errores  *nuevo=new Errores(yytext,"Error Lexico","Token Desconocido",linea,columna);
               std::cout<<"Error léxico, no se esperaba token:"<<yytext<<" en la linea:"<<linea<<std::endl;

            }

}

<COMM>"*/" { BEGIN INITIAL; }
<COMM>"\n" {linea++;};
<COMM>.;
<COMM><<EOF>> { yyerror("unclosed comment"); }
<COM>"\n" { linea++; columna = 0; BEGIN INITIAL; };
<COM>.;





%%




