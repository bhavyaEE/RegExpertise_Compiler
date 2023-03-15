#pragma once


#include "ast_node.hpp"

class Declarator : public Node 
{
	public:
		~Declarator(){}
        void visualiser(std::ostream &os) const override;
		void compile_declaration(std::ostream &os, /*Context& context,*/ type declarator_type) const override; 
		void compile_declaration_initialisation(std::ostream &os, /*Context& context,*/ type declarator_type, Expression* expressions) const override;
};
