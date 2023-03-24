/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "src/parser.y"

    #include "ast.hpp"
    #include <cassert>
    #include <vector>

    extern const Node *g_root;

    int yylex(void);
    void yyerror(const char *);

#line 60 "src/parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ASSIGN = 258,                /* T_ASSIGN  */
    T_PLUS_ASSIGN = 259,           /* T_PLUS_ASSIGN  */
    T_MINUS_ASSIGN = 260,          /* T_MINUS_ASSIGN  */
    T_TIMES_ASSIGN = 261,          /* T_TIMES_ASSIGN  */
    T_DIV_ASSIGN = 262,            /* T_DIV_ASSIGN  */
    T_RIGHT_ASSIGN = 263,          /* T_RIGHT_ASSIGN  */
    T_LEFT_ASSIGN = 264,           /* T_LEFT_ASSIGN  */
    T_AND_ASSIGN = 265,            /* T_AND_ASSIGN  */
    T_XOR_ASSIGN = 266,            /* T_XOR_ASSIGN  */
    T_OR_ASSIGN = 267,             /* T_OR_ASSIGN  */
    T_MOD_ASSIGN = 268,            /* T_MOD_ASSIGN  */
    T_TIMES = 269,                 /* T_TIMES  */
    T_DIVIDE = 270,                /* T_DIVIDE  */
    T_PLUS = 271,                  /* T_PLUS  */
    T_MINUS = 272,                 /* T_MINUS  */
    T_BIT_AND = 273,               /* T_BIT_AND  */
    T_BIT_OR = 274,                /* T_BIT_OR  */
    T_BIT_XOR = 275,               /* T_BIT_XOR  */
    T_LOGICAL_OR = 276,            /* T_LOGICAL_OR  */
    T_LOGICAL_AND = 277,           /* T_LOGICAL_AND  */
    T_RIGHT_SHIFT = 278,           /* T_RIGHT_SHIFT  */
    T_LEFT_SHIFT = 279,            /* T_LEFT_SHIFT  */
    T_NOT = 280,                   /* T_NOT  */
    T_BIT_NOT = 281,               /* T_BIT_NOT  */
    T_MOD = 282,                   /* T_MOD  */
    T_LBRACKET = 283,              /* T_LBRACKET  */
    T_RBRACKET = 284,              /* T_RBRACKET  */
    CUR_LBRACKET = 285,            /* CUR_LBRACKET  */
    CUR_RBRACKET = 286,            /* CUR_RBRACKET  */
    SQU_LBRACKET = 287,            /* SQU_LBRACKET  */
    SQU_RBRACKET = 288,            /* SQU_RBRACKET  */
    COLON = 289,                   /* COLON  */
    SEMICOLON = 290,               /* SEMICOLON  */
    COMMA = 291,                   /* COMMA  */
    T_LESSTHAN = 292,              /* T_LESSTHAN  */
    T_GREATERTHAN = 293,           /* T_GREATERTHAN  */
    T_LESS_EQUAL = 294,            /* T_LESS_EQUAL  */
    T_GREATER_EQUAL = 295,         /* T_GREATER_EQUAL  */
    T_EQUAL = 296,                 /* T_EQUAL  */
    T_NOT_EQUAL = 297,             /* T_NOT_EQUAL  */
    T_INT = 298,                   /* T_INT  */
    T_UNSIGNED = 299,              /* T_UNSIGNED  */
    T_FLOAT = 300,                 /* T_FLOAT  */
    T_IF = 301,                    /* T_IF  */
    T_ELSE = 302,                  /* T_ELSE  */
    T_WHILE = 303,                 /* T_WHILE  */
    T_RETURN = 304,                /* T_RETURN  */
    T_FOR = 305,                   /* T_FOR  */
    INC_OP = 306,                  /* INC_OP  */
    DEC_OP = 307,                  /* DEC_OP  */
    NAME = 308,                    /* NAME  */
    NUMBER = 309,                  /* NUMBER  */
    FLOAT_NUMBER = 310             /* FLOAT_NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_ASSIGN 258
#define T_PLUS_ASSIGN 259
#define T_MINUS_ASSIGN 260
#define T_TIMES_ASSIGN 261
#define T_DIV_ASSIGN 262
#define T_RIGHT_ASSIGN 263
#define T_LEFT_ASSIGN 264
#define T_AND_ASSIGN 265
#define T_XOR_ASSIGN 266
#define T_OR_ASSIGN 267
#define T_MOD_ASSIGN 268
#define T_TIMES 269
#define T_DIVIDE 270
#define T_PLUS 271
#define T_MINUS 272
#define T_BIT_AND 273
#define T_BIT_OR 274
#define T_BIT_XOR 275
#define T_LOGICAL_OR 276
#define T_LOGICAL_AND 277
#define T_RIGHT_SHIFT 278
#define T_LEFT_SHIFT 279
#define T_NOT 280
#define T_BIT_NOT 281
#define T_MOD 282
#define T_LBRACKET 283
#define T_RBRACKET 284
#define CUR_LBRACKET 285
#define CUR_RBRACKET 286
#define SQU_LBRACKET 287
#define SQU_RBRACKET 288
#define COLON 289
#define SEMICOLON 290
#define COMMA 291
#define T_LESSTHAN 292
#define T_GREATERTHAN 293
#define T_LESS_EQUAL 294
#define T_GREATER_EQUAL 295
#define T_EQUAL 296
#define T_NOT_EQUAL 297
#define T_INT 298
#define T_UNSIGNED 299
#define T_FLOAT 300
#define T_IF 301
#define T_ELSE 302
#define T_WHILE 303
#define T_RETURN 304
#define T_FOR 305
#define INC_OP 306
#define DEC_OP 307
#define NAME 308
#define NUMBER 309
#define FLOAT_NUMBER 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/parser.y"

	Node 		           *NodePtr;
	std::string        	*string;
	int 			          number;
  float               float_num;
	std::vector<Node*>* 	NodeVectorPtr;

#line 198 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
