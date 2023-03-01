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

[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\/]            { return T_DIVIDE; }
[%]             { return T_MOD; } 
[++]			      { return INCREMENT; }
[--]			      { return DECREMENT; }

[~]             { return T_BITNOT; }
[&]             { return T_BITAND; }
[|]             { return T_BITOR; }
[\^]            { return T_BITXOR; }
[<<]            { return T_BITLEFTSSHIFT; }
[<<]            { return T_BITRIGHTSHIFT; }

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

[!]             { return L_NOT; }
[&&]			{  return  L_AND; }
[||]			{  return  L_OR; }

[<=]			{  return  LESSTHAN; }
[>=]			{  return  GREATERTHAN; }
[==]			{  return  EQUAL; }
[!=]			{  return  NOTEQUAL; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]         { return CUR_LBRACKET; }
[}]         { return CUR_RBRACKET; }
[;]			    {  return  SEMICOLON  ; }

log             { return T_LOG; }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

return        { return RETURN; }
int           { return INT; }
if            { return IF; }
else          { return ELSE; }
etc

[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[a-z]+          { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
