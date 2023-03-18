#include "ast/ast_statement.hpp"

Compound_Statement::Compound_Statement (std::vector<Node*>* _declaration_list, std::vector<Node*>* _statement_list)
	: statement_list (_statement_list), declaration_list (_declaration_list) {}

void Compound_Statement::visualiser(std::ostream &os) const{
    if (declaration_list != NULL)
    {
        for (auto declaration = declaration_list->begin(); declaration != declaration_list->end(); declaration++)
        {
            (*declaration)->visualiser(os);
        }
    }

    if (statement_list != NULL)
    {
        for(auto statement = statement_list->begin(); statement != statement_list->end(); statement++)
        {
            (*statement)->visualiser(os);
        }
    }
}
void Compound_Statement::generateRISCV(std::ostream &os, Context& context, int destReg) const
{
    if (declaration_list != NULL)
    {
        for (auto declaration = declaration_list->begin(); declaration != declaration_list->end(); declaration++)
        {
            (*declaration)->generateRISCV(os, context, destReg);
        }
    }

    if (statement_list != NULL)
    {
        for(auto statement = statement_list->begin(); statement != statement_list->end(); statement++)
        {
            (*statement)->generateRISCV(os, context, destReg);
        }
    }
}
