/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */


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





# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1905

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNRULES -- Number of states.  */
#define YYNSTATES  476

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    16,    18,    24,
      28,    30,    34,    36,    39,    41,    43,    45,    48,    50,
      53,    55,    58,    60,    62,    64,    66,    69,    72,    76,
      78,    82,    84,    89,    93,    97,   101,   105,   109,   113,
     117,   121,   125,   129,   133,   137,   141,   145,   149,   151,
     153,   155,   157,   159,   161,   164,   166,   168,   170,   172,
     174,   177,   181,   183,   185,   194,   198,   202,   205,   208,
     211,   215,   222,   232,   234,   238,   242,   246,   248,   250,
     256,   260,   262,   264,   270,   276,   280,   283,   286,   289,
     294,   302,   305,   309,   312,   314,   323,   331,   336,   345,
     349,   353,   355,   357,   361,   369,   377,   387,   395,   398,
     400,   402,   408,   416,   423,   429,   435,   437,   439,   441,
     443,   445,   454,   464,   474,   484,   491,   493,   495,   497,
     499,   501,   503,   505,   516,   523,   531,   539,   546,   553,
     563,   566,   568,   570,   572,   574,   576,   578,   580,   583,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   604,
     606,   609,   612,   620,   623,   631,   638,   645,   651,   655,
     658,   663,   666,   670,   673,   677,   679,   681,   683,   685,
     687,   691,   693,   695,   697,   699,   701,   703,   705,   713,
     720,   726,   731,   735,   742,   749,   753,   757,   759
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    89,    -1,    89,    -1,    88,   133,
      -1,   133,    -1,    89,    90,    -1,    90,    -1,    71,    12,
      91,    93,    35,    -1,    72,    92,    34,    -1,    34,    -1,
      92,    37,    12,    -1,    12,    -1,    93,    94,    -1,    94,
      -1,    96,    -1,   153,    -1,    95,    96,    -1,   103,    -1,
      95,   103,    -1,   104,    -1,    95,   104,    -1,   163,    -1,
      76,    -1,    77,    -1,    78,    -1,    97,    99,    -1,   160,
      98,    -1,    98,    37,    12,    -1,    12,    -1,    36,   101,
      33,    -1,    33,    -1,    12,    36,   101,    33,    -1,   101,
      26,   101,    -1,   101,    27,   101,    -1,   101,    28,   101,
      -1,   101,    29,   101,    -1,   101,    30,   101,    -1,   101,
      19,   101,    -1,   101,    20,   101,    -1,   101,    21,   101,
      -1,   101,    22,   101,    -1,   101,    13,   101,    -1,   101,
      14,   101,    -1,   101,    15,   101,    -1,   101,    16,   101,
      -1,   101,    17,   101,    -1,   101,    18,   101,    -1,   143,
      -1,   146,    -1,   147,    -1,    12,    -1,   116,    -1,   161,
      -1,    23,   101,    -1,   102,    -1,     4,    -1,     3,    -1,
       7,    -1,     8,    -1,    27,   101,    -1,    31,   101,    32,
      -1,    82,    -1,    81,    -1,    12,    12,    36,    84,    12,
      31,    32,    33,    -1,    12,    12,    33,    -1,    39,    97,
     105,    -1,   106,   109,    -1,   107,   112,    -1,   108,   114,
      -1,    40,   101,    41,    -1,    40,   101,    41,    40,   101,
      41,    -1,    40,   101,    41,    40,   101,    41,    40,   101,
      41,    -1,    33,    -1,    36,   110,    33,    -1,    34,   111,
      35,    -1,   111,    37,   101,    -1,   101,    -1,    33,    -1,
      36,    34,   113,    35,    33,    -1,   113,    37,   110,    -1,
     110,    -1,    33,    -1,    36,    34,   115,    35,    33,    -1,
     115,    37,    34,   113,    35,    -1,    34,   113,    35,    -1,
      12,   106,    -1,    12,   107,    -1,    12,   108,    -1,   116,
      36,   101,    33,    -1,    42,    31,   101,    32,    34,   149,
     119,    -1,    35,   120,    -1,    35,   120,   121,    -1,    35,
     121,    -1,    35,    -1,   120,    43,    31,   101,    32,    34,
     149,    35,    -1,    43,    31,   101,    32,    34,   149,    35,
      -1,    44,    34,   149,    35,    -1,    49,    31,   124,   101,
      33,   123,    32,   125,    -1,    12,    26,    26,    -1,    12,
      27,    27,    -1,    96,    -1,   100,    -1,    34,   149,    35,
      -1,    51,    31,   101,    32,    34,   149,    35,    -1,    50,
      31,   101,    32,    34,   149,    35,    -1,    52,    34,   149,
      35,    50,    31,   101,    32,    33,    -1,    45,    31,   101,
      32,    34,   130,    35,    -1,   132,   131,    -1,   132,    -1,
     131,    -1,    47,    48,   149,    46,    33,    -1,   132,    25,
     101,    48,   149,    46,    33,    -1,    25,   101,    48,   149,
      46,    33,    -1,    55,    31,     3,    32,    33,    -1,    56,
      31,   101,    32,    33,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    -1,    57,    12,    36,    58,    31,
     101,    32,    33,    -1,    12,    83,    59,    31,   101,    37,
     101,    32,    33,    -1,    12,    83,    60,    31,   101,    37,
     101,    32,    33,    -1,    12,    83,    61,    31,   101,    37,
     101,    32,    33,    -1,    12,    83,    62,    31,    32,    33,
      -1,   142,    -1,   143,    -1,   144,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,    63,    12,    36,    64,    31,
     101,    37,   101,    32,    33,    -1,    12,    83,    65,    31,
      32,    33,    -1,    12,    83,    66,    31,   101,    32,    33,
      -1,    12,    83,    67,    31,   101,    32,    33,    -1,    12,
      83,    68,    31,    32,    33,    -1,    12,    83,    69,    31,
      32,    33,    -1,    70,    31,    12,    37,    12,    37,   101,
      32,    33,    -1,   149,   150,    -1,   150,    -1,    96,    -1,
     103,    -1,   151,    -1,   104,    -1,   117,    -1,   100,    -1,
     123,    33,    -1,   118,    -1,   128,    -1,   127,    -1,   122,
      -1,   126,    -1,   129,    -1,   134,    -1,   135,    -1,   141,
      -1,   152,    33,    -1,   161,    -1,    53,    33,    -1,    54,
      33,    -1,    12,    36,    84,    12,    31,    32,    33,    -1,
      80,   101,    -1,    75,    74,    95,   159,    12,   156,   154,
      -1,    75,    95,   159,    12,   156,   154,    -1,    75,    74,
     159,    12,   156,   154,    -1,    75,   159,    12,   156,   154,
      -1,    34,   149,    35,    -1,   160,    12,    -1,    39,   160,
      12,   158,    -1,    12,    12,    -1,    31,   157,    32,    -1,
      31,    32,    -1,   157,    37,   155,    -1,   155,    -1,   106,
      -1,   107,    -1,   108,    -1,   160,    -1,    39,   160,   158,
      -1,    12,    -1,    79,    -1,     6,    -1,    11,    -1,     5,
      -1,     9,    -1,    10,    -1,    12,    83,    12,    31,   162,
      32,    33,    -1,    12,    83,    12,    31,    32,    33,    -1,
      12,    31,   162,    32,    33,    -1,    12,    31,    32,    33,
      -1,    12,    83,    12,    -1,    12,    83,    12,    36,   101,
      33,    -1,    12,    83,   116,    36,   101,    33,    -1,    12,
      83,   116,    -1,   162,    37,   101,    -1,   101,    -1,    73,
      31,    32,   154,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   251,   251,   257,   263,   267,   272,   278,   286,   298,
     301,   305,   310,   318,   322,   327,   335,   340,   345,   352,
     357,   363,   368,   377,   380,   383,   388,   397,   403,   409,
     416,   421,   427,   441,   447,   453,   459,   465,   471,   478,
     484,   491,   497,   503,   509,   515,   521,   527,   534,   537,
     540,   543,   547,   552,   557,   562,   565,   568,   571,   574,
     577,   582,   587,   590,   597,   608,   622,   630,   634,   639,
     647,   652,   658,   666,   669,   673,   677,   681,   689,   692,
     698,   702,   710,   713,   718,   722,   731,   738,   745,   756,
     768,   777,   781,   785,   790,   795,   805,   815,   822,   833,
     840,   849,   853,   860,   869,   878,   892,   909,   916,   921,
     924,   928,   933,   942,   956,   961,   972,   976,   980,   984,
     988,   993,  1002,  1010,  1020,  1029,  1036,  1039,  1042,  1045,
    1048,  1051,  1054,  1058,  1064,  1068,  1073,  1080,  1084,  1088,
    1103,  1107,  1112,  1116,  1121,  1125,  1129,  1133,  1137,  1141,
    1145,  1149,  1153,  1157,  1161,  1165,  1169,  1173,  1177,  1181,
    1185,  1190,  1196,  1206,  1213,  1230,  1242,  1255,  1270,  1276,
    1283,  1289,  1297,  1300,  1306,  1310,  1317,  1320,  1323,  1330,
    1334,  1342,  1346,  1358,  1361,  1364,  1367,  1370,  1379,  1390,
    1400,  1406,  1410,  1416,  1422,  1428,  1433,  1439,  1447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "str", "cha", "cadena", "entero",
  "decimal", "numero", "caracter", "boolean", "doble", "Id", "comparar",
  "diferencia", "menorQ", "menorIgual", "mayorQ", "mayorIgual", "Or",
  "And", "Nand", "Nor", "Not", "notificar", "caso", "suma", "resta",
  "multiplicacion", "division", "potencia", "parA", "parC", "final",
  "llaveA", "llaveC", "igual", "coma", "puntoComa", "arreglo", "corA",
  "corC", "si", "SinoSi", "sino", "comprobar", "salir", "defecto",
  "dosPunto", "para", "mientras", "repetir", "hacer", "romper",
  "continuar", "incluir", "imprimir", "archivo", "crearDer",
  "crearConjunto", "crearRegex", "crearEntrada", "guardarA", "cuenta",
  "crearC", "verCuenta", "depCuenta", "resCuenta", "imprimirCuenta",
  "conCuenta", "transferir", "clase", "extender", "principal",
  "sobrescribir", "funcion", "publico", "privado", "protegido", "voide",
  "Retornar", "falso", "verdadero", "punto", "nuevo", "nonassoc",
  "$accept", "INICIO", "LISTA_INCLU", "CLASES", "CLASE", "EXTENDER",
  "HERENCIA", "LISTA_SENTENCIA", "CUERPO_CLASE", "VISIBILIDAD",
  "VAR_GLOBALES", "TIPO_DATO", "DEC_ID", "ASIGNACION", "ASIGNAR_VAR", "E",
  "IN_BOOL", "DECLARAR_OBJEC", "DECLAR_ARREGLO", "DIMENSION", "DIMENSION1",
  "DIMENSION2", "DIMENSION3", "TERMI1", "ARRAY1", "LISTA_NORMAL", "TERMI2",
  "LISTA2", "TERMI3", "LISTA3", "POR_ARREGLO", "REASIGNAR_ARREGLO",
  "START_SI", "OTRO_SI", "SINO_SI", "SINO", "START_PARA", "ACTUALIZAR",
  "INICIAR", "CUERPO_PARA", "START_REPETIR", "START_MIENTRAS",
  "START_HACER", "START_COMPROBAR", "CUERPO_COMPRO", "DEFAU", "LISTA_CASO",
  "START_INCLUIR", "START_IMPRIMIR", "SENTENCIA_ARCHIVOS", "ARCH",
  "NUEVO_CONJUNTO", "NUEVO_REGEX", "NUEVA_ENTRADA", "GUARDAR",
  "SENTENCIA_CUENTA", "CREAR_CUENTA", "VERIFICAR_CUENTA", "DEP_CUENTA",
  "RESTA_CUENTA", "IMPRI_CUENTA", "CONSUL_CUENTA", "TRANFERIR",
  "LISTA_GENERAL", "SENTENCIA_GENERAL", "NUEVO_OBJEC", "RETORNO",
  "METODO_FUNCION", "CUERPO_MF", "FUNCION_PARAMETRO", "PARAMETROS",
  "LISTA_PARAMETROS", "DIMENSION_N", "TIPO_F", "PRIMITIVO", "LLAMADA",
  "LISTA_VALORES", "PRINCIPAL", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    88,    89,    89,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    97,    98,    98,
      99,    99,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103,   104,   105,   105,   105,
     106,   107,   108,   109,   109,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   117,
     118,   119,   119,   119,   119,   120,   120,   121,   122,   123,
     123,   124,   124,   125,   126,   127,   128,   129,   130,   130,
     130,   131,   132,   132,   133,   134,   135,   135,   135,   135,
     135,   136,   137,   138,   139,   140,   141,   141,   141,   141,
     141,   141,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   152,   153,   153,   153,   153,   154,   155,
     155,   155,   156,   156,   157,   157,   158,   158,   158,   159,
     159,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   162,   162,   163
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     5,     3,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     2,     2,     3,     1,
       3,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     8,     3,     3,     2,     2,     2,
       3,     6,     9,     1,     3,     3,     3,     1,     1,     5,
       3,     1,     1,     5,     5,     3,     2,     2,     2,     4,
       7,     2,     3,     2,     1,     8,     7,     4,     8,     3,
       3,     1,     1,     3,     7,     7,     9,     7,     2,     1,
       1,     5,     7,     6,     5,     5,     1,     1,     1,     1,
       1,     8,     9,     9,     9,     6,     1,     1,     1,     1,
       1,     1,     1,    10,     6,     7,     7,     6,     6,     9,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     7,     2,     7,     6,     6,     5,     3,     2,
       4,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     7,     6,
       5,     4,     3,     6,     6,     3,     3,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     7,     5,     0,     0,
       1,     2,     4,     6,     0,    10,     0,     0,     0,    12,
       0,   185,   183,   186,   187,   184,     0,     0,     0,     0,
      23,    24,    25,     0,    14,     0,    15,     0,    18,    20,
      16,     0,    22,   114,     9,     0,     0,     0,     0,   181,
       0,     0,   182,     0,     0,   179,     8,    13,    17,    19,
      21,    31,     0,    26,    29,    27,    11,    65,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    56,    58,    59,    51,     0,     0,     0,    63,    62,
       0,    55,    52,    48,    49,    50,    53,     0,     0,     0,
      73,     0,    67,    78,     0,    68,    82,     0,    69,     0,
     198,   176,   177,   178,   180,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    54,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    28,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   147,   143,   145,     0,
     146,   149,   152,     0,   153,   151,   150,   154,   155,   156,
     116,   117,   118,   119,   120,   157,   126,   127,   128,   129,
     130,   131,   132,     0,   141,   144,     0,   159,     0,     0,
       0,     0,   173,     0,   175,     0,     0,   167,     0,   197,
       0,   192,     0,     0,     0,   195,    61,    42,    43,    44,
      45,    46,    47,    38,    39,    40,    41,    33,    34,    35,
      36,    37,     0,     0,    77,     0,    74,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,   161,     0,     0,     0,     0,   163,     0,   148,
     168,   140,   158,     0,   166,   165,   171,     0,   172,     0,
     169,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,     0,   174,   190,   196,     0,     0,
       0,     0,     0,     0,     0,    64,    71,    76,    79,    80,
      85,    83,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,   170,   189,     0,   193,   134,   137,   138,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,     0,
     188,     0,    84,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,   110,   109,     0,     0,     0,     0,
       0,     0,     0,     0,    72,   162,     0,     0,     0,   135,
     136,    94,    90,     0,     0,   107,     0,   108,     0,   105,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    93,     0,     0,     0,     0,    98,     0,   121,     0,
       0,   122,   123,   124,     0,     0,     0,    92,     0,     0,
       0,     0,   106,     0,   139,     0,     0,     0,     0,   111,
       0,   103,   133,     0,    97,     0,   113,     0,     0,     0,
     112,     0,     0,    96,     0,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    17,    20,    33,    34,    35,
     165,    37,    65,    63,   166,   209,    91,   167,   168,    70,
     122,   123,   124,   102,   237,   235,   105,   238,   108,   240,
      92,   170,   171,   412,   430,   431,   172,   173,   304,   436,
     174,   175,   176,   177,   393,   394,   395,     7,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    93,   188,   189,
      94,    95,   192,   193,   194,   195,   196,    40,   110,   204,
     119,   205,   114,    54,    41,    96,   210,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -241
static const yytype_int16 yypact[] =
{
      55,     8,    42,    81,    55,    76,  -241,  -241,    52,   -23,
    -241,    76,  -241,  -241,    96,  -241,   123,   643,   126,  -241,
      11,  -241,  -241,  -241,  -241,  -241,   152,   132,   134,   146,
    -241,  -241,  -241,   414,  -241,   596,  -241,   139,  -241,  -241,
    -241,   166,  -241,  -241,  -241,   170,   140,   148,   157,  -241,
     132,   517,  -241,    53,   191,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,   294,  -241,  -241,   189,  -241,  -241,   149,   294,
    -241,   144,   161,   168,   196,   148,    53,   225,   228,   205,
    -241,  -241,  -241,  -241,     4,   294,   294,   294,  -241,  -241,
    1409,  -241,  -241,  -241,  -241,  -241,  -241,   229,   235,  1255,
    -241,   214,  -241,  -241,   218,  -241,  -241,   221,  -241,  1141,
    -241,  -241,  -241,  -241,  -241,   244,   205,   205,   501,   196,
     117,    85,  -241,  -241,  -241,   880,   179,  1535,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,  -241,  -241,   240,   220,   294,   233,   214,
     248,    20,   252,   253,   255,   257,   258,   261,   259,   267,
     260,   292,   293,   277,   294,  -241,  -241,  -241,  -241,   274,
    -241,  -241,  -241,   278,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,   580,  -241,  -241,   285,  -241,   205,   196,
     196,   307,  -241,   132,  -241,    61,   308,  -241,   303,  1875,
      90,    64,   295,   306,   311,   312,  -241,   305,   305,   305,
     305,   305,   305,   748,   880,   880,   748,   179,   179,   309,
     309,  -241,   315,   294,  1875,   181,  -241,  -241,   192,   214,
     209,   318,   322,    30,   101,   294,   294,   382,   294,   294,
    1141,  -241,  -241,   294,   314,   316,   344,  1875,   294,  -241,
    -241,  -241,  -241,   196,  -241,  -241,  -241,   345,  -241,   698,
    -241,  -241,   325,   294,   231,   294,   327,   330,   332,   294,
     335,  1273,  -241,   294,   338,   214,   216,   339,   331,  -241,
    -241,   366,  1430,   348,   352,   353,   354,   355,   358,  1555,
    1575,   360,  -241,  -241,   294,  1595,  1615,   635,  1635,   342,
     337,   365,  1451,  -241,   148,  -241,  -241,  1875,   370,    99,
    1472,   371,   374,   375,  1493,  -241,   369,  1875,  -241,  -241,
    -241,  -241,   214,   380,  -241,   294,   294,   294,   381,   294,
     294,   378,   384,   294,  1514,   388,   393,   379,   383,   397,
     399,   403,  -241,  -241,  -241,   398,  -241,  -241,  -241,  -241,
    -241,   294,   224,   402,  1309,  1334,  1359,   404,  1655,  1675,
    1141,     3,   424,  1141,  1141,   407,  -241,   294,   294,   406,
    -241,  1291,  -241,   408,   294,   294,   294,  -241,   411,   413,
     690,   294,   416,   412,  -241,    59,    -5,   422,   745,   800,
     294,  1695,  1384,   294,  -241,  -241,  1715,  1735,  1755,  -241,
    -241,    47,  -241,  1209,  1141,  -241,   294,  -241,   425,  -241,
    -241,  1775,   428,   294,  1795,   429,   432,   433,   438,   436,
      75,  -241,  1141,   822,  1232,  1141,  -241,   449,  -241,  1815,
     452,  -241,  -241,  -241,   294,  1141,   455,  -241,   877,   461,
    1141,   932,  -241,   462,  -241,  1835,   987,   294,   463,  -241,
    1009,  -241,  -241,   454,  -241,  1855,  -241,   464,  1141,   465,
    -241,  1064,  1141,  -241,  1119,  -241
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,  -241,   494,    25,  -241,  -241,  -241,   470,    57,
     -16,   477,  -241,  -241,   268,   -62,  -241,    72,    82,  -241,
     -44,   -35,   -34,  -241,   -95,  -241,  -241,  -231,  -241,  -241,
    -105,  -241,  -241,  -241,  -241,    84,  -241,   133,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,   121,  -241,   514,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,     0,  -241,  -241,
       7,   103,  -241,  -240,  -184,  -241,  -241,  -241,  -117,   250,
    -102,  -241,   206,   -33,   -24,   110,   247,  -241
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      90,    36,   207,    71,   169,    55,   148,    99,   286,   261,
     307,    15,    72,    73,   199,   200,   215,    36,    77,    58,
      78,   241,   242,   125,   126,   127,    75,    55,   391,    55,
      13,   111,    46,    80,    81,   120,    13,    82,    83,     8,
     112,   113,    84,   115,    69,    44,   241,   242,    45,    16,
     392,   120,    55,    85,     9,    14,   243,    86,    21,    22,
      69,    87,    23,    24,    25,    49,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,    10,   264,   265,   416,   234,    53,   121,   169,    38,
     428,   429,    50,   268,   206,   274,   263,   211,   269,    39,
     275,   362,   257,   244,    69,    38,   392,    59,    76,   187,
       1,    88,    89,   211,   291,    39,   190,    60,   446,   429,
      80,    81,   272,   261,    82,    83,     2,   273,    18,    84,
     390,   355,    52,   398,   399,    19,   273,    21,    22,   215,
      85,    23,    24,    25,    86,   169,   313,     2,    87,   208,
     212,    21,    22,   213,   214,    23,    24,    25,    49,    43,
     293,   294,   295,   296,    46,    48,   212,   297,   298,   213,
     214,   281,    61,    67,   433,    62,    68,   100,    64,   267,
     101,   292,    66,   299,   300,    50,   305,   306,    69,    74,
     329,   308,   448,   187,   103,   451,   312,   104,    88,    89,
     190,   106,   169,    79,   107,   456,   261,   140,   141,   142,
     460,   317,   191,   320,   261,   261,   282,   324,   283,   197,
      51,   327,    30,    31,    32,    52,    97,   284,   471,   285,
     109,   302,   474,    98,    80,    81,   118,   116,    82,    83,
     117,   144,   344,    84,   287,   206,   288,   145,   147,   261,
     187,   330,   149,   285,    85,   150,   198,   190,    86,   382,
     233,   285,    87,   318,   261,   169,   236,   261,   169,   169,
     111,   232,   261,   364,   365,   366,   261,   368,   369,   112,
     113,   292,   239,   245,   246,   169,   247,   261,   248,   249,
     261,   253,   251,   169,   169,   250,   191,    80,    81,   381,
     252,    82,    83,   197,   254,   255,    84,   187,   256,   169,
     258,   259,    88,    89,   190,   401,   402,    85,   262,   266,
     270,    86,   406,   407,   408,    87,   276,   169,   169,   413,
     169,   138,   139,   140,   141,   142,   271,   277,   421,   142,
     169,   424,   278,   169,   289,   169,   169,   280,   279,   290,
     309,   169,   310,   191,   434,   169,   311,   314,   316,   321,
     197,   439,   322,   169,   323,   332,   169,   169,   325,   169,
     187,   328,   331,   187,   187,    88,    89,   190,   333,   335,
     190,   190,   455,   336,   337,   338,   339,    21,    22,   340,
     187,    23,    24,    25,   301,   465,   343,   190,   187,   187,
     349,   350,   351,   354,   357,   190,   190,   358,   359,   361,
     191,   363,   370,   367,   187,   379,   376,   197,   371,    21,
      22,   190,   373,    23,    24,    25,    26,   374,   377,   375,
     378,   380,   187,   187,   383,   187,   396,   387,   400,   190,
     190,   405,   190,   403,   409,   187,   410,   415,   187,    56,
     187,   187,   190,    27,   418,   190,   187,   190,   190,   435,
     187,   438,   441,   190,   414,   442,   443,   190,   187,   444,
     445,   187,   187,   191,   187,   190,   191,   191,   190,   190,
     197,   190,   452,   197,   197,   454,   457,    28,   468,    29,
      30,    31,    32,   191,   459,   462,   466,   470,    11,   472,
     197,   191,   191,    57,    47,   397,    21,    22,   197,   197,
      23,    24,    25,   201,   447,   303,   417,   191,    12,   315,
     353,   319,    21,    22,   197,     0,    23,    24,    25,    49,
       0,     0,     0,   202,     0,   191,   191,     0,   191,     0,
     203,     0,   197,   197,     0,   197,     0,     0,   191,     0,
       0,   191,     0,   191,   191,   197,    50,     0,   197,   191,
     197,   197,     0,   191,     0,     0,   197,     0,     0,     0,
     197,   191,     0,     0,   191,   191,     0,   191,   197,     0,
       0,   197,   197,     0,   197,    21,    22,     0,     0,    23,
      24,    25,   151,    30,    31,    32,    52,     0,     0,     0,
       0,    21,    22,     0,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,    27,
       0,     0,   152,     0,     0,   153,     0,     0,     0,   154,
     155,   156,   157,   158,   159,    27,   160,   161,     0,     0,
      21,    22,     0,   162,    23,    24,    25,   151,    21,    22,
     163,     0,    23,    24,    25,    26,     0,     0,     0,     0,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     347,     0,     0,     0,    27,     0,     0,   152,     0,     0,
     153,     0,    27,     0,   154,   155,   156,   157,   158,   159,
       0,   160,   161,     0,     0,    21,    22,     0,   162,    23,
      24,    25,   151,    21,    22,   163,     0,    23,    24,    25,
     201,     0,     0,     0,     0,   164,    28,     0,    29,    30,
      31,    32,     0,     0,     0,   411,     0,     0,     0,    27,
       0,     0,   152,     0,     0,   153,     0,   203,     0,   154,
     155,   156,   157,   158,   159,     0,   160,   161,     0,     0,
      21,    22,     0,   162,    23,    24,    25,   151,     0,     0,
     163,   128,   129,   130,   131,   132,   133,     0,   135,   136,
     164,     0,     0,     0,   138,   139,   140,   141,   142,     0,
     419,     0,     0,     0,    27,     0,     0,   152,     0,     0,
     153,     0,     0,     0,   154,   155,   156,   157,   158,   159,
       0,   160,   161,     0,     0,    21,    22,     0,   162,    23,
      24,    25,   151,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,    21,    22,     0,
       0,    23,    24,    25,   151,   420,     0,     0,     0,    27,
       0,     0,   152,     0,     0,   153,     0,     0,     0,   154,
     155,   156,   157,   158,   159,     0,   160,   161,     0,     0,
       0,    27,     0,   162,   152,     0,     0,   153,   449,     0,
     163,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     164,     0,    21,    22,     0,   162,    23,    24,    25,   151,
       0,     0,   163,   128,   129,   130,   131,   132,   133,     0,
       0,     0,   164,     0,     0,     0,   138,   139,   140,   141,
     142,     0,     0,     0,     0,     0,    27,     0,     0,   152,
       0,     0,   153,   458,     0,     0,   154,   155,   156,   157,
     158,   159,     0,   160,   161,     0,     0,    21,    22,     0,
     162,    23,    24,    25,   151,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
       0,    27,     0,     0,   152,     0,     0,   153,     0,     0,
       0,   154,   155,   156,   157,   158,   159,     0,   160,   161,
       0,     0,    21,    22,     0,   162,    23,    24,    25,   151,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,    21,    22,     0,     0,    23,    24,
      25,   151,   464,     0,     0,     0,    27,     0,     0,   152,
       0,     0,   153,     0,     0,     0,   154,   155,   156,   157,
     158,   159,     0,   160,   161,     0,     0,     0,    27,     0,
     162,   152,     0,     0,   153,   467,     0,   163,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   164,     0,    21,
      22,     0,   162,    23,    24,    25,   151,     0,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
       0,     0,     0,    27,     0,     0,   152,     0,     0,   153,
       0,     0,     0,   154,   155,   156,   157,   158,   159,     0,
     160,   161,     0,     0,    21,    22,     0,   162,    23,    24,
      25,   151,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,    21,    22,     0,     0,
      23,    24,    25,   151,   475,     0,     0,     0,    27,     0,
       0,   152,     0,     0,   153,     0,     0,     0,   154,   155,
     156,   157,   158,   159,     0,   160,   161,     0,     0,     0,
      27,     0,   162,   152,     0,     0,   153,     0,     0,   163,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   164,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,   432,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
     450,   138,   139,   140,   141,   142,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   146,     0,     0,   138,
     139,   140,   141,   142,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   326,     0,     0,   138,   139,   140,
     141,   142,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   404,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,   384,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,   140,   141,   142,     0,     0,     0,     0,     0,
       0,   385,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,   386,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,   140,   141,   142,     0,     0,     0,     0,     0,
       0,   423,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,   143,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,   140,   141,
     142,     0,     0,   334,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,   352,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
     140,   141,   142,     0,     0,   356,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,   138,
     139,   140,   141,   142,     0,     0,   360,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,   140,   141,   142,     0,     0,   372,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   216,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   341,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   342,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   345,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   346,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   348,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   388,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   389,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   422,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   425,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   426,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   427,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   437,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   440,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   453,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   463,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142,     0,   469,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,   140,   141,   142
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-241)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      62,    17,   119,    47,   109,    29,   101,    69,   239,   193,
     250,    34,    47,    47,   116,   117,   121,    33,    51,    35,
      53,    26,    27,    85,    86,    87,    50,    51,    25,    53,
       5,    75,    12,     3,     4,    31,    11,     7,     8,    31,
      75,    75,    12,    76,    40,    34,    26,    27,    37,    72,
      47,    31,    76,    23,    12,     3,    36,    27,     5,     6,
      40,    31,     9,    10,    11,    12,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   199,   200,    25,   147,    29,    83,   193,    17,
      43,    44,    39,    32,   118,    31,   198,    12,    37,    17,
      36,   332,   164,    83,    40,    33,    47,    35,    51,   109,
      55,    81,    82,    12,    84,    33,   109,    35,    43,    44,
       3,     4,    32,   307,     7,     8,    71,    37,    32,    12,
     370,    32,    79,   373,   374,    12,    37,     5,     6,   244,
      23,     9,    10,    11,    27,   250,   263,    71,    31,    32,
      65,     5,     6,    68,    69,     9,    10,    11,    12,    33,
      59,    60,    61,    62,    12,    31,    65,    66,    67,    68,
      69,   233,    33,    33,   414,    36,    36,    33,    12,   203,
      36,   243,    12,   245,   246,    39,   248,   249,    40,    32,
     285,   253,   432,   193,    33,   435,   258,    36,    81,    82,
     193,    33,   307,    12,    36,   445,   390,    28,    29,    30,
     450,   273,   109,   275,   398,   399,    35,   279,    37,   109,
      74,   283,    76,    77,    78,    79,    37,    35,   468,    37,
      34,   247,   472,    84,     3,     4,    31,    12,     7,     8,
      12,    12,   304,    12,    35,   269,    37,    12,    34,   433,
     250,    35,    34,    37,    23,    34,    12,   250,    27,    35,
      40,    37,    31,    32,   448,   370,    33,   451,   373,   374,
     314,    31,   456,   335,   336,   337,   460,   339,   340,   314,
     314,   343,    34,    31,    31,   390,    31,   471,    31,    31,
     474,    31,    33,   398,   399,    34,   193,     3,     4,   361,
      33,     7,     8,   193,    12,    12,    12,   307,    31,   414,
      36,    33,    81,    82,   307,   377,   378,    23,    33,    12,
      12,    27,   384,   385,   386,    31,    31,   432,   433,   391,
     435,    26,    27,    28,    29,    30,    33,    31,   400,    30,
     445,   403,    31,   448,    26,   450,   451,    32,    36,    27,
      36,   456,    36,   250,   416,   460,    12,    12,    33,    32,
     250,   423,    32,   468,    32,    34,   471,   472,    33,   474,
     370,    33,    33,   373,   374,    81,    82,   370,    12,    31,
     373,   374,   444,    31,    31,    31,    31,     5,     6,    31,
     390,     9,    10,    11,    12,   457,    36,   390,   398,   399,
      58,    64,    37,    33,    33,   398,   399,    33,    33,    40,
     307,    31,    34,    32,   414,    12,    33,   307,    34,     5,
       6,   414,    34,     9,    10,    11,    12,    34,    31,    50,
      31,    33,   432,   433,    32,   435,    12,    33,    31,   432,
     433,    33,   435,    37,    33,   445,    33,    35,   448,    35,
     450,   451,   445,    39,    32,   448,   456,   450,   451,    34,
     460,    33,    33,   456,    48,    33,    33,   460,   468,    31,
      34,   471,   472,   370,   474,   468,   373,   374,   471,   472,
     370,   474,    33,   373,   374,    33,    31,    73,    34,    75,
      76,    77,    78,   390,    33,    33,    33,    33,     4,    34,
     390,   398,   399,    33,    27,   372,     5,     6,   398,   399,
       9,    10,    11,    12,   430,   247,   395,   414,     4,   269,
     314,   274,     5,     6,   414,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    32,    -1,   432,   433,    -1,   435,    -1,
      39,    -1,   432,   433,    -1,   435,    -1,    -1,   445,    -1,
      -1,   448,    -1,   450,   451,   445,    39,    -1,   448,   456,
     450,   451,    -1,   460,    -1,    -1,   456,    -1,    -1,    -1,
     460,   468,    -1,    -1,   471,   472,    -1,   474,   468,    -1,
      -1,   471,   472,    -1,   474,     5,     6,    -1,    -1,     9,
      10,    11,    12,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    39,    56,    57,    -1,    -1,
       5,     6,    -1,    63,     9,    10,    11,    12,     5,     6,
      70,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      45,    -1,    39,    -1,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    -1,     5,     6,    -1,    63,     9,
      10,    11,    12,     5,     6,    70,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    80,    73,    -1,    75,    76,
      77,    78,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    45,    -1,    39,    -1,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    -1,
       5,     6,    -1,    63,     9,    10,    11,    12,    -1,    -1,
      70,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      80,    -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      35,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    -1,     5,     6,    -1,    63,     9,
      10,    11,    12,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,     5,     6,    -1,
      -1,     9,    10,    11,    12,    35,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    -1,
      -1,    39,    -1,    63,    42,    -1,    -1,    45,    46,    -1,
      70,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      80,    -1,     5,     6,    -1,    63,     9,    10,    11,    12,
      -1,    -1,    70,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    -1,     5,     6,    -1,
      63,     9,    10,    11,    12,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      -1,    -1,     5,     6,    -1,    63,     9,    10,    11,    12,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,    -1,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    39,    -1,
      63,    42,    -1,    -1,    45,    46,    -1,    70,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    80,    -1,     5,
       6,    -1,    63,     9,    10,    11,    12,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    -1,    -1,     5,     6,    -1,    63,     9,    10,
      11,    12,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    35,    -1,    -1,    -1,    39,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      39,    -1,    63,    42,    -1,    -1,    45,    -1,    -1,    70,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    80,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    48,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      48,    26,    27,    28,    29,    30,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    41,    -1,    -1,    26,
      27,    28,    29,    30,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    41,    -1,    -1,    26,    27,    28,
      29,    30,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    41,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    33,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    -1,    33,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    -1,    33,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    33,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    -1,    33,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    33,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    71,    87,    88,    89,    90,   133,    31,    12,
       0,    89,   133,    90,     3,    34,    72,    91,    32,    12,
      92,     5,     6,     9,    10,    11,    12,    39,    73,    75,
      76,    77,    78,    93,    94,    95,    96,    97,   103,   104,
     153,   160,   163,    33,    34,    37,    12,    97,    31,    12,
      39,    74,    79,    95,   159,   160,    35,    94,    96,   103,
     104,    33,    36,    99,    12,    98,    12,    33,    36,    40,
     105,   106,   107,   108,    32,   160,    95,   159,   159,    12,
       3,     4,     7,     8,    12,    23,    27,    31,    81,    82,
     101,   102,   116,   143,   146,   147,   161,    37,    84,   101,
      33,    36,   109,    33,    36,   112,    33,    36,   114,    34,
     154,   106,   107,   108,   158,   159,    12,    12,    31,   156,
      31,    83,   106,   107,   108,   101,   101,   101,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    26,    27,
      28,    29,    30,    33,    12,    12,    41,    34,   110,    34,
      34,    12,    42,    45,    49,    50,    51,    52,    53,    54,
      56,    57,    63,    70,    80,    96,   100,   103,   104,   116,
     117,   118,   122,   123,   126,   127,   128,   129,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   161,    12,   156,
     156,    12,    32,    39,   155,   157,   160,   154,    32,   101,
     162,    12,    65,    68,    69,   116,    32,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,    31,    40,   101,   111,    33,   110,   113,    34,
     115,    26,    27,    36,    83,    31,    31,    31,    31,    31,
      34,    33,    33,    31,    12,    12,    31,   101,    36,    33,
      35,   150,    33,   156,   154,   154,    12,   160,    32,    37,
      12,    33,    32,    37,    31,    36,    31,    31,    31,    36,
      32,   101,    35,    37,    35,    37,   113,    35,    37,    26,
      27,    84,   101,    59,    60,    61,    62,    66,    67,   101,
     101,    12,    96,   100,   124,   101,   101,   149,   101,    36,
      36,    12,   101,   154,    12,   155,    33,   101,    32,   162,
     101,    32,    32,    32,   101,    33,    41,   101,    33,   110,
      35,    33,    34,    12,    33,    31,    31,    31,    31,    31,
      31,    32,    32,    36,   101,    32,    32,    35,    32,    58,
      64,    37,    33,   158,    33,    32,    33,    33,    33,    33,
      33,    40,   113,    31,   101,   101,   101,    32,   101,   101,
      34,    34,    33,    34,    34,    50,    33,    31,    31,    12,
      33,   101,    35,    32,    37,    37,    37,    33,    32,    32,
     149,    25,    47,   130,   131,   132,    12,   123,   149,   149,
      31,   101,   101,    37,    41,    33,   101,   101,   101,    33,
      33,    35,   119,   101,    48,    35,    25,   131,    32,    35,
      35,   101,    32,    37,   101,    32,    32,    32,    43,    44,
     120,   121,    48,   149,   101,    34,   125,    32,    33,   101,
      32,    33,    33,    33,    31,    34,    43,   121,   149,    46,
      48,   149,    33,    32,    33,   101,   149,    31,    46,    33,
     149,    35,    33,    32,    35,   101,    33,    46,    34,    32,
      33,   149,    34,    35,   149,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"INICIO","INICIO");
        raiz=(yyval.node);
        raiz->add(*(yyvsp[(1) - (2)].node));
        raiz->add(*(yyvsp[(2) - (2)].node));

        }
    break;

  case 3:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"INICIO","INICIO");
        raiz=(yyval.node);
        raiz->add(*(yyvsp[(1) - (1)].node));
        }
    break;

  case 4:

    {
            (yyval.node)=(yyvsp[(1) - (2)].node);
            (yyval.node)->add(*(yyvsp[(2) - (2)].node));
            }
    break;

  case 5:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LISTA_INCLU","LISTA_INCLU");
            (yyval.node)->add(*(yyvsp[(1) - (1)].node));
            }
    break;

  case 6:

    {
        (yyval.node)=(yyvsp[(1) - (2)].node);
        //NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
        //nodo->add(*$2);
        (yyval.node)->add(*(yyvsp[(2) - (2)].node));
}
    break;

  case 7:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"CLASES","CLASES");
       // NodoAST *nodo=new NodoAST(@1.first_line, @1.first_column,"CLASE","CLASE");
        //nodo->add(*$1);
        (yyval.node)->add(*(yyvsp[(1) - (1)].node));
}
    break;

  case 8:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column,"clase",(yyvsp[(2) - (5)].TEXT));
        //AUN NO SE COMO MANEJAR LOS EXTENDER


        (yyval.node)->add(*(yyvsp[(3) - (5)].node));// HERENCIA O sin_herencia

        (yyval.node)->add(*(yyvsp[(4) - (5)].node));//le asigno la lista sentencias

        }
    break;

  case 9:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);
          }
    break;

  case 10:

    {
          (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"sin_herencia","sin_herencia");
          }
    break;

  case 11:

    {
            (yyval.node)=(yyvsp[(1) - (3)].node);
            NodoAST *ide=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(3) - (3)].TEXT));
            (yyval.node)->add(*ide);
          }
    break;

  case 12:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"HERENCIA","HERENCIA");
            NodoAST *ide=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"Id",(yyvsp[(1) - (1)].TEXT));
            (yyval.node)->add(*ide);
          }
    break;

  case 13:

    {
                 (yyval.node)=(yyvsp[(1) - (2)].node);
                 (yyval.node)->add(*(yyvsp[(2) - (2)].node));
                 }
    break;

  case 14:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LISTA_SENTENCIA","LISTA_SENTENCIA");
                  (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                  }
    break;

  case 15:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"VARIABLE","VARIABLE");
                NodoAST *nodo=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"publico","publico");
               // nodo->add(*$1);
                (yyval.node)->add(*nodo);
                (yyval.node)->add(*(yyvsp[(1) - (1)].node));

              }
    break;

  case 16:

    {

              (yyval.node)=(yyvsp[(1) - (1)].node);
              }
    break;

  case 17:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"VARIABLE","VARIABLE");
              (yyval.node)->add(*(yyvsp[(1) - (2)].node));
              (yyval.node)->add(*(yyvsp[(2) - (2)].node));
              }
    break;

  case 18:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"OBJETO","OBJETO");
              NodoAST *nodo=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"publico","publico");
              (yyval.node)->add(*nodo);
              (yyval.node)->add(*(yyvsp[(1) - (1)].node));

              }
    break;

  case 19:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"OBJETO","OBJETO");
              (yyval.node)->add(*(yyvsp[(1) - (2)].node));
              (yyval.node)->add(*(yyvsp[(2) - (2)].node));
              }
    break;

  case 20:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"ARREGLO","ARREGLO");
              NodoAST *nodo =new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"publico","publico");
              (yyval.node)->add(*nodo);
              (yyval.node)->add(*(yyvsp[(1) - (1)].node));
              }
    break;

  case 21:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"ARREGLO","ARREGLO");
              (yyvsp[(1) - (2)].node)->add(*(yyvsp[(1) - (2)].node));//visibilidad
              (yyval.node)->add(*(yyvsp[(2) - (2)].node));//datos
              }
    break;

  case 22:

    {

                (yyval.node)=(yyvsp[(1) - (1)].node);
              }
    break;

  case 23:

    {
             (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"publico","publico");
             }
    break;

  case 24:

    {
             (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"privado","privado");
             }
    break;

  case 25:

    {
             (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"protegido","protegido");
              }
    break;

  case 26:

    {
               (yyval.node)=(yyvsp[(1) - (2)].node);
               //NodoAST *node=new NodoAST(@1.first_line,@1.first_column,"ASIGNACION","ASIGNACION");
               //node->add(*$2);
               (yyval.node)->add(*(yyvsp[(2) - (2)].node));
            }
    break;

  case 27:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"TIPO_DATO","TIPO_DATO");
            (yyval.node)->add(*(yyvsp[(1) - (2)].node));
            (yyval.node)->add(*(yyvsp[(2) - (2)].node));
            }
    break;

  case 28:

    {
        //DEC_ID ES UNA LISTA DE IDS
        (yyval.node)=(yyvsp[(1) - (3)].node);
        NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(3) - (3)].TEXT));
        (yyval.node)->add(*nodo);
        }
    break;

  case 29:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"DEC_ID","DEC_ID");
        NodoAST *nodo=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"Id",(yyvsp[(1) - (1)].TEXT));
        (yyval.node)->add(*nodo);
        }
    break;

  case 30:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"operacion","operacion");

            (yyval.node)->add(*(yyvsp[(2) - (3)].node));
            }
    break;

  case 31:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"final",(yyvsp[(1) - (1)].TEXT));
            }
    break;

  case 32:

    {
               (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,"operacion","operacion");
               NodoAST *nodo=new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,"Id",(yyvsp[(1) - (4)].TEXT));
               (yyval.node)->add(*nodo);
               (yyval.node)->add(*(yyvsp[(3) - (4)].node));//guarda

            }
    break;

  case 33:

    {
            NodoAST *nodo =new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"suma",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
       }
    break;

  case 34:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"resta",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
       }
    break;

  case 35:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"multiplicacion",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
       }
    break;

  case 36:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"division",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
       }
    break;

  case 37:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"potencia",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 38:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Or",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;

        }
    break;

  case 39:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"And",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
       }
    break;

  case 40:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Nand",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;

        }
    break;

  case 41:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Nor",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 42:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"comparar",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 43:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"diferencia",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 44:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"menorQ",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 45:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"menorIgual",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 46:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"mayorQ",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;
        }
    break;

  case 47:

    {
            NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"mayorIgual",(yyvsp[(2) - (3)].TEXT));
            nodo->add(*(yyvsp[(1) - (3)].node));
            nodo->add(*(yyvsp[(3) - (3)].node));
            (yyval.node)=nodo;

       }
    break;

  case 48:

    {
          (yyval.node)=(yyvsp[(1) - (1)].node);
       }
    break;

  case 49:

    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
       }
    break;

  case 50:

    {
            (yyval.node)=(yyvsp[(1) - (1)].node);
       }
    break;

  case 51:

    {
           (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"Id",(yyvsp[(1) - (1)].TEXT));

       }
    break;

  case 52:

    {
            NodoAST *node=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"POR_ARREGLO","POR_ARREGLO");
            node->add(*(yyvsp[(1) - (1)].node));   
            (yyval.node)=node;
        }
    break;

  case 53:

    {//va a devolver externa_F_v, Local_F_V, etc
            NodoAST *node =new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LLAMADA_FUNCION","LLAMADA_FUNCION");
            node->add(*(yyvsp[(1) - (1)].node));
            (yyval.node)=node;
       }
    break;

  case 54:

    {
             NodoAST *nodo=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"Not",(yyvsp[(1) - (2)].TEXT));
             nodo->add(*(yyvsp[(2) - (2)].node));
             (yyval.node)=nodo;
        }
    break;

  case 55:

    {
        (yyval.node)=(yyvsp[(1) - (1)].node);
       }
    break;

  case 56:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"cha",(yyvsp[(1) - (1)].TEXT));
       }
    break;

  case 57:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"str",(yyvsp[(1) - (1)].TEXT));
       }
    break;

  case 58:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"decimal",(yyvsp[(1) - (1)].TEXT));
       }
    break;

  case 59:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"numero",(yyvsp[(1) - (1)].TEXT));
       }
    break;

  case 60:

    {
          NodoAST *nega=new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"negativo",(yyvsp[(1) - (2)].TEXT));
          nega->add(*(yyvsp[(2) - (2)].node));
          (yyval.node)=nega;
       }
    break;

  case 61:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);
        }
    break;

  case 62:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"verdadero",(yyvsp[(1) - (1)].TEXT));
         }
    break;

  case 63:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"falso",(yyvsp[(1) - (1)].TEXT));
         }
    break;

  case 64:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (8)]).first_line,(yylsp[(1) - (8)]).first_column,"nuevo_objeto","nuevo_objeto");

                    NodoAST *nodo=new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,"Id",(yyvsp[(1) - (8)].TEXT));//clase
                    NodoAST *nodo1=new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,"Id",(yyvsp[(2) - (8)].TEXT));//objeto
                    //NodoAST *nodo2=new NodoAST(@1.first_line, @1.first_column,"clase",$5);
                    (yyval.node)->add(*nodo);
                    (yyval.node)->add(*nodo1);


                }
    break;

  case 65:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"No_Inicial","No_Inicial");
                  NodoAST *nodo=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(1) - (3)].TEXT));//clase
                  NodoAST *nodo1=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(2) - (3)].TEXT));//objeto
                  (yyval.node)->add(*nodo);
                  (yyval.node)->add(*nodo1);
                }
    break;

  case 66:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"arreglo","arreglo");
                (yyval.node)->add(*(yyvsp[(2) - (3)].node));//primitivo y ids
                (yyval.node)->add(*(yyvsp[(3) - (3)].node));//dimensiones y se inicia

                }
    break;

  case 67:

    {
                (yyval.node)=(yyvsp[(1) - (2)].node);
                (yyval.node)->add(*(yyvsp[(2) - (2)].node));
            }
    break;

  case 68:

    {
                (yyval.node)=(yyvsp[(1) - (2)].node);
                (yyval.node)->add(*(yyvsp[(2) - (2)].node));

            }
    break;

  case 69:

    {
                (yyval.node)=(yyvsp[(1) - (2)].node);
                (yyval.node)->add(*(yyvsp[(2) - (2)].node));
            }
    break;

  case 70:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"DIMENSION1","DIMENSION1");
            (yyval.node)->add(*(yyvsp[(2) - (3)].node));
                   }
    break;

  case 71:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"DIMENSION2","DIMENSION2");
            (yyval.node)->add(*(yyvsp[(2) - (6)].node));
            (yyval.node)->add(*(yyvsp[(5) - (6)].node));
                   }
    break;

  case 72:

    {
                        (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column,"DIMENSION3","DIMENSION3");
                (yyval.node)->add(*(yyvsp[(2) - (9)].node));
                (yyval.node)->add(*(yyvsp[(5) - (9)].node));
                (yyval.node)->add(*(yyvsp[(8) - (9)].node));
                      }
    break;

  case 73:

    {
         (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"final","final");
        }
    break;

  case 74:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);//lista normal
        }
    break;

  case 75:

    {
        (yyval.node)=(yyvsp[(2) - (3)].node);
        }
    break;

  case 76:

    {
        (yyval.node)=(yyvsp[(1) - (3)].node);
        (yyval.node)->add(*(yyvsp[(3) - (3)].node));
        }
    break;

  case 77:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LISTA_NORMAL","LISTA_NORMAL");
        (yyval.node)->add(*(yyvsp[(1) - (1)].node));
        }
    break;

  case 78:

    {
         (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"final","final");
         }
    break;

  case 79:

    {
            (yyval.node)=(yyvsp[(3) - (5)].node);//Lista 2
         }
    break;

  case 80:

    {
        (yyval.node)=(yyvsp[(1) - (3)].node);//Lista 2
        (yyval.node)->add(*(yyvsp[(3) - (3)].node));//ingreso objeto de lista 2
        }
    break;

  case 81:

    {
         (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LISTA2","LISTA2");
         (yyval.node)->add(*(yyvsp[(1) - (1)].node)); //devuelve objeto lista normal
        }
    break;

  case 82:

    {
         (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"final","final");
         }
    break;

  case 83:

    {
            (yyval.node)=(yyvsp[(3) - (5)].node);
         }
    break;

  case 84:

    {
         (yyval.node)=(yyvsp[(1) - (5)].node);
         (yyval.node)->add(*(yyvsp[(4) - (5)].node));//devuelve objeto de lista 2
         }
    break;

  case 85:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"LISTA3","LISTA3");
            (yyval.node)->add(*(yyvsp[(2) - (3)].node));//devuelve objeto de lista 2
        }
    break;

  case 86:

    {
                (yyval.node)=(yyvsp[(2) - (2)].node);
                NodoAST *node =new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(1) - (2)].TEXT));
                (yyval.node)->add(*node);
               // $$->add(*$2);//si es dimen1,dimen2 o dimen3

              }
    break;

  case 87:

    {
                (yyval.node)=(yyvsp[(2) - (2)].node);
                NodoAST *node =new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(1) - (2)].TEXT));
                (yyval.node)->add(*node);
                //$$->add(*$2);

              }
    break;

  case 88:

    {
                (yyval.node)=(yyvsp[(2) - (2)].node);
                NodoAST *node =new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(1) - (2)].TEXT));
                (yyval.node)->add(*node);
                //$$->add(*$2);
              }
    break;

  case 89:

    {
                        (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,"REASIGNAR_ARREGLO","REASIGNAR_ARREGLO");
                        (yyval.node)->add(*(yyvsp[(1) - (4)].node));
                        (yyval.node)->add(*(yyvsp[(3) - (4)].node));
                    }
    break;

  case 90:

    {
            //OTRO_SI PUEDE ESTAR VACIO O PUEDE TENER OTRO SI Y A LA VEZ SINO
            (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"START_SI","START_SI");
            (yyval.node)->add(*(yyvsp[(3) - (7)].node));//enlazo con la condicion
            (yyval.node)->add(*(yyvsp[(6) - (7)].node));//enlazo con las sentencias
            (yyval.node)->add(*(yyvsp[(7) - (7)].node));//enalzo con ListaSI,
          }
    break;

  case 91:

    {
            (yyval.node)=(yyvsp[(2) - (2)].node);
           //recibo padre como Lista_SI
        }
    break;

  case 92:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);//recibo como Padre Lista_Si
            (yyval.node)->add(*(yyvsp[(3) - (3)].node));//enlace con sino
         }
    break;

  case 93:

    {

            (yyval.node)=(yyvsp[(2) - (2)].node);//enlazo con la sino

         }
    break;

  case 94:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"FIN_SI","FIN_SI");//solo viene un si

         }
    break;

  case 95:

    {
            (yyval.node)=(yyvsp[(1) - (8)].node);//recibo Lista_si

            NodoAST *nodo=new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,"SinoSi",(yyvsp[(2) - (8)].TEXT));//creacion de sinosi

            nodo->add(*(yyvsp[(4) - (8)].node));
            nodo->add(*(yyvsp[(7) - (8)].node));
            (yyval.node)->add(*nodo);

         }
    break;

  case 96:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"LISTA_SI","LISTA_SI");//creacion de la lista si
            NodoAST *nodo=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"SinoSi",(yyvsp[(1) - (7)].TEXT));//creacion de sinoSI

            nodo->add(*(yyvsp[(3) - (7)].node));//condicion
            nodo->add(*(yyvsp[(6) - (7)].node));//Lista sentencia
            (yyval.node)->add(*nodo);//enlazo Lista_SI a sinosi
         }
    break;

  case 97:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,"sino","sino");//sino,
            (yyval.node)->add(*(yyvsp[(3) - (4)].node));//enlazo sino con la ->condicion
       }
    break;

  case 98:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,"START_PARA","START_PARA");
                (yyval.node)->add(*(yyvsp[(3) - (8)].node));
                //NodoAST *no=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                (yyval.node)->add(*(yyvsp[(4) - (8)].node));
                //$$->add(*no);
                (yyval.node)->add(*(yyvsp[(6) - (8)].node));
                (yyval.node)->add(*(yyvsp[(8) - (8)].node));

            }
    break;

  case 99:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"actualizar",(yyvsp[(2) - (3)].TEXT));
            NodoAST *node=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(1) - (3)].TEXT));
            (yyval.node)->add(*node);


            }
    break;

  case 100:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"actualizar",(yyvsp[(2) - (3)].TEXT));
            NodoAST *node=new NodoAST((yylsp[(1) - (3)]).first_line,(yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(1) - (3)].TEXT));

            (yyval.node)->add(*node);


           }
    break;

  case 101:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"VAR_GLOBALES","VAR_GLOBALES");
            (yyval.node)->add(*(yyvsp[(1) - (1)].node));
         }
    break;

  case 102:

    {
               (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"ASIGNAR_VAR","ASIGNAR_VAR");
            (yyval.node)->add(*(yyvsp[(1) - (1)].node));
          }
    break;

  case 103:

    {
                 //  $$=new NodoAST(@1.first_line, @1.first_column,"CUERPO_PARA","CUERPO_PARA");
                   (yyval.node)=(yyvsp[(2) - (3)].node);

            }
    break;

  case 104:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"START_REPETIR","START_REPETIR");

                (yyval.node)->add(*(yyvsp[(3) - (7)].node));
                (yyval.node)->add(*(yyvsp[(6) - (7)].node));
               }
    break;

  case 105:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"START_MIENTRAS","START_MIENTRAS");
               // NodoAST *node=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
               // node->add(*$3);

                //NodoAST *nod1=new NodoAST(@1.first_line, @1.first_column,"LISTA_GENERAL","LISTA_GENERAL");
                //nod1->add(*$6);

                (yyval.node)->add(*(yyvsp[(3) - (7)].node));//condicion
                (yyval.node)->add(*(yyvsp[(6) - (7)].node));//listaGeneral
                }
    break;

  case 106:

    {
               (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column,"START_HACER","START_HACER");

               //NodoAST *nod=new NodoAST(@1.first_line, @1.first_column,"LISTA_GENERAL","LISTA_GENERAL");
               //nod->add(*$3);

               //NodoAST *nod1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
               //nod1->add(*$7);
               (yyval.node)->add(*(yyvsp[(3) - (9)].node));
               (yyval.node)->add(*(yyvsp[(7) - (9)].node));

            }
    break;

  case 107:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"START_COMPROBAR","START_COMPROBAR");
                  (yyval.node)->add(*(yyvsp[(3) - (7)].node));
                  (yyval.node)->add(*(yyvsp[(6) - (7)].node));
                }
    break;

  case 108:

    {
                (yyval.node)=(yyvsp[(1) - (2)].node);//recibo una lista de casos
                (yyval.node)->add(*(yyvsp[(2) - (2)].node));//ingreso el defau

              }
    break;

  case 109:

    {
              (yyval.node)=(yyvsp[(1) - (1)].node);//recibo una lista de casos
              }
    break;

  case 110:

    {
              (yyval.node)=(yyvsp[(1) - (1)].node);//ingreso solo el dafau
              }
    break;

  case 111:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column,"defecto","defecto");
        (yyval.node)->add(*(yyvsp[(3) - (5)].node));
      }
    break;

  case 112:

    {
            (yyval.node)=(yyvsp[(1) - (7)].node);
            NodoAST *no1=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"caso","caso");
            no1->add(*(yyvsp[(3) - (7)].node));
            no1->add(*(yyvsp[(5) - (7)].node));
          
            (yyval.node)->add(*no1);

            }
    break;

  case 113:

    {

            (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"LISTA_CASO","LISTA_CASO");
            NodoAST *no1=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"caso","caso");
            no1->add(*(yyvsp[(2) - (6)].node));
            no1->add(*(yyvsp[(4) - (6)].node));
          
            (yyval.node)->add(*no1);
            }
    break;

  case 114:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column,"incluir",(yyvsp[(3) - (5)].TEXT));
                }
    break;

  case 115:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column,"imprimir",(yyvsp[(1) - (5)].TEXT));
                    //NodoAST *no=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                    //no->add(*$3);
                    (yyval.node)->add(*(yyvsp[(3) - (5)].node));

                }
    break;

  case 116:

    {
                        //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 117:

    {
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 118:

    {
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                     }
    break;

  case 119:

    {
                       // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 120:

    {
                        //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                        (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 121:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,"archivo",(yyvsp[(2) - (8)].TEXT));
            //NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
            (yyval.node)->add(*(yyvsp[(6) - (8)].node));

            }
    break;

  case 122:

    {
                 (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column,"nuevo_conjunto",(yyvsp[(1) - (9)].TEXT));
                // NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                 (yyval.node)->add(*(yyvsp[(5) - (9)].node));
                 (yyval.node)->add(*(yyvsp[(7) - (9)].node));

                }
    break;

  case 123:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column,"nuevo_regex",(yyvsp[(1) - (9)].TEXT));

                //NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                (yyval.node)->add(*(yyvsp[(5) - (9)].node));
                (yyval.node)->add(*(yyvsp[(7) - (9)].node));
                //$$->add(*n1);

            }
    break;

  case 124:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column,"nueva_entrada",(yyvsp[(1) - (9)].TEXT));

                   // NodoAST *n1=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                    (yyval.node)->add(*(yyvsp[(5) - (9)].node));
                    (yyval.node)->add(*(yyvsp[(7) - (9)].node));
                    //$$->add(*n1);
                }
    break;

  case 125:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"guarda_arch",(yyvsp[(1) - (6)].TEXT));
        }
    break;

  case 126:

    {
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 127:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 128:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 129:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 130:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 131:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 132:

    {
                  (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 133:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (10)]).first_line,(yylsp[(1) - (10)]).first_column,"cuenta",(yyvsp[(2) - (10)].TEXT));
              (yyval.node)->add(*(yyvsp[(6) - (10)].node));
              (yyval.node)->add(*(yyvsp[(8) - (10)].node));
              }
    break;

  case 134:

    {
                  (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"verCuenta",(yyvsp[(1) - (6)].TEXT));
                  }
    break;

  case 135:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"depCuenta",(yyvsp[(1) - (7)].TEXT));
              (yyval.node)->add(*(yyvsp[(5) - (7)].node));
              }
    break;

  case 136:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"resCuenta",(yyvsp[(1) - (7)].TEXT));
                (yyval.node)->add(*(yyvsp[(5) - (7)].node));
              }
    break;

  case 137:

    {
              (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"imprimirCuenta",(yyvsp[(1) - (6)].TEXT));
              }
    break;

  case 138:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"conCuenta",(yyvsp[(1) - (6)].TEXT));
                }
    break;

  case 139:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (9)]).first_line,(yylsp[(1) - (9)]).first_column,"transferir","transferir");
            NodoAST *ide1=new NodoAST((yylsp[(1) - (9)]).first_line,(yylsp[(1) - (9)]).first_column,"Id",(yyvsp[(3) - (9)].TEXT));
            (yyval.node)->add(*ide1);//cuenta 1
            NodoAST *de2=new NodoAST((yylsp[(1) - (9)]).first_line,(yylsp[(1) - (9)]).first_column,"Id",(yyvsp[(5) - (9)].TEXT));
            (yyval.node)->add(*de2);//cuenta 2
            (yyval.node)->add(*(yyvsp[(7) - (9)].node));// monto
            }
    break;

  case 140:

    {
               (yyval.node)=(yyvsp[(1) - (2)].node);
               (yyval.node)->add(*(yyvsp[(2) - (2)].node));
               }
    break;

  case 141:

    {
               (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"LISTA_GENERAL","LISTA_GENERAL");
               (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                         }
    break;

  case 142:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"VAR_GLOBALES","VAR_GLOBALES");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 143:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"OBJETO","OBJETO");

                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 144:

    {
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 145:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"ARREGLO","ARREGLO");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 146:

    {
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 147:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"ASIGNAR_VAR","ASIGNAR_VAR");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 148:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (2)].node);
                    }
    break;

  case 149:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 150:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 151:

    {
                   // $$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 152:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 153:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 154:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 155:

    {
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                    }
    break;

  case 156:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"SENTENCIA_ARCHIVOS","SENTENCIA_ARCHIVOS");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 157:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"SENTENCIA_CUENTA","SENTENCIA_CUENTA");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 158:

    {
                    
                    (yyval.node)=(yyvsp[(1) - (2)].node);
                    }
    break;

  case 159:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LLAMADA_FUNCION","LLAMADA_FUNCION");
                    (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 160:

    {
                    NodoAST *node=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"romper",(yyvsp[(1) - (2)].TEXT));
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=node;
                    }
    break;

  case 161:

    {
                    NodoAST *node=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"continuar",(yyvsp[(1) - (2)].TEXT));
                    //$$=new NodoAST(@1.first_line, @1.first_column,"SENTENCIA_GENERAL","SENTENCIA_GENERAL");
                    (yyval.node)=node;
                    }
    break;

  case 162:

    { 
                //ca=nuevo Clase1()
                (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"NUEVO_OBJEC","NUEVO_OBJEC");
                NodoAST *node=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"Id",(yyvsp[(1) - (7)].TEXT));//id obje
                NodoAST *node1=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"Id",(yyvsp[(4) - (7)].TEXT));//id clase
                (yyval.node)->add(*node);
                (yyval.node)->add(*node1);
            }
    break;

  case 163:

    {
        (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"RETORNO","RETORNO");
        (yyval.node)->add(*(yyvsp[(2) - (2)].node));
        }
    break;

  case 164:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"METODO_FUNCION","METODO_FUNCION");
                NodoAST *node1=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"sobrescribir",(yyvsp[(2) - (7)].TEXT));
                (yyval.node)->add(*node1);//sobreescribir
                (yyval.node)->add(*(yyvsp[(3) - (7)].node));//visibilidad

                //funcion o metodo,tipo de retorno
                (yyval.node)->add(*(yyvsp[(4) - (7)].node));

                NodoAST *nod=new NodoAST((yylsp[(1) - (7)]).first_line,(yylsp[(1) - (7)]).first_column,"Id",(yyvsp[(5) - (7)].TEXT));
                (yyval.node)->add(*nod);

                (yyval.node)->add(*(yyvsp[(6) - (7)].node));//parametros

                (yyval.node)->add(*(yyvsp[(7) - (7)].node));//cuerpo

                }
    break;

  case 165:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"METODO_FUNCION","METODO_FUNCION");
                    (yyval.node)->add(*(yyvsp[(2) - (6)].node));//visibilidad
                    //funcion o metodo,tipo de retorno
                    (yyval.node)->add(*(yyvsp[(3) - (6)].node));
                    NodoAST *no=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"Id",(yyvsp[(4) - (6)].TEXT));

                    (yyval.node)->add(*no);//id
                    (yyval.node)->add(*(yyvsp[(5) - (6)].node));//parametros
                    (yyval.node)->add(*(yyvsp[(6) - (6)].node));//cuerpo

                }
    break;

  case 166:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"METODO_FUNCION","METODO_FUNCION");
                    NodoAST *node=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"sobrescribir",(yyvsp[(2) - (6)].TEXT));
                    NodoAST *n1=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"publico","publico");
                    (yyval.node)->add(*node);//sobre
                    (yyval.node)->add(*n1);//visibilidad
                    //funcion o metodo,tipo de retorno
                    (yyval.node)->add(*(yyvsp[(3) - (6)].node));
                    NodoAST *ide=new NodoAST((yylsp[(1) - (6)]).first_line,(yylsp[(1) - (6)]).first_column,"Id",(yyvsp[(4) - (6)].TEXT));
                    (yyval.node)->add(*ide);//id
                    (yyval.node)->add(*(yyvsp[(5) - (6)].node));//parametros
                    (yyval.node)->add(*(yyvsp[(6) - (6)].node));//cuerpo
               }
    break;

  case 167:

    {
                    (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line,(yylsp[(1) - (5)]).first_column,"METODO_FUNCION","METODO_FUNCION");
                    NodoAST *visi=new NodoAST((yylsp[(1) - (5)]).first_line,(yylsp[(1) - (5)]).first_column,"publico","publico");
                    (yyval.node)->add(*visi);//visibilidad
                    //funcion o metodo
                    (yyval.node)->add(*(yyvsp[(2) - (5)].node));
                    NodoAST *ide=new NodoAST((yylsp[(1) - (5)]).first_line,(yylsp[(1) - (5)]).first_column,"Id",(yyvsp[(3) - (5)].TEXT));

                    (yyval.node)->add(*ide);//id
                    (yyval.node)->add(*(yyvsp[(4) - (5)].node));//parametros
                    (yyval.node)->add(*(yyvsp[(5) - (5)].node));//metodo

                }
    break;

  case 168:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);

            }
    break;

  case 169:

    {//variable
                    (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"variable","variable");
                    (yyval.node)->add(*(yyvsp[(1) - (2)].node));
                    NodoAST *node =new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(2) - (2)].TEXT));
                    (yyval.node)->add(*node);

                    }
    break;

  case 170:

    {//arreglo
                    (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line,(yylsp[(1) - (4)]).first_column,"arreglo",(yyvsp[(3) - (4)].TEXT));
                    (yyval.node)->add(*(yyvsp[(2) - (4)].node));//dato primitivo
                    (yyval.node)->add(*(yyvsp[(4) - (4)].node));

                    }
    break;

  case 171:

    {//objeto
                    (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"objeto","objeto");
                    NodoAST *no1=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(1) - (2)].TEXT));//clase
                    NodoAST *no2=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"Id",(yyvsp[(2) - (2)].TEXT));//objec
                    (yyval.node)->add(*no1);
                    (yyval.node)->add(*no2);
                    }
    break;

  case 172:

    {
            (yyval.node)=(yyvsp[(2) - (3)].node);
            }
    break;

  case 173:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (2)]).first_line,(yylsp[(1) - (2)]).first_column,"SIN_PARAMETRO","SIN_PARAMETRO");

            }
    break;

  case 174:

    {
                        (yyval.node)=(yyvsp[(1) - (3)].node);
                        (yyval.node)->add(*(yyvsp[(3) - (3)].node));
                    }
    break;

  case 175:

    {
                        (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line,(yylsp[(1) - (1)]).first_column,"LISTA_PARAMETROS","LISTA_PARAMETROS");
                        (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                    }
    break;

  case 176:

    {
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 177:

    {
                    (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 178:

    {
                      (yyval.node)=(yyvsp[(1) - (1)].node);
                  }
    break;

  case 179:

    {

           (yyval.node)=(yyvsp[(1) - (1)].node);
        }
    break;

  case 180:

    {

            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"arreglo","arreglo");

            (yyval.node)->add(*(yyvsp[(2) - (3)].node));//primitivo
            (yyval.node)->add(*(yyvsp[(3) - (3)].node));//dimensiones[][][]

        }
    break;

  case 181:

    {

            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"clase",(yyvsp[(1) - (1)].TEXT));//nombre de la clase
        }
    break;

  case 182:

    {

             (yyval.node) =new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"void",(yyvsp[(1) - (1)].TEXT));

        }
    break;

  case 183:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"entero","entero");
           }
    break;

  case 184:

    {
           (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"doble","doble");
           }
    break;

  case 185:

    {
           (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"cadena","cadena");
           }
    break;

  case 186:

    {
           (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"caracter","caracter");
           }
    break;

  case 187:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"boolean","boolean");
            }
    break;

  case 188:

    {
            //----llamada de una funcion de otra clase

            (yyval.node)=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"Externa_F_V",(yyvsp[(1) - (7)].TEXT));//contiene el id del objeto

            NodoAST *nodo1=new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column,"Id",(yyvsp[(3) - (7)].TEXT));//id de la funcion
           
            (yyval.node)->add(*nodo1);//funcion
            (yyval.node)->add(*(yyvsp[(5) - (7)].node));//valores de parametro


        }
    break;

  case 189:

    { //llamada de una funcion externa sin valores

            (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"Externa_F_S",(yyvsp[(1) - (6)].TEXT));//contiene el id del objeto

            
            NodoAST *nodo1=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"Id",(yyvsp[(3) - (6)].TEXT));//funcion como tal
           
            (yyval.node)->add(*nodo1);//funcion


        }
    break;

  case 190:

    {//----> este ya funciona
            (yyval.node)=new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column,"Local_F_V",(yyvsp[(1) - (5)].TEXT));
            (yyval.node)->add(*(yyvsp[(3) - (5)].node));



        }
    break;

  case 191:

    {//este ya funciona 
                (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,"Local_F_S",(yyvsp[(1) - (4)].TEXT));


        }
    break;

  case 192:

    {//llamada de variable extena 
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Externa_Var",(yyvsp[(1) - (3)].TEXT));//contiene el id del objeto
            NodoAST *nodo1=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Id",(yyvsp[(3) - (3)].TEXT));//id de la variable
            (yyval.node)->add(*nodo1);

         }
    break;

  case 193:

    {//llamada de variable extena 
            (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"Externa_Var_A",(yyvsp[(1) - (6)].TEXT));//contiene el id del objeto
            NodoAST *nodo1=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"Id",(yyvsp[(3) - (6)].TEXT));//id de la variable
            (yyval.node)->add(*nodo1);
            (yyval.node)->add(*(yyvsp[(5) - (6)].node));

         }
    break;

  case 194:

    {//llamada arreglo externo
            (yyval.node)=new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,"Externa_Ar_A",(yyvsp[(1) - (6)].TEXT));//contiene el id del objeto
            (yyval.node)->add(*(yyvsp[(3) - (6)].node));//trae id y dimension
            (yyval.node)->add(*(yyvsp[(5) - (6)].node));//trae el valor a asignar
         }
    break;

  case 195:

    {//llamada arreglo externo
            (yyval.node)=new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,"Externa_Ar",(yyvsp[(1) - (3)].TEXT));//contiene el id del objeto
            (yyval.node)->add(*(yyvsp[(3) - (3)].node));
         }
    break;

  case 196:

    {
                (yyval.node)=(yyvsp[(1) - (3)].node);
                //NodoAST *node=new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                //node->add(*$3);
                (yyval.node)->add(*(yyvsp[(3) - (3)].node));
                }
    break;

  case 197:

    {
                (yyval.node)=new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,"LISTA_VALORES","LISTA_VALORES");
                //NodoAST *node =new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
                //node->add(*$1);
                (yyval.node)->add(*(yyvsp[(1) - (1)].node));
                }
    break;

  case 198:

    {
            (yyval.node)=new NodoAST((yylsp[(1) - (4)]).first_line,(yylsp[(1) - (4)]).first_column,"PRINCIPAL","PRINCIPAL");
            (yyval.node)->add(*(yyvsp[(4) - (4)].node));

            }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}














