#pragma once

#include "ast_node.hpp"

#include <string>
#include <iostream>
#include <map>
#include <memory>


class Add_Expression : public Node
{
	public:
		Add_Expression (Expression* _left, Expression* _right) : Operator (_left, _right) {}

		void generateRISCV(std::ostream &os, /*Context& context,*/ int destReg) const override
		{

		}
		
};

class Sub_Expression : public Node
{
	public:
		Sub_Expression (Expression* _left, Expression* _right) : Operator (_left, _right) {}

		void generateRISCV(std::ostream &os, /*Context& context,*/ int destReg) const override
		{

		}
};

class Multiply_Expression : public Node
{
	public:
		Multiply_Expression (Expression* _left, Expression* _right) : Operator (_left,_right) {}


};

class Divide_Expression : public Node
{
	public:
		Divide_Expression (Expression* _left, Expression* _right) : Operator (_left,_right) {}

};

class Less_Than_Expression : public Node
{
	public:
		Less_Than_Expression (Expression* _left, Expression* _right) : Operator (_left, _right) {}
};

class More_Than_Expression : public Node
{
	public:
		More_Than_Expression (Expression* _left, Expression* _right) : Operator (_left, _right) {}
};

class Less_Equal_Expression : public Node
{
	public:
		Less_Than_Equal_Expression (Expression* _left, Expression* _right) : Operator (_left, _right) {}
};

class More_Equal_Expression : public Node
{
	public:
		More_Than_Equal_Expression (Expression* _left, Expression* _right) : Operator (_left,_right) {}
};

class Equal_Expression : public Node
{
	public:
		Equal_Expression (Expression* _left, Expression* _right) : Operator (_left,_right) {}
};

class Not_Equal_Expression : public Node
{
	public:
		Not_Equal_Expression (Expression* _left, Expression* _right) : Operator (_left,_right) {}
};

