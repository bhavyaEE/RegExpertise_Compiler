%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  	const Node *NodePtr;
  	int number;
  	std::string string;
  	Declarator 		*DeclaratorPtr;
	Declaration 	*DeclarationPtr;
	Statement 		*StatementPtr;
	Expression 		*ExpressionPtr;
	std::vector<Declaration*> *DeclarationVectorPtr; 
  //can I have vector of node pointer?
}



%token NAME //CONSTANT STRING_LITERAL SIZEOF
//arithmetic operators
%token T_TIMES T_PLUS T_MINUS T_DIVIDE T_MOD T_INCREMENT T_DECREMENT 
//bitwise operators
%token T_BIT_NOT T_BIT_AND T_BIT_OR T_BIT_XOR T_BIT_LEFT_SHIFT T_BIT_RIGHT_SHIFT
//assignment
%token RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
//logical operators
%token T_L_NOT T_L_AND T_L_OR
//comparison
%token T_LESSTHAN T_GREATERTHAN T_EQUAL T_NOTEQUAL
//characters
%token T_LBRACKET T_RBRACKET CUR_LBRACKET CUR_RBRACKET SQU_LBRACKET SQU_RBRACKET SEMICOLON COLON COMMA
//structures
%token T_RETURN T_IF T_ELSE
//%token TYPEDEF EXTERN STATIC AUTO REGISTER
//types
%token T_INT //CHAR SHORT  LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID


/* %type need to do this */
%type <NodePtr> root_program external_declaration function_definition
%type <NodePtr> type_specifier
%type <string> NAME  
%type <number> NUMBER
%type <StatementPtr> statement compound_statement jump_statement
%type <DeclarationVectorPtr> parameter_list
%type <DeclarationPtr> parameter_declaration
%type <DeclaratorPtr> declarator
%type <DeclarationPtr> declaration
%type <ExpressionPtr> expression assignment_expression conditional_expression logical_and_expression logical_or_expression
%type <ExpressionPtr> inclusive_or_expression exclusive_or_expression
%type <ExpressionPtr> and_expression equality_expression relational_expression shift_expression 
%type <ExpressionPtr> additive_expression multiplicative_expression unary_expression postfix_expression primary_expression
//T_INT is also pointer to a string but why


%start ROOT
%%

/* ------------------------------------	*/
ROOT : root_program { g_root = $1; }

root_program
	: external_declaration { $$ = $1; }
	| root_program external_declaration { std::cerr << "TODO, write a root_program function i guess in ast" << std::endl;  }
	;

external_declaration
	: function_definition { $$ = $1; }
	| declaration { $$ = $1; }
	;

function_definition
	: type_specifier NAME T_LBRACKET T_RBRACKET compound_statement { $$ = new Function_No_Arg_Definition( $1, *$2, $5 ); /*need to implement func_def*/} //like int f( ){ body};
	| type_specifier NAME T_LBRACKET parameter_list T_RBRACKET compound_statement { $$ = new Function_With_Arg_Definition( $1, *$2, $4, $6 );} //like int f(parameters ){ body};
	;

declaration
	: type_specifier SEMICOLON
	| type_specifier init_declarator SEMICOLON {$$ = new Declaration(*$1, $2);}
	;

/* init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	; */

init_declarator
	: declarator
	| declarator '=' initializer
	;


type_specifier
	: //VOID
	/* | CHAR
	| SHORT |*/
	 T_INT { $$ = new type_specifier(typeINT); }
	/* | LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME */
	;

declarator
	: NAME { $$ = new Variable_Declarator(*$1); /*need to implement declarator*/}
	/* | direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']' */
	/* | declarator T_LBRACKET parameter_type_list T_RBRACKET
	| declarator T_LBRACKET identifier_list T_RBRACKET */
	; 

parameter_list
	: parameter_declaration { $$ = new std::vector<Declaration*>{$1}; }
	| parameter_list COMMA parameter_declaration {$1->push_back($3); $$ = $1;}
	;

parameter_declaration
	: type_specifier declarator { $$ = new Declaration($1, $2);}
	/* | declaration_specifiers abstract_declarator
	| declaration_specifiers */
	;

compound_statement
	: CUR_LBRACKET CUR_RBRACKET
	| CUR_LBRACKET statement_list CUR_RBRACKET
	| CUR_LBRACKET declaration_list CUR_RBRACKET
	| CUR_LBRACKET declaration_list statement_list CUR_RBRACKET
	;

declaration_list
	: declarator
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| T_LBRACKET expression T_RBRACKET
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression T_LBRACKET T_RBRACKET
	| postfix_expression T_LBRACKET argument_expression_list T_RBRACKET
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF T_LBRACKET type_name T_RBRACKET
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;


multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;


init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;



struct_or_union_specifier
	: struct_or_union IDENTIFIER CUR_LBRACKET struct_declaration_list CUR_RBRACKET
	| struct_or_union CUR_LBRACKET struct_declaration_list CUR_RBRACKET
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM CUR_LBRACKET enumerator_list CUR_RBRACKET
	| ENUM IDENTIFIER CUR_LBRACKET enumerator_list CUR_RBRACKET
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;


pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;




identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: T_LBRACKET abstract_declarator T_RBRACKET
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| T_LBRACKET T_RBRACKET
	| T_LBRACKET parameter_type_list T_RBRACKET
	| direct_abstract_declarator T_LBRACKET T_RBRACKET
	| direct_abstract_declarator T_LBRACKET parameter_type_list T_RBRACKET
	;

initializer
	: assignment_expression
	| CUR_LBRACKET initializer_list CUR_RBRACKET
	| CUR_LBRACKET initializer_list ',' CUR_RBRACKET
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;


expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF T_LBRACKET expression T_RBRACKET statement
	| IF T_LBRACKET expression T_RBRACKET statement ELSE statement
	| SWITCH T_LBRACKET expression T_RBRACKET statement
	;

iteration_statement
	: WHILE T_LBRACKET expression T_RBRACKET statement
	| DO statement WHILE T_LBRACKET expression T_RBRACKET ';'
	| FOR T_LBRACKET expression_statement expression_statement T_RBRACKET statement
	| FOR T_LBRACKET expression_statement expression_statement expression T_RBRACKET statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;



%%

const Node *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}