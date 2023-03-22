#pragma once


#include "ast_node.hpp"

class Variable_Declarator : public Node
{
	private: std::string variable_name;
	public:
		Variable_Declarator(std::string var_name);
		~Variable_Declarator();
		virtual std::string get_variable_name() const;
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

class Array_Declarator : public Node
{
	private:
		std::string array_name;
		Node*		array_size_expression;
	public:
		Array_Declarator(std::string _array_name, Node* _expression);
		~Array_Declarator();
		std::string get_array_name() const;
		int get_array_size(Context& context) const;
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};
