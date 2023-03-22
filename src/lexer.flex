%option noyywrap

%{
  #include "parser.tab.hpp"
%}


%%
  /* Comments (To be done at a later date) */
  // "/*"			{ comment(); }

[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\/]            { return T_DIVIDE; }

[&]                                 { return (T_BIT_AND); }
[|]                                 { return (T_BIT_OR); }
[\^]                                { return (T_BIT_XOR); }
[|][|]            {return (T_LOGICAL_OR);}     
[&][&]            {return (T_LOGICAL_AND);}  
[+][+]            {return (INC_OP); }                     

[<]			{  return  T_LESSTHAN; }
[>]			{  return  T_GREATERTHAN; }
[<][=]   { return T_LESS_EQUAL; }
[>][=]    { return T_GREATER_EQUAL; }
[=][=]			{  return  T_EQUAL; }
[!][=]			{  return  T_NOT_EQUAL; }
[>][>]			{  return  T_RIGHT_SHIFT; }
[<][<]			{  return  T_LEFT_SHIFT; }

[=]     { return T_ASSIGN; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]         { return CUR_LBRACKET; }
[}]         { return CUR_RBRACKET; }
[[]         { return SQU_LBRACKET; }
[]]         { return SQU_RBRACKET; }
[;]			    { return  SEMICOLON; }
[:]         { return COLON;}
[,]         { return COMMA; }

"return"        { return T_RETURN; }
"if"            { return T_IF; }
"else"          { return T_ELSE; }
"while"         { return T_WHILE; }
"for"			      { return(T_FOR); }

"int"           { return T_INT; }
"unsigned"      { return T_UNSIGNED;}

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