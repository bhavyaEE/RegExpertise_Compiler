#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_declaration.hpp"
#include "ast/ast_declarator.hpp"
#include "ast/ast_function.hpp"
#include "ast/ast_integer.hpp"
#include "ast/ast_return.hpp"
#include "ast/ast_node.hpp"


extern const Expression *parseAST();

#endif
