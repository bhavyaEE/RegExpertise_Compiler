%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
////assignment =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=

//bitwise &, ^, |, ~, >>, <<

//comparison ==, !=, >, < >=, <=

//logical &&, ||, !
//+, -, *, /, % (mod), ++, -- arithmetic

extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%
/* arithmetic operators */
[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\/]            { return T_DIVIDE; }
[%]             { return T_MOD; } 
[++]			      { return T_INCREMENT; }
[--]			      { return T_DECREMENT; }

/*bitwise operators*/
[~]             { return T_BIT_NOT; }
[&]             { return T_BIT_AND; }
[|]             { return T_BIT_OR; }
[\^]            { return T_BIT_XOR; }
[<<]            { return T_BIT_LEFT_SHIFT; }
[<<]            { return T_BIT_RIGHT_SHIFT; }

/* assignet operators*/
[>>=]			    { return RIGHT_ASSIGN; }
[<<=]			      {  return LEFT_ASSIGN; }
[+=]	    		  {  return  ADD_ASSIGN; }
[-=]            {  return  SUB_ASSIGN; }
[*=]	    		  {  return  MUL_ASSIGN; }
[/=]	    		  {  return  DIV_ASSIGN; }
[%=]			{  return  MOD_ASSIGN; }
[&=]			{  return  AND_ASSIGN; }
[^=]			{  return  XOR_ASSIGN; }
[|=]			{  return  OR_ASSIGN; }

/* logical operators */
[!]             { return T_L_NOT; }
[&&]			{  return  T_L_AND; }
[||]			{  return  T_L_OR; }

/* comparison */
[<]			{  return  T_LESSTHAN; }
[>]			{  return  T_GREATERTHAN; }
[==]			{  return  T_EQUAL; }
[!=]			{  return  T_NOTEQUAL; }

/* characters */
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]         { return CUR_LBRACKET; }
[}]         { return CUR_RBRACKET; }
[[]         { return SQU_LBRACKET; }
[]]         { return SQU_RBRACKET; }
[;]			    { return  SEMICOLON; }
[:]         { return COLON;}
[,]         { return COMMA; }

/* structures */
"return"        { return T_RETURN; }
"if"            { return T_IF; }
"else"          { return T_ELSE; }

/* types */
"int"           { return T_INT; }
/* for later
"double"        { return T_DOUBLE;}
"char"        { return T_CHAR;}
"float"        { return T_FLOAT;}
"double"        { return T_DOUBLE;} */


[0-9]+([.][0-9]*)?      { yylval.number=strtod(yytext, 0); return NUMBER; }
[a-zA-Z_]+[a-zA-Z0-9_]* { yylval.string= new std::string(yytext); return NAME; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
