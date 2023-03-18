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
