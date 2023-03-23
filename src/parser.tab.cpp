/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ASSIGN = 3,                   /* T_ASSIGN  */
  YYSYMBOL_T_TIMES = 4,                    /* T_TIMES  */
  YYSYMBOL_T_DIVIDE = 5,                   /* T_DIVIDE  */
  YYSYMBOL_T_PLUS = 6,                     /* T_PLUS  */
  YYSYMBOL_T_MINUS = 7,                    /* T_MINUS  */
  YYSYMBOL_T_BIT_AND = 8,                  /* T_BIT_AND  */
  YYSYMBOL_T_BIT_OR = 9,                   /* T_BIT_OR  */
  YYSYMBOL_T_BIT_XOR = 10,                 /* T_BIT_XOR  */
  YYSYMBOL_T_LOGICAL_OR = 11,              /* T_LOGICAL_OR  */
  YYSYMBOL_T_LOGICAL_AND = 12,             /* T_LOGICAL_AND  */
  YYSYMBOL_T_RIGHT_SHIFT = 13,             /* T_RIGHT_SHIFT  */
  YYSYMBOL_T_LEFT_SHIFT = 14,              /* T_LEFT_SHIFT  */
  YYSYMBOL_T_LBRACKET = 15,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 16,                /* T_RBRACKET  */
  YYSYMBOL_CUR_LBRACKET = 17,              /* CUR_LBRACKET  */
  YYSYMBOL_CUR_RBRACKET = 18,              /* CUR_RBRACKET  */
  YYSYMBOL_SQU_LBRACKET = 19,              /* SQU_LBRACKET  */
  YYSYMBOL_SQU_RBRACKET = 20,              /* SQU_RBRACKET  */
  YYSYMBOL_COLON = 21,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_T_LESSTHAN = 24,                /* T_LESSTHAN  */
  YYSYMBOL_T_GREATERTHAN = 25,             /* T_GREATERTHAN  */
  YYSYMBOL_T_LESS_EQUAL = 26,              /* T_LESS_EQUAL  */
  YYSYMBOL_T_GREATER_EQUAL = 27,           /* T_GREATER_EQUAL  */
  YYSYMBOL_T_EQUAL = 28,                   /* T_EQUAL  */
  YYSYMBOL_T_NOT_EQUAL = 29,               /* T_NOT_EQUAL  */
  YYSYMBOL_T_INT = 30,                     /* T_INT  */
  YYSYMBOL_T_UNSIGNED = 31,                /* T_UNSIGNED  */
  YYSYMBOL_T_IF = 32,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 33,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 34,                   /* T_WHILE  */
  YYSYMBOL_T_RETURN = 35,                  /* T_RETURN  */
  YYSYMBOL_T_FOR = 36,                     /* T_FOR  */
  YYSYMBOL_INC_OP = 37,                    /* INC_OP  */
  YYSYMBOL_NAME = 38,                      /* NAME  */
  YYSYMBOL_NUMBER = 39,                    /* NUMBER  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_ROOT = 41,                      /* ROOT  */
  YYSYMBOL_root_program = 42,              /* root_program  */
  YYSYMBOL_external_declaration = 43,      /* external_declaration  */
  YYSYMBOL_function_definition = 44,       /* function_definition  */
  YYSYMBOL_initialisation_declarator = 45, /* initialisation_declarator  */
  YYSYMBOL_declaration_list = 46,          /* declaration_list  */
  YYSYMBOL_declarator = 47,                /* declarator  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_parameter_declaration = 49,     /* parameter_declaration  */
  YYSYMBOL_parameter_list = 50,            /* parameter_list  */
  YYSYMBOL_function_call_expression = 51,  /* function_call_expression  */
  YYSYMBOL_primary_expression = 52,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 53,        /* postfix_expression  */
  YYSYMBOL_add_expression = 54,            /* add_expression  */
  YYSYMBOL_multiply_expression = 55,       /* multiply_expression  */
  YYSYMBOL_shift_expression = 56,          /* shift_expression  */
  YYSYMBOL_compare_expression = 57,        /* compare_expression  */
  YYSYMBOL_equal_expression = 58,          /* equal_expression  */
  YYSYMBOL_bitwise_expression = 59,        /* bitwise_expression  */
  YYSYMBOL_logical_expression = 60,        /* logical_expression  */
  YYSYMBOL_assignment_expression = 61,     /* assignment_expression  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_statement_list = 64,            /* statement_list  */
  YYSYMBOL_compound_statement = 65,        /* compound_statement  */
  YYSYMBOL_jump_statement = 66,            /* jump_statement  */
  YYSYMBOL_expression_statement = 67,      /* expression_statement  */
  YYSYMBOL_condition_statement = 68,       /* condition_statement  */
  YYSYMBOL_iteration_statement = 69,       /* iteration_statement  */
  YYSYMBOL_type_specifier = 70             /* type_specifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    78,    79,    83,    84,    88,    89,    98,
      99,   103,   104,   108,   109,   110,   111,   115,   116,   120,
     123,   124,   128,   129,   132,   133,   134,   135,   136,   137,
     141,   142,   146,   147,   148,   152,   153,   154,   158,   159,
     160,   164,   165,   166,   167,   168,   172,   173,   174,   178,
     179,   180,   181,   184,   185,   186,   189,   190,   194,   199,
     200,   201,   202,   203,   208,   209,   213,   214,   215,   216,
     221,   222,   225,   228,   229,   233,   234,   235,   240,   241
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_ASSIGN", "T_TIMES",
  "T_DIVIDE", "T_PLUS", "T_MINUS", "T_BIT_AND", "T_BIT_OR", "T_BIT_XOR",
  "T_LOGICAL_OR", "T_LOGICAL_AND", "T_RIGHT_SHIFT", "T_LEFT_SHIFT",
  "T_LBRACKET", "T_RBRACKET", "CUR_LBRACKET", "CUR_RBRACKET",
  "SQU_LBRACKET", "SQU_RBRACKET", "COLON", "SEMICOLON", "COMMA",
  "T_LESSTHAN", "T_GREATERTHAN", "T_LESS_EQUAL", "T_GREATER_EQUAL",
  "T_EQUAL", "T_NOT_EQUAL", "T_INT", "T_UNSIGNED", "T_IF", "T_ELSE",
  "T_WHILE", "T_RETURN", "T_FOR", "INC_OP", "NAME", "NUMBER", "$accept",
  "ROOT", "root_program", "external_declaration", "function_definition",
  "initialisation_declarator", "declaration_list", "declarator",
  "declaration", "parameter_declaration", "parameter_list",
  "function_call_expression", "primary_expression", "postfix_expression",
  "add_expression", "multiply_expression", "shift_expression",
  "compare_expression", "equal_expression", "bitwise_expression",
  "logical_expression", "assignment_expression", "expression", "statement",
  "statement_list", "compound_statement", "jump_statement",
  "expression_statement", "condition_statement", "iteration_statement",
  "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,  -111,  -111,    28,    22,  -111,  -111,  -111,    41,  -111,
    -111,  -111,     5,    33,  -111,   107,   118,   107,  -111,   107,
      -4,  -111,  -111,    11,    10,   176,   169,   146,    92,   166,
     173,  -111,    56,  -111,   -10,    20,    47,     3,  -111,    77,
      74,   107,   107,  -111,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,    68,  -111,    56,    22,    86,  -111,  -111,  -111,  -111,
     131,   169,    89,  -111,   176,   176,    47,    47,    10,    10,
     169,   169,   169,   169,   146,   146,    92,    92,    92,   166,
     166,  -111,   111,   115,    49,   127,    93,  -111,   133,  -111,
     101,  -111,  -111,  -111,  -111,  -111,    44,  -111,  -111,   122,
    -111,   107,  -111,   107,   107,  -111,   137,   107,  -111,  -111,
     126,  -111,  -111,  -111,    53,  -111,   134,   176,   135,   147,
    -111,   107,  -111,  -111,    42,    42,    76,   157,  -111,    42,
     175,    42,  -111,    42,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    78,    79,     0,     2,     3,     5,     6,     0,     1,
       4,    17,    13,     0,     9,     0,     0,     0,    18,     0,
      25,    24,    30,    35,    38,    32,    41,    46,    49,    53,
      56,    10,    15,    20,     0,     0,    35,     0,    58,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    16,     0,    13,    19,    14,    27,    28,
       0,    22,     0,    57,    33,    34,    36,    37,    40,    39,
      42,    44,    43,    45,    47,    48,    50,    51,    52,    55,
      54,    66,     0,     0,     0,     0,     0,    11,     0,    64,
       0,    60,    59,    61,    62,    63,     0,     8,    21,     0,
      29,     0,    26,     0,     0,    70,     0,     0,    68,    12,
       0,    72,    67,    65,    13,    15,     0,    23,     0,     0,
      71,     0,    69,    16,     0,     0,     0,    73,    75,     0,
       0,     0,    76,     0,    74,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   188,  -111,  -111,  -111,   158,   -49,   130,
      87,  -111,  -111,   -15,     2,   -41,   116,   132,   121,   129,
    -111,    12,   -19,   -74,    99,   -14,  -111,  -110,  -111,  -111,
       1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    13,    96,    14,     7,    33,
      34,    70,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    38,    98,    99,   100,   101,   102,   103,   104,   105,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,     8,    36,    74,    75,     8,    63,   131,    15,    44,
      45,    40,    97,    64,    42,    41,    44,    45,    62,    37,
      16,   136,    72,    67,    17,    36,   123,    31,     9,    36,
      36,    76,    77,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,   123,   119,    43,   107,
      78,    79,     1,     2,    73,    18,    15,    19,    65,    61,
     137,   138,   106,    11,    19,   142,    11,   144,   109,   145,
     127,   115,    17,    61,    92,   116,    93,    94,    95,    12,
      20,    21,   124,    19,    43,    61,    91,    20,    21,    19,
      69,    19,   139,    68,   128,   129,    36,   106,     1,     2,
      92,   109,    93,    94,    95,    17,    20,    21,    19,   112,
      61,   118,    20,    21,    20,    21,    19,   140,    61,   122,
      54,    55,    19,     1,     2,    92,   113,    93,    94,    95,
     114,    20,    21,    92,    32,    93,    94,    95,   125,    20,
      21,    19,   117,    61,   132,    20,    21,   110,     1,     2,
     133,   134,     1,     2,   111,   121,    71,    64,    92,   130,
      93,    94,    95,   135,    20,    21,    80,    81,    82,    83,
      50,    51,    52,    53,    56,    57,    58,    86,    87,    88,
      46,    47,    48,    49,    59,    60,    84,    85,    89,    90,
     141,   143,    10,    66,   108,   120,   126
};

static const yytype_uint8 yycheck[] =
{
      19,     0,    17,    44,    45,     4,    16,   117,     3,     6,
       7,    15,    61,    23,     3,    19,     6,     7,    32,    17,
      15,   131,    41,    20,    19,    40,   100,    15,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   120,    96,    37,    63,
      48,    49,    30,    31,    42,    22,     3,    15,    38,    17,
     134,   135,    61,    22,    15,   139,    22,   141,    15,   143,
     111,    22,    19,    17,    32,    94,    34,    35,    36,    38,
      38,    39,    38,    15,    37,    17,    18,    38,    39,    15,
      16,    15,    16,    16,   113,   114,   111,    96,    30,    31,
      32,    15,    34,    35,    36,    19,    38,    39,    15,    20,
      17,    18,    38,    39,    38,    39,    15,   136,    17,    18,
      28,    29,    15,    30,    31,    32,    15,    34,    35,    36,
      15,    38,    39,    32,    16,    34,    35,    36,    16,    38,
      39,    15,    15,    17,    18,    38,    39,    16,    30,    31,
      16,    16,    30,    31,    23,    22,    40,    23,    32,    22,
      34,    35,    36,    16,    38,    39,    50,    51,    52,    53,
      24,    25,    26,    27,     8,     9,    10,    56,    57,    58,
       4,     5,    13,    14,    11,    12,    54,    55,    59,    60,
      33,    16,     4,    35,    64,    96,   109
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    31,    41,    42,    43,    44,    48,    70,     0,
      43,    22,    38,    45,    47,     3,    15,    19,    22,    15,
      38,    39,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    16,    49,    50,    70,    53,    54,    61,    62,
      15,    19,     3,    37,     6,     7,     4,     5,    13,    14,
      24,    25,    26,    27,    28,    29,     8,     9,    10,    11,
      12,    17,    65,    16,    23,    38,    47,    20,    16,    16,
      51,    56,    62,    61,    55,    55,    53,    53,    54,    54,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    59,
      59,    18,    32,    34,    35,    36,    46,    48,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    65,    49,    15,
      16,    23,    20,    15,    15,    22,    62,    15,    18,    48,
      64,    22,    18,    63,    38,    16,    50,    55,    62,    62,
      22,    67,    18,    16,    16,    16,    67,    63,    63,    16,
      62,    33,    63,    16,    63,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    55,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    68,    68,    69,    69,    69,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     5,     6,     1,
       3,     1,     2,     1,     4,     3,     4,     2,     3,     2,
       1,     3,     1,     3,     1,     1,     4,     3,     3,     4,
       1,     2,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     4,
       2,     3,     2,     5,     7,     5,     6,     7,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* ROOT: root_program  */
#line 75 "src/parser.y"
                    { g_root = (yyvsp[0].NodePtr); }
#line 1509 "src/parser.tab.cpp"
    break;

  case 3: /* root_program: external_declaration  */
#line 78 "src/parser.y"
                               { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1515 "src/parser.tab.cpp"
    break;

  case 4: /* root_program: root_program external_declaration  */
#line 79 "src/parser.y"
                                            { (yyval.NodePtr) = new Add_Program((yyvsp[-1].NodePtr), (yyvsp[0].NodePtr)); }
#line 1521 "src/parser.tab.cpp"
    break;

  case 5: /* external_declaration: function_definition  */
#line 83 "src/parser.y"
                              { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1527 "src/parser.tab.cpp"
    break;

  case 6: /* external_declaration: declaration  */
#line 84 "src/parser.y"
                      { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1533 "src/parser.tab.cpp"
    break;

  case 7: /* function_definition: type_specifier NAME T_LBRACKET T_RBRACKET compound_statement  */
#line 88 "src/parser.y"
                                                                       { (yyval.NodePtr) = new Function_No_Arg_Definition( *(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[0].NodePtr) );}
#line 1539 "src/parser.tab.cpp"
    break;

  case 8: /* function_definition: type_specifier NAME T_LBRACKET parameter_list T_RBRACKET compound_statement  */
#line 89 "src/parser.y"
                                                                                      { (yyval.NodePtr) = new Function_With_Arg_Definition( *(yyvsp[-5].string), *(yyvsp[-4].string), (yyvsp[-2].NodeVectorPtr), (yyvsp[0].NodePtr) );}
#line 1545 "src/parser.tab.cpp"
    break;

  case 9: /* initialisation_declarator: declarator  */
#line 98 "src/parser.y"
                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1551 "src/parser.tab.cpp"
    break;

  case 10: /* initialisation_declarator: NAME T_ASSIGN assignment_expression  */
#line 99 "src/parser.y"
                                                                                { (yyval.NodePtr) = new Initialisation_Variable_Declarator(*(yyvsp[-2].string), (yyvsp[0].NodePtr)); }
#line 1557 "src/parser.tab.cpp"
    break;

  case 11: /* declaration_list: declaration  */
#line 103 "src/parser.y"
                                                                                                                { (yyval.NodeVectorPtr) = new std::vector<Node*>(1, (yyvsp[0].NodePtr)); }
#line 1563 "src/parser.tab.cpp"
    break;

  case 12: /* declaration_list: declaration_list declaration  */
#line 104 "src/parser.y"
                                                                        { (yyvsp[-1].NodeVectorPtr)->push_back((yyvsp[0].NodePtr)); (yyval.NodeVectorPtr) = (yyvsp[-1].NodeVectorPtr); }
#line 1569 "src/parser.tab.cpp"
    break;

  case 13: /* declarator: NAME  */
#line 108 "src/parser.y"
         { (yyval.NodePtr) = new Variable_Declarator(*(yyvsp[0].string)); }
#line 1575 "src/parser.tab.cpp"
    break;

  case 14: /* declarator: NAME SQU_LBRACKET add_expression SQU_RBRACKET  */
#line 109 "src/parser.y"
                                                  { (yyval.NodePtr) = new Array_Declarator(*(yyvsp[-3].string), (yyvsp[-1].NodePtr));}
#line 1581 "src/parser.tab.cpp"
    break;

  case 15: /* declarator: NAME T_LBRACKET T_RBRACKET  */
#line 110 "src/parser.y"
                                                { (yyval.NodePtr) = new Function_Declarator(*(yyvsp[-2].string), nullptr) ; }
#line 1587 "src/parser.tab.cpp"
    break;

  case 16: /* declarator: NAME T_LBRACKET parameter_list T_RBRACKET  */
#line 111 "src/parser.y"
                                                  { (yyval.NodePtr) = new Function_Declarator(*(yyvsp[-3].string), (yyvsp[-1].NodeVectorPtr));}
#line 1593 "src/parser.tab.cpp"
    break;

  case 18: /* declaration: type_specifier initialisation_declarator SEMICOLON  */
#line 116 "src/parser.y"
                                                                {(yyval.NodePtr) = new Declaration(*(yyvsp[-2].string), (yyvsp[-1].NodePtr)); }
#line 1599 "src/parser.tab.cpp"
    break;

  case 19: /* parameter_declaration: type_specifier declarator  */
#line 120 "src/parser.y"
                                    { (yyval.NodePtr) = new Declaration(*(yyvsp[-1].string), (yyvsp[0].NodePtr)); }
#line 1605 "src/parser.tab.cpp"
    break;

  case 20: /* parameter_list: parameter_declaration  */
#line 123 "src/parser.y"
                                                                                                { (yyval.NodeVectorPtr) = new std::vector<Node*>(1, (yyvsp[0].NodePtr)); }
#line 1611 "src/parser.tab.cpp"
    break;

  case 21: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 124 "src/parser.y"
                                                                                        { (yyvsp[-2].NodeVectorPtr)->push_back((yyvsp[0].NodePtr)); (yyval.NodeVectorPtr) = (yyvsp[-2].NodeVectorPtr); }
#line 1617 "src/parser.tab.cpp"
    break;

  case 22: /* function_call_expression: shift_expression  */
#line 128 "src/parser.y"
                                                                                                { (yyval.NodeVectorPtr) = new std::vector<Node*>(1, (yyvsp[0].NodePtr)); }
#line 1623 "src/parser.tab.cpp"
    break;

  case 23: /* function_call_expression: function_call_expression COMMA multiply_expression  */
#line 129 "src/parser.y"
                                                       { (yyvsp[-2].NodeVectorPtr)->push_back((yyvsp[0].NodePtr)); (yyval.NodeVectorPtr) = (yyvsp[-2].NodeVectorPtr); }
#line 1629 "src/parser.tab.cpp"
    break;

  case 24: /* primary_expression: NUMBER  */
#line 132 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = new Int((yyvsp[0].number)); }
#line 1635 "src/parser.tab.cpp"
    break;

  case 25: /* primary_expression: NAME  */
#line 133 "src/parser.y"
                                                  { (yyval.NodePtr) = new Variable(*(yyvsp[0].string));}
#line 1641 "src/parser.tab.cpp"
    break;

  case 26: /* primary_expression: NAME SQU_LBRACKET expression SQU_RBRACKET  */
#line 134 "src/parser.y"
                                                { (yyval.NodePtr) = new Array(*(yyvsp[-3].string), (yyvsp[-1].NodePtr));}
#line 1647 "src/parser.tab.cpp"
    break;

  case 27: /* primary_expression: T_LBRACKET expression T_RBRACKET  */
#line 135 "src/parser.y"
                                                                                                                { (yyval.NodePtr) = (yyvsp[-1].NodePtr); }
#line 1653 "src/parser.tab.cpp"
    break;

  case 28: /* primary_expression: NAME T_LBRACKET T_RBRACKET  */
#line 136 "src/parser.y"
                                                        { (yyval.NodePtr) = new Function_Call(*(yyvsp[-2].string), nullptr) ; }
#line 1659 "src/parser.tab.cpp"
    break;

  case 29: /* primary_expression: NAME T_LBRACKET function_call_expression T_RBRACKET  */
#line 137 "src/parser.y"
                                                               { (yyval.NodePtr) = new  Function_Call(*(yyvsp[-3].string), (yyvsp[-1].NodeVectorPtr)); }
#line 1665 "src/parser.tab.cpp"
    break;

  case 30: /* postfix_expression: primary_expression  */
#line 141 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1671 "src/parser.tab.cpp"
    break;

  case 31: /* postfix_expression: postfix_expression INC_OP  */
#line 142 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Post_Increment_Expression((yyvsp[-1].NodePtr)); }
#line 1677 "src/parser.tab.cpp"
    break;

  case 32: /* add_expression: multiply_expression  */
#line 146 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1683 "src/parser.tab.cpp"
    break;

  case 33: /* add_expression: add_expression T_PLUS multiply_expression  */
#line 147 "src/parser.y"
                                                                                                        { (yyval.NodePtr) = new Add_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1689 "src/parser.tab.cpp"
    break;

  case 34: /* add_expression: add_expression T_MINUS multiply_expression  */
#line 148 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Sub_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1695 "src/parser.tab.cpp"
    break;

  case 35: /* multiply_expression: postfix_expression  */
#line 152 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1701 "src/parser.tab.cpp"
    break;

  case 36: /* multiply_expression: multiply_expression T_TIMES postfix_expression  */
#line 153 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Multiply_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1707 "src/parser.tab.cpp"
    break;

  case 37: /* multiply_expression: multiply_expression T_DIVIDE postfix_expression  */
#line 154 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Divide_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1713 "src/parser.tab.cpp"
    break;

  case 38: /* shift_expression: add_expression  */
#line 158 "src/parser.y"
                     { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1719 "src/parser.tab.cpp"
    break;

  case 39: /* shift_expression: shift_expression T_LEFT_SHIFT add_expression  */
#line 159 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Left_Shift_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1725 "src/parser.tab.cpp"
    break;

  case 40: /* shift_expression: shift_expression T_RIGHT_SHIFT add_expression  */
#line 160 "src/parser.y"
                                                                                { (yyval.NodePtr) = new Right_Shift_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1731 "src/parser.tab.cpp"
    break;

  case 41: /* compare_expression: shift_expression  */
#line 164 "src/parser.y"
                       { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1737 "src/parser.tab.cpp"
    break;

  case 42: /* compare_expression: compare_expression T_LESSTHAN shift_expression  */
#line 165 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Less_Than_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1743 "src/parser.tab.cpp"
    break;

  case 43: /* compare_expression: compare_expression T_LESS_EQUAL shift_expression  */
#line 166 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Less_Equal_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1749 "src/parser.tab.cpp"
    break;

  case 44: /* compare_expression: compare_expression T_GREATERTHAN shift_expression  */
#line 167 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new More_Than_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1755 "src/parser.tab.cpp"
    break;

  case 45: /* compare_expression: compare_expression T_GREATER_EQUAL shift_expression  */
#line 168 "src/parser.y"
                                                                                { (yyval.NodePtr) = new More_Equal_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1761 "src/parser.tab.cpp"
    break;

  case 46: /* equal_expression: compare_expression  */
#line 172 "src/parser.y"
                         { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1767 "src/parser.tab.cpp"
    break;

  case 47: /* equal_expression: equal_expression T_EQUAL compare_expression  */
#line 173 "src/parser.y"
                                                                                                { (yyval.NodePtr) = new Equal_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1773 "src/parser.tab.cpp"
    break;

  case 48: /* equal_expression: equal_expression T_NOT_EQUAL compare_expression  */
#line 174 "src/parser.y"
                                                                                        { (yyval.NodePtr) = new Not_Equal_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1779 "src/parser.tab.cpp"
    break;

  case 49: /* bitwise_expression: equal_expression  */
#line 178 "src/parser.y"
                         { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1785 "src/parser.tab.cpp"
    break;

  case 50: /* bitwise_expression: bitwise_expression T_BIT_AND equal_expression  */
#line 179 "src/parser.y"
                                                                                                { (yyval.NodePtr) = new Bit_And_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1791 "src/parser.tab.cpp"
    break;

  case 51: /* bitwise_expression: bitwise_expression T_BIT_OR equal_expression  */
#line 180 "src/parser.y"
                                                                                                { (yyval.NodePtr) = new Bit_Or_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1797 "src/parser.tab.cpp"
    break;

  case 52: /* bitwise_expression: bitwise_expression T_BIT_XOR equal_expression  */
#line 181 "src/parser.y"
                                                                                                { (yyval.NodePtr) = new Bit_Xor_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1803 "src/parser.tab.cpp"
    break;

  case 53: /* logical_expression: bitwise_expression  */
#line 184 "src/parser.y"
                           { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1809 "src/parser.tab.cpp"
    break;

  case 54: /* logical_expression: logical_expression T_LOGICAL_AND bitwise_expression  */
#line 185 "src/parser.y"
                                                                                                        { (yyval.NodePtr) = new Logic_And_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1815 "src/parser.tab.cpp"
    break;

  case 55: /* logical_expression: logical_expression T_LOGICAL_OR bitwise_expression  */
#line 186 "src/parser.y"
                                                                                                        { (yyval.NodePtr) = new Logic_Or_Expression((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1821 "src/parser.tab.cpp"
    break;

  case 56: /* assignment_expression: logical_expression  */
#line 189 "src/parser.y"
                       { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1827 "src/parser.tab.cpp"
    break;

  case 57: /* assignment_expression: postfix_expression T_ASSIGN assignment_expression  */
#line 190 "src/parser.y"
                                                                                                { (yyval.NodePtr) = new Direct_Assignment((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1833 "src/parser.tab.cpp"
    break;

  case 58: /* expression: assignment_expression  */
#line 194 "src/parser.y"
                          { (yyval.NodePtr)=(yyvsp[0].NodePtr); }
#line 1839 "src/parser.tab.cpp"
    break;

  case 59: /* statement: jump_statement  */
#line 199 "src/parser.y"
                                                                                                                                { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1845 "src/parser.tab.cpp"
    break;

  case 60: /* statement: compound_statement  */
#line 200 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1851 "src/parser.tab.cpp"
    break;

  case 61: /* statement: expression_statement  */
#line 201 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1857 "src/parser.tab.cpp"
    break;

  case 62: /* statement: condition_statement  */
#line 202 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1863 "src/parser.tab.cpp"
    break;

  case 63: /* statement: iteration_statement  */
#line 203 "src/parser.y"
                                                                                                                                { (yyval.NodePtr) = (yyvsp[0].NodePtr); }
#line 1869 "src/parser.tab.cpp"
    break;

  case 64: /* statement_list: statement  */
#line 208 "src/parser.y"
              { (yyval.NodeVectorPtr) = new std::vector<Node*>{(yyvsp[0].NodePtr)}; }
#line 1875 "src/parser.tab.cpp"
    break;

  case 65: /* statement_list: statement_list statement  */
#line 209 "src/parser.y"
                                        { (yyvsp[-1].NodeVectorPtr)->push_back((yyvsp[0].NodePtr)); (yyval.NodeVectorPtr) = (yyvsp[-1].NodeVectorPtr); }
#line 1881 "src/parser.tab.cpp"
    break;

  case 66: /* compound_statement: CUR_LBRACKET CUR_RBRACKET  */
#line 213 "src/parser.y"
                              {(yyval.NodePtr) = new Compound_Statement(NULL, NULL);}
#line 1887 "src/parser.tab.cpp"
    break;

  case 67: /* compound_statement: CUR_LBRACKET statement_list CUR_RBRACKET  */
#line 214 "src/parser.y"
                                                                                { (yyval.NodePtr) = new Compound_Statement((yyvsp[-1].NodeVectorPtr), NULL); }
#line 1893 "src/parser.tab.cpp"
    break;

  case 68: /* compound_statement: CUR_LBRACKET declaration_list CUR_RBRACKET  */
#line 215 "src/parser.y"
                                                      { (yyval.NodePtr) = new Compound_Statement(NULL, (yyvsp[-1].NodeVectorPtr)); }
#line 1899 "src/parser.tab.cpp"
    break;

  case 69: /* compound_statement: CUR_LBRACKET declaration_list statement_list CUR_RBRACKET  */
#line 216 "src/parser.y"
                                                              {(yyval.NodePtr) = new Compound_Statement((yyvsp[-1].NodeVectorPtr), (yyvsp[-2].NodeVectorPtr));}
#line 1905 "src/parser.tab.cpp"
    break;

  case 70: /* jump_statement: T_RETURN SEMICOLON  */
#line 221 "src/parser.y"
                                                                                                                { (yyval.NodePtr) = new Return(NULL); }
#line 1911 "src/parser.tab.cpp"
    break;

  case 71: /* jump_statement: T_RETURN expression SEMICOLON  */
#line 222 "src/parser.y"
                                                                                                                { (yyval.NodePtr) = new Return((yyvsp[-1].NodePtr)); }
#line 1917 "src/parser.tab.cpp"
    break;

  case 72: /* expression_statement: expression SEMICOLON  */
#line 225 "src/parser.y"
                                                                                                                        { (yyval.NodePtr) = (yyvsp[-1].NodePtr); }
#line 1923 "src/parser.tab.cpp"
    break;

  case 73: /* condition_statement: T_IF T_LBRACKET expression T_RBRACKET statement  */
#line 228 "src/parser.y"
                                                        { (yyval.NodePtr) = new If_Statement((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1929 "src/parser.tab.cpp"
    break;

  case 74: /* condition_statement: T_IF T_LBRACKET expression T_RBRACKET statement T_ELSE statement  */
#line 229 "src/parser.y"
                                                                         { (yyval.NodePtr) = new If_Else_Statement((yyvsp[-4].NodePtr), (yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1935 "src/parser.tab.cpp"
    break;

  case 75: /* iteration_statement: T_WHILE T_LBRACKET expression T_RBRACKET statement  */
#line 233 "src/parser.y"
                                                           { (yyval.NodePtr) = new While_Statement((yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1941 "src/parser.tab.cpp"
    break;

  case 76: /* iteration_statement: T_FOR T_LBRACKET expression_statement expression_statement T_RBRACKET statement  */
#line 234 "src/parser.y"
                                                                                    { (yyval.NodePtr) = new For_Loop((yyvsp[-3].NodePtr), (yyvsp[-2].NodePtr), NULL, (yyvsp[0].NodePtr)); }
#line 1947 "src/parser.tab.cpp"
    break;

  case 77: /* iteration_statement: T_FOR T_LBRACKET expression_statement expression_statement expression T_RBRACKET statement  */
#line 235 "src/parser.y"
                                                                                                     { (yyval.NodePtr) = new For_Loop((yyvsp[-4].NodePtr), (yyvsp[-3].NodePtr), (yyvsp[-2].NodePtr), (yyvsp[0].NodePtr)); }
#line 1953 "src/parser.tab.cpp"
    break;

  case 78: /* type_specifier: T_INT  */
#line 240 "src/parser.y"
                        { (yyval.string) = new std::string("int"); }
#line 1959 "src/parser.tab.cpp"
    break;

  case 79: /* type_specifier: T_UNSIGNED  */
#line 241 "src/parser.y"
               {(yyval.string) = new std::string("unsigned");}
#line 1965 "src/parser.tab.cpp"
    break;


#line 1969 "src/parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 245 "src/parser.y"



const Node *g_root;

const Node* parseAST()
{
	g_root = 0;
	yyparse ();
	return g_root;
}
