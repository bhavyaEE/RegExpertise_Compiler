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
	const Node 		*NodePtr;
	std::string 	*string;
	int 			number;
	std::vector<NodePtr>* 	NodeVectorPtr;
}

/* ------------------------------------					Tokens					------------------------------------ */

// Assignment Operators needed
%token T_ASSIGN
// Arithmetic Operators
%token T_TIMES T_DIVIDE T_PLUS T_MINUS 
// Characters Operators
%token T_LBRACKET T_RBRACKET CUR_LBRACKET CUR_RBRACKET SQU_LBRACKET SQU_RBRACKET COLON SEMICOLON COMMA
// Comparison Operators
%token T_LESSTHAN T_GREATERTHAN T_LESS_EQUAL T_GREATER_EQUAL T_EQUAL T_NOT_EQUAL
// Types Operators
%token T_INT 
// Structures Operators
%token T_IF T_ELSE T_WHILE T_RETURN
// Rules
%token NAME NUMBER 


%type <NodePtr> root_program external_declaration function_definition

%type <NodePtr>	declarator initialisation_declarator
%type <NodeVectorPtr> initialisation_declarator_list

%type <NodePtr> declaration //parameter_declaration 
%type <NodeVectorPtr> declaration_list //parameter_list

%type <NodePtr> primary_expression postfix_expression 
%type <NodePtr> multiply_expression add_expression 
%type <NodePtr> compare_expression equal_expression
%type <NodePtr> bitwise_expression logical_expression  
%type <NodePtr> assignment_expression expression 

%type <NodePtr> statement 
%type <NodePtr> jump_statement compound_statement expression_statement condition_statement iteration_statement

%type <NodeVectorPtr> statement_list

%type <string> 	NAME   

%type <string> 	type_specifier 

%type <number> NUMBER


%start ROOT

%%


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
	: type_specifier NAME T_LBRACKET T_RBRACKET compound_statement { $$ = new Function_No_Arg_Definition( *$1, *$2, $5 );} //like int f( ){ body};
	/* | type_specifier NAME T_LBRACKET parameter_list T_RBRACKET compound_statement { $$ = new Function_With_Arg_Definition( $1, *$2, $4, $6 );} //like int f(parameters ){ body}; */
	;

initialisation_declarator_list	
    : 	initialisation_declarator 											{ $$ = new std::vector<NodePtr>(1, $1);	}
	|	initialisation_declarator_list COMMA initialisation_declarator	{ $1->push_back($3); $$ = $1; }

initialisation_declarator		
    : 	declarator 													{ $$ = $1; }
	| 	declarator T_ASSIGN assignment_expression 					{ $$ = new Initialisation_Variable_Declarator($1, $3); }

declaration_list				
    : 	declaration 												{ $$ = new std::vector<NodePtr>(1, $1); } 
	| 	declaration_list declaration  								{ $1->push_back($2); $$ = $1; }

declarator: 	
    NAME { $$ = new Variable_Declarator(*$1); }

declaration 					
    :	type_specifier SEMICOLON											{ $$ = new Declaration(*$1); }
	| 	type_specifier initialisation_declarator_list SEMICOLON 			{ $$ = new Declaration(*$1, $2); }



primary_expression				
    : 	NUMBER														{ $$ = new Int($1); }
	| 	NAME		 											{ $$ = new Variable(*$1);	}	
	| 	T_LBRACKET expression T_RBRACKET								{ $$ = $2; }		

postfix_expression				
    :	primary_expression												{ $$ = $1; }
	/* |	primary_expression INC_OP										{ $$ = new Post_Increment_Expression($1); } */

add_expression					
    : 	multiply_expression					  							{ $$ = $1; }
	| 	add_expression T_PLUS multiply_expression						{ $$ = new Add_Expression($1, $3); }
	| 	add_expression T_MINUS multiply_expression  					{ $$ = new Sub_Expression($1, $3); }

multiply_expression				
    :	postfix_expression				 								{ $$ = $1; }
	| 	multiply_expression T_TIMES postfix_expression 				{ $$ = new Multiply_Expression($1, $3); }
	| 	multiply_expression T_DIVIDE postfix_expression 				{ $$ = new Divide_Expression($1, $3); }

compare_expression				
    : 	add_expression
    |	compare_expression T_LESSTHAN add_expression					{ $$ = new Less_Than_Expression($1, $3); }
    |	compare_expression T_LESS_EQUAL add_expression				{ $$ = new Less_Equal_Expression($1, $3); }
    |	compare_expression T_GREATERTHAN add_expression				{ $$ = new More_THAN_Expression($1, $3); }
    |	compare_expression T_GREATER_EQUAL add_expression			{ $$ = new More_Equal_Expression($1, $3); }

equal_expression				
    : 	compare_expression 
    |	equal_expression T_EQUAL compare_expression						{ $$ = new Equal_Expression($1, $3); }
    |	equal_expression T_NOT_EQUAL compare_expression					{ $$ = new Not_Equal_Expression($1, $3); }

bitwise_expression				
    : 	equal_expression 

logical_expression				
    : 	bitwise_expression

assignment_expression			
    : 	logical_expression 
	|	postfix_expression T_ASSIGN assignment_expression 				{ $$ = new Direct_Assignment($1, $3); }	

expression 
    :   assignment_expression


statement 						
    : 	jump_statement														{ $$ = $1; }
    | 	compound_statement													{ $$ = $1; }
    | 	expression_statement												{ $$ = $1; }
    | 	condition_statement													{ $$ = $1; }
    |	iteration_statement													{ $$ = $1; }


statement_list 					
    : 	statement 															{ $$ = new std::vector<NodePtr>(1, $1); }
    | 	statement_list statement											{ $1->push_back($2); $$ = $1; }


compound_statement  			
    : 	CUR_LBRACKET CUR_RBRACKET									{ $$ = new Compound_Statement(); }
    | 	CUR_LBRACKET statement_list CUR_RBRACKET					{ $$ = new Compound_Statement(NULL, $2); }
    | 	CUR_LBRACKET declaration_list CUR_RBRACKET					{ $$ = new Compound_Statement($2, NULL); }
    | 	CUR_LBRACKET declaration_list statement_list CUR_RBRACKET	{ $$ = new Compound_Statement($2, $3); }
					
jump_statement					
    : 	T_RETURN SEMICOLON												{ $$ = new Jump_Statement(); }
    | 	T_RETURN expression SEMICOLON										{ $$ = new Jump_Statement($2); }

expression_statement			
    : 	expression SEMICOLON												{ $$ = new Expression_Statement($1); }

condition_statement 			
    :	T_IF T_LBRACKET expression T_RBRACKET statement						{ $$ = new Condition_If_Statement($3,$5); }	
    |	T_IF T_LBRACKET expression T_RBRACKET statement T_ELSE statement	{ $$ = new Condition_If_Else_Statement($3,$5,$7); }

iteration_statement				
    :	T_WHILE T_LBRACKET expression T_RBRACKET statement 				{ $$ = new While_Statement($3,$5); }


type_specifier	
:	T_INT 		{ $$ = new std::string("int"); }
		

%%


const Node *g_root; 

const Node* parseAST()
{
	g_root = 0;
	yyparse ();
	return g_root;
}
