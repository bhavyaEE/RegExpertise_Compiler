#ifndef ast_declaration.hpp
#define ast_declaration.hpp


#include "ast/ast_node.hpp"
#include "ast/ast_type_specifier.hpp"

class Declaration : public Node
{
    private:
		type_specifier* Type;
		Declarator* Init_Declarator;

	public:
		Declaration(type_specifier* _TYPE, Declarator* _init_declarator) 
		: TYPE(_TYPE), Init_Declarator(_init_declarator) {}

		virtual void compile(std::ostream &dst, Context& context, int destReg) const override
		{
			*Init_Declarator->generateRISCV(dst, context, destReg);
		}
}