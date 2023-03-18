#pragma once


#include "ast_node.hpp"

class Variable_Declarator : public Node
{
	private: std::string variable_name;
	public:
		Variable_Declarator(std::string var_name);
		~Variable_Declarator();
        void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;

};

class Initialisation_Variable_Declarator : public Node
{
	private:
		std::string variable_name;
		Node*		expression;
	public:
		Initialisation_Variable_Declarator(std::string var_name, Node* _expression);
		~Initialisation_Variable_Declarator();
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;


};
