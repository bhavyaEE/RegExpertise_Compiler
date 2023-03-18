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
    T_LBRACKET = 263,              /* T_LBRACKET  */
    T_RBRACKET = 264,              /* T_RBRACKET  */
    CUR_LBRACKET = 265,            /* CUR_LBRACKET  */
    CUR_RBRACKET = 266,            /* CUR_RBRACKET  */
    SQU_LBRACKET = 267,            /* SQU_LBRACKET  */
    SQU_RBRACKET = 268,            /* SQU_RBRACKET  */
    COLON = 269,                   /* COLON  */
    SEMICOLON = 270,               /* SEMICOLON  */
    COMMA = 271,                   /* COMMA  */
    T_LESSTHAN = 272,              /* T_LESSTHAN  */
    T_GREATERTHAN = 273,           /* T_GREATERTHAN  */
    T_LESS_EQUAL = 274,            /* T_LESS_EQUAL  */
    T_GREATER_EQUAL = 275,         /* T_GREATER_EQUAL  */
    T_EQUAL = 276,                 /* T_EQUAL  */
    T_NOT_EQUAL = 277,             /* T_NOT_EQUAL  */
    T_INT = 278,                   /* T_INT  */
    T_UNSIGNED = 279,              /* T_UNSIGNED  */
    T_IF = 280,                    /* T_IF  */
    T_ELSE = 281,                  /* T_ELSE  */
    T_WHILE = 282,                 /* T_WHILE  */
    T_RETURN = 283,                /* T_RETURN  */
    NAME = 284,                    /* NAME  */
    NUMBER = 285                   /* NUMBER  */
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
#define T_LBRACKET 263
#define T_RBRACKET 264
#define CUR_LBRACKET 265
#define CUR_RBRACKET 266
#define SQU_LBRACKET 267
#define SQU_RBRACKET 268
#define COLON 269
#define SEMICOLON 270
#define COMMA 271
#define T_LESSTHAN 272
#define T_GREATERTHAN 273
#define T_LESS_EQUAL 274
#define T_GREATER_EQUAL 275
#define T_EQUAL 276
#define T_NOT_EQUAL 277
#define T_INT 278
#define T_UNSIGNED 279
#define T_IF 280
#define T_ELSE 281
#define T_WHILE 282
#define T_RETURN 283
#define NAME 284
#define NUMBER 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "src/parser.y"

	Node 		           *NodePtr;
	std::string        	*string;
	int 			          number;
	std::vector<Node*>* 	NodeVectorPtr;

#line 147 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
