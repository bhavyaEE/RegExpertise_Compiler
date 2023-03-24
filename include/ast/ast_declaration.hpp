#pragma once

#include "ast_node.hpp"
#include "ast_declarator.hpp"

class Declaration : public Node
{
    private:
		std::string Type;
		std::vector<Node*>* Init_Declarator_List;

	public:
		Declaration(std::string _TYPE, std::vector<Node*>* _Init_Declarator_List);
		~Declaration();
		virtual std::string get_parameter() const;
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
		std::string get_data_type(Context& context) const override;
};

class Add_Program : public Node
{
	private:
		Node* left;
		Node* right;

	public:
		Add_Program(Node* _left, Node* _right);
		~Add_Program(){};
		void visualiser(std::ostream &os) const override;
		void generateRISCV(std::ostream &os, Context& context, int destReg) const override;
};
