#pragma once

#include "ast_node.hpp"


class Compound_Statement : public Node
{
	private:
		std::vector<Node*>* 	statement_list;
		std::vector<Node*>* 	declaration_list;

	public:
		Compound_Statement (std::vector<Node*>* _declaration_list, std::vector<Node*>* _statement_list);
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};

class If_Statement : public Node
{
	private:
		Node* condition;
		Node* statement;

	public:
		If_Statement (Node* _condition, Node* _statement);
		~If_Statement(); 
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};

class If_Else_Statement : public Node
{
	private:
		Node*	condition;
		Node*	true_statement;
		Node* else_statement;

	public:
		If_Else_Statement (Node* _condition, Node* _true_statement, Node* _else_statement);
		~If_Else_Statement(); 
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};

class While_Statement : public Node
{
	private:
		Node* 	expression;
		Node*	statement; 	
	public:
		While_Statement (Node* _expression, Node* _statement);
		~While_Statement(); 
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};

class For_Loop : public Node 
{
	private: 
		Node* initial_expression;
		Node* loop_condition;
		Node* increment_expression;
		Node* statement;

	public: 
		For_Loop (Node* _initial_expression, Node* _loop_condition, Node* _increment_expression, Node* _statement);
		~For_Loop(); 
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};