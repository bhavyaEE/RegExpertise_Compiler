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
		Declaration(type_specifier* _TYPE, Declarator* _init_declarator);
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &dst, Context& context, int destReg) const override;
}