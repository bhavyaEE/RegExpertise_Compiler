#pragma once

#include "ast_node.hpp"
#include "ast_primitive.hpp"

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Direct_Assignment : public Node
{
private:
	Node *left;
	Node *expression;

public:
	Direct_Assignment(Node *_left, Node *_right);
	~Direct_Assignment(){};
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Function_Call : public Node
{
private:
	std::string function_name;
	std::vector<Node *> *function_arguments;

public:
	Function_Call(std::string _function_name, std::vector<Node *> *_function_arguments);
	~Function_Call(){};
	bool isFunction() const override;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

/* -------------------Arithmetic------------------------ */

class Add_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Add_Expression(Node *left, Node *right);
	~Add_Expression();
	int get_value(Context &context) const override;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Sub_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Sub_Expression(Node *left, Node *right);
	~Sub_Expression();
	int get_value(Context &context) const override;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Multiply_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Multiply_Expression(Node *_left, Node *_right);
	~Multiply_Expression();
	int get_value(Context &context) const override;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Divide_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Divide_Expression(Node *_left, Node *_right);
	~Divide_Expression();
	int get_value(Context &context) const override;
	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

/* -------------------Comparison------------------------ */

class Equal_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Equal_Expression(Node *_left, Node *_right);
	~Equal_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Not_Equal_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Not_Equal_Expression(Node *_left, Node *_right);
	~Not_Equal_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Less_Than_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Less_Than_Expression(Node *_left, Node *_right);
	~Less_Than_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class More_Than_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	More_Than_Expression(Node *_left, Node *_right);
	~More_Than_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Less_Equal_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Less_Equal_Expression(Node *_left, Node *_right);
	~Less_Equal_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class More_Equal_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	More_Equal_Expression(Node *_left, Node *_right);
	~More_Equal_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

/* -------------------Bitwise------------------------ */

class Bit_And_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Bit_And_Expression(Node *_left, Node *_right);
	~Bit_And_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Bit_Or_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Bit_Or_Expression(Node *_left, Node *_right);
	~Bit_Or_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Bit_Xor_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Bit_Xor_Expression(Node *_left, Node *_right);
	~Bit_Xor_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Bit_Not_Expression : public Node
{
private:
	Node *op;

public:
	Bit_Not_Expression(Node *_op);
	~Bit_Not_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

/* -------------------Logical------------------------ */

class Logic_And_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Logic_And_Expression(Node *_left, Node *_right);
	~Logic_And_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Logic_Or_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Logic_Or_Expression(Node *_left, Node *_right);
	~Logic_Or_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Logic_Not_Expression : public Node
{
private:
	Node *op;

public:
	Logic_Not_Expression(Node *_op);
	~Logic_Not_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Left_Shift_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Left_Shift_Expression(Node *_left, Node *_right);
	~Left_Shift_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Right_Shift_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Right_Shift_Expression(Node *_left, Node *_right);
	~Right_Shift_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Mod_Expression : public Node
{
private:
	Node *leftop;
	Node *rightop;

public:
	Mod_Expression(Node *_left, Node *_right);
	~Mod_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Post_Increment_Expression : public Node
{
private:
	Node *op;

public:
	Post_Increment_Expression(Node *_op);
	~Post_Increment_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Pre_Increment_Expression : public Node
{
private:
	Node *op;

public:
	Pre_Increment_Expression(Node *_op);
	~Pre_Increment_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Post_Decrement_Expression : public Node
{
private:
	Node *op;

public:
	Post_Decrement_Expression(Node *_op);
	~Post_Decrement_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};
class Pre_Decrement_Expression : public Node
{
private:
	Node *op;

public:
	Pre_Decrement_Expression(Node *_op);
	~Pre_Decrement_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};

class Negation_Expression : public Node
{
private:
	Node *op;

public:
	Negation_Expression(Node *_op);
	~Negation_Expression();

	void visualiser(std::ostream &os) const override;
	void generateRISCV(std::ostream &os, Context &context, int destReg) const override;
};
