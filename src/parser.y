%define parse.error verbose

%code requires{
    #include "ast.hpp"
    #include <cassert>
    #include <vector>

    extern const Node *g_root;

    int yylex(void);
    void yyerror(const char *);
}

%union
{
	Node 		           *NodePtr;
	std::string        	*string;
	int 			          number;
  float               float_num;
	std::vector<Node*>* 	NodeVectorPtr;
}

/* ------------------------------------					Tokens					------------------------------------ */

// Assignment Operators needed
%token T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN  T_TIMES_ASSIGN T_DIV_ASSIGN T_RIGHT_ASSIGN T_LEFT_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN T_MOD_ASSIGN
// Arithmetic Operators
%token T_TIMES T_DIVIDE T_PLUS T_MINUS
// Bitwise and Logical Operators
%token T_BIT_AND T_BIT_OR T_BIT_XOR T_LOGICAL_OR T_LOGICAL_AND T_RIGHT_SHIFT T_LEFT_SHIFT T_NOT T_BIT_NOT T_MOD
// Characters Operators
%token T_LBRACKET T_RBRACKET CUR_LBRACKET CUR_RBRACKET SQU_LBRACKET SQU_RBRACKET COLON SEMICOLON COMMA
// Comparison Operators
%token T_LESSTHAN T_GREATERTHAN T_LESS_EQUAL T_GREATER_EQUAL T_EQUAL T_NOT_EQUAL
// Types Operators
%token T_INT T_UNSIGNED T_FLOAT
// Structures Operators
%token T_IF T_ELSE T_WHILE T_RETURN T_FOR INC_OP DEC_OP
// Rules
%token NAME NUMBER FLOAT_NUMBER


%type <NodePtr> root_program external_declaration function_definition

%type <NodePtr>	declarator initialisation_declarator
%type <NodeVectorPtr> initialisation_declarator_list initialisation_list

%type <NodePtr> declaration parameter_declaration
%type <NodeVectorPtr> declaration_list parameter_list
%type <NodeVectorPtr> function_call_expression

%type <NodePtr> primary_expression postfix_expression
%type <NodePtr> multiply_expression add_expression unary_expression
%type <NodePtr> shift_expression compare_expression equal_expression
%type <NodePtr> bitwise_expression logical_expression
%type <NodePtr> assignment_expression expression

%type <NodePtr> statement
%type <NodePtr> jump_statement compound_statement expression_statement condition_statement iteration_statement

%type <NodeVectorPtr> statement_list

%type <string> 	NAME

%type <string> 	type_specifier

%type <number> NUMBER

%type <float_num> FLOAT_NUMBER


%start ROOT

%%


ROOT : root_program { g_root = $1; }

root_program
	: external_declaration { $$ = $1; }
	| root_program external_declaration { $$ = new Add_Program($1, $2); }
	;

external_declaration
	: function_definition { $$ = $1; }
	| declaration { $$ = $1; }
	;

function_definition
	: type_specifier NAME T_LBRACKET T_RBRACKET compound_statement { $$ = new Function_No_Arg_Definition( *$1, *$2, $5 );}
	| type_specifier NAME T_LBRACKET parameter_list T_RBRACKET compound_statement { $$ = new Function_With_Arg_Definition( *$1, *$2, $4, $6 );}
	;

initialisation_declarator_list
  : initialisation_declarator 											{ $$ = new std::vector<Node*>(1, $1);	}
	|	initialisation_declarator_list COMMA initialisation_declarator	{ $1->push_back($3); $$ = $1; }
  ;

initialisation_declarator
  : 	declarator 	{ $$ = $1; }
  | 	NAME T_ASSIGN assignment_expression 					{ $$ = new Initialisation_Variable_Declarator(*$1, $3); }
  | 	NAME SQU_LBRACKET add_expression SQU_RBRACKET T_ASSIGN CUR_LBRACKET initialisation_list CUR_RBRACKET 	{ $$ = new Initialisation_Array_Declarator(*$1, $3, $7); }
  ;

declaration_list
  : 	declaration 												{ $$ = new std::vector<Node*>(1, $1); }
	| 	declaration_list declaration  				{ $1->push_back($2); $$ = $1; }
  ;

declarator
  : NAME { $$ = new Variable_Declarator(*$1); }
  | NAME SQU_LBRACKET add_expression SQU_RBRACKET { $$ = new Array_Declarator(*$1, $3);}
  | NAME T_LBRACKET T_RBRACKET			{ $$ = new Function_Declarator(*$1, nullptr) ; }
  |	NAME T_LBRACKET parameter_list T_RBRACKET { $$ = new Function_Declarator(*$1, $3);}
  ;

declaration
  :	type_specifier SEMICOLON
	| type_specifier initialisation_declarator_list SEMICOLON 	{$$ = new Declaration(*$1, $2); }
  ;

parameter_declaration
  :	type_specifier declarator   { $$ = new Declaration(*$1, new std::vector<Node*>(1, $2)); }
  ;
parameter_list
  :	parameter_declaration				     					{ $$ = new std::vector<Node*>(1, $1); }
	|	parameter_list COMMA parameter_declaration 				{ $1->push_back($3); $$ = $1; }
  ;

function_call_expression
  : shift_expression										{ $$ = new std::vector<Node*>(1, $1); }
  | function_call_expression COMMA multiply_expression { $1->push_back($3); $$ = $1; }

primary_expression
  : 	NUMBER														{ $$ = new Int($1); }
  |   FLOAT_NUMBER                      {  $$ = new Float($1);}
	| 	NAME                              { $$ = new Variable(*$1);}
  |   NAME SQU_LBRACKET expression SQU_RBRACKET { $$ = new Array(*$1, $3);}
	| 	T_LBRACKET expression T_RBRACKET								{ $$ = $2; }
  |	  NAME T_LBRACKET T_RBRACKET			{ $$ = new Function_Call(*$1, nullptr) ; }
  |	  NAME T_LBRACKET function_call_expression T_RBRACKET  { $$ = new  Function_Call(*$1, $3); }
  ;

postfix_expression
  :	primary_expression												{ $$ = $1; }
	|	postfix_expression INC_OP 						{ $$ = new Post_Increment_Expression($1); }
  |	postfix_expression DEC_OP 						{ $$ = new Post_Decrement_Expression($1); }
  ;

add_expression
  : 	multiply_expression					  							{ $$ = $1; }
	| 	add_expression T_PLUS multiply_expression						{ $$ = new Add_Expression($1, $3); }
  | 	add_expression T_MINUS multiply_expression  					{ $$ = new Sub_Expression($1, $3); }
  ;

multiply_expression
  :	unary_expression				 								{ $$ = $1; }
	| multiply_expression T_TIMES unary_expression 				{ $$ = new Multiply_Expression($1, $3); }
	| multiply_expression T_DIVIDE unary_expression 				{ $$ = new Divide_Expression($1, $3); }
  | multiply_expression T_MOD unary_expression {  $$ = new Mod_Expression($1, $3);  }
  ;

unary_expression
	: postfix_expression { $$ = $1; }
	| INC_OP unary_expression { $$ = new Pre_Increment_Expression($2); }
	| DEC_OP unary_expression { $$ = new Pre_Decrement_Expression($2); }
	| T_PLUS multiply_expression { $$ = $2; }
	| T_MINUS multiply_expression { $$ = new Negation_Expression($2); }
	| T_NOT multiply_expression { $$ = new Logic_Not_Expression($2); }
  | T_BIT_NOT multiply_expression { $$ = new Bit_Not_Expression($2); }
	;

shift_expression
    : add_expression { $$=$1; }
    |	shift_expression T_LEFT_SHIFT add_expression					{ $$ = new Left_Shift_Expression($1, $3); }
    |	shift_expression T_RIGHT_SHIFT add_expression				{ $$ = new Right_Shift_Expression($1, $3); }
    ;

compare_expression
    : shift_expression { $$=$1; }
    |	compare_expression T_LESSTHAN shift_expression					{ $$ = new Less_Than_Expression($1, $3); }
    |	compare_expression T_LESS_EQUAL shift_expression				{ $$ = new Less_Equal_Expression($1, $3); }
    |	compare_expression T_GREATERTHAN shift_expression				{ $$ = new More_Than_Expression($1, $3); }
    |	compare_expression T_GREATER_EQUAL shift_expression			{ $$ = new More_Equal_Expression($1, $3); }
    ;

equal_expression
    : compare_expression { $$=$1; }
    |	equal_expression T_EQUAL compare_expression						{ $$ = new Equal_Expression($1, $3); }
    |	equal_expression T_NOT_EQUAL compare_expression					{ $$ = new Not_Equal_Expression($1, $3); }
    ;

bitwise_expression
  : 	equal_expression { $$=$1; }
  |   bitwise_expression T_BIT_AND equal_expression						{ $$ = new Bit_And_Expression($1, $3); }
  |   bitwise_expression T_BIT_OR equal_expression						{ $$ = new Bit_Or_Expression($1, $3); }
  |   bitwise_expression T_BIT_XOR equal_expression						{ $$ = new Bit_Xor_Expression($1, $3); }
  ;
logical_expression
  : 	bitwise_expression { $$=$1; }
  |   logical_expression T_LOGICAL_AND bitwise_expression						{ $$ = new Logic_And_Expression($1, $3); }
  |   logical_expression T_LOGICAL_OR bitwise_expression						{ $$ = new Logic_Or_Expression($1, $3); }
  ;
assignment_expression
  : logical_expression { $$=$1; }
	|	unary_expression T_ASSIGN assignment_expression 				{ $$ = new Direct_Assignment($1, $3); }
	| unary_expression T_TIMES_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Multiply_Expression($1, $3)); }
	| unary_expression T_DIV_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Divide_Expression($1, $3)); }
	| unary_expression T_MOD_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Mod_Expression($1, $3)); }
	| unary_expression T_PLUS_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Add_Expression($1, $3)); }
	| unary_expression T_MINUS_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Sub_Expression($1, $3)); }
	| unary_expression T_LEFT_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Left_Shift_Expression($1, $3)); }
	| unary_expression T_RIGHT_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Right_Shift_Expression($1, $3)); }
	| unary_expression T_AND_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Bit_And_Expression($1, $3)); }
	| unary_expression T_XOR_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Bit_Xor_Expression($1, $3)); }
	| unary_expression T_OR_ASSIGN assignment_expression { $$ = new Direct_Assignment($1, new Bit_Or_Expression($1, $3)); }
	;


initialisation_list
  : assignment_expression 			{ $$ = new std::vector<Node*>(1, $1);	}
  |	initialisation_list COMMA assignment_expression 	{ $1->push_back($3); $$=$1; }
  ;

expression
  : assignment_expression { $$=$1; }
  ;


statement
  : jump_statement														{ $$ = $1; }
  | compound_statement													{ $$ = $1; }
  | expression_statement												{ $$ = $1; }
  | condition_statement													{ $$ = $1; }
  |	iteration_statement													{ $$ = $1; }
  ;


statement_list
  : statement { $$ = new std::vector<Node*>{$1}; }
  | statement_list statement		{ $1->push_back($2); $$ = $1; }
  ;

compound_statement
  : CUR_LBRACKET CUR_RBRACKET {$$ = new Compound_Statement(NULL, NULL);}
  | CUR_LBRACKET statement_list CUR_RBRACKET					{ $$ = new Compound_Statement($2, NULL); }
  | CUR_LBRACKET declaration_list CUR_RBRACKET        { $$ = new Compound_Statement(NULL, $2); }
  | CUR_LBRACKET declaration_list statement_list CUR_RBRACKET {$$ = new Compound_Statement($3, $2);}
  ;


jump_statement
  : T_RETURN SEMICOLON												{ $$ = new Return(NULL); }
  | T_RETURN expression SEMICOLON										{ $$ = new Return($2); }

expression_statement
  : expression SEMICOLON												{ $$ = $1; }

condition_statement
  :	T_IF T_LBRACKET expression T_RBRACKET statement { $$ = new If_Statement($3, $5); }
  |	T_IF T_LBRACKET expression T_RBRACKET statement T_ELSE statement { $$ = new If_Else_Statement($3, $5, $7); }
  ;

iteration_statement
  :	T_WHILE T_LBRACKET expression T_RBRACKET statement { $$ = new While_Statement($3, $5); }
  | T_FOR T_LBRACKET expression_statement expression_statement T_RBRACKET statement { $$ = new For_Loop($3, $4, NULL, $6); }
	| T_FOR T_LBRACKET expression_statement expression_statement expression T_RBRACKET statement { $$ = new For_Loop($3, $4, $5, $7); }
  ;


type_specifier
  :	T_INT 		{ $$ = new std::string("int"); }
  | T_UNSIGNED {$$ = new std::string("unsigned");}
  | T_FLOAT {$$ = new std::string("float");}
;


%%


const Node *g_root;

const Node* parseAST()
{
	g_root = 0;
	yyparse ();
	return g_root;
}
