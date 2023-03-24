#pragma once

#include "ast_node.hpp"

class Variable_Declarator : public Node
{
private:
	std::string variable_name;

public:
	Variable_Declarator(std::string var_name);
	~Variable_Declarator();
	virtual std::string get_variable_name() const;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Initialisation_Variable_Declarator : public Node
{
private:
	std::string variable_name;
	Node *expression;

public:
	Initialisation_Variable_Declarator(std::string var_name, Node *_expression);
	~Initialisation_Variable_Declarator();
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Array_Declarator : public Node
{
private:
	std::string array_name;
	Node *array_size_expression;

public:
	Array_Declarator(std::string _array_name, Node *_expression);
	~Array_Declarator();
	std::string get_array_name() const;
	int get_array_size(Context &context) const;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Initialisation_Array_Declarator : public Node
{
private:
	std::string init_array_name;
	Node *expression;
	std::vector<Node *> *initialisation_list;

public:
	Initialisation_Array_Declarator(std::string _array_name, Node *_expression, std::vector<Node *> *_initialisation_list);
	~Initialisation_Array_Declarator(){};
	int get_array_size(Context &context) const;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Function_Declarator : public Node
{
private:
	std::string fname;
	std::vector<Node *> *argument_list;

public:
	Function_Declarator(std::string _fname, std::vector<Node *> *_argument_list);
	~Function_Declarator() {}
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};
