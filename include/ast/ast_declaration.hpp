#pragma once

#include "ast_node.hpp"


class Declaration : public Node
{
    private:
		std::string Type;
		Node* Init_Declarator;

	public:
		Declaration(std::string _TYPE, Node* _init_declarator);
		~Declaration(){}
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, /*Context& context,*/ int destReg) const override;
};
