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
[=]             { return T_ASSIGN; }
[+=]            { return T_PLUSEQUAL; }
[!]             { return T_NOT; }

[~]             { return T_BITNOT; }
[&]             { return T_BITAND; }
[|]             { return T_BITOR; }
[\^]            { return T_BITXOR; }
[<<]            { return T_BITLEFTSSHIFT; }
[<<]            { return T_BITRIGHTSHIFT; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }

log             { return T_LOG; }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

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
