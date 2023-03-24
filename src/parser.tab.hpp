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
    T_TIMES = 259,                 /* T_TIMES  */
    T_DIVIDE = 260,                /* T_DIVIDE  */
    T_PLUS = 261,                  /* T_PLUS  */
    T_MINUS = 262,                 /* T_MINUS  */
    T_BIT_AND = 263,               /* T_BIT_AND  */
    T_BIT_OR = 264,                /* T_BIT_OR  */
    T_BIT_XOR = 265,               /* T_BIT_XOR  */
    T_LOGICAL_OR = 266,            /* T_LOGICAL_OR  */
    T_LOGICAL_AND = 267,           /* T_LOGICAL_AND  */
    T_RIGHT_SHIFT = 268,           /* T_RIGHT_SHIFT  */
    T_LEFT_SHIFT = 269,            /* T_LEFT_SHIFT  */
    T_LBRACKET = 270,              /* T_LBRACKET  */
    T_RBRACKET = 271,              /* T_RBRACKET  */
    CUR_LBRACKET = 272,            /* CUR_LBRACKET  */
    CUR_RBRACKET = 273,            /* CUR_RBRACKET  */
    SQU_LBRACKET = 274,            /* SQU_LBRACKET  */
    SQU_RBRACKET = 275,            /* SQU_RBRACKET  */
    COLON = 276,                   /* COLON  */
    SEMICOLON = 277,               /* SEMICOLON  */
    COMMA = 278,                   /* COMMA  */
    T_LESSTHAN = 279,              /* T_LESSTHAN  */
    T_GREATERTHAN = 280,           /* T_GREATERTHAN  */
    T_LESS_EQUAL = 281,            /* T_LESS_EQUAL  */
    T_GREATER_EQUAL = 282,         /* T_GREATER_EQUAL  */
    T_EQUAL = 283,                 /* T_EQUAL  */
    T_NOT_EQUAL = 284,             /* T_NOT_EQUAL  */
    T_INT = 285,                   /* T_INT  */
    T_UNSIGNED = 286,              /* T_UNSIGNED  */
    T_FLOAT = 287,                 /* T_FLOAT  */
    T_IF = 288,                    /* T_IF  */
    T_ELSE = 289,                  /* T_ELSE  */
    T_WHILE = 290,                 /* T_WHILE  */
    T_RETURN = 291,                /* T_RETURN  */
    T_FOR = 292,                   /* T_FOR  */
    INC_OP = 293,                  /* INC_OP  */
    NAME = 294,                    /* NAME  */
    NUMBER = 295,                  /* NUMBER  */
    FLOAT_NUMBER = 296             /* FLOAT_NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_ASSIGN 258
#define T_TIMES 259
#define T_DIVIDE 260
#define T_PLUS 261
#define T_MINUS 262
#define T_BIT_AND 263
#define T_BIT_OR 264
#define T_BIT_XOR 265
#define T_LOGICAL_OR 266
#define T_LOGICAL_AND 267
#define T_RIGHT_SHIFT 268
#define T_LEFT_SHIFT 269
#define T_LBRACKET 270
#define T_RBRACKET 271
#define CUR_LBRACKET 272
#define CUR_RBRACKET 273
#define SQU_LBRACKET 274
#define SQU_RBRACKET 275
#define COLON 276
#define SEMICOLON 277
#define COMMA 278
#define T_LESSTHAN 279
#define T_GREATERTHAN 280
#define T_LESS_EQUAL 281
#define T_GREATER_EQUAL 282
#define T_EQUAL 283
#define T_NOT_EQUAL 284
#define T_INT 285
#define T_UNSIGNED 286
#define T_FLOAT 287
#define T_IF 288
#define T_ELSE 289
#define T_WHILE 290
#define T_RETURN 291
#define T_FOR 292
#define INC_OP 293
#define NAME 294
#define NUMBER 295
#define FLOAT_NUMBER 296

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

#line 170 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
