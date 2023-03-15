#ifndef ast_declaration.hpp
#define ast_declaration.hpp


#include "ast_node.hpp"


class Declaration : public Node
{
    private:
		std::string Type;
		Node* Init_Declarator;

	public:
		Declaration(std::string _TYPE, Node* _init_declarator);
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &dst, Context& context, int destReg) const override;
}