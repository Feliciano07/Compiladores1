/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     str = 258,
     cha = 259,
     cadena = 260,
     entero = 261,
     decimal = 262,
     numero = 263,
     caracter = 264,
     boolean = 265,
     doble = 266,
     Id = 267,
     comparar = 268,
     diferencia = 269,
     menorQ = 270,
     menorIgual = 271,
     mayorQ = 272,
     mayorIgual = 273,
     Or = 274,
     And = 275,
     Nand = 276,
     Nor = 277,
     Not = 278,
     notificar = 279,
     caso = 280,
     suma = 281,
     resta = 282,
     multiplicacion = 283,
     division = 284,
     potencia = 285,
     parA = 286,
     parC = 287,
     final = 288,
     llaveA = 289,
     llaveC = 290,
     igual = 291,
     coma = 292,
     puntoComa = 293,
     arreglo = 294,
     corA = 295,
     corC = 296,
     si = 297,
     SinoSi = 298,
     sino = 299,
     comprobar = 300,
     salir = 301,
     defecto = 302,
     dosPunto = 303,
     para = 304,
     mientras = 305,
     repetir = 306,
     hacer = 307,
     romper = 308,
     continuar = 309,
     incluir = 310,
     imprimir = 311,
     archivo = 312,
     crearDer = 313,
     crearConjunto = 314,
     crearRegex = 315,
     crearEntrada = 316,
     guardarA = 317,
     cuenta = 318,
     crearC = 319,
     verCuenta = 320,
     depCuenta = 321,
     resCuenta = 322,
     imprimirCuenta = 323,
     conCuenta = 324,
     transferir = 325,
     clase = 326,
     extender = 327,
     principal = 328,
     sobrescribir = 329,
     funcion = 330,
     publico = 331,
     privado = 332,
     protegido = 333,
     voide = 334,
     Retornar = 335,
     falso = 336,
     verdadero = 337,
     punto = 338,
     nuevo = 339,
     nonassoc = 340
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *node;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */
