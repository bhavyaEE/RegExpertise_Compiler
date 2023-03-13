#ifndef ast_function.hpp
#define ast_function.hpp


#include "ast/ast_node.hpp"

class Declarator : public Node 
{
	public:
        void visualiser(std::ostream &os) const override;
		virtual void compile_declaration(std::ostream &dst, Context& context, type declarator_type) const override; 
		virtual void compile_declaration_initialisation(std::ostream &dst, Context& context, type declarator_type, Expression* expressions) const override;
};